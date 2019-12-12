#include <iostream>
#include <string>
#include <map>


int is_purrfect(std::string inner, int k)
{
	using namespace std;
	map<char, int> myMap;
	for (int i = 0; i < inner.size(); i++)
	{
		if (!myMap.count(inner[i]))
			myMap.emplace(inner[i], 1);

		else
			myMap[inner[i]]++;
		
	}

	for (map<char, int>::iterator i = myMap.begin(); i != myMap.end(); i++)
	{
		if (i->second != k)	
			return 0;
		
	}

	return 1;
}

int perfect_sub(std::string str, int k)
{
	using namespace std;
	int len = str.size();
	
	int count = 0;
	for (int i = 1; i < len; i++)
	{
		for (int j = 0; j < i; j++)
		{
			string inner = str.substr(j, i - j + 1);

			if (is_purrfect(inner, k))
			{
				count++;
				cout << "str[" << j << ", " << i << "] = \"" << inner + "\"" << endl;
			}
				
		}

	}

	return count;
}

int main()
{
	std::string str = "1102021222";
	std::cout << "initial string is: " + str + "\n";
	int r = perfect_sub(str, 2);
	std::cout << "Perfect substrings: " << r << "\n";
	std::cin.get();
	return 0;

}