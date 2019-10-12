#include "pch.h" //Include standard C++ includes & set namespace



#include "Item.h" //This will allow us to use item
#include "ContainerTest.h"

void	TestMap() {
	map<string, int> tNumbers = {    {"richard",5000}
									,{"fred",500} 
									,{"fred",6500}
									,{"Abby",9500}
									,{"Samantha",7550}
									,{"Gail",7590}
									,{"Sue",4400}
									,{"Dave",6700}
									,{"Tammie",17500}
									,{"John",227500}
	};
	for (auto tI = tNumbers.begin(); tI != tNumbers.end(); ++tI) {
		cout << "Key:" << tI->first << " Value:" << tI->second << " @0x" << hex << &(*tI) << endl;
	}
}



void	TestList() {
	list<int> tNumbers = { 5,4,99,7,4,11,45,33,17,0 }; //Make a  list of 10 integers & initalise
	for (auto tI = tNumbers.begin(); tI != tNumbers.end(); ++tI) {
		cout << *tI << " @0x" << hex << &(*tI) << endl;
	}
}


void	TestVector() {

	vector<int> tNumbers = { 5,4,99,7,4,11,45,33,17,0 }; //Make a a vector of 10 integers & initalise

	for (vector<int>::iterator tI = tNumbers.begin(); tI != tNumbers.end(); ++tI) {
		cout << *tI << " @0x" << hex << &(*tI) << endl;
	}

	for (auto tI = tNumbers.begin(); tI != tNumbers.end(); ++tI) {
		cout << *tI << " @0x" <<hex << &(*tI) << endl;
	}
}

void RandomAccess() {
	vector<int> tVectorNumbers = { 5,4,99,7,4,11,45,33,17,0 }; //Make a a vector of 10 integers & initalise
	cout << tVectorNumbers[5] << " @0x" << hex << &tVectorNumbers[5] << endl;

	list<int> tListNumbers = { 5,4,99,7,4,11,45,33,17,0 }; //Make a  list of 10 integers & initalise
	int tIndex = 0;
	for (auto tI = tListNumbers.begin(); tI != tListNumbers.end(); ++tI) {
		if (tIndex == 5) { //Are we at 5th index
			cout << (dec) << *tI << " @0x" << hex << &(*tI) << endl;
			break;
		}
		tIndex++;
	}

}

void PrintItems(vector<int> vData) //Print the items
{
	for (size_t tI = 0; tI < vData.size(); tI++)
	{
		cout << vData[tI] << endl; //Uses [] index operator to get access to item at a specific index
	}
}


vector<int> BubbleSort(vector<int> vData) //Template, some code missing
{
	bool tSwap;
	do
	{
		tSwap = false;
		for (size_t tI = 0; tI < vData.size() - 1; tI++) //Same as above
		{
			if (vData[tI] > vData[tI + 1])
			{
				int tTempData = vData[tI + 1]; //We swap by using a tamp variable
				vData[tI + 1] = vData[tI];	//As here we are overwriting it
				vData[tI] = tTempData;
				tSwap = true;	//We have swpped so not yet done
			}
		}
	} while (tSwap);	//If we have not made any swaps then we are done
	return	vData;	//Return sorted items
}

void TestBubble() {
	vector<int> tVectorNumbers = { 5,4,99,7,4,11,45,33,17,0 }; //Make a a vector of 10 integers & initalise
	cout << "Before" << endl;
	PrintItems(tVectorNumbers);
	cout << "Sorted" << endl;
	tVectorNumbers = BubbleSort(tVectorNumbers);
	PrintItems(tVectorNumbers);
}




void PrintItems(std::list<std::shared_ptr<Item>> &tItems)
{
	for (auto tI = tItems.begin(); tI != tItems.end(); ++tI) {
		cout << (*tI)->ToString() << endl;
	}
}


void	SortByWeight(list<shared_ptr<Item>>& tItems)
{
	tItems.sort([](shared_ptr<Item> vFirst, shared_ptr<Item> vSecond) {
		bool tSwap = ((*vFirst).GetWeight() < (*vSecond).GetWeight()); //Sort ascending
		return tSwap;
	}
	);
}

int main() {

	list<shared_ptr<Item>> tItems;		//make a list of shared pointers to our Item from last week

	tItems.emplace_back(make_shared<Item>("Axe", 50.0f, 0.2f, 0.0f));
	tItems.emplace_back(make_shared<Item>("Sword", 20.0f, 0.1f, 0.0f));
	tItems.emplace_back(make_shared<Item>("Hammer", 75.0f, 0.3f, 0.0f));
	tItems.emplace_back(make_shared<Item>("Magic Popsicle", 1.0f, 0.02f, 0.0f));

	cout << "Before" << endl;
	PrintItems(tItems);
	
	if (tItems.size() > 0) { //Make sure there is an item in the list
		shared_ptr<Item> tFirstItem = tItems.front(); //Get first item in list
		cout << "Removing:" << (*tFirstItem).ToString() << endl;
		tItems.remove(tFirstItem);	//Remove item from list
	}

	SortByWeight(tItems);

	cout << "After" << endl;
	PrintItems(tItems);

	return 0;
}

