//
//  CardFacotry.hpp
//  Core-beta
//
//  Created by Photon Cat on 2018/5/6.
//  Copyright © 2018 Must Studio. All rights reserved.
//

#ifndef CardBuilder_hpp
#define CardBuilder_hpp

#include <string>

namespace INVIGILATION_CORE
{
    class Card;
    enum CardType;
    
    /**
     * Friend of Card.
     * Generates Card.
     */
    class CardBuilder
    {
    public:
        // Change a card's id to a new one.
        // Use this to make a card a new one.
        static void reId(Card &card);
    private:
        CardType typeId = ELEMENTAL;
        std::string name = "Void";
    public:
        CardBuilder& setTypeId(int id);
        CardBuilder& setName(std::string name) {this->name = name; return *this;}
        std::unique_ptr<Card> makeCard();
    };
}

#endif /* CardBuilder_hpp */
