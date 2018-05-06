//
//  main.cpp
//  Core-beta-test
//
//  Created by Photon Cat on 2018/5/6.
//  Copyright © 2018 Must Studio. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "../Core-beta/Card.hpp"
#include "../Core-beta/CardFactory.hpp"

int main(int argc, const char * argv[]) {
    std::ofstream result("testResult.txt");
    auto card = INVIGILATION_CORE::CardFactory::makeCard();
    result << "Hello, Test!" << std::endl;
    result << card->toString() << std::endl;
    return 0;
}
