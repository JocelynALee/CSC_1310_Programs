/*************************************************************************
	Title: 	 DataClass.cpp
	Authors: Jocelyn Lee & Kylie Truong
	Date:  	 11/1/2024
	Purpose: Implements DataClass setters defined in the header
*************************************************************************/
#include "DataClass.h"

/* Constructor Implementation*/
DataClass::DataClass(const string& name, int powerLevel, const string& superpower)
    : name(name), powerLevel(powerLevel), superpower(superpower) {}

/* Setters */
void DataClass::setName(const string& n) { name = n; }
void DataClass::setPowerLevel(int p) { powerLevel = p; }
void DataClass::setSuperPower(const string& s) { superpower = s; }