# include <iostream>
# include <cstdio>
# include <cstdlib>
# include <algorithm>
# include <fstream>
# include <cstring>
# include <map>
# define uint unsigned int
using namespace std;
int current_count;
map<string, int> data;
int main(int argc, char const *argv[])
{
	//freopen ("input_sbank.txt","r",stdin);
	//freopen ("output_sbank.txt","w",stdout);
	char input [33];
	gets (input);
	int total = strtol (input, NULL, 10);
	while (total--)
	{
		data.clear();
		gets (input);
		current_count = strtol (input, NULL, 10);
		for (int i = 0; i < current_count; i++)
		{
			gets (input);
			data[input]++;
		}
		gets (input);
		map<string, int>::const_iterator it = data.begin();
		while (it != data.end())
		{
			int times_repeating = (*it).second;
			string no_of_times = "";
			while (times_repeating)
			{
				no_of_times.insert (0, string (1, (times_repeating%10) + 48));
				times_repeating /= 10;
			}
			puts (((*it).first + no_of_times + "\n").c_str());
			it++;
		}
	}
	return 0;
}