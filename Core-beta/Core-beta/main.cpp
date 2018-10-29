//
//  main.cpp
//  Core-beta-test
//
//  Created by Photon Cat on 2018/5/6.
//  Copyright © 2018 Must Studio. All rights reserved.
//
#include "stdafx.h"

#include <fstream>
#include <iostream>
#include <random>
#include "Card/Card.hpp"
#include "Card/CardFactory.hpp"
#include "Core/Core.hpp"
#include "Core/Player.hpp"
#include "Interface/Action.pb.h"
#include "Interface/ConsoleInterface.hpp"
#include "utility.hpp"

void deckBuildingTest() {
  std::ofstream result("testResult.txt");
  INVIGILATION_CORE::Core core;
  core.createPlayers();
  result << "Hello, Test!" << std::endl;
  result << core.toString() << std::endl;
}

void interactionTest() {
  INVIGILATION_CORE::ConsoleInterface ci;
  while (ci.action().type() != INVIGILATION_CORE::Action::Nothing)
    std::cout << "ActionReceived" << std::endl;
}

namespace INVIGILATION_CORE {
namespace UTILITY {
extern std::mt19937 RandomDevice19937ForShuffling;
}
}  // namespace INVIGILATION_CORE

int main(int argc, const char* argv[]) {
  INVIGILATION_CORE::UTILITY::RandomDevice19937ForShuffling.seed(42);
  deckBuildingTest();
  return 0;
}
