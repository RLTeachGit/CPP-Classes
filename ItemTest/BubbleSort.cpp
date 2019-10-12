
#include "BubbleSort.h"


int BubbleSortByRef(vector<int>& vData) //Data is passed by reference, its not copied so any actions on data will be seen outside
{
	int tSwapCount=0; //Keep a count of the total number of swaps
	bool tSwap;
	do
	{
		tSwap = false;
		for(size_t tI = 0; tI < vData.size()-1; tI++)	//Go throught array -1
		{
			if (vData[tI] > vData[tI + 1])	//Compare adjacant numbers
			{
				int tTempData = vData[tI + 1]; //If out of order swap via temp variable
				vData[tI + 1] = vData[tI];
				vData[tI] = tTempData;
				tSwap = true;	//Set Swap flag
				tSwapCount++;	//Update count
			}
		}
	} while (tSwap); //When we have been though the array without swaps we are done

	return	tSwapCount;
}

vector<int> BubbleSortByValue(vector<int> vData) //Data is passed by Value, ie. copied, any changes are keep to this function scope
{
	int tSwapCount = 0;
	bool tSwap;
	do
	{
		tSwap = false;
		for (size_t tI = 0; tI < vData.size() - 1; tI++) //Same as above
		{
			if (vData[tI] > vData[tI + 1])
			{
				int tTempData = vData[tI + 1];
				vData[tI + 1] = vData[tI];
				vData[tI] = tTempData;
				tSwap = true;
				tSwapCount++;
			}
		}
	} while (tSwap);

	return	vData;
}


