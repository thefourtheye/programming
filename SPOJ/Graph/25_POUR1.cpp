# include <iostream>
# include <cstdio>
# include <cstdlib>
# include <queue>
# include <cmath>
using namespace std;
int N, A, B, C, GCD;
int PlainGCD (int a, int b)
{
	if (b == 0) return a;
	else return PlainGCD (b, a % b);
}
int Distances [40000][40000];
int main(int argc, char const *argv[])
{
	freopen ("25_POUR1_input.txt",  "r", stdin);
	freopen ("25_POUR1_output.txt", "w", stdout);
	scanf ("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf ("%d%d%d", &A, &B, &C);
		if (A < B) {int t = B; B = A; A = t;}
		if (A == C || B == C)
		{
			printf ("1\n");
			continue;
		}
		else if ((A<C && B<C) || !(A%B) || !(B%A) || C % (GCD = PlainGCD (A, B)))
		{
			printf ("-1\n");
			continue;
		}
		memset (Distances, 0, sizeof Distances);
	}
	return 0;
}
