#pragma once

#include <atomic>
#include <iostream>
#include <memory>
#include <mutex>
#include <queue>
// #include <condition_variable>

template <typename T> class CFGQueue {
public:
    CFGQueue(const size_t size_max) : m_SizeMax(size_max) {
        // // used for blocking queue
        // m_Quit = ATOMIC_VAR_INIT(false);
        // m_Finished = ATOMIC_VAR_INIT(false);
    }

    ~CFGQueue() {
        clear();
    }

    bool push(T &data) {
        std::unique_lock<std::mutex> lock(m_Mutex);
        if (m_Queue.size() < m_SizeMax) {
            m_Queue.push(std::move(data));
            return true;
        }
        return false;
    }

    bool pop() {
        std::unique_lock<std::mutex> lock(m_Mutex);
        if (!m_Queue.empty()) {
            m_Queue.pop();
            return true;
        }
        return false;
    }

    bool front(T &data) {
        std::unique_lock<std::mutex> lock(m_Mutex);
        if (!m_Queue.empty()) {
            data = m_Queue.front();
            return true;
        }
        return false;
    }

    int length() {
        std::unique_lock<std::mutex> lock(m_Mutex);
        int size = static_cast<int>(m_Queue.size());
        return size;
    }

    bool empty() {
        std::unique_lock<std::mutex> lock(m_Mutex);
        bool isEmpty = m_Queue.empty();
        return isEmpty;
    }

    bool full() {
        std::unique_lock<std::mutex> lock(m_Mutex);
        bool isFull = m_Queue.size() >= m_SizeMax ? true : false;
        return isFull;
    }

    bool clear() {
        std::unique_lock<std::mutex> lock(m_Mutex);
        while (!m_Queue.empty()) {
            m_Queue.pop();
        }
        return true;
    }

private:
    std::queue<T> m_Queue;
    typename std::queue<T>::size_type m_SizeMax;

    std::mutex m_Mutex;

    // // used for blocking queue
    // std::condition_variable m_FullCon;
    // std::condition_variable m_EmptyCon;

    // std::atomic_bool m_Quit;
    // std::atomic_bool m_Finished;
};