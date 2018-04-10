#pragma once
#include <fstream>
#include "json.h"
#include <typeinfo>
#include "structuresUsed.h"

using namespace std;


void const checkFileExists(const char* fileName)
{
	ifstream fileInputStreamObject;
	fileInputStreamObject.open(fileName);


	if (!fileInputStreamObject)
		throw runtime_error("FILE NOT FOUND");


	else
		fileInputStreamObject.close();
}


vector<Item> const getItems(const char* fileName)
{
	checkFileExists(fileName);											//Raising exceptions when file is not found
	
	vector<Item> Items;
	ifstream cakeItems(fileName);
	Json::Reader reader;
	Json::Value val;
	reader.parse(cakeItems, val);
	vector<Item> AllItems;

	for (auto var : val["items"]["item"])
		AllItems.push_back(var);

	cout << AllItems[0].vecBatters[3].id;

	return AllItems;
}