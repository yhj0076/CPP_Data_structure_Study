#include <iostream>
#include <vector>

int main()
{
	std::vector<int> vec1;
	vec1.push_back(10);
	vec1.push_back(20);
	vec1.push_back(30);
	vec1.push_back(40);
	vec1.push_back(50);

	for (size_t i = 0; i < vec1.size(); i++)
	{
		std::cout << vec1[i] << std::endl;
	}

	for (auto i : vec1)
	{
		std::cout << i << std::endl;
	}

	return 0;
}