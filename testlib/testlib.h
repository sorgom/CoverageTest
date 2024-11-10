//  CppUTest style test "framework"
#pragma once
#ifndef TESTLIB_H
#define TESTLIB_H

//  test definition and add to run macro
#define TEST(name) \
struct name : Test \
{ \
    name(): \
        Test(#name) \
    {} \
    void body() override; \
}; \
name __##name; \
void name::body()

struct Test
{
    Test(const char* const name);
    void run();
    virtual void body() = 0;
    Test* next = nullptr;
    const char* const name;
};

//  test runner for main
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
