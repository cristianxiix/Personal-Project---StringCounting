#include <iostream>
#include <unordered_map>
#include <map>
#include <string>
int ReturnHowManyTimes(const std::string& a, const std::string& b);

int main()
{
	std::string test = "abaabaaba";
	std::string s2 = "aba";
	
 	std::cout << ReturnHowManyTimes(test, s2);
}

int ReturnHowManyTimes(const std::string& a, const std::string& b)
{
	std::map<char, int> myMapS1;
	int count = 0;
	int temp = 0;
	for (int i = 0; i < a.length(); i++)
	{
		if (myMapS1.contains(a[i]))
		{
			myMapS1[a[i]] += 1;
		}
		else
		{
			myMapS1.insert({ a[i], 1 });
		}
	}
	bool x = true;
	while (x)
	{
		for (int i = 0; i < b.length(); i++)
		{
			if (!(myMapS1.contains(b[i])))
			{
				count = 0;
				x = false;
				return count;
			}
			else //daca contine char din b
			{
				if (myMapS1.at(b[i]) != 0)
				{
					myMapS1.at(b[i]) -= 1;
				}
				else
				{
					return count;
				}
			}
		}
			count++;
	}
	std::cout << "You can write this string " << count << " time(s)" << std::endl;
	return count;
	
}


