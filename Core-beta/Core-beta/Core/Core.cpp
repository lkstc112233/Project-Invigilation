//
//  Core.cpp
//  Core-beta
//
//  Created by Photon Cat on 2018/4/29.
//  Copyright © 2018 Must Studio. All rights reserved.
//
#include "../stdafx.h"

#include <sstream>

#include "../Card/Card.hpp"
#include "../Card/CardFactory.hpp"
#include "../utility.hpp"
#include "Core.hpp"
#include "Player.hpp"

namespace INVIGILATION_CORE {
Core::Core() {}

Core::~Core() {}

void Core::createPlayers(int count) {
  // remove any existing player, and any existing deck.
  players.clear();
  pubDeck.clear();
  for (int i = 0; i < count; ++i) {
    auto player = std::make_unique<Player>(UTILITY::IDGenerator::getId());
    auto deck = player->loadDeck();
    for (auto& pnt : deck) pubDeck.push_back(std::move(pnt));
    player->shuffleDeck();
    players.push_back(std::move(player));
  }
  UTILITY::shuffle(pubDeck.begin(), pubDeck.end());
}

std::string Core::toString() {
  std::ostringstream result;
  result << "Core:" << std::endl;
  result << "  Players: " << std::endl;
  for (auto const& player : players) {
    std::string cardText = player->toString();
    result << "    "
           << UTILITY::trimEnd(UTILITY::replaceAll(cardText, "\n", "\n    "),
                               ' ');
  }
  result << "  Public Deck: " << std::endl;
  for (auto const& card : pubDeck) {
    std::string cardText = card->toString();
    result << "    "
           << UTILITY::trimEnd(UTILITY::replaceAll(cardText, "\n", "\n    "),
                               ' ');
  }
  return result.str();
}
}  // namespace INVIGILATION_CORE
