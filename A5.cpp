#include <iostream>
#include <algorithm>
#include "Item.h"

using namespace std;

vector<Item> permuteAll(const vector<Item>&); //function to return all permutations of items in vector
vector<Item> permuteSort(const vector<Item>&, unsigned int); //function to return all permutations of sorted items in vector
void writeToFile(const vector<Item>&); //final function to write all sorted items to file location

int main(int argc, char* argv[])
{
	//write your input/read part of the file here into itemVec


	//assuming you extract all the items to a vector called itemVec
	vector<Item> itemVec;

	//converting the array of character arrays into a vector of strings, I don't like working with char arrays
	std::vector<string> allArgs(argv, argv + argc);

	if (argc < 3 || argc > 5 || argc == 4)
	{
		cout << "Please input the correct number of arguments" << endl;
		return -1;
	}

	//write to file a permutated list
	if (argc == 3)
	{
		writeToFile(permuteAll(itemVec));
		return 0;
	}

	//assuming argc is 5
	if (allArgs[1] != "-s") //checks if option argument is really -s
	{
		cout << "Please use correct format for option: -s" << endl;
		return -1;
	}

	//declaring sorting field option integer: 0 is by id, 1 is by type, 2 is by name, 3 is by batter and 4 is by topping
	unsigned int sortInt;
	if (allArgs[2] == "id" || allArgs[2] == "Id") sortInt = 0;
	else if (allArgs[2] == "type" || allArgs[2] == "Type") sortInt = 1;
	else if (allArgs[2] == "name" || allArgs[2] == "Name") sortInt = 2;
	else if (allArgs[2] == "batter" || allArgs[2] == "Batter") sortInt = 3;
	else if (allArgs[2] == "topping" || allArgs[2] == "Topping") sortInt = 4;
	else
	{
		cout << "Incorrect sorting field: must be either id, type, name, batter or topping" << endl;
		return -1;
	}

	//write to file a sorted permutated list
	writeToFile(permuteSort(itemVec, sortInt));
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
		for (unsigned int j = 0; j < (v[i].batter).size(); j++)
		{
			//go through all toppings of each item
			for (unsigned int k = 0; k < (v[i].topping).size(); k++)
			{
				//create permutations based off of each item's batters and toppings and put them in the created vector
				Item a(v[i].id, v[i].type, v[i].name, (v[i].batter)[j], (v[i].topping)[k]);
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

bool sortBatter(Item one, Item two) {return (one.batter)[0] < (two.batter)[0];}

bool sortTopping(Item one, Item two) {return (one.topping)[0] < (two.topping)[0];}

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

void writeToFile(const vector<Item>& v)
{
	//write to destination file output
	//assume the given vector is permutated and its item are sorted and that the member vectors batter and topping
	//only have one element
	//Example: first element of vector is item1 and item1 has id = 0001, type = chocolate, name = gucci
	//and that the vector batter has only one string = vanilla_batter and that the vector topping only has
	//one string = chocolate_chips
}

