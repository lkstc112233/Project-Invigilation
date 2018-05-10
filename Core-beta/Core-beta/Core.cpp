//
//  Core.cpp
//  Core-beta
//
//  Created by Photon Cat on 2018/4/29.
//  Copyright © 2018 Must Studio. All rights reserved.
//

#include "stdafx.h"
#include <sstream>
#include <algorithm>
#include <random>

#include "Core.hpp"
#include "Player.hpp"
#include "Card.hpp"
#include "utility.hpp"
#include "CardFactory.hpp"

namespace INVIGILATION_CORE {
    Core::Core()
    {
        
    }
    
    Core::~Core()
    {
        
    }
    
    void Core::createPlayers(int count)
    {
        // remove any existing player, and any existing deck.
        players.clear();
        pubDeck.clear();
        for (int i = 0; i < count; ++i)
        {
            auto player = std::make_unique<Player>(CardBuilder::geterateId());
            auto deck = player->loadDeck();
            for (auto& pnt : deck)
                pubDeck.push_back(std::move(pnt));
            player->shuffleDeck();
            players.push_back(std::move(player));
        }
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(pubDeck.begin(), pubDeck.end(), g);
    }
    
    std::string Core::toString()
    {
        std::ostringstream result;
        result << "Core:" << std::endl;
        result << "  Players: " << std::endl;
        for (auto const & player : players)
        {
            std::string cardText = player->toString();
            result << "    " << UTILITY::trimEnd(UTILITY::replaceAll(cardText, "\n", "\n    "), ' ');
        }
        result << "  Public Deck: " << std::endl;
        for (auto const & card : pubDeck)
        {
            std::string cardText = card->toString();
            result << "    " << UTILITY::trimEnd(UTILITY::replaceAll(cardText, "\n", "\n    "), ' ');
        }
        return result.str();
    }
}
