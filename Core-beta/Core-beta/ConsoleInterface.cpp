//
//  ConsoleInterface.cpp
//  Core-beta
//
//  Created by Photon Cat on 2018/5/9.
//  Copyright © 2018 Must Studio. All rights reserved.
//

#include "stdafx.h"
#include "ConsoleInterface.hpp"
#include "Action.hpp"

#include <iostream>
using std::cout;
using std::endl;

namespace INVIGILATION_CORE {
    ConsoleInterface::ConsoleInterface()
    {
        
    }
    
    ConsoleInterface::~ConsoleInterface()
    {
        
    }
    
    std::unique_ptr<Action> ConsoleInterface::action()
    {
        auto decision = std::make_unique<Action>();
        cout << "Make a decision: " << endl << "  1: Elemental Stuff" << endl << "  2: Play a card from hand" << endl << " >";
        return decision;
    }
}
