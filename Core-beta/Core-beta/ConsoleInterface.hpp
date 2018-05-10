//
//  ConsoleInterface.hpp
//  Core-beta
//
//  Created by Photon Cat on 2018/5/9.
//  Copyright © 2018 Must Studio. All rights reserved.
//

#ifndef ConsoleInterface_hpp
#define ConsoleInterface_hpp

#include "Controller.hpp"

namespace INVIGILATION_CORE {
    // This is an interface for controller.
    class Action;
    class Status;
    
    class ConsoleInterface: public Controller
    {
    public:
        ConsoleInterface();
        virtual ~ConsoleInterface();
        virtual std::unique_ptr<Action> action();
        virtual void notify(const Status& status);
    };
}

#endif /* ConsoleInterface_hpp */
