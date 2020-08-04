#include "Application.h"
#include "FGQueue.hpp"
#include "Service.h"

#include <iostream>

int main() {
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
    return 0;
}