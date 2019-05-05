#include <iostream>
#include <boost/config.hpp>
#include "Runnable.h"

class Test: public Runnable {
public:
    virtual void run() override;
    ~Test();
};

void Test::run() {
    std::cout << "Running" << std::endl;
}

Test::~Test() {
    std::cout << "Destroyed" << std::endl;
}

extern "C" BOOST_SYMBOL_EXPORT Test plugin;
Test plugin;