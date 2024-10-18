#pragma once
#ifndef USE_H
#define USE_H

//  enable usage of "and", "or" 
#include <ciso646>

//  avoid unused variables warning
template <typename... Args>
inline void use(const Args&... args)
{}

#endif // _H