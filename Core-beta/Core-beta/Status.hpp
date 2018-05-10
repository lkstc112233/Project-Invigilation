//
//  Status.hpp
//  Core-beta
//
//  Created by Photon Cat on 2018/5/10.
//  Copyright © 2018 Must Studio. All rights reserved.
//

#ifndef Status_hpp
#define Status_hpp

#include <vector>

namespace INVIGILATION_CORE {
    // Used for action.
    enum StatusType
    {
        ElementalAction,
        DamageReduction,
        PlayCard,
    };
    
    // This is an interface for controller.
    // It fires Action to push forward game process.
    class Status
    {
    public:
        Status();
        virtual ~Status();
    private:
        StatusType m_type;
    public:
        StatusType getType() { return m_type; }
        StatusType setType(StatusType type) { auto temp = m_type; m_type = type; return temp; }
        std::vector<int> info;
    };
}

#endif /* Status_hpp */
