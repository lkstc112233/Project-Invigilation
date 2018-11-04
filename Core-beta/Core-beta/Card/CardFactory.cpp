//
//  CardFacotry.cpp
//  Core-beta
//
//  Created by Photon Cat on 2018/5/6.
//  Copyright © 2018 Must Studio. All rights reserved.
//
#include "../stdafx.h"

#include "../utility.hpp"
#include "Card.hpp"
#include "CardFactory.hpp"
using std::unique_ptr;

namespace INVIGILATION_CORE {
void CardBuilder::reId(Card& card) {
  card.m_cardId = UTILITY::IDGenerator::getId();
}

CardBuilder& CardBuilder::setType(CardData::Type type) {
  typeId = type;
  return *this;
}

unique_ptr<Card> CardBuilder::makeCard() {
  struct Shared_Card : public Card {};
  auto newCard = std::make_unique<Shared_Card>();
  newCard->data.set_type(typeId);
  newCard->data.set_name(name);
  return newCard;
}
}  // namespace INVIGILATION_CORE
