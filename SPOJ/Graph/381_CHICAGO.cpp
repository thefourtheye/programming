# include <iostream>
# include <map>
# include <limits>
# include <queue>
# include <cstdio>
# include <iomanip>
using namespace std;
struct Node
{
	Node (int next = 0, int weight = 0)
		{Next = next; Weight = weight;}
	int Next, Weight;
};
map <int, vector <Node> > Table;
queue <int> Queue;
double Percentages [100];
int main(int argc, char const *argv[])
{
	//freopen ("381_CHICAGO_input.txt", "r", stdin);
	//freopen ("381_CHICAGO_output.txt", "w", stderr);
	//freopen ("381_CHICAGO_output.txt", "w", stdout);
	freopen ("/dev/null", "w", stderr);
	int N, M;
	while (cin >> N && N && cin >> M)
	{
		Table.clear();
		fill (Percentages, Percentages + 100, numeric_limits <double>::min());
		for (int i = 0; i < M; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			Table [a].push_back (Node (b, c));
			Table [b].push_back (Node (a, c));
		}
		Queue.push (1);
		Percentages [1] = 1;
		double Max = numeric_limits <double>::min();
		while (!Queue.empty())
		{
			int current = Queue.front();
			Queue.pop();
			cerr << "Current is " << current << endl;
			if (current == N)
			{
				Max = max (Max, Percentages[current]);
				continue;
			}
			for (vector <Node>::iterator it = Table [current].begin(); it != Table [current].end(); it++)
			{
				cerr << "Next is " << it->Next << " and % is " << Percentages [it->Next] << endl;
				if (Percentages [it->Next] < (Percentages[current] * (it->Weight / 100.0)))
				{
					Percentages [it->Next] = Percentages[current] * (it->Weight / 100.0);
					cerr << "Updating Percent with " << Percentages [it->Next] << " for " << current << " and " << it->Next << endl;
					Queue.push (it->Next);
				}
			}
		}
		cout << fixed << setprecision (6) << Max * 100 << " percent" << endl;
	}
	return 0;
}