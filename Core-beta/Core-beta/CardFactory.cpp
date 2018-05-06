//
//  CardFacotry.cpp
//  Core-beta
//
//  Created by Photon Cat on 2018/5/6.
//  Copyright © 2018 Must Studio. All rights reserved.
//

#include "Card.hpp"
#include "CardFactory.hpp"
#include <memory>
using std::unique_ptr;

namespace INVIGILATION_CORE
{
    unique_ptr<Card> CardFactory::makeCard()
    {
        struct Shared_Card : public Card {};
        auto newCard = std::make_unique<Shared_Card>();
        newCard->m_type = ELEMENTAL;
        return newCard;
    }
}
