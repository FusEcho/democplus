#pragma once

#include <iostream>
#include <thread>
#include <atomic>
// #include <memory>
#include <mutex>
#include <liveMedia.hh>
#include <BasicUsageEnvironment.hh>

class CRtspSource
{
public:
    CRtspSource(const std::string &url);
    ~CRtspSource();

    void start();
    void stop();

private:
    void connect();
    static void continueAfterDESCRIBE(RTSPClient *rtsp_client, int resultCode, char* resultString);

private:
    std::atomic_bool m_bRunning;
    bool m_bClosed;
    std::thread m_Worker;
    std::string m_Url;

public:
    RTSPClient *m_RtspClient;
};