#include <iostream>
#include <string>

#pragma warning(disable:4996)

class TestClass 
{ 
private: 
	char* name;

public:
	TestClass(const char* str)
	{
		name = new char[strlen(str) + 1];
		strcpy(name, str);
	}

	TestClass(const TestClass& ref)
	{
		if (name != nullptr)
		{
			delete[] name;
		}

		name = new char[strlen(ref.name) + 1];
		strcpy(name, ref.name);
	}
	
	~TestClass() 
	{ 
		delete[] name;
		std::cout << "¼Ò¸êÀÚ È£ÃâµÊ" << std::endl;
	} 
	void ShowData() 
	{ 
		std::cout << "name: " << name << std::endl;
	} 
};


int main()
{
	TestClass tc1("evan"); 
	TestClass tc2 = tc1;
	
	tc1.ShowData(); 
	tc2.ShowData();	

	return 0;
}