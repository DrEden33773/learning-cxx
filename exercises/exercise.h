#ifndef __EXERCISE_H__
#define __EXERCISE_H__

#include <iostream>

#define ASSERT(COND, MSG)                                                                    \
    if (!(COND)) {                                                                           \
        std::cerr << "\x1b[31mAssertion failed at line #" << __LINE__ << ": \x1b[0m" << '\n' \
                  << '\n'                                                                    \
                  << #COND << '\n'                                                           \
                  << '\n'                                                                    \
                  << "\x1b[34mMessage:\x1b[0m" << '\n'                                       \
                  << '\n'                                                                    \
                  << MSG << '\n'                                                             \
                  << '\n';                                                                   \
        exit(1);                                                                             \
    }

#endif// __EXERCISE_H__
