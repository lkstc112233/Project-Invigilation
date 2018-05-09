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
#include "CardFactory.hpp"
using std::unique_ptr;

namespace INVIGILATION_CORE {
    Player::Player()
    {
        
    }
    
    Player::~Player()
    {
        
    }
    
    void Player::takeCardIntoHand(std::unique_ptr<Card> card)
    {
        hand.push_back(std::move(card));
    }
    
    void Player::shuffleDeck()
    {
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(deck.begin(), deck.end(),g);
    }
    
    std::vector<unique_ptr<Card>> Player::loadDeck()
    {
        std::vector<unique_ptr<Card>> result;
        
        return result;
    }
    
    std::string Player::toString()
    {
        std::ostringstream result;
        result << "Player:" << std::endl;
        result << "\tHand: " << std::endl;
        for (auto const & card : hand)
        {
            std::string cardText = card->toString();
            result << "\t\t" << UTILITY::trimEnd(UTILITY::replaceAll(cardText, "\n", "\n\t\t"), '\t');
        }
        result << "\tPersonal Deck: " << std::endl;
        for (auto const & card : deck)
        {
            std::string cardText = card->toString();
            result << "\t\t" << UTILITY::trimEnd(UTILITY::replaceAll(cardText, "\n", "\n\t\t"), '\t');
        }
        return result.str();
    }
}
