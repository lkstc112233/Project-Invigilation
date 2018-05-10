//
//  ConsoleInterface.cpp
//  Core-beta
//
//  Created by Photon Cat on 2018/5/9.
//  Copyright © 2018 Must Studio. All rights reserved.
//

#include "stdafx.h"
#include "ConsoleInterface.hpp"
#include "Action.hpp"

#include <iostream>
#include <iomanip>
#include <ios>
using std::cout;
using std::endl;

namespace INVIGILATION_CORE {
    int ConsoleInterface::MenuItem::interact()
    {
        int result = -1;
        cout << "Please make a selection below:" << endl << std::left;
        int i = 1;
        for (const auto& t: selections)
        {
            cout << " " << std::setw(3) << i << ": " << t << endl;
            i += 1;
        }
        cout << " >" << std::right;
        while (!(std::cin >> result))
        {
            cout << "Invalid input. Please try again." << endl << " >";
            std::cin.clear();
            std::cin.ignore();
        }
        return result;
    }
    
    void ConsoleInterface::MenuItem::addCancel(const std::string &hint)
    {
        addItem(hint, -1);
    }

    void ConsoleInterface::MenuItem::addItem(const std::string &hint, int result)
    {
        selections.push_back(hint);
        returnValues.push_back(std::make_unique<MenuItemAction>(result));
    }
    
    void ConsoleInterface::MenuItem::addItem(const std::string &hint, std::unique_ptr<MenuItem> input)
    {
        selections.push_back(hint);
        returnValues.push_back(std::make_unique<MenuItemAction>(std::move(input)));
    }
    
    ConsoleInterface::ConsoleInterface()
    {
        defaultActionSelection = std::make_unique<MenuItem>();
        auto actionSubMenu = std::make_unique<MenuItem>();
        actionSubMenu->addItem("Elemental Attack", 1);
        actionSubMenu->addItem("Elemental Communicate", 2);
        actionSubMenu->addCancel("Cancel");
        defaultActionSelection->addItem("Elemental Related Action", std::move(actionSubMenu));
        actionSubMenu->addCancel("Pass Turn");
    }
    
    ConsoleInterface::~ConsoleInterface()
    {
        
    }
    
    std::unique_ptr<Action> ConsoleInterface::action()
    {
        auto decision = std::make_unique<Action>();
        int selection = defaultActionSelection->interact();
        switch (selection) {
            case 1:
                decision->setType(ElementalAction);
                break;
            case 2:
                decision->setType(ElementalAction);
                break;
            case -1:
            default:
                decision->setType(Nothing);
        }
        return decision;
    }
    
    void ConsoleInterface::notify(const Status& status)
    {
        
    }
}
