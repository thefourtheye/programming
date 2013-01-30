# include <iostream>
# include <cstdio>
# include <cstring>
# include <queue>
# include <limits>
using namespace std;
int Weight  [26][26];
int Distance[26][26];
struct Node
{
	Node (int x = 0, int y = 0) { X = x; Y = y;}
	int X, Y;
};
int main(int argc, char const *argv[])
{
	//freopen ("96_SHOP_input.txt", "r", stdin);
	//freopen ("96_SHOP_output.txt", "w", stdout);
	int W, H;
	char Row [27]; Node Start, End;
	while (cin >> W >> H)
	{
		if (W == 0 && H == 0) break;
		memset (Weight, 0, sizeof Weight);
		for (int i = 0; i < 26; i++)
			for (int j = 0; j < 26; j++)
				Distance [i][j] = numeric_limits <int>::max();
		for (int i = 0; i < H; i++)
		{
			cin >> Row;
			for (int j = 0; j < W; j++)
			{
				if (Row [j] == 'S')
					Start = Node (i, j);
				else if (Row [j] == 'D')
					End = Node (i, j);
				else if (Row [j] == 'X')
					Weight [i][j] = -1;
				else
					Weight [i][j] = Row [j] - 48;
			}
		}
		queue <Node> Q;
		Q.push (Start);
		Distance [Start.X][Start.Y] = 0;
		while (!Q.empty())
		{
			Node node = Q.front(); Q.pop();
			//cout << "Popping " << node.X << " " << node.Y << endl;
			if (node.X == End.X && node.Y == End.Y) continue;
			if (Weight [node.X][node.Y] == -1) continue;
			if (node.X - 1 >= 0 && Distance [node.X - 1][node.Y] > Distance [node.X][node.Y] + Weight [node.X][node.Y])
			{
				Distance [node.X - 1][node.Y] = Distance [node.X][node.Y] + Weight [node.X][node.Y];
				Q.push (Node (node.X - 1, node.Y));
			}
			if (node.Y - 1 >= 0 && Distance [node.X][node.Y - 1] > Distance [node.X][node.Y] + Weight [node.X][node.Y])
			{
				Distance [node.X][node.Y - 1] = Distance [node.X][node.Y] + Weight [node.X][node.Y];
				Q.push (Node (node.X, node.Y - 1));
			}
			if (node.X + 1 < H && Distance [node.X + 1][node.Y] > Distance [node.X][node.Y] + Weight [node.X][node.Y])
			{
				Distance [node.X + 1][node.Y] = Distance [node.X][node.Y] + Weight [node.X][node.Y];
				Q.push (Node (node.X + 1, node.Y));
			}
			if (node.Y + 1 < W && Distance [node.X][node.Y + 1] > Distance [node.X][node.Y] + Weight [node.X][node.Y])
			{
				Distance [node.X][node.Y + 1] = Distance [node.X][node.Y] + Weight [node.X][node.Y];
				Q.push (Node (node.X, node.Y + 1));
			}
		}
		cout << (Distance [End.X] [End.Y] == numeric_limits <int>::max()?0:Distance [End.X] [End.Y]) << endl;
	}
	return 0;
}