/********************************************************************************
	Title: 	    Driver.cpp
	Authors:    Jocelyn Lee & Kylie Truong
	Date:  	    11/1/2024
	Purpose:    Contains full program flow, all classes used, all 
                    functions can be tested, takes user input & ends naturally
*********************************************************************************/
#include "LinkedListDriver.h"
#include "DataClass.h"
#include "SmartPointer.h"
#include <fstream> 
#include <iostream>
#include <sstream>

using namespace std;

/*Driver function Prototypes*/
void superPrint();
void menuDisplay();
void saveToFile(const SuperList<DataClass>& heroList, const string& heroFile);
void loadFile(SuperList<DataClass>& heroList, const string& heroFile);

//******************************************************************
//                          main() Function
//******************************************************************
int main()
{
	/*Creates SuperList*/
	SuperList<DataClass> heroList;

    /*Opens File*/
    const string heroFile = "superheroes.txt";
    loadFile(heroList, heroFile);

    /*Variables*/
    int choice;
    string name;
    int powerLevel;
    string superpower;
	bool run = true;

    /*Main Menu*/
    superPrint();
    cout << "\n***Welcome to Superhero Super Sort!***";
    cout << "\nSee who's the best of the best or even who's the worst!" << endl;

    /*Display Menu*/
    do
    {
        menuDisplay();
        cin >> choice;

        /*Input Validation*/
        while(choice < 1 || choice > 7)
        {
            cout << "Invalid User Input. Please try again: ";
            cin >> choice;
        }
        cin.ignore();

        switch(choice)
        {
            /*User Adds SuperHeroes until they choose to exit*/
            case 1:
                name = "";
                while(name != "exit")
                {
                    cout << "\nInput 'exit' to no longer add Superheroes.";
                    cout << "\nEnter Superhero Name: ";
                    getline(cin, name);
                    if(name == "exit")
                    {
                        break;
                    }
                    cout << "Enter Power Level: ";
                        cin >> powerLevel;
				    while(powerLevel < 0)
                    {
                        cout << "\nPower Level is Invalid. Try again: ";
                            cin >> powerLevel;
                    }
                    cin.ignore();

                    cout << "Enter Superpower: ";
                    getline(cin, superpower);
                    heroList.appendSuperHero(DataClass(name, powerLevel, superpower));
                    cout << "\nSuperhero added successfully!\n";
                }
                break;

            /*User Removes SuperHero*/
            case 2:
				cout << "\nEnter the name of the superhero to remove: ";
					getline(cin, name);
				if (heroList.removeHero(DataClass(name, 0, "")))
				{
					cout << "\nSuperhero removed successfully!\n";
				}
					else 
					{
						cout << "\nSuperhero not found!\n";
					}
				break;

            /*Prints heroes from best to worst*/
            case 3:
                heroList.mergeSort();
                cout << "\nHeroes from Best to Worst:\n";
                heroList.printHeroesTop();
                break;

            /*Prints heroes from worst to best*/
            case 4:
                heroList.mergeSort();
                cout << "\nHeroes from Worst to Best:\n";
                heroList.printHeroesBottom();
                break;
            
            /*Prints heroes by index*/
            case 5:
                cout << "\nHeroes by Index:\n";
                heroList.printHeroesByIndex(); 
                break;

            /*Selects Hero from Index*/
            case 6:
                int index;
                cout << "\nEnter the index of the superhero to retrieve: ";
                cin >> index;

                if (index < 0 || index >= heroList.getSize()) 
                {
                    cout << "Invalid index. Please enter a valid index between 0 and " << heroList.getSize() - 1 << ".\n";
                }
                else 
                {
                    DataClass hero("", 0, "");
                    if (heroList.getAtHero(index, hero)) 
                    {
                        cout << "Hero at index " << index << ": " << hero << endl;
                    } 
                    else 
                    {
                        cout << "\nNo hero found at that index.\n";
                    }
                }
                break;
            
            /*Exits Program and saves to file*/
            case 7:
                saveToFile(heroList, heroFile);
                cout << "Exiting the program. Up-Up-And-Away!\n";
                run = false;
                break;
        }
    }while(run!=false);
    return 0;
}

//******************************************************************
//                       superPrint() Function
//******************************************************************
void superPrint()
{
    cout << "\t ######  ##     ## ########  ######## ######## " << endl;
    cout << "\t##    ## ##     ## ##     ## ##       ##     ##" << endl;
    cout << "\t##       ##     ## ##     ## ##       ##     ##" << endl;
    cout << "\t ######  ##     ## ########  ######   ######## " << endl;
    cout << "\t      ## ##     ## ##        ##       ##   ##  " << endl;
    cout << "\t##    ## ##     ## ##        ##       ##    ## " << endl;
    cout << "\t ######   #######  ##        ######## ##     ##" << endl;
    cout << "\t ######   #######  ########  ######## ####     " << endl;
    cout << "\t##    ## ##     ## ##     ##    ##    ####     " << endl;   
    cout << "\t##       ##     ## ##     ##    ##    ####     " << endl;
    cout << "\t ######  ##     ## ########     ##     ##      " << endl;
    cout << "\t      ## ##     ## ##   ##      ##             " << endl;
    cout << "\t##    ## ##     ## ##    ##     ##    ####     " << endl;   
    cout << "\t ######   #######  ##     ##    ##    ####     "  <<endl;     
}

//******************************************************************
//                         menuDisplay()
//******************************************************************
void menuDisplay()
{
    cout << "\n! Superhero List Manager !\n";
    cout << "\t1. Add a Superhero\n";
    cout << "\t2. Remove a Superhero\n";
    cout << "\t3. View Heroes (Best to Worst)\n";
    cout << "\t4. View Heroes (Worst to Best)\n";
    cout << "\t5. Print Heroes by Index\n";
    cout << "\t6. Get Hero at Index\n";
    cout << "\t7. Save and Exit\n";
    cout << "Choose an option: ";
}

//******************************************************************
//                      saveToFile() Function
//******************************************************************
void saveToFile(const SuperList<DataClass>& heroList, const string& heroFile) 
{
    ofstream outFile(heroFile);
    if (!outFile) 
	{
        cout << "Error opening file for saving!\n";
        return;
    }
    outFile << "Name,PowerLevel,Superpower\n";
    for (int i = 0; i < heroList.getSize(); ++i) {
        DataClass hero("", 0, "");
        heroList.getAtHero(i, hero);
        outFile << hero.getName() << "," << hero.getPowerLevel() << "," << hero.getSuperPower() << "\n";
    }
    outFile.close();
    cout << "Data saved successfully to " << heroFile << "!\n";
}

//******************************************************************
//                      loadFile() Function
//******************************************************************
void loadFile(SuperList<DataClass>& heroList, const string& heroFile) {
    ifstream inFile(heroFile);
    if (!inFile) {
        cout << "No existing data file found. Starting with an empty list.\n";
        return;
    }

    string line;
    // Skip header line
    getline(inFile, line);

    while (getline(inFile, line)) 
    {
        stringstream ss(line);
        string name, superpower;
        int powerLevel;

        getline(ss, name, ',');
        ss >> powerLevel;
        ss.ignore(1); 
        getline(ss, superpower);

        heroList.appendSuperHero(DataClass(name, powerLevel, superpower));
    }

    inFile.close();
    cout << "Data loaded successfully from " << heroFile << "!\n";
}