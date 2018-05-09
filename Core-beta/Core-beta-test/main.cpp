//
//  main.cpp
//  Core-beta-test
//
//  Created by Photon Cat on 2018/5/6.
//  Copyright © 2018 Must Studio. All rights reserved.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "../Core-beta/Card.hpp"
#include "../Core-beta/Player.hpp"
#include "../Core-beta/CardFactory.hpp"
#include "../Core-beta/Core.hpp"

int main(int argc, const char * argv[]) {
    std::ofstream result("testResult.txt");
    INVIGILATION_CORE::Core core;
    core.createPlayers();
    result << "Hello, Test!" << std::endl;
    result << core.toString() << std::endl;
    return 0;
}
