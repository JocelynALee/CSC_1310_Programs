/********************************************************************************
	Title: 	  storageClass.h
	Authors:  Anthony Filigenzi, Jocelyn Lee, Kylie Truong & Adam Yang
	Date:  	  09/11/2024
	Purpose:  Header file for storageClass.cpp 
*********************************************************************************/
#ifdef STORAGECLASS_H
#define STORAGECLASS_H

#include "dataClass.h"
#include "PokedexDriver.h"
#include "otherClass.h"

//Maximum number of entires is just like the first gen
const int maxPokemon = 150;
Student studentPoke;
Info infoPoke;


class PokedexInfo{
	private: 
	//Maximum number of entires is just like the first gen
	const int maxPokemon = 150;
	Student studentPoke;
	Info infoPoke;
	public:
	friend void addToPokedex();
	friend void deletePokemon(int, int);
};

#endif
