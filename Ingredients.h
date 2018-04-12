#pragma once
#include <fstream>
#include <string>
#include "json.h"
#include <typeinfo>
#include <sstream>
#include "structuresUsed.h"

using namespace std;


void const checkFileExists(const char* fileName)
{
	ifstream fileInputStreamObject;										//Creating an input filestream object
	fileInputStreamObject.open(fileName);								//Opening the file


	if (!fileInputStreamObject)											//If the file cannot be opened, then this would result in a runtimeError
		throw runtime_error("FILE NOT FOUND");


	else																//Otherwise, the file is closed and no error is raised
		fileInputStreamObject.close();
}

Json::Value const setUp(const char* fileName)
{
	checkFileExists(fileName);											//Raising exceptions when file is not found/ does not exist


	ifstream ifstrm(fileName);											//creating input filestream object
	Json::Value val;													//Creating a handler to hold the value Json file
	Json::Reader reader;												//Creating a handler to read the Jsonfile


	reader.parse(ifstrm, val);											//Transfering the contents of the file to the value handler
	return val;															//Returning the value handler
}

vector<Item> const getItems(const char* fileName)
{
	Json::Value val = setUp(fileName);									//Running the setup for the Json File handler
	vector<Item> AllItems;												//Creating an array for where all the items are stored


	for (Item var : val["items"]["item"])
		if (!isItemEmpty(var))											//If the item var is empty, then it will not be added to the list of items, then it 
			AllItems.push_back(var);


	//cout << AllItems[0].vecBatters[3].id;								//This is used to test if setting and reading everything has been succesful


	return AllItems;
}

string getItemInfo(Item itm)
{
	ostringstream os;


	os << ""	 << itm.id 
	   << "\t\t" << itm.type
	   << "\t\t" << itm.name
//	   << "\t\t" << itm.ppu
	   << "\t\t" << itm.vecBatters[0].type
	   << "\t\t" << itm.vecToppings[0].type;


	return os.str();
}

void const saveMenuToFolder(vector<Item> AllItems, ofstream& outputFileHandler)
{
	outputFileHandler << "Id\t\tType\t\tName\t\tBatter\t\tTopping" << endl << endl;
	for (Item itm : AllItems)
		outputFileHandler << getItemInfo(itm) << endl;
}

void const saveMenuToFolder(vector<Item> AllItems)
{
	for (Item itm : AllItems)
		cout << getItemInfo(itm) << endl;
}
