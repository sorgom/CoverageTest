#pragma once
#ifndef TEST_H
#define TEST_H

using testfunc = void(*)();

void settest(const char* name);

void test(testfunc func);

#endif // _H