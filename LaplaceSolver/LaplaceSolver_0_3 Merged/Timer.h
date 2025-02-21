#pragma once

#include <chrono>
#include <cstring>
#include <iostream>

struct Timer
{
    using clock_t = std::chrono::high_resolution_clock;
    using time_point_t = std::chrono::time_point<clock_t>;
    using elapsed_time_t = std::chrono::duration<double, std::milli>;
    
    time_point_t mStartTime;
    time_point_t mStopTime;
    elapsed_time_t mElapsedTime;
    int counter;
    
    void Start()
    {
        mElapsedTime = elapsed_time_t::zero();
        mStartTime = clock_t::now();
        counter += 1;
    }
    
    void Stop(const std::string& msg)
    {
        mStopTime = clock_t::now();
        std::chrono::duration<double, std::milli> elapsedTime = mStopTime - mStartTime;
        std::cout << "[" << msg << elapsedTime.count() << "ms]" << std::endl;
    }

    void Reset()
    {
        mElapsedTime = elapsed_time_t::zero();
        counter = 0;
    }
    
    void Restart()
    {
        mStartTime = clock_t::now();
        counter += 1;
    }

    void Pause()
    {
        mStopTime = clock_t::now();
        mElapsedTime += mStopTime-mStartTime;
    }

    void Print(const std::string& msg)
    {
        std::cout << "[" << msg << mElapsedTime.count() << "ms]" << std::endl;
    }

    void PrintAverage(const std::string& msg)
    {
        std::cout << "[" << msg << mElapsedTime.count() / counter << "ms]" << std::endl;
    }
    
    int GetElapsedTime()
    {
        return mElapsedTime.count();
    }
};
