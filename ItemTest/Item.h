#pragma once
#include "pch.h"



//Declaration for Item Class
class Item
{
public:
	Item();
	Item(	string vName, 
			float vWeight,		//How much this item weights in Kg
			float vDamage,		//Damage this item does as a % of current item health
			float vArmorValue,	//How much this item will protect as a % by reducing the damage
			float vHealth = 1.0); //Note different order, if Health is not specfied it default to 1.0 ie 100%


	~Item();

	float		GetHealth(); //Getter for Health
	float		GetHWeight(); //Getter for Weight
	float		GetDamage();	//Getter for Damage
	float		GetArmorValue();	//Getter for Armor Value
	string		GetName();	//Getter for Name

	string		ToString(); //Turn item data into a handy string

private:
	float		mHealth;	//Item health <=0 means its expired
	float		mWeight; //Item Weight in KG
	float		mDamage; //How much damage this item deals
	float		mArmorValue; //How much damage this item absorbs as %
	string		mName;		//Name of this item
};

