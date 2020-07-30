#include <iostream>
#include <unistd.h>
#include <csignal>
#include "RtspSource.hpp"

volatile bool stop_signal = false;
void stop_handler(int signal)
{
    if(SIGTSTP == signal)
    {
        stop_signal = true;
    }
}

int main()
{
    std::signal(SIGTSTP, stop_handler);

    CRtspSource rtspClient("rtsp://172.17.0.2/a5");
    rtspClient.start();
    while(false == stop_signal){
        sleep(1);
    }
    rtspClient.stop();

    return 0;
}