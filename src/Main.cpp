#include <iostream>
#include "opencv2/opencv.hpp"


using namespace cv;

int main()
{
    const std::string rstp_url = "rtsp://admin:FBx!admin2023@192.168.1.108:554";

    Mat frame;
    VideoCapture cap(rstp_url, cv::CAP_FFMPEG);

    if (!cap.isOpened()) {
        std::cout << "Cannot open RTSP stream" << std::endl;

        return -1;
    }

    while (true) {
        cap >> frame;
        imshow("RTSP stream", frame);

        if (waitKey(1) == 27) {
            break;
        }
    }

    cap.release();
    destroyAllWindows();

    return 0;
}