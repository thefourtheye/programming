# include <iostream>
# include <cstring>
# include <cstdio>
# include <vector>
# include <bitset>
# include <stack>
# include <limits>
using namespace std;
# define MAXVALUE 1001
struct Node
{
	Node (int x = 0, int y = 0, int distance = numeric_limits <int>::min()) {X = x; Y = y; Distance = distance;}
	int X, Y, Distance;
};
stack <Node> Stack;
int N, Cols, Rows;
bool Graph   [MAXVALUE][MAXVALUE];
bool Visited [MAXVALUE][MAXVALUE];
int main(int argc, char const *argv[])
{
	//freopen ("38_LABYR1_input.txt",  "r", stdin);
	//freopen ("38_LABYR1_output.txt", "w", stdout);
	scanf ("%d", &N);
	char Str[MAXVALUE];
	while (N--)
	{
		bool FirstNode = false;
		memset (Graph,   false, MAXVALUE * MAXVALUE);
		memset (Visited, false, MAXVALUE * MAXVALUE);
		scanf ("%d%d", &Cols, &Rows);
		for (int i = 0; i < Rows; i++)
		{
			scanf ("%s", Str);
			for (int j = 0; j < Cols; j++)
			{
				if (Str[j] == '.')
				{
					Graph [i][j] = true;
					if (!FirstNode)
					{
						Stack.push (Node (i, j, 0));
						FirstNode = !FirstNode;
					}
				}
			}
		}
		Node BestNode (-1, -1);
		while (!Stack.empty())
		{
			Node node = Stack.top();
			Stack.pop();
			Visited [node.X] [node.Y] = true;
			if (BestNode.Distance < node.Distance) BestNode = node;
			if (node.X - 1 >= 0 && Graph[node.X - 1][node.Y] && !Visited [node.X-1] [node.Y])
				Stack.push (Node (node.X-1, node.Y, node.Distance + 1));
			if (node.Y - 1 >= 0 && Graph[node.X][node.Y-1] && !Visited [node.X] [node.Y-1])
				Stack.push (Node (node.X, node.Y-1, node.Distance + 1));
			if (node.X + 1 < Rows && Graph[node.X + 1][node.Y] && !Visited [node.X+1] [node.Y])
				Stack.push (Node (node.X+1, node.Y, node.Distance + 1));
			if (node.Y + 1 < Cols && Graph[node.X][node.Y+1] && !Visited [node.X] [node.Y+1])
				Stack.push (Node (node.X, node.Y+1, node.Distance + 1));
		}
		BestNode.Distance = 0;
		Stack.push (BestNode);
		BestNode.Distance = numeric_limits <int>::min();
		memset (Visited, false, MAXVALUE * MAXVALUE);
		while (!Stack.empty())
		{
			Node node = Stack.top();
			Stack.pop();
			Visited [node.X] [node.Y] = true;
			if (BestNode.Distance < node.Distance) BestNode = node;
			if (node.X - 1 >= 0 && Graph[node.X - 1][node.Y] && !Visited [node.X-1] [node.Y])
				Stack.push (Node (node.X-1, node.Y, node.Distance + 1));
			if (node.Y - 1 >= 0 && Graph[node.X][node.Y-1] && !Visited [node.X] [node.Y-1])
				Stack.push (Node (node.X, node.Y-1, node.Distance + 1));
			if (node.X + 1 < Rows && Graph[node.X + 1][node.Y] && !Visited [node.X+1] [node.Y])
				Stack.push (Node (node.X+1, node.Y, node.Distance + 1));
			if (node.Y + 1 < Cols && Graph[node.X][node.Y+1] && !Visited [node.X] [node.Y+1])
				Stack.push (Node (node.X, node.Y+1, node.Distance + 1));
		}
		printf ("Maximum rope length is %d.\n", BestNode.Distance);
	}
}
