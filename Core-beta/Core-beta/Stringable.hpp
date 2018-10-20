//
//  Stringable.hpp
//  Core-beta
//
//  Created by Photon Cat on 2018/5/6.
//  Copyright © 2018 Must Studio. All rights reserved.
//

#ifndef Stringable_h
#define Stringable_h

#include <string>

namespace INVIGILATION_CORE
{
    /**
     * This is an interface indicating that the class can be represented into a string.
     * The converted string is human-readable, so it can be used to make automated tests.
     * upon converted the string is stored in a std::string structure.
     */
    class Stringable
    {
    public:
        virtual std::string toString() = 0;
    };
}

#endif /* Stringable_h */
