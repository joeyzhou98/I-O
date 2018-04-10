
#include "stdafx.h"
#include "Ingredients.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
	const char * fname = "sample.json";
	vector<Items> AllItems= getItems(fname); //Getting all the items from the Json file
	cout << "ID: " << AllItems[0].id << endl;
	cout << "If no errors raised, it works!";
	cin.ignore();
	return 0;
}
