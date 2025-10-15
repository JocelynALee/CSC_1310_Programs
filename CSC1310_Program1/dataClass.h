/********************************************************************************
	Title: 	  dataClass.h
	Authors:  Anthony Filigenzi, Jocelyn Lee, Kylie Truong & Adam Yang
	Date:  	  09/11/2024
	Purpose:  Header file for dataClass.cpp 
*********************************************************************************/
#ifndef DATACLASS_H
#define DATACLASS_H

#include "PokedexDriver.h"
#include "storageClass.h"
#include "otherClass.h"

using namespace std;

class Student{
    Info pokeInfo;
private:
	string studentName[150];
public:
	friend class PokedexInfo;
	friend void getPokemonInfo(int numGet);
	friend void recordPokeInfo();

	friend void addToPokedex();
	friend void deletePokemon(int, int);
	friend void pokedexCount();	
};

#endif
