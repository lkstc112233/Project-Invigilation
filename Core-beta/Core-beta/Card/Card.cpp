//
//  Card.cpp
//  Core-beta
//
//  Created by Photon Cat on 2018/4/29.
//  Copyright © 2018 Must Studio. All rights reserved.
//
#include "../stdafx.h"

#include "Card.hpp"

#include <sstream>
#include <string>

#include "Card.pb.h"

namespace INVIGILATION_CORE {
Card::Card() : m_cardId(UTILITY::IDGenerator::getId()) {}

Card::~Card() {}

std::string getCardTypeString(CardData::Type type) {
  return CardData::Type_Name(type);
}
std::string Card::toString() {
  std::ostringstream result;
  result << "Card:" << std::endl;
  result << "  Id: " << getId() << std::endl;
  result << "  Type: " << getCardTypeString(getType()) << std::endl;
  result << "  Name: " << getCardName() << std::endl;
  return result.str();
}
}  // namespace INVIGILATION_CORE
