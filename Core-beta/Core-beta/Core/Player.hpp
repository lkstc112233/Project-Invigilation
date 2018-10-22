//
//  Player.hpp
//  Core-beta
//
//  Created by Photon Cat on 2018/4/29.
//  Copyright © 2018 Must Studio. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <vector>
#include <string>
#include "../Stringable.hpp"

namespace INVIGILATION_CORE {
    class Card;
    
    class Player : public Stringable {
    public:
        Player(int id);
        virtual ~Player();
    protected:
        long id;
        int life;
        int initialLife;
        std::vector<std::unique_ptr<Card>> hand;
        std::vector<std::unique_ptr<Card>> deck;
    public:
        std::vector<std::unique_ptr<Card>> loadDeck();
        void shuffleDeck();
        void takeCardIntoHand(std::unique_ptr<Card> card);
        long getId() { return id; }
        int getLife() { return life; }
        virtual std::string toString();
    };
}

#endif /* Player_hpp */
