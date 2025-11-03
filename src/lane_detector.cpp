#include "lane_detector.h"
#include <iostream>

LaneDetector::LaneDetector() {}

cv::Mat LaneDetector::regionOfInterest(const cv::Mat &img)
{
    cv::Mat mask = cv::Mat::zeros(img.size(), img.type());
    cv::Point pts[4] = {
        {img.cols * 0.1, img.rows},
        {img.cols * 0.45, img.rows * 0.6},
        {img.cols * 0.55, img.rows * 0.6},
        {img.cols * 0.9, img.rows}};
    cv::fillConvexPoly(mask, pts, 4, cv::Scalar(255, 255, 255));
    cv::Mat roi;
    cv::bitwise_and(img, mask, roi);
    return roi;
}

std::vector<cv::Vec4i> LaneDetector::detectEdgesAndLines(const cv::Mat &frame)
{
    cv::Mat gray, blur, edges;
    cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);
    cv::GaussianBlur(gray, blur, cv::Size(7, 7), 0);
    cv::Canny(blur, edges, 50, 150);
    cv::Mat roi = regionOfInterest(edges);
    std::vector<cv::Vec4i> lines;
    cv::HoughLinesP(roi, lines, 1, CV_PI / 180, 50, 50, 150);
    return lines;
}

void LaneDetector::drawLaneLines(cv::Mat &frame, const std::vector<cv::Vec4i> &lines)
{
    for (auto l : lines)
    {
        cv::line(frame, {l[0], l[1]}, {l[2], l[3]}, cv::Scalar(0, 255, 0), 3, cv::LINE_AA);
    }
}

cv::Mat LaneDetector::processFrame(const cv::Mat &frame)
{
    auto lines = detectEdgesAndLines(frame);
    cv::Mat output = frame.clone();
    drawLaneLines(output, lines);
    return output;
}
