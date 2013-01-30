# include <iostream>
# include <cstdio>
using namespace std;
int main ()
{
	//freopen ("input_beads.txt",  "r", stdin);
	//freopen ("output_beads.txt", "w", stdout);
	int total;
	cin >> total;
	while (total--)
	{
		string str;
		cin >> str;
		string minimal_string = str;
		int start_point = 0, str_len = str.length(), min_index = 0;
		while (++start_point < str_len)
		{
			string new_str = str.substr (start_point) + str.substr (0, start_point);
			bool incomplete = false;
			if (new_str.compare (minimal_string) < 0)
				incomplete = true;
			/*for (int i = 0; i < str_len; i++)
			{
				if (new_str[i] > minimal_string[i])
				{
					
					cout << "new_str[" << i << "] : " << new_str[i] << ", minimal_string[" << i << "] : " << minimal_string[i] << endl;
					incomplete = true;
					break;
				}
			}*/
			if (incomplete)
			{
				//cout << "start_point: " << start_point << ", New String : " << new_str << ", Min String : " << minimal_string << endl;
				//cout << "New Index  : " << start_point << endl;
				minimal_string = new_str;
				min_index = start_point;
			}
		}
		cout << (min_index + 1) << endl;
	}
}