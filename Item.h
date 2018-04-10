#ifndef I_O_ITEM_H_
#define I_O_ITEM_H_

#include <string>
#include <vector>

using namespace std;

struct Item{

	Item(int i, string typ, string n, string b, string top): id(i), type(typ), name(n)
	{
		batter.push_back(b);
		topping.push_back(top);
	}

	int id;
	string type;
	string name;
	vector<string> batter;
	vector<string> topping;
};



#endif /* I_O_ITEM_H_ */
