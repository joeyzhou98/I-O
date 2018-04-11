#pragma once
#include <string>
#include <vector>
#include "json.h"

struct Batters
{
	Batters(Json::Value val)
	{
		id = val["id"].asString();
		type = val["type"].asString();
	}


	std::string id;
	std::string type;
};



struct Toppings
{
	Toppings(Json::Value val)
	{
		id = val["id"].asString();
		type = val["type"].asString();
	}


	std::string id;
	std::string type;
};



struct Item
{
	Item(Json::Value val)																		//Constructor From a Json Value
	{
		id   = val["id"].asString();
		type = val["type"].asString();
		name = val["name"].asString();
		ppu  = val["ppu"].asDouble();


		for (auto var : val["batters"]["batter"])
			vecBatters.push_back(Batters(var));


		for (auto var : val["topping"])
			vecToppings.push_back(Toppings(var));
	}


	std::string id;
	std::string type;
	std::string name;
	double ppu;


	std::vector<Batters> vecBatters;
	std::vector<Toppings> vecToppings;
};

bool isItemEmpty(Item itm)
{
	return itm.id == "" && itm.name == "" && itm.type == "" && itm.ppu == NULL;
}