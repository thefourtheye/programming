# include <iostream>
# include <queue>
# include <limits>
//# include <bitset>
# include <cstdlib>
# include <cstring>
# include <cstdio>
using namespace std;
int  Table [101][101];
unsigned short Weight[101][101];
//bitset <65536> Visited;
struct Node
{
	Node (int X = 0, int Y = 0, int Weight = 0) { x = X; y = Y; weight = Weight; }
	int x, y, weight;
};
queue <Node> Queue;
int main(int argc, char const *argv[])
{
	//freopen ("3920_BYTESE1_input.txt",  "r", stdin);
	//freopen ("3920_BYTESE1_output.txt", "w", stderr);
	freopen ("/dev/null", "w", stderr);
	int M, N;
	cin >> M;
	while (cin >> M >> N)
	{
		cerr << "Processing " << M << ", " << N << endl;
		//Visited.reset();
		Node Target;
		memset (Table,  0, 10201);
		for (int i = 0; i < 101; i++)
			fill (Weight[i], Weight[i] + 101, numeric_limits <unsigned short>::max());
		for (int i = 1; i <= M; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				cin >> Table [i][j];
				//Table [i][j] -= 48;
			}
		}
		cin >> Target.x >> Target.y >> Target.weight;
		Queue.push (Node (1, 1, Table [1][1]));
		Weight [1][1] = Table [1][1];
		while (!Queue.empty())
		{
			Node node = Queue.front();
			Queue.pop();
			if (node.x < M && Weight [node.x] [node.y] + Table[node.x + 1] [node.y] < Weight[node.x + 1][node.y])
			{
				Weight[node.x + 1][node.y] = Weight [node.x] [node.y] + Table[node.x + 1] [node.y];
				cerr << "Updating ["<<node.x+1<<","<<node.y<<"] from ["<<node.x<<","<<node.y<<"] with "<<Weight[node.x+1][node.y]<<endl;
				Queue.push (Node (node.x + 1, node.y, Weight[node.x + 1][node.y]));
			}
			if (node.y < N && Weight [node.x] [node.y] + Table[node.x] [node.y + 1] < Weight[node.x][node.y + 1])
			{
				Weight[node.x][node.y + 1] = Weight [node.x] [node.y] + Table[node.x] [node.y + 1];
				cerr << "Updating ["<<node.x<<","<<node.y+1<<"] from ["<<node.x<<","<<node.y<<"] with "<<Weight[node.x][node.y+1]<<endl;
				Queue.push (Node (node.x, node.y + 1, Weight[node.x][node.y + 1]));
			}
			if (node.x - 1 >= 1 && Weight [node.x] [node.y] + Table[node.x - 1] [node.y] < Weight[node.x - 1][node.y])
			{
				Weight[node.x - 1][node.y] = Weight [node.x] [node.y] + Table[node.x - 1] [node.y];
				cerr << "Updating ["<<node.x-1<<","<<node.y<<"] from ["<<node.x<<","<<node.y<<"] with "<<Weight[node.x-1][node.y]<<endl;
				Queue.push (Node (node.x - 1, node.y, Weight[node.x - 1][node.y]));
			}
			if (node.y - 1 >= 1 && Weight [node.x] [node.y] + Table[node.x] [node.y - 1] < Weight[node.x][node.y - 1])
			{
				Weight[node.x][node.y - 1] = Weight [node.x] [node.y] + Table[node.x] [node.y - 1];
				cerr << "Updating ["<<node.x<<","<<node.y-1<<"] from ["<<node.x<<","<<node.y<<"] with "<<Weight[node.x][node.y-1]<<endl;
				Queue.push (Node (node.x, node.y - 1, Weight[node.x][node.y - 1]));
			}
		}
		//cout << Target.weight << " " << Weight[Target.x][Target.y] << endl;
		if (Weight[Target.x][Target.y] <= Target.weight)
		{
			cout << "YES" << endl << abs (Target.weight - Weight[Target.x][Target.y]) << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}
