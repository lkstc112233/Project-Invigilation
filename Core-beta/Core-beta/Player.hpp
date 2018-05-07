//
//  Player.hpp
//  Core-beta
//
//  Created by Photon Cat on 2018/4/29.
//  Copyright © 2018 Must Studio. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <memory>
#include <vector>

namespace INVIGILATION_CORE {
    class Card;
    
    class Player{
    public:
        Player();
        virtual ~Player();
    protected:
        std::vector<std::unique_ptr<Card>> hand;
        std::vector<std::unique_ptr<Card>> deck;
    };
}

#endif /* Player_hpp */
