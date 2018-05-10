//
//  utility.hpp
//  Core-beta
//
//  Created by Photon Cat on 2018/5/6.
//  Copyright © 2018 Must Studio. All rights reserved.
//

#ifndef utility_hpp
#define utility_hpp

#include <string>
#include <atomic>
#include <random>

namespace INVIGILATION_CORE {
    namespace UTILITY{
        std::string& replaceAll(std::string &input, const std::string &pattern, const std::string &replacement);
        std::string& trimEnd(std::string &input, char toRemove);
        template<typename RandomAccessIterator>
        void shuffle(RandomAccessIterator begin, RandomAccessIterator end)
        {
            extern std::mt19937 RandomDevice19937ForShuffling;
            std::shuffle(begin, end, RandomDevice19937ForShuffling);
        }
        class IDGenerator
        {
        private:
            static std::atomic<long> idGenerator;
        public:
            static long getId();
        };
    }
}

#endif /* utility_hpp */
