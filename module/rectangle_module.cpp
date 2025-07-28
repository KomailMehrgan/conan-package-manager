#include "module/rectangle_module.h"
#include <fstream>
#include <stdexcept>

namespace ai {

RectangleModule::RectangleModule() : result_callback_(nullptr), rect_(0, 0, 100, 100), color_(0, 255, 0), thickness_(2) {}

RectangleModule::~RectangleModule() {
    destroy();
}

bool RectangleModule::init(const std::string& config_path) {
    try {
        std::ifstream config_file(config_path);
        if (!config_file.is_open()) {
            throw std::runtime_error("Failed to open config file: " + config_path);
        }

        json config;
        config_file >> config;

        // Parse rectangle parameters
        rect_.x = config.at("rectangle").at("x").get<int>();
        rect_.y = config.at("rectangle").at("y").get<int>();
        rect_.width = config.at("rectangle").at("width").get<int>();
        rect_.height = config.at("rectangle").at("height").get<int>();

        // Parse color (RGB)
        color_ = cv::Scalar(
            config.at("color").at("b").get<int>(),
            config.at("color").at("g").get<int>(),
            config.at("color").at("r").get<int>()
        );

        // Parse thickness
        thickness_ = config.at("thickness").get<int>();

        return true;
    } catch (const std::exception& e) {
        std::cerr << "Error initializing RectangleModule: " << e.what() << std::endl;
        return false;
    }
}

cv::Mat RectangleModule::process(const cv::Mat& input) {
    if (input.empty()) {
        return input;
    }

    cv::Mat output = input.clone();
    cv::rectangle(output, rect_, color_, thickness_);

    // Prepare JSON result
    json result = {
        {"module", "RectangleModule"},
        {"rectangle", {
            {"x", rect_.x},
            {"y", rect_.y},
            {"width", rect_.width},
            {"height", rect_.height}
        }},
        {"status", "success"}
    };

    // Invoke callback if set
    if (result_callback_) {
        result_callback_(result, output);
    }

    return output;
}

bool RectangleModule::update(const std::string& config_path) {
    try {
        std::ifstream config_file(config_path);
        if (!config_file.is_open()) {
            throw std::runtime_error("Failed to open config file: " + config_path);
        }

        json config;
        config_file >> config;

        // Parse rectangle parameters
        rect_.x = config.at("rectangle").at("x").get<int>();
        rect_.y = config.at("rectangle").at("y").get<int>();
        rect_.width = config.at("rectangle").at("width").get<int>();
        rect_.height = config.at("rectangle").at("height").get<int>();

        // Parse color (RGB)
        color_ = cv::Scalar(
            config.at("color").at("b").get<int>(),
            config.at("color").at("g").get<int>(),
            config.at("color").at("r").get<int>()
        );

        // Parse thickness
        thickness_ = config.at("thickness").get<int>();

        return true;
    }
    catch (const std::exception& e) {
        std::cerr << "Error initializing RectangleModule: " << e.what() << std::endl;
        return false;
    }
}

void RectangleModule::destroy() {
    // Clean up resources if needed
    result_callback_ = nullptr;
}

void RectangleModule::setResultCallback(ResultCallback callback) {
    result_callback_ = callback;
}

} // namespace ai