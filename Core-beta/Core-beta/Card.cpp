//
//  Card.cpp
//  Core-beta
//
//  Created by Photon Cat on 2018/4/29.
//  Copyright © 2018 Must Studio. All rights reserved.
//

#include <string>
#include <sstream>
#include "stdafx.h"
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
        result << "\tType: " << getCardTypeString(getType()) << std::endl;
        return result.str();
    }
}
