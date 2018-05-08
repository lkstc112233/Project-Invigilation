//
//  utility.cpp
//  Core-beta
//
//  Created by Photon Cat on 2018/5/6.
//  Copyright © 2018 Must Studio. All rights reserved.
//

#include "stdafx.h"
#include "utility.hpp"


namespace INVIGILATION_CORE {
    namespace UTILITY{
        /**
         * Replaces all occurrence of pattern in input with replacement.
         */
        std::string& replaceAll(std::string &input, const std::string &pattern, const std::string &replacement)
        {
            if (pattern.size() == 0)
                return input;
            auto pos = input.find(pattern);
            while (pos != std::string::npos)
            {
                input.replace(pos, pattern.size(), replacement);
                pos += replacement.size();
                pos = input.find(pattern, pos);
            }
            return input;
        }
        
        std::string& trimEnd(std::string &input, char c)
        {
            input.erase(input.find_last_not_of(c) + 1);
            return input;
        }
    }
}
