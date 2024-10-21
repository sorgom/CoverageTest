#pragma once
#ifndef COVERAGE_FD_SET_H
#define COVERAGE_FD_SET_H

#include <coverage.h>

#ifdef _WIN32
#include <winsock2.h>
#else
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#endif

void selectSocket1(const int socket)
{
    fd_set readfds;
    FD_ZERO(&readfds);
    FD_SET(socket, &readfds);
}

void selectSocket2(const int socket)
{
    fd_set readfds;
    FD_ZERO(&readfds);
    BULLSEY_PAUSE
    #pragma CTC SKIP
    FD_SET(socket, &readfds);
    #pragma CTC ENDSKIP
    BULLSEY_RESUME
}
#endif // _H
