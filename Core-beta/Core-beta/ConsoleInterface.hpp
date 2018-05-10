//
//  ConsoleInterface.hpp
//  Core-beta
//
//  Created by Photon Cat on 2018/5/9.
//  Copyright © 2018 Must Studio. All rights reserved.
//

#ifndef ConsoleInterface_hpp
#define ConsoleInterface_hpp

#include "Controller.hpp"
#include <vector>
#include <string>

namespace INVIGILATION_CORE {
    // This is an interface for controller.
    class Action;
    class Status;
    
    class ConsoleInterface: public Controller
    {
    private:
        class MenuItemAction;
        class MenuItem
        {
        public:
            MenuItem(){}
            ~MenuItem(){}
            std::vector<std::string> selections;
            std::vector<std::unique_ptr<MenuItemAction>> returnValues;
            int interact();
            void addCancel(const std::string &hint);
            void addItem(const std::string &hint, int result);
            void addItem(const std::string &hint, std::unique_ptr<MenuItem> input);
        };
    private:
        class MenuItemAction
        {
        public:
            MenuItemAction(int result): isNumbericResult(true), numbericResult(result) {}
            MenuItemAction(std::unique_ptr<MenuItem> result): isNumbericResult(false), nonNumbericResult(std::move(result)) {}
            ~MenuItemAction(){}
            const bool isNumbericResult;
            const int numbericResult = 0;
            std::unique_ptr<MenuItem> nonNumbericResult;
            std::unique_ptr<MenuItemAction> parent;
            void setParent(std::unique_ptr<MenuItemAction> newParent) { parent = std::move(newParent); }
        };
    public:
        ConsoleInterface();
        virtual ~ConsoleInterface();
        virtual std::unique_ptr<Action> action();
        virtual void notify(const Status& status);
    private:
        std::unique_ptr<MenuItem> defaultActionSelection;
    };
}

#endif /* ConsoleInterface_hpp */
