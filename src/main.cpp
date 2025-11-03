#include "lane_detector.h"
#include <opencv2/opencv.hpp>

int main()
{
    LaneDetector detector;
    cv::VideoCapture cap("../data/solidWhiteRight.mp4");
    if (!cap.isOpened())
    {
        std::cerr << "Cannot open video file!\n";
        return -1;
    }

    cv::Mat frame, output;
    while (true)
    {
        cap >> frame;
        if (frame.empty())
            break;

        output = detector.processFrame(frame);

        cv::imshow("Lane Detection", output);
        if (cv::waitKey(33) == 27)
            break; // ESC to quit
    }
    return 0;
}
