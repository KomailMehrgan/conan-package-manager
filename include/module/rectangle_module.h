#ifndef RECTANGLE_MODULE_H
#define RECTANGLE_MODULE_H

#include "ai_interface.h"
#include <opencv2/opencv.hpp>
#include <nlohmann/json.hpp>

namespace ai {

class RectangleModule : public AIInterface {
public:
    RectangleModule();
    ~RectangleModule() override;

    bool init(const std::string& config_path) override;
    cv::Mat process(const cv::Mat& input) override;
    bool update(const std::string& config_path) override;
    void destroy() override;
    void setResultCallback(ResultCallback callback) override;

private:
    ResultCallback result_callback_;
    cv::Rect rect_;
    cv::Scalar color_;
    int thickness_;
};

} // namespace ai

#endif // RECTANGLE_MODULE_H