//
//  Card.cpp
//  Core-beta
//
//  Created by Photon Cat on 2018/4/29.
//  Copyright © 2018 Must Studio. All rights reserved.
//

#include "stdafx.h"
#include <string>
#include <sstream>
#include "Card.hpp"

namespace INVIGILATION_CORE {
    Card::Card()
    {
        
    }
    
    Card::~Card()
    {
        
    }
    
    std::string getCardTypeString(CardType type)
    {
        switch (type) {
            case ELEMENTAL:
                return "Elemental";
            default:
                return "Other";
        }
    }
    std::string Card::toString()
    {
        std::ostringstream result;
        result << "Card:" << std::endl;
        result << "  Id: " << getId() << std::endl;
        result << "  Type: " << getCardTypeString(getType()) << std::endl;
        result << "  Name: " << getCardName() << std::endl;
        return result.str();
    }
}
