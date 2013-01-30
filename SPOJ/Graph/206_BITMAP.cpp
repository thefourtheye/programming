# include <iostream>
# include <cstdio>
# include <algorithm>
# include <utility>
# include <cstring>
# include <vector>
# include <limits>
# include <cstdlib>
# include <queue>
using namespace std;
vector < pair <int, int> > Nodes;
//bool Holes [182][182];
int  Distances [182][182];
const int MAXIMUM = numeric_limits <int>::max();
struct Node
{
	Node (int x = 0, int y = 0, int distance = 0)
	{
		X = x;
		Y = y;
		Distance = distance;
	}
	int X, Y, Distance;
};
/*int GetMaxDistance (int i, int j)
{
	int Min = MAXIMUM;
	int Size = Nodes.size();
	for (int k = 0; k < Size; k++)
	{
		int curdist = abs (Nodes[k].first - i) + abs (Nodes[k].second - j);
		if (Min > curdist) Min = curdist;
	}
	if (Min == MAXIMUM) Min = 0;
	return Min;
}*/
queue <pair <int, int> > Queue;
int main(int argc, char const *argv[])
{
	//freopen ("206_BITMAP_input.txt",  "r", stdin);
	//freopen ("206_BITMAP_output.txt", "w", stdout);
	int N, rows, cols; char str[183]; int Size = Nodes.size(), Min, curdist;
	scanf ("%d", &N);
	while (N--)
	{
		scanf ("%d%d", &rows, &cols);
		Nodes.clear();
		//memset (Holes, false, sizeof (Holes[0][0]) * 182 * 182);
		for (int i = 0; i < 182; i++)
			for (int j = 0; j < 182; j++)
				Distances [i][j] = MAXIMUM;
		for (int i = 0; i < rows; i++)
		{
			scanf ("%s", str);
			for (int j = 0; j < cols; j++)
				if (str [j] == '1')
				{ 
					//Holes [i][j] = true;
					Nodes.push_back (make_pair (i, j));
					Distances [i][j] = 0;
				}
		}
		Size = Nodes.size();
		for (int i = 0; i < Size; i++)
		{
			Queue.push (make_pair (Nodes[i].first, Nodes[i].second));
			//cout << "Main Pushing X : " << Nodes[i].first << ", Y : " << Nodes[i].second << endl;
			while (!Queue.empty())
			{
				pair <int, int> node = Queue.front();
				Queue.pop();
				//cout << "X : " << node.first << ", Y : " << node.second << endl;
				if (node.first + 1 < rows && Distances [node.first + 1][node.second] > Distances [node.first][node.second] + 1)
				{
					Distances [node.first + 1][node.second] = Distances [node.first][node.second] + 1;
					Queue.push (make_pair (node.first + 1, node.second));
					//cout << "Pushing 1 X : " << node.first + 1 << ", Y : " << node.second << endl;
				}
				if (node.second + 1 < cols && Distances [node.first][node.second + 1] > Distances [node.first][node.second] + 1)
				{
					Distances [node.first][node.second + 1] = Distances [node.first][node.second] + 1;
					Queue.push (make_pair (node.first, node.second + 1));
					//cout << "Pushing 2 X : " << node.first << ", Y : " << node.second + 1 << endl;
				}
				if (node.first - 1 >= 0 && Distances [node.first - 1][node.second] > Distances [node.first][node.second] + 1)
				{
					Distances [node.first - 1][node.second] = Distances [node.first][node.second] + 1;
					Queue.push (make_pair (node.first - 1, node.second));
					//cout << "Pushing 3 X : " << node.first - 1 << ", Y : " << node.second << endl;
				}
				if (node.second - 1 >= 0 && Distances [node.first][node.second - 1] > Distances [node.first][node.second] + 1)
				{
					Distances [node.first][node.second - 1] = Distances [node.first][node.second] + 1;
					Queue.push (make_pair (node.first, node.second - 1));
					//cout << "Pushing 4 X : " << node.first << ", Y : " << node.second - 1 << endl;
				}
			}
		}
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				printf ("%d ", Distances[i][j]);
			}
			printf ("\n");
		}
	}
	return 0;
}