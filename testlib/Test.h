#pragma once
#ifndef TEST_H
#define TEST_H

struct Test
{
    Test(const char* const name);
    void run();
    virtual void body() = 0;
    Test* next = nullptr;
    const char* const name;
};

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

#endif // _H
