#include "Application.h"
#include "FGBlockingQueue.hpp"
#include "FGQueue.hpp"
#include "Service.h"

#include <iostream>
#include <thread>
#include <unistd.h>

CFGBlockingQueue<int> m_Queue(100);

void run1()
{
    int i = 0;
    while (true) {
        if (m_Queue.push(++i)) {
            std::cout << "thread 1 is running " << i << std::endl;
            sleep(1);
        }
    }
}

void run2()
{
    while (true) {
        int j;
        if (m_Queue.pop(j)) {
            std::cout << "thread 2 running " << j << std::endl;
        } else {
            std::cout << "runing" << std::endl;
        }
    }
}

int main()
{
    std::thread t1(run1);
    t1.detach();

    std::thread t2(run2);
    t2.join();

#ifdef FALSE
    CFGQueue<int> myqueue(5);
    int i = 2;
    int j = 3;
    myqueue.push(i);
    myqueue.push(j);

    std::cout << "hello world " << myqueue.length() << std::endl;
    myqueue.pop();
    int ret;
    myqueue.front(ret);
    std::cout << "hello world " << myqueue.length() << " front " << ret << std::endl;

    myqueue.clear();
    std::cout << "hello world " << myqueue.length() << std::endl;
#endif
    return 0;
}