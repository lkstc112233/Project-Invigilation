//
//  CardFacotry.hpp
//  Core-beta
//
//  Created by Photon Cat on 2018/5/6.
//  Copyright © 2018 Must Studio. All rights reserved.
//

#ifndef CardFacotry_hpp
#define CardFacotry_hpp

#include <string>

namespace INVIGILATION_CORE
{
    class Card;
    /**
     * Friend of Card.
     * Generates Card.
     */
    class CardFactory
    {
    public:
        static std::unique_ptr<Card> makeCard(int typeID = 0, std::string name = "Blank");
    };
    
    enum CardType;
    
    /**
     * Friend of Card.
     * Generates Card.
     */
    class CardBuilder
    {
    private:
        CardType typeId;
        std::string name;
    public:
        CardBuilder& setTypeId(int id);
        CardBuilder& setName(std::string name) {this->name = name; return *this;}
        std::unique_ptr<Card> makeCard();
    };
}

#endif /* CardFacotry_hpp */
