#include <iostream>
#include <vector>

#include <opencv2/opencv.hpp>
#include "nlohmann/json.hpp"

// for convenience
using json = nlohmann::json;

int main() {
    // 1. Define our drawing parameters using a JSON object
    json config = {
        {"image_width", 400},
        {"image_height", 400},
        {"circle", {
            {"center_x", 200},
            {"center_y", 200},
            {"radius", 100},
            {"color_bgr", {0, 255, 0}} // Blue, Green, Red
        }}
    };

    std::cout << "--- Configuration ---" << std::endl;
    std::cout << config.dump(4) << std::endl; // pretty-print the JSON
    std::cout << "---------------------" << std::endl;
    std::cout << "OpenCV version: " << CV_VERSION << std::endl;

    // 2. Parse values from the JSON object
    int width = config["image_width"];
    int height = config["image_height"];

    cv::Point center(
        config["circle"]["center_x"],
        config["circle"]["center_y"]
    );

    int radius = config["circle"]["radius"];

    std::vector<int> color_vec = config["circle"]["color_bgr"];
    cv::Scalar color(color_vec[0], color_vec[1], color_vec[2]);


    // 3. Use the parsed values to create the image with OpenCV
    cv::Mat image = cv::Mat::zeros(height, width, CV_8UC3);
    cv::circle(image, center, radius, color, -1);

    cv::imshow("OpenCV + JSON Demo", image);
    cv::waitKey(0);

    return 0;
}
