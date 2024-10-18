#pragma once
#ifndef CODING_H
#define CODING_H

//  unified instance declaration
#define INSTANCE_DEC(NAME) \
    static NAME& instance();

//  unified instance definition
#define INSTANCE_DEF(NAME) \
    NAME& NAME::instance() \
    { \
        static NAME instance; \
        return instance; \
    }
#endif // _H
