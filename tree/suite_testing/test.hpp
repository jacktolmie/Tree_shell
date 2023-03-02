#ifndef TESTS_HPP
#define TESTS_HPP

#include <iostream>

class Tests
{
    virtual std::string get_title();
    
    virtual std::string get_docs();

	virtual bool run();

	virtual bool run_optimized();

	virtual bool verify();
    
    virtual bool pre();

	virtual bool janitor();
};

#endif //TEST_HPP
