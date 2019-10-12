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
	return	tMyItem;	//Calling function now responsible for deleting the item
}


void TestItemHeapWithDefaults()
{
	Item*	tMyItem = new Item("Magic Shield", 2.0f,0.5f,100.0f); //Init with defaults, stored on heap

	//Notmally do stuff with item

	delete tMyItem;	//Delete item to tidy up
}


Item TestMyItem() {
	Item	tMyItem("Axe",10.0,11.0,0.0);

	return	tMyItem; //This is OK, as item will be copied if assigned on function return
}

Item* TestMyItem1() {
	Item	tMyItem("Axe", 10.0, 11.0, 0.0);

	return	&tMyItem; //No, No, No here we return a pointer to an item stored on a stackframe which will go away
}


