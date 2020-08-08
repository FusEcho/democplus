#pragma once

#include <atomic>
#include <condition_variable>
#include <iostream>
#include <memory>
#include <mutex>
#include <queue>

template <typename T> class CFGBlockingQueue
{
public:
    CFGBlockingQueue(const size_t size_max)
        : m_SizeMax(size_max)
    {
    }

    ~CFGBlockingQueue()
    {
        clear();
    }

    bool push(T &data)
    {
        std::unique_lock<std::mutex> lck(m_Mutex);

        if (m_Queue.size() < m_SizeMax) {
            m_Queue.push(std::move(data));

            m_EmptyCon.notify_all();
            return true;
        } else {
            m_FullCon.wait(lck);
        }

        return false;
    }

    bool pop(T &data)
    {
        std::unique_lock<std::mutex> lck(m_Mutex);

        if (!m_Queue.empty()) {
            data = m_Queue.front();
            m_Queue.pop();

            m_FullCon.notify_all();
            return true;
        } else {
            m_EmptyCon.wait(lck);
        }

        return false;
    }

    bool front(T &data)
    {
        std::unique_lock<std::mutex> lck(m_Mutex);
        if (!m_Queue.empty()) {
            data = m_Queue.front();
            return true;
        }
        return false;
    }

    int length()
    {
        std::unique_lock<std::mutex> lck(m_Mutex);
        int size = static_cast<int>(m_Queue.size());
        return size;
    }

    bool empty()
    {
        std::unique_lock<std::mutex> lck(m_Mutex);
        bool isEmpty = m_Queue.empty();
        return isEmpty;
    }

    bool full()
    {
        std::unique_lock<std::mutex> lck(m_Mutex);
        bool isFull = m_Queue.size() >= m_SizeMax ? true : false;
        return isFull;
    }

    bool clear()
    {
        std::unique_lock<std::mutex> lck(m_Mutex);
        while (!m_Queue.empty()) {
            m_Queue.pop();
        }
        return true;
    }

private:
    std::queue<T> m_Queue;
    typename std::queue<T>::size_type m_SizeMax;

    std::mutex m_Mutex;

    // used for blocking queue
    std::condition_variable m_FullCon;
    std::condition_variable m_EmptyCon;
};