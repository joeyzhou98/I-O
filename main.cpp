
#include "stdafx.h"
#include "Ingredients.h"
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

int main()
{
	const char * fname = "sample.json";
	//getItems(fname);

	//cout << getItems(fname).size();

	//cout << getItemInfo(getItems(fname)[0]);

	//for (size_t i = 0; i < getItems(fname).size(); i++)
	//{
	//	cout << getItems(fname)[i].vecBatters[0].id << endl;
	//}

	saveMenuToFolder(getItems(fname));
	cout << "If you're reading this, this was a success! :) " << endl;
	cin.ignore();
	return 0;
}