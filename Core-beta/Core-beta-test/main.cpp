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
#include <random>
#include "../Core-beta/Card/Card.hpp"
#include "../Core-beta/Core/Player.hpp"
#include "../Core-beta/Card/CardFactory.hpp"
#include "../Core-beta/Core/Core.hpp"
#include "../Core-beta/Interface/ConsoleInterface.hpp"
#include "../Core-beta/Interface/Action.hpp"
#include "../Core-beta/utility.hpp"

void deckBuildingTest()
{
    std::ofstream result("testResult.txt");
    INVIGILATION_CORE::Core core;
    core.createPlayers();
    result << "Hello, Test!" << std::endl;
    result << core.toString() << std::endl;
}

void interactionTest()
{
    INVIGILATION_CORE::ConsoleInterface ci;
    while (ci.action()->getType() != INVIGILATION_CORE::Nothing)
        std::cout << "ActionReceived" << std::endl;
}

namespace INVIGILATION_CORE
{
    namespace UTILITY
    {
        extern std::mt19937 RandomDevice19937ForShuffling;
    }
}

int main(int argc, const char * argv[]) {
    INVIGILATION_CORE::UTILITY::RandomDevice19937ForShuffling.seed(42);
    deckBuildingTest();
    return 0;
}

