#include "opencv4/opencv2/opencv.hpp"
#include <iostream>

int main() {
    cv::VideoCapture cap(0);

    if (!cap.isOpened())
    {
        std::cout << "Error opening video stream" << std::endl;
        return -1;
    }

    int frame_width = cap.get(cv::CAP_PROP_FRAME_WIDTH);
    int frame_height = cap.get(cv::CAP_PROP_FRAME_HEIGHT);

    cv::VideoWriter video("outcpp.avi", cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), 25, cv::Size(frame_width, frame_height));
    //VideoWriter video("outcpp1.avi", CV_FOURCC('M', 'P', '4', '2'), 25, Size(frame_width, frame_height));


    while (1)
    {
        cv::Mat frame;
        cap >> frame;

        if (frame.empty())
            break;

        video.write(frame);
        imshow("Frame", frame);

        // Press  ESC on keyboard to  exit   按ESC 推出录制
        char c = (char)cv::waitKey(1);
        if (c == 27)
            break;
    }

    cap.release();
    video.release();
    cv::destroyAllWindows();
    return 0;
}
