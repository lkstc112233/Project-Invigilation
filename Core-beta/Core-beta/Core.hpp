//
//  Core.hpp
//  Core-beta
//
//  Created by Photon Cat on 2018/4/29.
//  Copyright © 2018 Must Studio. All rights reserved.
//

#ifndef Core_hpp
#define Core_hpp

#include <vector>
#include "Stringable.hpp"

namespace INVIGILATION_CORE {
    class Player;
    class Card;
    
    class Core{
    public:
        Core();
        virtual ~Core();
        void loadDeck();
    private:
        std::vector<unique_ptr<Player>> players;
        std::vector<unique_ptr<Card>> pubDeck;
    public:
        virtual std::string toString();
    };
}

#endif /* Core_hpp */
