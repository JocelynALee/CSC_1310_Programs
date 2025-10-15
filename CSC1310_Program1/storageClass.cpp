/********************************************************************************
	Title: 	  storageClass.cpp
	Authors:  Anthony Filigenzi, Jocelyn Lee, Kylie Truong & Adam Yang
	Date:  	  09/11/2024
	Purpose:  Pointer to an array of pointers to the data in the data class. 
*********************************************************************************/
#include "dataClass.h"
#include "PokedexDriver.h"
#include "storageClass.h"
#include "otherClass.h"

using namespace std;
Info pokeInfo2;
Student studInfo;

//******************************************************************
//
//                            pokeCount()
//
//   Purpose: keeps up with sudent IDs even after one is deleted
//*******************************************************************
void pokedexCount(){
    fstream pokeCount;
    pokeCount.open("pokedex.txt");
    string line;
    int lineTotal = 0;
    int lineRead = 0;
    string s;
    int studentInfo = 0;
    while(!pokeCount.eof()){
    getline(pokeCount, line);
    getline(pokeCount, studInfo.studentName[studentInfo]);
    getline(pokeCount, pokeInfo2.favPokemon[studentInfo]);
    getline(pokeCount, pokeInfo2.favStarter[studentInfo]);
    lineTotal ++;
    studentInfo ++;
    }

    numIDs = lineTotal;

    pokeCount.close();
    
};
