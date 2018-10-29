//
//  ConsoleInterface.hpp
//  Core-beta
//
//  Created by Photon Cat on 2018/5/9.
//  Copyright © 2018 Must Studio. All rights reserved.
//

#ifndef ConsoleInterface_hpp
#define ConsoleInterface_hpp

#include <iostream>
#include <string>
#include <vector>
#include "Action.pb.h"
#include "Controller.hpp"
#include "Status.pb.h"

namespace INVIGILATION_CORE {
// This is an interface for controller.

class ConsoleInterface : public Controller {
 private:
  class MenuItemAction;
  class MenuItem {
   public:
    MenuItem() {}
    ~MenuItem() {}
    std::vector<std::string> selections;
    std::vector<std::unique_ptr<MenuItemAction>> returnValues;
    int interact();
    void printSelections(std::ostream &ost) const;
    void addCancel(const std::string &hint);
    void addItem(const std::string &hint, int result);
    void addItem(const std::string &hint, std::unique_ptr<MenuItem> input);
  };

 private:
  class MenuItemAction {
   private:
    const bool isNumbericResult;
    const int numbericResult = 0;
    std::unique_ptr<MenuItem> nonNumbericResult;

   public:
    MenuItemAction(int result)
        : isNumbericResult(true), numbericResult(result) {}
    MenuItemAction(std::unique_ptr<MenuItem> result)
        : isNumbericResult(false), nonNumbericResult(std::move(result)) {}
    ~MenuItemAction() {}
    int interact();
  };

 public:
  ConsoleInterface();
  virtual ~ConsoleInterface();
  virtual Action action();
  virtual void notify(const Status &status);

 private:
  std::unique_ptr<MenuItem> defaultActionSelection;
};
}  // namespace INVIGILATION_CORE

#endif /* ConsoleInterface_hpp */
