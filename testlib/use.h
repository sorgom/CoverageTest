#pragma once
#ifndef USE_H
#define USE_H

//  enable usage of "and", "or"
#include <ciso646>

//  avoid unused variables warning
template <typename... Args>
inline void use(const Args&... args) {}

//  bool parameter call
inline static void call(const bool) {}

//  do nothing
inline void pass() {}

#endif // _H
