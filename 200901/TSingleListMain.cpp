#include <iostream>
#include "TSingleList.h"

int main()
{
	TSingleList<int> intList;
	intList.Insert(10);
	intList.Insert(20);
	intList.Insert(30);
	intList.Insert(40);
	intList.Insert(50);

	std::cout << intList.Retrieve(3) << std::endl;

	return 0;
}