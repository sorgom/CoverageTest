#pragma once
#ifndef TEST_RUNNER_H
#define TEST_RUNNER_H

struct Test
{
    Test();
    virtual void run() = 0;
    Test* next = nullptr;
};

class TestRunner
{
public:
    static Test* pStart;
    static Test* pCurr;
    static void add(Test* test);
    static void run();
};

inline Test::Test()
{
    TestRunner::add(this);
}

#endif // _H
