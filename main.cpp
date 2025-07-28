#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
    std::cout << "OpenCV version: " << CV_VERSION << std::endl;

    cv::Mat image = cv::Mat::zeros(400, 400, CV_8UC3);
    cv::circle(image, cv::Point(200, 200), 100, cv::Scalar(0, 255, 0), -1);

    cv::imshow("Green Circle", image);
    cv::waitKey(0);

    return 0;
}