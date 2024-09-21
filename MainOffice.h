#pragma once
#include <string>
#include <map>
#include <vector>
#include "Branch.h"
#include "HWExceptions.h"

class Branch;

class MainOffice {
private:
    // Inner class responsible for destroying the singleton instance
    friend class Cleaner;
    class Cleaner {
    public:
        Cleaner(MainOffice* s = 0) { _singleton = s; }
        ~Cleaner() { delete _singleton; }
        void SetMainOffice(MainOffice* s) { _singleton = s; }

    private:
        MainOffice* _singleton;
    };

    std::map<std::string, Branch> branches;  // Map of branches with location as key
    static MainOffice* instance;
    static Cleaner cleaner;

    // Private constructor and destructor for Singleton pattern
    MainOffice() {}
    ~MainOffice() {}
    MainOffice(const MainOffice& other);
    void operator=(const MainOffice& other) {}

    static bool compareBranchesByValue(const Branch* a, const Branch* b);

    void printBranches(void (*printFunc)(const Branch&), bool byValue=false)const;
public:
    // Public method to get the singleton instance
    static MainOffice& getInstance();

    // Interface methods
    void addBranch(const std::string& location, int capacity);
    void removeBranch(const std::string& location);
    Branch& getBranch(const std::string& location);
    void printBranchesByLocation(void (*printFunc)(const Branch&)) const;
    void printBranchesByValue(void (*printFunc)(const Branch&)) const;
};
