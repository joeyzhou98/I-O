
#include "stdafx.h"
#include "Ingredients.h"
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

int main()
{
	const char * fname = "sample.json";
	getItems(fname);

	cin.ignore();
	return 0;
}