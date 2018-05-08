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

int main(int argc, const char * argv[]) {
    std::ofstream result("testResult.txt");
    INVIGILATION_CORE::Player player;
    INVIGILATION_CORE::CardBuilder cardBuilder;
    cardBuilder.setTypeId(0).setName("Fire");
    auto card = cardBuilder.makeCard();
    player.takeCardIntoHand(std::move(card));
    cardBuilder.setName("Ice");
    card = cardBuilder.makeCard();
    player.takeCardIntoHand(std::move(card));
    result << "Hello, Test!" << std::endl;
    result << player.toString() << std::endl;
    return 0;
}
