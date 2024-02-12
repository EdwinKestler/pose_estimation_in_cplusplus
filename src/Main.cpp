#include <iostream>
#include <opencv2/opencv.hpp>


using namespace cv;

int main()
{
    const std::string RTSP_URL = "rtsp://user:pass@192.168.0.189:554/h264Preview_01_main";

#if WIN32
    _putenv_s("OPENCV_FFMPEG_CAPTURE_OPTIONS", "rtsp_transport;udp");
#else
    setenv("OPENCV_FFMPEG_CAPTURE_OPTIONS", "rtsp_transport;udp", 1);
#endif

    Mat frame;
    VideoCapture cap(RTSP_URL, CAP_FFMPEG);

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