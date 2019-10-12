#include "pch.h" //Include standard C++ includes & set namespace

//Selection of containers
#include <vector>
#include <list>
#include <deque>
#include <map>

#include "Item.h" //This will allow us to use item


int main() {
	unique_ptr<Item> tItem = make_unique <Item>("Axe", 0, 0, 0, 0);
	unique_ptr<Item> tItem1 = move(tItem);

	cout << tItem1->ToString() << endl;

	cout << tItem->ToString() << endl;

	return 0;
}
