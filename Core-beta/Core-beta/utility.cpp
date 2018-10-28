//
//  utility.cpp
//  Core-beta
//
//  Created by Photon Cat on 2018/5/6.
//  Copyright © 2018 Must Studio. All rights reserved.
//

#include "utility.hpp"
#include <atomic>
#include "stdafx.h"

namespace INVIGILATION_CORE {
namespace UTILITY {
std::random_device RandomDeviceForShuffling;
std::mt19937 RandomDevice19937ForShuffling(RandomDeviceForShuffling());

/**
 * Replaces all occurrence of pattern in input with replacement.
 */
std::string &replaceAll(std::string &input, const std::string &pattern,
                        const std::string &replacement) {
  if (pattern.size() == 0) return input;
  auto pos = input.find(pattern);
  while (pos != std::string::npos) {
    input.replace(pos, pattern.size(), replacement);
    pos += replacement.size();
    pos = input.find(pattern, pos);
  }
  return input;
}

std::string &trimEnd(std::string &input, char c) {
  input.erase(input.find_last_not_of(c) + 1);
  return input;
}

std::atomic<long> IDGenerator::idGenerator;
long IDGenerator::getId() {
  return idGenerator.fetch_add(1, std::memory_order_relaxed);
}
}  // namespace UTILITY
}  // namespace INVIGILATION_CORE
