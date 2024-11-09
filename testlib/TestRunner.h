#pragma once
#ifndef TEST_RUNNER_H
#define TEST_RUNNER_H

#include <Test.h>

class TestRunner
{
public:
    static void add(Test* test);
    static void run();
private:
    static Test* pStart;
    static Test* pCurr;
};

#endif // _H
