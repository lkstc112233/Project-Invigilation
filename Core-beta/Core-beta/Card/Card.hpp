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

namespace INVIGILATION_CORE {
enum CardType {
  ELEMENTAL,
  SORCERY,
};

class Card : Stringable {
 public:
  friend class CardBuilder;

 protected:
  Card();

 public:
  virtual ~Card();

 protected:
  long m_cardId;
  CardType m_type;
  std::string m_cardName;

 public:
  virtual std::string toString();
  long getId() { return m_cardId; }
  CardType getType() { return m_type; }
  std::string getCardName() { return m_cardName; }
};
}  // namespace INVIGILATION_CORE

#endif /* Card_hpp */
