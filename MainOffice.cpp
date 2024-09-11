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

    // Explicitly define the types for the result of try_emplace
    std::pair<std::map<std::string, Branch>::iterator, bool> result;

    // Try to emplace a new branch into the map
    result = branches.try_emplace(location, Branch(location, capacity));

    // Check if insertion was successful
    if (!result.second) {
        // If the branch already exists, throw an exception
        throw ExistingBranchInsertError();
    }
}

void MainOffice::removeBranch(const std::string& location) {
    // Define the iterator type explicitly
    std::map<std::string, Branch>::iterator it;

    // Find the branch with the specified location
    it = branches.find(location);

    // Check if the branch was found
    if (it == branches.end()) {
        throw NonExistingBranchRemoveError();
    }

    // Remove the branch from the map
    branches.erase(it);
}

// Retrieve a branch by location
Branch& MainOffice::getBranch(const std::string& location) {
    auto it = branches.find(location);
    if (it == branches.end()) {
        throw NonExistingBranchRetrieveError();
    }

    return it->second;
}

// Print branches sorted by value using a custom print function
//void MainOffice::printBranchesByValue(void (*printFunc)(const Branch&)) const {
//    // Copy branches to a vector for sorting
//    std::vector<std::pair<std::string, Branch>> sortedBranches(branches.begin(), branches.end());
//
//    // Sort branches using the compareBranches function
//    std::sort(sortedBranches.begin(), sortedBranches.end(), compareBranchesByValue);
//
//    // Define the iterator
//    std::vector<std::pair<std::string, Branch>>::iterator it;
//
//    // Print sorted branches using the provided print function with iterators
//    for (it = sortedBranches.begin(); it != sortedBranches.end(); ++it) {
//        printFunc(it->second);
//    }
//}

void MainOffice::printBranchesByLocation(void (*printFunc)(const Branch&))const
{
    std::cout << "There are " << branches.size() << " branches in Main Office: " << std::endl;
    for (std::map<std::string, Branch>::const_iterator it = branches.begin(); it != branches.end(); ++it) {
        std::cout << it->second.getLocation() << " : Item count: " << it->second.getCatalog().size() << ", Total Value: " << it->second.getTotalValue() << std::endl;
        printFunc(it->second);
    }
}

void MainOffice::printBranchesByValue(void(*printFunc)(const Branch&))const
{
    // Store pointers to the branches and locations
    std::vector<std::pair<const std::string*, const Branch*>> branchValues;

    for (std::map<std::string, Branch>::const_iterator it = branches.begin(); it != branches.end(); ++it) {
        branchValues.push_back(std::make_pair(&(it->first), &(it->second))); // Store pointers
    }

    // Comparison function for sorting branches by value (ascending) and alphabetically
    struct CompareBranches {
        bool operator()(const std::pair<const std::string*, const Branch*>& a,
            const std::pair<const std::string*, const Branch*>& b) {
            int valueA = a.second->getTotalValue();
            int valueB = b.second->getTotalValue();
            if (valueA != valueB) {
                return valueA < valueB; // ascending by value
            }
            return *(a.first) < *(b.first); // alphabetically by location
        }
    };

    std::sort(branchValues.begin(), branchValues.end(), CompareBranches());

    std::cout << "There are " << branches.size() << " branches in Main Office: " << std::endl;

    // Print branches in sorted order
    /*for (std::vector<std::pair<const std::string*, const Branch*>>::iterator it = branchValues.begin();
        it != branchValues.end(); ++it) {
        std::cout << it->second.getLocation() << " : Item count: " << it->second.getCatalog().size() << ", Total Value: " << it->second.getTotalValue() << std::endl;

        printFunc(*(it->second));
    }*/
    for (std::vector<std::pair<const std::string*, const Branch*>>::iterator it = branchValues.begin();
        it != branchValues.end(); ++it) {
        std::cout << *(it->first) << " : Item count: "
            << it->second->getCatalog().size()
            << ", Total Value: "
            << it->second->getTotalValue() << std::endl;
        printFunc(*(it->second));

    }
}

bool MainOffice::compareBranchesByValue(const std::pair<std::string, Branch>& a, const std::pair<std::string, Branch>& b) {
    if (a.second.getTotalValue() == b.second.getTotalValue()) {
        return a.first < b.first; // Sort alphabetically by location if values are equal
    }
    return a.second.getTotalValue() < b.second.getTotalValue(); // Sort by total value
}

// Print branches sorted by location using a custom print function
//void MainOffice::printBranchesByLocation(void (*printFunc)(const Branch&)) const {
//
//    std::vector<std::pair<std::string, Branch>> sortedBranches(branches.begin(), branches.end());
//
//    // Sort branches alphabetically by location
//    std::sort(sortedBranches.begin(), sortedBranches.end(), compareBranchesAlphabetically);
//
//    // Define the iterator
//    std::vector<std::pair<std::string, Branch>>::iterator it;
//
//    // Print sorted branches using the provided print function with iterators
//    for (it = sortedBranches.begin(); it != sortedBranches.end(); ++it) {
//        printFunc(it->second);
//    }
//}

bool MainOffice::compareBranchesAlphabetically(const std::pair<std::string, Branch>& a, const std::pair<std::string, Branch>& b) {
    return a.first < b.first; // Compare by location (alphabetically)
}
