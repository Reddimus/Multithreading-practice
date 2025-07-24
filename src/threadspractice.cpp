#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <vector>
#include "threadspractice.h"
#define N_MAX 10

void ThreadsPractice::first(std::function<void()> algorithm1COut)
{
    std::unique_lock<std::mutex> lck(mtx);
    algorithm1COut();
    stage = Stage::Second;
    cv.notify_all();
}

void ThreadsPractice::second(std::function<void()> algorithm2COut)
{
    std::unique_lock<std::mutex> lck(mtx);
    cv.wait(
        lck,
        [this]()
        {
            return stage == Stage::Second;
        }
    );
    algorithm2COut();
    stage = Stage::Third;
    cv.notify_all();
}

void ThreadsPractice::third(std::function<void()> algorithm3COut)
{
    std::unique_lock<std::mutex> lck(mtx);
    cv.wait(
        lck,
        [this]()
        {
            return stage == Stage::Third;
        }
    );
    algorithm3COut();
}

std::string algorithm1()
{
    for (int i = 0; i < N_MAX; ++i) {
        for (int j = 0; j < N_MAX; ++j) {
            for (int k = 0; k < N_MAX; ++k);
        }
    }
    return "A1 ";   
}

std::string algorithm2()
{
    for (int i = 0; i < N_MAX; ++i) {
        for (int j = 0; j < N_MAX; ++j);
    }
    return "A2 ";
}

std::string algorithm3()
{
    for (int i = 0; i < N_MAX; ++i);
    return "A3 ";
}

// Test function to demonstrate the solution
void ThreadedAlgorithmsTest::in_order(const std::vector<std::function<std::string()>>& algorithms) {
    ThreadsPractice threadsPractice;
    std::vector<std::thread> threads;

    // Create threads based on the input order
    for (const std::function<std::string()>& alg : algorithms)
    {
        // Extract function pointer to determine which algorithm this is
        std::string (*const *targetFunction)() = alg.target<std::string(*)()>();
        if (!targetFunction) {
            std::cerr << "Error: Invalid function pointer." << std::endl;
            return;
        }

        if (*targetFunction == algorithm1)
        {
            threads.emplace_back([&threadsPractice]()
            {
                const std::string algorithmOutput = algorithm1(); // Start work immediately
                threadsPractice.first([algorithmOutput](){ std::cout << algorithmOutput; });
            });
        }
        else if (*targetFunction == algorithm2)
        {
            threads.emplace_back([&threadsPractice]()
            {
                const std::string algorithmOutput = algorithm2();
                threadsPractice.second([algorithmOutput]() { std::cout << algorithmOutput; });
            });
        }
        else if (*targetFunction == algorithm3)
        {
            threads.emplace_back([&threadsPractice]()
            {
                const std::string algorithmOutput = algorithm3();
                threadsPractice.third([algorithmOutput]() { std::cout << algorithmOutput; });
            });
        }
    }

    // Wait for all threads to complete
    for (std::thread &t : threads)
    {
        t.join();
    }

    std::cout << std::endl;
}
