#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std; //makes std::vector accessible wihout prefix

extern	int BubbleSortByRef(vector<int>& vData); //Pass by reference
extern	vector<int> BubbleSortByValue(vector<int> vData); //Pass by Value
