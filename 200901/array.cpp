#include <iostream>

void funcTest(int* arr)
{
	arr[0] = 20;
}

void funcTest2(int* arr)
{
	arr[2] = 30;
}

int main()
{
	int grade[3] = { 85,65,90 };
	int* pNum = grade;

	std::cout << grade[0] << std::endl;
	funcTest(grade);
	std::cout << grade[0] << std::endl;
	std::cout << grade[2] << std::endl;
	funcTest(&grade[0]);
	std::cout << grade[2] << std::endl;


	int arr[5] = { 10,20,30,40,50 };

	int* pArr = new int[5];
	delete[] pArr;

	return 0;
}