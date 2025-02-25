﻿#define _CRT_SECURE_NO_WARNINGS

#include "test.h"
#include <iostream>

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: xmake run learn <exercice number>" << '\n';
        return EXIT_FAILURE;
    }
    int num;
    if (1 != std::sscanf(argv[1], "%d", &num)) {
        std::cerr << "Invalid exercise number: " << argv[1] << '\n';
    };
    Log{Console{}} << num;
    return EXIT_SUCCESS;
}
