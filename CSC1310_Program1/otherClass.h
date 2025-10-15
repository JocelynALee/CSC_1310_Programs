/********************************************************************************
	Title: 	  otherClass.h
	Authors:  Anthony Filigenzi, Jocelyn Lee, Kylie Truong & Adam Yang
	Date:  	  09/11/2024
	Purpose:  Header file for otherClass.cpp 
*********************************************************************************/
#ifndef OTHERCLASS_H
#define OTHERCLASS_H

#include "dataClass.h"
#include "PokedexDriver.h"
#include "storageClass.h"

using namespace std;

class Info{
private:
	string favPokemon[150];
    string favStarter[150];
public:
	friend class Student;
	friend class PokedexInfo;
	void displayPokedex();
	friend void getPokemonInfo(int numGet);
	friend void recordPokeInfo();
	friend void pokedexCount();
	friend void deletePokemon(int, int);
};

#endif
