#ifndef TIME_METRIC_HPP
#define TIME_METRIC_HPP

#include <unordered_map>
#include <iostream>
#include "zkassert.hpp"
#include "zkmax.hpp"
#include "timer.hpp"

class TimeMetric
{
    public:
        uint64_t time;
        uint64_t times;
    TimeMetric() : time(0), times(0) {;}
};

class TimeMetricStorage
{
public:
    unordered_map<string, TimeMetric> map;
    void add(const char * pChar, uint64_t time, uint64_t times=1)
    {
        string key = pChar;
        add(key, time, times);
    }
    void add(string &key, uint64_t time, uint64_t times=1);
    void print(const char * pTitle, uint64_t padding = 32);
};

#endif