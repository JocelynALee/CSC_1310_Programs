/********************************************************************************
	Title: 	  otherClass.cpp
	Authors:  Anthony Filigenzi, Jocelyn Lee, Kylie Truong & Adam Yang
	Date:  	  09/11/2024
	Purpose:  Median for PokedexDriver.cpp and storage 
*********************************************************************************/
#include "dataClass.h"
#include "PokedexDriver.h"
#include "storageClass.h"
#include "otherClass.h"
#include <filesystem>
using namespace std;

//****************************************************************************
//                                 displayPokedex()
//
// task:          Shows User the pokemon from file
//
//****************************************************************************
void displayPokedex(){
fstream pokeDisplay;
pokeDisplay.open("pokedex.txt");
int length;

 if (filesystem::file_size("pokedex.txt") == 0){
	cout << "NO ENTRIES FOUND" << endl;
 	cout << endl;
        pokeDisplay.close();
}
    else {
        cout << endl;
        cout << pokeDisplay.rdbuf();
        cout << endl;
    }
};
