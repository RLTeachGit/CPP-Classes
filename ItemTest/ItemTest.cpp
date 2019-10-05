// ItemTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"

#include "Item.h"


void TestItemLocal() 
{
	Item	tMyItem; //Will be stored on in TestItem() Stack frame
	cout << "Showing MyItem " << tMyItem.ToString() << endl;
}

void TestItemHeap()
{
	Item*	tMyItem = new Item(); //Will be stored on Heap using a pointer
	cout << "Showing MyItem " << tMyItem->ToString() << endl;
	delete tMyItem;
}

Item* TestItemHeapAndReturn()
{
	Item*	tMyItem = new Item(); //Will be stored on Heap using a pointer
	return	tMyItem;
}


void TestItemHeapWithDefaults()
{
	Item*	tMyItem = new Item("Magic Shield", 2.0f,0.5f,100.0f); //Init with defaults
	delete tMyItem;
}


int main()
{
//	TestItemLocal();
//	TestItemHeap();

//	Item* tMyItem = TestItemHeapAndReturn(); //NB this is a different scope and hence totally differn variable from the one in TestItemHeapAndReturn()
//	cout << "Showing MyItem " << tMyItem->ToString() << endl;

	TestItemHeapWithDefaults();



//	delete tMyItem; //Delete

}