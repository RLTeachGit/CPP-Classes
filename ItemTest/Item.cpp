#include "pch.h"

#include "Item.h"

using namespace std;

Item::Item() :mWeight(0), mArmorValue(0), mDamage(),mHealth(0), mName("NoName") //Init defaults
{
	cout << "Debug:Item " <<ToString() <<" created" << endl;
}

Item::Item(	string vName,
			float vWeight,
			float vDamage,
			float vArmorValue,
			float vHealth) : mWeight(vWeight), mArmorValue(vArmorValue), mDamage(vDamage), mHealth(vHealth), mName(vName) //Init with user defaults
{
	cout << "Debug:Item " << ToString() << " created" << endl;
}


Item::~Item()
{
	cout << "Debug:Item " << ToString() << " destroyed" << endl;
}

float Item::GetHealth()
{
	return mHealth;
}

float Item::GetHWeight()
{
	return mHealth;
}

float Item::GetDamage()
{
	return mDamage;
}

float Item::GetArmorValue()
{
	return mArmorValue;
}

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
