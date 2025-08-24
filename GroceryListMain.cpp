//Raytovian Jones CS210 Project 3

#include <iostream>
#include "GroceryList.h"
using namespace std;

int main() {
    GroceryList cornerGrocer; //Creates an instance of GroceryList class
    cornerGrocer.fileIn("CS210_Project_Three_Input_File.txt"); //Load data from input file

    int option; //Used to store user input
  
    //Program loops until user enter "4"
    while (option != 4){
        //Displays menu, prompts user to input an option, then stores input
        cornerGrocer.menuOptions();
        cout << "Enter an option: ";
        cin >> option;

        //Handles what to do based on what option user choose
        switch (option) {
            //If user chose 1, search for item in the file
            case 1: {
                string groceryItem; 
                cout << "Enter the item name: ";
                cin >> groceryItem;
                cornerGrocer.menuOption1(groceryItem);
                break;
            }
            //If user chose 2, print frequency list
            case 2: {
                cornerGrocer.printMenuOption2();
                break;
            }
            //If user chose 3, print frequency histogram
            case 3: {
                cornerGrocer.printMenuOption3();
                break;
            }
            //If user chose 4, end the program
            case 4:
                cout << "Program finished" << endl;
                break; //Ends the program
            //If user enters an number not from 1 - 4, display error message
            default:
                cout << "The choice you made was not valid , Please choose another valid choice between 1 and 4" << endl;
        }
    } 

    //Save item frequencies into an output file
    cornerGrocer.fileOut("frequency.dat");

    return 0;
}