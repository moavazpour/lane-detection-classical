#pragma once
#include <opencv2/opencv.hpp>

class LaneDetector {
public:
    LaneDetector();
    cv::Mat processFrame(const cv::Mat& frame);
private:
    cv::Mat regionOfInterest(const cv::Mat& img);
    std::vector<cv::Vec4i> detectEdgesAndLines(const cv::Mat& frame);
    void drawLaneLines(cv::Mat& frame, const std::vector<cv::Vec4i>& lines);
};
