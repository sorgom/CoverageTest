#pragma once
#ifndef TEST_RUNNER_H
#define TEST_RUNNER_H

struct Test
{
    Test(const char* const name = nullptr);
    void run();
    virtual void body() = 0;
    Test* next = nullptr;
    const char* const name = nullptr;
};

class TestRunner
{
public:
    static Test* pStart;
    static Test* pCurr;
    static void add(Test* test);
    static void run();
};

#endif // _H
