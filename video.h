#ifndef AUTOMATIC_AIMING_SYSTEM_VIDEO_H
#define AUTOMATIC_AIMING_SYSTEM_VIDEO_H

#include <opencv2/opencv.hpp>
#include <string>
#include <driver/Camera.h>
#include "common/CycleQueue.h"
#include "common/Time.h"


class Video{
public:
    Video();
    ~Video();
    bool getVideo(cv::Mat& srcImg);
    std::string Filename();


public:
    cv::VideoWriter             _VideoWriter;
};

#endif //AUTOMATIC_AIMING_SYSTEM_VIDEO_H
