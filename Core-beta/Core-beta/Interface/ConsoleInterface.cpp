//
//  ConsoleInterface.cpp
//  Core-beta
//
//  Created by Photon Cat on 2018/5/9.
//  Copyright © 2018 Must Studio. All rights reserved.
//

#include "../stdafx.h"
#include "ConsoleInterface.hpp"
#include "Action.pb.h"

#include <iostream>
#include <iomanip>
#include <ios>
using std::cout;
using std::endl;

namespace INVIGILATION_CORE {
    int ConsoleInterface::MenuItem::interact()
    {
        int result = -1;
        printSelections(cout);
        bool invalid = false;
        do
        {
            invalid = false;
            while (!(std::cin >> result))
            {
                cout << "Invalid input. Please try again." << endl << " >";
                std::cin.clear();
                std::cin.ignore(INT_MAX, '\n');
            }
            if (result < 1 || result > selections.size())
            {
                cout << "Invalid input. Please try again." << endl << " >";
                invalid = true;
                continue;
            }
            if (returnValues[result - 1]->isNumbericResult)
                return returnValues[result - 1]->numbericResult;
            result = returnValues[result - 1]->nonNumbericResult->interact();
            if (result == -1)
            {
                printSelections(cout);
                invalid = true;
            }
        } while (invalid);
        return result;
    }
    void ConsoleInterface::MenuItem::printSelections(std::ostream& ost) const
    {
        ost << "Please make a selection below:" << endl << std::left;
        int i = 1;
        for (const auto& t: selections)
        {
            ost << " " << std::setw(3) << i << ": " << t << endl;
            i += 1;
        }
        ost << " >" << std::right;
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
        defaultActionSelection->addCancel("Pass Turn");
    }
    
    ConsoleInterface::~ConsoleInterface()
    {
        
    }
    
    Action ConsoleInterface::action()
    {
        Action decision;
        int selection = defaultActionSelection->interact();
        switch (selection) {
            case 1:
                decision.set_type(Action::ElementalAction);
                break;
            case 2:
                decision.set_type(Action::ElementalAction);
                break;
            case -1:
            default:
                decision.set_type(Action::Nothing);
        }
        return decision;
    }
    
    void ConsoleInterface::notify(const Status& status)
    {
        
    }
}
