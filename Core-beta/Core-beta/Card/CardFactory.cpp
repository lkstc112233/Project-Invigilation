//
//  CardFacotry.cpp
//  Core-beta
//
//  Created by Photon Cat on 2018/5/6.
//  Copyright © 2018 Must Studio. All rights reserved.
//

#include "CardFactory.hpp"
#include "../stdafx.h"
#include "../utility.hpp"
#include "Card.hpp"
using std::unique_ptr;

namespace INVIGILATION_CORE {
void CardBuilder::reId(Card& card) {
  card.m_cardId = UTILITY::IDGenerator::getId();
}

CardBuilder& CardBuilder::setTypeId(int id) {
  switch (id) {
    case 0:
    default:
      typeId = ELEMENTAL;
      break;
  }
  return *this;
}

unique_ptr<Card> CardBuilder::makeCard() {
  struct Shared_Card : public Card {};
  auto newCard = std::make_unique<Shared_Card>();
  newCard->m_cardId = UTILITY::IDGenerator::getId();
  newCard->m_type = typeId;
  newCard->m_cardName = name;
  return newCard;
}
}  // namespace INVIGILATION_CORE
