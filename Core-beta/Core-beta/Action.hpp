//
//  Action.hpp
//  Core-beta
//
//  Created by Photon Cat on 2018/5/9.
//  Copyright © 2018 Must Studio. All rights reserved.
//

#ifndef Action_hpp
#define Action_hpp

namespace INVIGILATION_CORE {
    // This is an interface for controller.
    // It fires Action to push forward game process.
    class Action
    {
    public:
        Action();
        virtual ~Action();
    };
}

#endif /* Action_hpp */
