// main.cpp
#include "rstpStream.h"

int main() {
    const std::string rstp_url = "rtsp://admin:FBx!admin2023@192.168.1.108:554";
    openRTSPStream(rstp_url);
    return 0;
}