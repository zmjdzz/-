//
// Created by m on 2020/12/28.
//
#include "common/Video.h"
#include <iostream>
#include "driver/Camera.h"
#include <opencv2/opencv.hpp>

Video::Video() {
    std::string finalname = Filename();
    _VideoWriter.open(finalname,cv::VideoWriter::fourcc('M','P','4','2'),25,cv::Size(1280,1024));
}

Video::~Video() {
    _VideoWriter.release();
}

bool Video::getVideo(cv::Mat& srcImg) {
    cv::Mat frame;
    frame = srcImg;
    _VideoWriter.write(frame);
    return true;
}

std::string Video::Filename() {
    time_t currentTime;
    struct tm* timePointer;
    time(&currentTime);
    timePointer = localtime(&currentTime);

    std::string name;
    name = "/home/m/automatic-aiming-system/output/";
    std::string filename;
    filename = name + std::to_string(timePointer->tm_year + 1900) + "-" +
           std::to_string(timePointer->tm_mon + 1) + "-" +
           std::to_string(timePointer->tm_mday) + " " +
           std::to_string(timePointer->tm_hour) + ":" +
           std::to_string(timePointer->tm_min) + ":" +
           std::to_string(timePointer->tm_sec) + ".avi";
    return filename;
}

