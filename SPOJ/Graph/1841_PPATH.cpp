# include <iostream>
# include <limits>
# include <cstdio>
# include <queue>
# include <bitset>
# include <cmath>
# include <map>
using namespace std;
int first, last, Min ;
struct Node
{
	Node (int ID = 0, int Dist = 0) {id = ID; dist = Dist;}
	short id, dist;
};
int POW (int X, int Y)
{
	int Z = 1;
	if (Y <= 0) return 1;
	else {for (int xyz = 0; xyz < Y; xyz++) Z *= X; return Z;}
}
queue <Node> Queue;
bitset <10000> Primes;
bitset <10000> Visited;
map <int, vector <int> > Table;
void GenPrimes()
{
	vector <int> temp_primes;
	bool isprime = true;
	for (int i = 2; i <= 9999; i++)
	{
		isprime = true; int half = (i / 2) + 1;
		for (vector<int>::iterator it = temp_primes.begin(); (it != temp_primes.end()) && isprime && (*it <= half); it++)
		{
			if ((i % *it) == 0) isprime = false;
		}
		if (isprime) {Primes[i] = true; temp_primes.push_back (i);}
	}
}
int main(int argc, char const *argv[])
{
	//freopen ("1841_PPATH_input.txt",  "r", stdin);
	//freopen ("1841_PPATH_output.txt", "w", stdout);
	GenPrimes();
	for (int i = 1000; i < 10000; i++)
	{
		if (Primes [i])
		{
			for (int j = 0; j < 4; j++)
			{
				int fpart = (i / POW (10, (j + 1))) * POW (10, j + 1); int spart = (j > 0? i % POW(10, j) : j);
				//cout << (i / POW (10, j + 1)) << " " << POW (10, j + 1) << " " << fpart << " " << spart << " " << i << " " << j << endl;
				int cur = fpart + spart; int inc = 1 * POW (10, j);
				//int cur = ((i / (int)pow (10, j + 1)) * (int)pow (10, j + 1)) + (j > 0? i % (int)pow(10, j) : j), inc = 1 * (int)pow (10, j);
				//cout << "Cur : " << cur << ", I : " << i << endl;
				for (int k = 0; k < 10; k++)
				{
					//cout << cur + (k * inc) << endl;
					if (Primes [cur + (k * inc)] && cur + (k * inc) > 1000) 
						{ Table[i].push_back (cur + (k * inc));}
				}
			}
		}
	}
	cin >> first;
	while (cin >> first >> last)
	{
		Visited.reset();
		Min = 0;
		while (Queue.empty() == false) Queue.pop();
		Queue.push (Node (first, 0));
		bool met_last = false;
		if (first == last) met_last = true;
		while (Queue.empty() == false && !met_last)
		{
			Node current = Queue.front();
			Queue.pop();
			Visited [current.id] = true;
			for (vector<int>::iterator it = Table [current.id].begin(); it != Table [current.id].end(); it++)
			{
				if (*it == last) { met_last = true; Min = current.dist + 1; break; }
				else if (!Visited [*it]) Queue.push (Node (*it, current.dist + 1));
			}
		}
		if (!met_last) cout << "Impossible";
		else cout << Min << endl;
	}
	return 0;
}
