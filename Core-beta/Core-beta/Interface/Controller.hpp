//
//  Controller.hpp
//  Core-beta
//
//  Created by Photon Cat on 2018/5/9.
//  Copyright © 2018 Must Studio. All rights reserved.
//

#ifndef Controller_hpp
#define Controller_hpp

#include "Action.pb.h"

namespace INVIGILATION_CORE {
    // This is an interface for controller.
    // It fires Action to push forward game process.
    class Action;
    class Status;
    
    class Controller
    {
    public:
        Controller();
        virtual ~Controller();
        virtual Action action() = 0;
        virtual void notify(const Status& update) = 0;
    };
}

#endif /* Controller_hpp */
