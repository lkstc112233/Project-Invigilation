//
//  Controller.hpp
//  Core-beta
//
//  Created by Photon Cat on 2018/5/9.
//  Copyright © 2018 Must Studio. All rights reserved.
//

#ifndef Controller_hpp
#define Controller_hpp

namespace INVIGILATION_CORE {
    // This is an interface for controller.
    // It fires Action to push forward game process.
    class Action;
    
    class Controller
    {
    public:
        Controller();
        virtual ~Controller();
    };
}

#endif /* Controller_hpp */
