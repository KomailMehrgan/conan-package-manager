#include <iostream>
#include <opencv2/opencv.hpp>
#include <openvino/openvino.hpp>

int main() {
    std::cout << "OpenCV version: " << CV_VERSION << std::endl;
    std::cout << "Creating a simple image..." << std::endl;

    // Create a black 400x400 image
    cv::Mat image = cv::Mat::zeros(400, 400, CV_8UC3);

    // Draw a solid green circle in the center
    cv::circle(image, cv::Point(200, 200), 100, cv::Scalar(0, 255, 0), -1);

    // Display the image in a window
    cv::imshow("OpenCV + Conan Demo", image);


    ov::Core core;

        
        // This is the correct method for this version of the library.
        std::cout << "OpenVINO version: " << core.get_versions("CPU").at("CPU") << std::endl;

        //  Get the list of available inference devices
        std::vector<std::string> devices = core.get_available_devices();

        //  Print the available devices
        std::cout << "Available devices:" << std::endl;
        for (const auto& device : devices) {
            std::cout << "  - " << device << std::endl;
        }

    // Wait for a key press before closing the window
    cv::waitKey(0);

    return 0;
}