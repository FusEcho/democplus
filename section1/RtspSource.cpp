#include "RtspSource.hpp"

const int RTSP_CLIENT_VERBOSITY_LEVEL = 0;

CRtspSource::CRtspSource(const std::string &url) : m_Url(url), m_bRunning(false)
{

}

CRtspSource::~CRtspSource()
{
    
}

void CRtspSource::start()
{
    if(!m_bRunning){
        m_bRunning = true;
        m_bClosed = false;
        m_Worker = std::thread([this]{connect();});
        m_Worker.detach();
    }
}

void CRtspSource::stop()
{
    m_bRunning = false;
    m_bClosed = true;
}

void CRtspSource::connect()
{
    TaskScheduler *scheduler = BasicTaskScheduler::createNew();
	UsageEnvironment *env = BasicUsageEnvironment::createNew(*scheduler);

    std::string progName = "Deepglint";
    m_RtspClient = RTSPClient::createNew(*env, m_Url.c_str(), RTSP_CLIENT_VERBOSITY_LEVEL, progName.c_str(), 0, -1);
    m_RtspClient->sendDescribeCommand(continueAfterDESCRIBE);

    env->taskScheduler().doEventLoop((char*)&m_bClosed);

    std::cout << "finished" << std::endl;
}

void CRtspSource::continueAfterDESCRIBE(RTSPClient *rtsp_client, int resultCode, char* resultString)
{
    std::cout << "return " << resultCode << std::endl;
    std::cout << "return " << resultString << std::endl;
}