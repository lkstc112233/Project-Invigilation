//
//  Action.hpp
//  Core-beta
//
//  Created by Photon Cat on 2018/5/9.
//  Copyright © 2018 Must Studio. All rights reserved.
//

#ifndef Action_hpp
#define Action_hpp

#include <vector>

namespace INVIGILATION_CORE {
    // Used for action.
    enum ActionType
    {
        Nothing,
        ElementalAction,
        DamageReduction,
        PlayCard,
    };

    // This is an interface for controller.
    // It fires Action to push forward game process.
    class Action
    {
    public:
        Action();
        virtual ~Action();
    private:
        ActionType m_type;
    public:
        ActionType getType() { return m_type; }
        ActionType setType(ActionType type) { auto temp = m_type; m_type = type; return temp; }
        std::vector<int> info;
    };
}

#endif /* Action_hpp */
