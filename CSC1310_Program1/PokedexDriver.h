/********************************************************************************
	Title: 	    PokedexDriver.cpp
	Authors:    Anthony Filigenzi, Jocelyn Lee, Kylie Truong & Adam Yang
	Date:  	    09/11/2024
	Purpose:    Header file for PokedexDriver.cpp
*********************************************************************************/
#ifndef POKEDEXDRIVER_H
#define POKEDEXDRIVER_H

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cctype>
#include <ctime>
#include "dataClass.h"
#include "storageClass.h"
#include "otherClass.h"

using namespace std;

int numIDs = 1;

int main();
void pokedexCount();
void addToPokedex();
void displayPokedex();
void deletePokemon(int,int);

#endif
