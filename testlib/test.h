#pragma once
#ifndef TEST_H
#define TEST_H

using testfunc = void(*)();

void setTest(const char* name, int argc = 0);

void runTest(testfunc func);

#endif // _H