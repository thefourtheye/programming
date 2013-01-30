# include <iostream>
# include <string>
# include <cstdio>
# include <map>
# include <cmath>
# include <cstdlib>
using namespace std;
string Strings[100000];
int Origins [26];
map <int, int> startCount, endCount;
int GetOrigin (int X)
{
	return Origins [X] = (X == Origins [X]? X : GetOrigin (Origins [X]));
}
int main(int argc, char const *argv[])
{
	//freopen ("41_Words1_input.txt",  "r", stdin);
	//freopen ("41_Words1_output.txt", "w", stdout);
	int total, N;
	cin >> total;
	while (total--)
	{
		for (int i = 0; i < 26; i++)
		{
			Origins [i] = i;
		}
		startCount.clear();
		endCount.clear();
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> Strings [i];
			int start = Strings[i][0] - 97, finish = Strings[i][Strings[i].length() - 1] - 97;
			int sorigin = GetOrigin (start), forigin = GetOrigin (finish);
			startCount [start]++;
			endCount [finish]++;
			Origins [finish] = sorigin;
		}
		bool SingleSet = true, ValidEulerPathExist = true;
		int TheOrigin = -1, idx;
		for (idx = 0; idx < 26; idx++)
		{
			if (startCount[idx] || endCount[idx])
			{
				TheOrigin = GetOrigin (idx);
				break;
			}
		}
		for (idx++; idx < 26; idx++)
		{
			if (startCount[idx] || endCount[idx])
			{
				if (TheOrigin != GetOrigin (idx))
				{
					SingleSet = false;
					break;
				}
			}
		}
		int FreeEnds = 0;
		for (int i = 0; i < 26 && FreeEnds <= 2; i++)
		{
			if (abs (startCount[i] - endCount[i]) > 1)
			{
				ValidEulerPathExist = false;
				break;
			}
			if (abs (startCount[i] - endCount[i]) == 1) FreeEnds++;
		}
		if (FreeEnds <= 2 && ValidEulerPathExist && SingleSet)
		{
			cout << "Ordering is possible." << endl;
		}
		else
		{
			//cout << FreeEnds << " " << ValidEulerPathExist << " " << SingleSet << endl;
			cout << "The door cannot be opened." << endl;
		}
	}
	return 0;
}