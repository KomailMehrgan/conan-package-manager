#include "ai_interface.h"
#include "module/rectangle_module.h"
#include <opencv2/opencv.hpp>
#include <iostream>

int main() {

    cv::utils::logging::setLogLevel(cv::utils::logging::LOG_LEVEL_WARNING);


    ai::RectangleModule module;
    if (!module.init("config/rectangle_config.json")) {
        std::cerr << "Failed to initialize RectangleModule" << std::endl;
        return -1;
    }

    // Set up callback
    module.setResultCallback([](const nlohmann::json& result, const cv::Mat& output) {
        std::cout << "Result: " << result.dump(4) << std::endl;
        cv::imshow("Output", output);
        cv::imwrite("Output.png", output);
        cv::waitKey(0); // Wait for key press to close window
        });

    // Create a blank image for testing
    cv::Mat input(480, 640, CV_8UC3, cv::Scalar(255, 255, 255)); // White 640x480 image


    // Process the image
    cv::Mat output = module.process(input);
  
  
    return 0;
}