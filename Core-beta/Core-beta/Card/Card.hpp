//
//  Card.hpp
//  Core-beta
//
//  Created by Photon Cat on 2018/4/29.
//  Copyright © 2018 Must Studio. All rights reserved.
//

#ifndef Card_hpp
#define Card_hpp

#include <string>
#include "../Stringable.hpp"

#include "Card.pb.h"

namespace INVIGILATION_CORE {
class Card : Stringable {
 public:
  friend class CardBuilder;

 private:
  Card();

 public:
  Card(CardData data);
  virtual ~Card();

 private:
  long m_cardId;
  CardData data;

 public:
  virtual std::string toString();
  long getId() { return m_cardId; }
  CardData::Type getType() { return data.type(); }
  std::string getCardName() { return data.name(); }
};
}  // namespace INVIGILATION_CORE

#endif /* Card_hpp */
