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
    Player::Player(int idinput)
    : id(idinput)
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
        UTILITY::shuffle(deck.begin(), deck.end());
    }
    
    std::vector<unique_ptr<Card>> Player::loadDeck()
    {
        deck.clear();
        std::vector<unique_ptr<Card>> result;
        int deckId = rand() % 4;
        CardBuilder builder_fire;
        CardBuilder builder_ice;
        CardBuilder builder_aero;
        CardBuilder builder_earth;
        builder_fire.setTypeId(0).setName("Fire");
        builder_ice.setTypeId(0).setName("Ice");
        builder_aero.setTypeId(0).setName("Aero");
        builder_earth.setTypeId(0).setName("Earth");
        for (int i = 0; i < 20; ++i)
        {
            switch(deckId)
            {
                case 0:
                    result.push_back(builder_fire.makeCard());
                    deck.push_back(builder_fire.makeCard());
                    break;
                case 1:
                    result.push_back(builder_ice.makeCard());
                    deck.push_back(builder_ice.makeCard());
                    break;
                case 2:
                    result.push_back(builder_aero.makeCard());
                    deck.push_back(builder_aero.makeCard());
                    break;
                case 3:
                    result.push_back(builder_earth.makeCard());
                    deck.push_back(builder_earth.makeCard());
                    break;
            }
        }
        for (int i = 0; i < 5; ++i)
        {
            deck.push_back(builder_fire.makeCard());
            deck.push_back(builder_ice.makeCard());
            deck.push_back(builder_aero.makeCard());
            deck.push_back(builder_earth.makeCard());
        }
        return result;
    }
    
    std::string Player::toString()
    {
        std::ostringstream result;
        result << "Player:" << std::endl;
        result << "  Hand: " << std::endl;
        for (auto const & card : hand)
        {
            std::string cardText = card->toString();
            result << "    " << UTILITY::trimEnd(UTILITY::replaceAll(cardText, "\n", "\n    "), ' ');
        }
        result << "  Personal Deck: " << std::endl;
        for (auto const & card : deck)
        {
            std::string cardText = card->toString();
            result << "    " << UTILITY::trimEnd(UTILITY::replaceAll(cardText, "\n", "\n    "), ' ');
        }
        return result.str();
    }
}
