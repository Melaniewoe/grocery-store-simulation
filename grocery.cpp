//
//  grocery.cpp
//  Woe_HW6
//
//  Copyright © 2016 Melanie Woe. All rights reserved.
//

#include "grocery.h"
#include <cassert> //provide asser
#include <cstdlib>

using namespace std;

bool_source::bool_source(double p)
{
    assert(p >= 0);
    assert(p <= 1);
    probability = p;
}

bool bool_source::query() const
{
    return (rand() < probability * RAND_MAX);
}

averager::averager()
{
    count = 0;
    sum = 0;
}

void averager::nextnum(double val)
{
    ++count;
    sum += val;
}

double averager::average() const
{
    //assert(numbers_count() > 0);
    return sum / count;
}

Register::Register(unsigned int t)
{
    seconds_for_register = t;
    register_time_left = 0;
    status = 'a';
    in_line = 0;
}

void Register::one_sec()
{
    if(_busy())
        --register_time_left;
    
}

void Register::start_register()
{
    assert(!_busy());
    register_time_left = seconds_for_register;
}





