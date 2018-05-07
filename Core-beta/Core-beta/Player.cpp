//
//  Player.cpp
//  Core-beta
//
//  Created by Photon Cat on 2018/4/29.
//  Copyright © 2018 Must Studio. All rights reserved.
//

#include "stdafx.h"
#include <string>
#include <sstream>
#include "Player.hpp"
#include "Card.hpp"
#include "utility.hpp"

namespace INVIGILATION_CORE {
    Player::Player()
    {
        
    }
    
    Player::~Player()
    {
        
    }
    
    std::string Player::toString()
    {
        std::ostringstream result;
        result << "Player:" << std::endl;
        result << "\tHand: " << std::endl;
        for (auto const & card : hand)
        {
            std::string cardText = card->toString();
            result << UTILITY::trimEnd(UTILITY::replaceAll(cardText, "\n", "\n\t"), '\t');
        }
        result << "\tPersonal Deck: " << std::endl;
        for (auto const & card : deck)
        {
            std::string cardText = card->toString();
            result << UTILITY::trimEnd(UTILITY::replaceAll(cardText, "\n", "\n\t"), '\t');
        }
        return result.str();
    }
}
