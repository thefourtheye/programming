# include <iostream>
# include <cstring>
# include <cstdio>
# include <set>
# include <queue>
# include <map>
# include <algorithm>
# include <limits>
using namespace std;
# define MAXVALUE 100001
map <short, map <short, short> > Weights;
//short Weights [MAXVALUE][MAXVALUE];
unsigned long long Distances [MAXVALUE];
map <int, vector <int> > Nodes;
int main(int argc, char const *argv[])
{
	//freopen ("3381_HIGHWAYS_input.txt",  "r", stdin);
	//freopen ("3381_HIGHWAYS_output.txt", "w", stdout);
	int N, TotalCities, TotalIntersections, Start, End;
	scanf ("%d", &N);
	queue <int> Queue;
	while (N--)
	{
		scanf ("%d%d%d%d", &TotalCities, &TotalIntersections, &Start, &End);
		//memset (Weights, 0, sizeof (Weights) * MAXVALUE * MAXVALUE);
		//for (int i = 0; i < MAXVALUE; i++)
		fill (Distances, Distances + MAXVALUE, numeric_limits <unsigned long long>::max());
		//memset (Distances, 0, sizeof (Distances) * MAXVALUE * MAXVALUE);
		for (int i = 0; i < TotalIntersections; i++)
		{
			int A, B, C;
			scanf ("%d%d%d", &A, &B, &C);
			Weights [A][B] = C;
			Weights [B][A] = C;
			Nodes[A].push_back (B);
			Nodes[B].push_back (A);
		}
		Distances [Start] = 0;
		Queue.push (Start);
		while (!Queue.empty())
		{
			int current = Queue.front();
			Queue.pop();
			vector <int> nodes = Nodes [current];
			for (int Sz = nodes.size(), i = 0; i < Sz; i++)
			{
				if (Distances [nodes[i]] > Distances [current] + Weights [current][nodes[i]])
				{
					Distances [nodes[i]] = Distances [current] + Weights [current][nodes[i]];
					Queue.push (nodes[i]);
				}
			}
		}
		if (Distances [End] == numeric_limits <unsigned long long>::max())
			printf ("NONE\n");
		else
			printf ("%llu\n", Distances [End]);
	}
	return 0;
}