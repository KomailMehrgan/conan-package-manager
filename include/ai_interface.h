#ifndef AI_INTERFACE_H
#define AI_INTERFACE_H

#include <opencv2/opencv.hpp>
#include <nlohmann/json.hpp>
#include <functional>
#include <string>

namespace ai {

using json = nlohmann::json;

// Callback function type for results: JSON data and processed cv::Mat
using ResultCallback = std::function<void(const json&, const cv::Mat&)>;

class AIInterface {
public:
    virtual ~AIInterface() = default;

    // Initialize the module with a JSON configuration file
    virtual bool init(const std::string& config_path) = 0;

    // Process an input frame and return the processed frame
    virtual cv::Mat process(const cv::Mat& input) = 0;

    // Update internal state or parameters (optional, e.g., for real-time adjustments)
    virtual bool update(const std::string& config_path) = 0;

    // Clean up resources
    virtual void destroy() = 0;

    // Set the callback function for results
    virtual void setResultCallback(ResultCallback callback) = 0;
};

} // namespace ai

#endif // AI_INTERFACE_H