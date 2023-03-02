
#ifndef SUITE_H
#define SUITE_H

#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

class Suite
{
public:
    /**
     * Default constructor
     */
    Suite();
    static void run_test(std::string&&);
    static void test1();
    static void test2();
    static void test3();
};

#endif // SUITE_H
