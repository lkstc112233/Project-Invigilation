//
//  Core.cpp
//  Core-beta
//
//  Created by Photon Cat on 2018/4/29.
//  Copyright © 2018 Must Studio. All rights reserved.
//

#include "stdafx.h"
#include "Core.hpp"
#include "Player.hpp"
#include "Card.hpp"
#include "utility.hpp"

#include <sstream>

namespace INVIGILATION_CORE {
    Core::Core()
    {
        
    }
    
    Core::~Core()
    {
        
    }
    
    void Core::loadDeck()
    {
        
    }
    
    std::string Core::toString()
    {
        std::ostringstream result;
        result << "Core:" << std::endl;
        result << "\tPlayers: " << std::endl;
        for (auto const & player : players)
        {
            std::string cardText = player->toString();
            result << "\t\t" << UTILITY::trimEnd(UTILITY::replaceAll(cardText, "\n", "\n\t\t"), '\t');
        }
        result << "\tPublic Deck: " << std::endl;
        for (auto const & card : pubDeck)
        {
            std::string cardText = card->toString();
            result << "\t\t" << UTILITY::trimEnd(UTILITY::replaceAll(cardText, "\n", "\n\t\t"), '\t');
        }
        return result.str();
    }
}
