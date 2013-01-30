# include <iostream>
# include <cstdio>
# include <algorithm>
# include <set>
# include <utility>
using namespace std;
# define MAXVALUE 10001
int Colors [MAXVALUE], Common;
set <pair <int, int> > Edges;
bool Replace (int X)
{
	return X == Common;
}
int main(int argc, char const *argv[])
{
	//freopen ("1436_PT07Y_input.txt",  "r", stdin);
	//freopen ("1436_PT07Y_output.txt", "w", stdout);
	int N, M, A, B;
	scanf ("%d%d", &N, &M);
	fill (Colors, Colors + N, -1);
	for (int i = 0; i < M; i++)
	{
		scanf ("%d%d", &A, &B);
		Edges.insert (make_pair (min (A,B), max (A, B)));
		if (A == B)
		{
			printf ("NO\n"); return 0;
		}
		else if (Colors [A] == Colors [B] && Colors [B] == -1) Colors [A] = Colors [B] = A;
		else if (Colors [A] == -1) Colors [A] == Colors[B];
		else if (Colors [B] == -1) Colors [B] == Colors[A];
		else if (Colors [A] == Colors [B])
		{
			printf ("NO\n"); return 0;
		}
		else
		{
			Common = Colors [A];
			replace_if (Colors, Colors + N, Replace, Colors [B]);
		}
	}
	printf ("%s\n", Edges.size() != N-1?"NO":"YES");
	return 0;
}