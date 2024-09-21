#include "MainOffice.h"
#include <iostream>
#include <algorithm>


// Static cleaner object, which will automatically delete the singleton instance at program exit


MainOffice* MainOffice::instance = NULL;
MainOffice::Cleaner MainOffice::cleaner(NULL);

// Public method to access the singleton instance
MainOffice& MainOffice::getInstance() {
    if (instance == NULL) {
        instance = new MainOffice();
        cleaner.SetMainOffice(instance);
    }
    return *instance;
}

void MainOffice::addBranch(const std::string& location, int capacity) {
    if (branches.find(location) != branches.end()) {
        throw ExistingBranchInsertError();
    }

    std::pair<std::map<std::string, Branch>::iterator, bool> result;

    result = branches.try_emplace(location, Branch(location, capacity));

    // Check if insertion was successful
    if (!result.second) {
        // If the branch already exists, throw an exception
        throw ExistingBranchInsertError();
    }
}

void MainOffice::removeBranch(const std::string& location) {
    std::map<std::string, Branch>::iterator it;
    it = branches.find(location);
    if (it == branches.end()) {
        throw NonExistingBranchRemoveError();
    }
    branches.erase(it);
}

Branch& MainOffice::getBranch(const std::string& location) {
    std::map<std::string, Branch>::iterator it;
    it = branches.find(location);
    if (it == branches.end()) {
        throw NonExistingBranchRetrieveError();
    }
    return it->second;
}

void MainOffice::printBranchesByLocation(void (*printFunc)(const Branch&))const
{
    printBranches(printFunc, false);
}

void MainOffice::printBranchesByValue(void(*printFunc)(const Branch&))const
{
    printBranches(printFunc, true);
}

bool MainOffice::compareBranchesByValue(const Branch* a, const Branch* b) {
    if (a->getTotalValue() == b->getTotalValue()) {
        return a->getLocation()< b->getLocation(); // Sort alphabetically by location if values are equal
    }
    return a->getTotalValue() < b->getTotalValue(); // Sort by total value
}

void MainOffice::printBranches(void (*printFunc)(const Branch&), bool byValue )const {
    std::cout << "There are " << branches.size() << " branches in Main Office: " << std::endl;
    if (!byValue) {
        for (std::map<std::string, Branch>::const_iterator it = branches.begin(); it != branches.end(); ++it)
            it->second.printBranch(printFunc);
    }
    else {
        std::vector<const Branch*> branchValues;
        for (std::map<std::string, Branch>::const_iterator it = branches.begin(); it != branches.end(); ++it) {
            branchValues.push_back(&(it->second)); // Store pointers
        }
        std::sort(branchValues.begin(), branchValues.end(), compareBranchesByValue);
        for (int i = 0; i < branchValues.size(); ++i) branchValues[i]->printBranch(printFunc);
    }
}
