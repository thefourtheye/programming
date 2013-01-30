# include <iostream>
# include <cstdio>
# include <limits>
# include <queue>
# include <map>
# include <vector>
using namespace std;
int N, E, T, M;
int Weights  [101][101];
int Distances[101];
map <int, vector <int> > Nodes;
int main(int argc, char const *argv[])
{
	//freopen ("1845_MICEMAZE_input.txt",  "r", stdin);
	//freopen ("1845_MICEMAZE_output.txt", "w", stdout);
	scanf ("%d%d%d%d", &N, &E, &T, &M);
	//printf ("%d %d %d %d", N, E, T, M);
	for (int i = 0; i < 101; i++)
		fill (Weights[i], Weights[i] + 101, numeric_limits <int>::max());
	fill (Distances, Distances + 101, numeric_limits <int>::max());
	for (int i = 0; i < M; i++)
	{
		int A, B, C;
		scanf ("%d%d%d", &A, &B, &C);
		//cout << A << " " << B << " " << C << endl;
		Weights [A] [B] = C;
		Nodes [A].push_back (B);
	}
	int Counter = 0;
	queue <int> Queue;
	for (int i = 1; i <= N; i++)
	{
		fill (Distances, Distances + 101, numeric_limits <int>::max());
		Distances [i] = 0;
		if (i != E) Queue.push (i);
		while (!Queue.empty())
		{
			int current = Queue.front();
			Queue.pop();
			vector <int> nodes = Nodes [current];
			//cout << "Current : " << current << " " << nodes.size() << endl;
			for (int Sz = nodes.size(), j = 0; j < Sz; j++)
			{
				//cout << "Node : " << nodes [j] << endl;
				if (Distances [nodes[j]] > Distances [current] + Weights [current][nodes[j]])
				{
					Distances [nodes[j]] = Distances [current] + Weights [current][nodes[j]];
					Queue.push (nodes[j]);
				}
			}
		}
		//printf ("%d\n", Distances [E]);
		if (Distances [E] != numeric_limits <int>::max() && Distances [E] <= T) Counter++;
	}
	printf ("%d\n", Counter);
	return 0;
}