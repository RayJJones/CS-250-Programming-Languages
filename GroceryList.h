#pragma once
//Raytovian Jones CS210 Project 3

#include <map>
#include <string>
using namespace std;

class GroceryList {
public:
    GroceryList(); // Constructor to initialize GroceryList map
    void fileIn(const string& filename); // Used to load data from a file into groceryList map
    void menuOptions();          // Show all available options on menu
    void menuOption1(const string& item); // Request and item to search and display the frequency of it 
    void printMenuOption2();           // Prints the item frequency amount of each item 
    void printMenuOption3(); // Prints the item frequency amount of each item using histogram
    void fileOut(const string& filename); // output frequency of all items to a file called frequency.dat

private:
    map<string, int>groceryList; // Private member variable to store frequencies of items
};