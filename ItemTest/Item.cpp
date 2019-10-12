#include "pch.h"

#include "Item.h"


//Definition for Item Class

//Constructor which takes sensible defaults
Item::Item() :mWeight(0), mArmorValue(0), mDamage(),mHealth(0), mName("NoName") //Init defaults
{
	cout << "Debug:Item " <<ToString() <<" created" << endl;
}

//Constructor which takes user supplied defaults
Item::Item(	string vName,
			float vWeight,
			float vDamage,
			float vArmorValue,
			float vHealth) : mWeight(vWeight), mArmorValue(vArmorValue), mDamage(vDamage), mHealth(vHealth), mName(vName) //Init with user defaults
{
	cout << "Debug:Item " << ToString() << " created" << endl;
}

//Destructor, just prints message
Item::~Item()
{
	cout << "Debug:Item " << ToString() << " destroyed" << endl;
}


//Health Getter
float Item::GetHealth()
{
	return mHealth;
}

//Weight Getter
float Item::GetHWeight()
{
	return mHealth;
}

//Damage Getter
float Item::GetDamage()
{
	return mDamage;
}

//Armor Getter
float Item::GetArmorValue()
{
	return mArmorValue;
}

//Name Getter
string Item::GetName()
{
	return mName;
}



string Item::ToString()
{
	stringstream tSS;
	tSS << "Name:" << mName << " Weight:" << to_string(mWeight) << " Health:" << to_string(mHealth) 
		<< " Armour:" << to_string(mArmorValue) << " in RAM @0x" << hex << this;
	return tSS.str();
}
