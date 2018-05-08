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

namespace INVIGILATION_CORE {
    class Player;
    class Card;
    
    class Core{
    public:
        Core();
        virtual ~Core();
    private:
        std::vector<std::unique_ptr<Player>> players;
        std::vector<std::unique_ptr<Card>> pubDeck;
    };
}

#endif /* Core_hpp */
