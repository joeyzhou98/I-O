#include <iostream>
#include <algorithm>
#include "Ingredients.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

vector<Item> permuteAll(const vector<Item>&); //function to return all permutations of items in vector
vector<Item> permuteSort(const vector<Item>&, unsigned int); //function to return all permutations of sorted items in vector

int main(int argc, char* argv[])
{
	cout << "Running" << endl;

	cout << "Arguments:" << endl;
	for (int i = 0; i<argc; i++ )
		cout << argv[i] << endl;

	if (argc < 3 || argc > 5 || argc == 4)
	{
		cout << "Please input the correct number of arguments" << endl;
		return -1;
	}

	//write to file a permutated list
	if (argc == 3)
	{
		vector<Item> itemVec = getItems(argv[1]);
		ofstream out;
		out.open(argv[2]);
		saveMenuToFolder(permuteAll(itemVec), out);
		out.close();
		cout << "Done" << endl;

		return 0;
	}

	//assuming argc is 5
	string s = "-s";
	if (argv[1] != s) //checks if option argument is really -s
	{
		cout << argv[1];
		cout << "Please use correct format for option: -s" << endl;
		return -1;
	}

	vector<Item> itemVec = getItems(argv[3]);

	//declaring sorting field option integer: 0 is by id, 1 is by type, 2 is by name, 3 is by batter and 4 is by topping
	unsigned int sortInt;
	string p = argv[2];
	string i = "id";
	string t = "type";
	string n = "name";
	string b = "batter";
	string to = "topping";

	if (p == i) sortInt = 0;
	else if (p == t) sortInt = 1;
	else if (p == n) sortInt = 2;
	else if (p == b) sortInt = 3;
	else if (p == to) sortInt = 4;
	else
	{
		cout << "Incorrect sorting field: must be either id, type, name, batter or topping" << endl;
		return -1;
	}

	//write to file a sorted permutated list
	ofstream out;
	out.open(argv[4]);
	saveMenuToFolder(permuteSort(itemVec, sortInt), out);
	out.close();
	cout << "Done" << endl;

	return 0;
}

vector<Item> permuteAll(const vector<Item> &v)
{
	//declare another vector
	vector<Item> permutatedList;

	//go through all items
	for (unsigned int i = 0; i < v.size(); i++)
	{
		//go through all batters of each item
		for (unsigned int j = 0; j < (v[i].vecBatters).size(); j++)
		{
			//go through all toppings of each item
			for (unsigned int k = 0; k < (v[i].vecToppings).size(); k++)
			{
				//create permutations based off of each item's batters and toppings and put them in the created vector
				Item a(v[i].id, v[i].type, v[i].name, (v[i].vecBatters)[j], (v[i].vecToppings)[k]);
				permutatedList.push_back(a);
			}
		}
	}
	//return that permutated list
	return permutatedList;
}

bool sortId(Item one, Item two) {return one.id < two.id;}

bool sortType(Item one, Item two) {return one.type < two.type;}

bool sortName(Item one, Item two) {return one.name < two.name;}

bool sortBatter(Item one, Item two) {return (one.vecBatters)[0].type < (two.vecBatters)[0].type;}

bool sortTopping(Item one, Item two) {return (one.vecToppings)[0].type < (two.vecToppings)[0].type;}

vector<Item> permuteSort(const vector<Item> &v, unsigned int s)
{
	//declare a permutated vector
	vector<Item> permutatedSortedList = permuteAll(v);

	if (s == 0) {sort(permutatedSortedList.begin(), permutatedSortedList.end(), sortId);}

	else if (s == 1) {sort(permutatedSortedList.begin(), permutatedSortedList.end(), sortType);}

	else if (s == 2) {sort(permutatedSortedList.begin(), permutatedSortedList.end(), sortName);}

	else if (s == 3) {sort(permutatedSortedList.begin(), permutatedSortedList.end(), sortBatter);}

	else if (s == 4) {sort(permutatedSortedList.begin(), permutatedSortedList.end(), sortTopping);}

	return permutatedSortedList;
}


