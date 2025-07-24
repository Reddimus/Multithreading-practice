#ifndef THREADS_PRACTICE_H  // Header guard to prevent multiple inclusions
#define THREADS_PRACTICE_H

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <vector>

std::string algorithm1();
std::string algorithm2();
std::string algorithm3();

class ThreadsPractice
{
private:
    enum class Stage : int8_t { First, Second, Third };
    Stage stage;
    std::mutex mtx;
    std::condition_variable cv;
public:
    // Simple constructor that will not throw exceptions
    ThreadsPractice() noexcept : stage(Stage::First) {}
    void first(std::function<void()> algorithm1);
    void second(std::function<void()> algorithm2);
    void third(std::function<void()> algorithm3);
};

namespace ThreadedAlgorithmsTest
{
    void in_order(const std::vector<std::function<std::string()>>& algorithms);
}

#endif // THREADS_PRACTICE_H
