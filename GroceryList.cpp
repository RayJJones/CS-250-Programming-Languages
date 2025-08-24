//Raytovian Jones CS210 Project 3

#include "GroceryList.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>
using namespace std;

GroceryList::GroceryList() { } //Constructor to initialize GroceryList object
map<string, int> groceryList;
//Function to open a file and read the map
void GroceryList::fileIn(const string& filename) {
    ifstream inputFile(filename); //Load data from file into groceryList
    
    string item;
    
    //Reads item data from file
    while (inputFile >> item) {
        cout << item<< endl ;
        // for loop to add to map, accumulating frequencies
        // if statement map function "count" to determine if item is already in map
        if (groceryList.count(item) > 0) {
            //if in map, add 1 to the frequency
            groceryList.at(item) += 1;
            cout << item << "  " << groceryList.at(item) << endl;
            
        }
        // else statement for adding item to map.
        else {
            groceryList.emplace(item, 1);
            cout << item << "  " << groceryList.at(item) << endl;
            
        }
    }
    inputFile.close(); //Close input file
}

//Function to display menu. Prompt uuser to select an option.
void GroceryList::menuOptions() {
    cout << "Here is you menu options in regard to Grocery List: " << endl;
    cout << "Menu option 1: Search for an item and get the frequency of item" << endl;
    cout << "Menu option 2: Print the list of items along with their frequency of item" << endl;
    cout << "Menu option 3: Print the 'histogram' list of items along with their frequency of item" << endl;
    cout << "Menu option 4: Exit the Program" << endl;
}

//Function to search for an item in the map
void GroceryList::menuOption1(const string& item) {
    cout << item << " has the frequency amount of " << groceryList.at(item) << "." << endl;
}

//Function to search and print the item frequency list
void GroceryList::printMenuOption2() {
    cout << "Here is the frequency of each item:" << endl;
    //Iterates through the map and prints frequencies
    for (const auto& pair : groceryList) {
        cout << pair.first << " " << pair.second << endl;
    }
}

//Function to output histogram of item using asterisks
void GroceryList::printMenuOption3() {
    cout << "Here is the frequency of each item using histogram:" << endl;
  //Iterates through the map and prints frequency histograms
    for (const auto& pair : groceryList) {
        cout << pair.first << " ";
        //Loop to print atericks according to item amount
        for (int i = 0; i < pair.second; i++) {
            cout << "*";
        }
        cout << endl;
    }
}

//Function to save the item frequencies to a file
void GroceryList::fileOut(const string& filename) {
    ofstream outputFile(filename); //Opens file for file writing
  
    //Iterates through the map and writes item frequencies into the output file
    for (const auto& pair : groceryList) {
        outputFile << pair.first << " " << pair.second << endl;
    }
    outputFile.close(); //Closes output file.
}
