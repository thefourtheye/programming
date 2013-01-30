# include <iostream>
# include <cstdio>
# include <limits>
# include <vector>
# include <stack>
# include <algorithm>
# include <map>
using namespace std;
map <int, vector <int> > Nodes;
bool Visited [10001];
int Distances [10001];
int BestDistance = numeric_limits<int>::min(), BestNode = 0;
int main(int argc, char const *argv[])
{
	//freopen ("1437_PT07Z_input.txt", "r", stdin);
	//freopen ("1437_PT07Z_output.txt","w", stdout);
	int N, A, B, Start;
	cin >> N;
	while (cin >> A >> B)
	{
		Start = A;
		Nodes [A].push_back (B);
		Nodes [B].push_back (A);
	}
	stack <int> Stack;
	Stack.push (Start);
	fill (Distances, Distances + 10002, numeric_limits<int>::min());
	Distances [Start] = 0;
	BestDistance = numeric_limits<int>::min(), BestNode = Start;
	while (!Stack.empty())
	{
		int current = Stack.top();
		Stack.pop();
		Visited [current] = true;
		for (vector<int>::iterator it = Nodes[current].begin(); it != Nodes[current].end(); it++)
		{
			if (!Visited [*it])
			{
				if (Distances [current] + 1 > Distances [*it])
				{
					Distances [*it] = Distances [current] + 1;
					if (Distances [*it] > BestDistance)
					{
						BestDistance = Distances [*it];
						BestNode = *it;
					}
					Stack.push (*it);
				}
			}
		}
	}
	Start = BestNode;
	Stack.push (Start);
	fill (Distances, Distances + 10002, numeric_limits<int>::min());
	fill (Visited, Visited + 10002, false);
	Distances [Start] = 0;
	BestDistance = numeric_limits<int>::min(), BestNode = Start;
	while (!Stack.empty())
	{
		int current = Stack.top();
		Stack.pop();
		Visited [current] = true;
		for (vector<int>::iterator it = Nodes[current].begin(); it != Nodes[current].end(); it++)
		{
			if (!Visited [*it])
			{
				if (Distances [current] + 1 > Distances [*it])
				{
					Distances [*it] = Distances [current] + 1;
					if (Distances [*it] > BestDistance)
					{
						BestDistance = Distances [*it];
						BestNode = *it;
					}
					Stack.push (*it);
				}
			}
		}
	}
	cout << BestDistance << endl;
	return 0;
}
