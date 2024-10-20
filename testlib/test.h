#pragma once
#ifndef TEST_H
#define TEST_H

using testfunc = void(*)();

void settest(const char* name, int argc = 0);

void test(testfunc func);

#endif // _H