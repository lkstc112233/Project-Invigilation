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
#include "Stringable.hpp"

namespace INVIGILATION_CORE {
    enum CardType
    {
        ELEMENTAL,
        SORCERY,
    };
    
    class CardFactory;
    
    class Card : Stringable
    {
    public:
        friend CardFactory;
    protected:
        Card();
    public:
        virtual ~Card();
        virtual std::string toString();
    };
}

#endif /* Card_hpp */
