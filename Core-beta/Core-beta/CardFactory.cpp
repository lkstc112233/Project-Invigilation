//
//  CardFacotry.cpp
//  Core-beta
//
//  Created by Photon Cat on 2018/5/6.
//  Copyright © 2018 Must Studio. All rights reserved.
//

#include "stdafx.h"
#include "Card.hpp"
#include "CardFactory.hpp"
#include <memory>
using std::unique_ptr;

namespace INVIGILATION_CORE
{
    unique_ptr<Card> CardFactory::makeCard(int id, std::string name)
    {
        struct Shared_Card : public Card {};
        auto newCard = std::make_unique<Shared_Card>();
        newCard->m_type = ELEMENTAL;
        newCard->m_cardName = name;
        return newCard;
    }
}
