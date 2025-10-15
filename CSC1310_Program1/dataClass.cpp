/*************************************************************************
	Title: 	 dataClass.cpp
	Authors: Anthony Filigenzi, Jocelyn Lee, Kylie Truong & Adam Yang
	Date:  	 09/11/2024
	Purpose: Stores the information of students, their favorite 
 	         Pokemon and favorite starter Pokemon.
*************************************************************************/
#include "dataClass.h"
#include "PokedexDriver.h"
#include "storageClass.h"
#include "otherClass.h"

Student studentInfo;
Info pokeInfo;

//****************************************************************************
//                                 getPokemonInfo()
//
// task:          Collects the name of the favorite Pokemon and starter.
//
//****************************************************************************

void getPokemonInfo(int numInfo){
    fstream pokeCount;
    pokeCount.open("pokedex.txt");
    getline(cin, studentInfo.studentName[numInfo]);
    cout << "Name of Favorite Pokemon: ";
    getline(cin, pokeInfo.favPokemon[numInfo]);
    cout << "Name of Favorite Starter: ";
    getline(cin, pokeInfo.favStarter[numInfo]);
    };

//*****************************************************************************
//                                 recordPokeInfo()
//
// task:          Adds info into the program
//
//*****************************************************************************
void recordPokeInfo(){
	fstream pokedexAdd;
    pokedexAdd.open("pokedex.txt", ios::app);
    pokedexAdd << "ID Number: " << numIDs << endl;
    pokedexAdd << "Student Name: " << studentInfo.studentName[numIDs] << endl;
    pokedexAdd << "Favorite Pokemon: " << pokeInfo.favPokemon[numIDs] << endl;
    pokedexAdd << "Favorite Starter: " << pokeInfo.favStarter[numIDs] << endl;
    numIDs++;
    pokedexAdd.close();
	};


//****************************************************************************
//                                 addToPokedex()
//
// task:          Adds Info on Students.
//
//****************************************************************************
void addToPokedex(){
        cout << "A Wild Tech Student Appeared!";
        cout << "\nQUICK! Add Them to Your Pokedex!" << endl;
        cout << "Name of Student: ";
        cin.ignore();
        getPokemonInfo(numIDs);
        cout << endl;

    //Record it to file
    recordPokeInfo();

};


//*****************************************************************************
//                                 deletePokemon(int, int)
//
// task:          Allows the user to delete the information of a Tech Student.
//
//*****************************************************************************
void deletePokemon(int numPokemon, int choicePokemon){
   fstream pokeDelete;
pokeDelete.open("pokedex.txt", std::ios::out);

//If it's the highest number
    if (numPokemon == choicePokemon){
        string lineRandom;
        //Loop until you find the right line
        for (int j = 0; j < (numPokemon*4)-4; j++){
            getline(pokeDelete, lineRandom);
        }
        pokeDelete << "";
        pokeDelete << "";
        pokeDelete << "";
        studentInfo.studentName[numPokemon] = "";
        pokeInfo.favPokemon[numPokemon] = "";
        pokeInfo.favStarter[numPokemon] = "";

    }
    else if (numPokemon > choicePokemon){
	    for (int i = choicePokemon; i < numPokemon; ++i){
	    studentInfo.studentName[i] = studentInfo.studentName[i + 1];
	    pokeInfo.favPokemon[i] = pokeInfo.favPokemon[i + 1];
	    pokeInfo.favStarter[i] = pokeInfo.favStarter[i + 1];
	    }
    }
    numIDs--;


    for (int q = 1; q < numPokemon - 1; q++){
    pokeDelete << "ID Number: " << q << endl;
    pokeDelete << "Student Name: " << studentInfo.studentName[q] << endl;
    pokeDelete << "Favorite Pokemon: " << pokeInfo.favPokemon[q] << endl;
    pokeDelete << "Favorite Starter: " << pokeInfo.favStarter[q] << endl;
    }
    pokeDelete.close();
    //Keep entry number from getting to zero
    if (numIDs == 0){
        numIDs++;
    }
};
