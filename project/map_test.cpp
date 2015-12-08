#include <iostream>
#include <map>

int main(int argc, char const *argv[])
{
	std::map<int, int> myMap;

	myMap[1] = 1;
	myMap[2] = 2;

	for (std::map<int, int>::reverse_iterator it = myMap.rbegin(); it != myMap.rend(); ++it)
	{
		std::cout << it->second << "\t";
	}
	return 0;
}