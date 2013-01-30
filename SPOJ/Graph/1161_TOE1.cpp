# include <iostream>
# include <algorithm>
# include <cstdio>
# include <cstdlib>
using namespace std;
char Board[3][4];
bool isWin (char X)
{
	if (Board[0][0] + Board[0][1] + Board[0][2] == 3*X) return true;
	if (Board[1][0] + Board[1][1] + Board[1][2] == 3*X) return true;
	if (Board[2][0] + Board[2][1] + Board[2][2] == 3*X) return true;
	if (Board[0][0] + Board[1][0] + Board[2][0] == 3*X) return true;
	if (Board[0][1] + Board[1][1] + Board[2][1] == 3*X) return true;
	if (Board[0][2] + Board[1][2] + Board[2][2] == 3*X) return true;
	if (Board[0][0] + Board[1][1] + Board[2][2] == 3*X) return true;
	if (Board[2][0] + Board[1][1] + Board[0][2] == 3*X) return true;
	return false;
}
int main(int argc, char const *argv[])
{
	//freopen ("1161_TOE1_input.txt",  "r", stdin);
	//freopen ("1161_TOE1_output.txt",  "w", stdout);
	int N;
	scanf ("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int XCount = 0, OCount = 0, DotCount = 0;
		bool IsValid = true;
		for (int j = 0; j < 3; j++)
		{
			scanf ("%s", Board [j]);
			for (int k = 0; k < 3; k++)
				if (Board[j][k] == 'X') XCount++;
				else if (Board[j][k] == 'O') OCount++;
				else DotCount++;
		}
		bool XWins = isWin ('X'), OWins = isWin ('O');
		//cout << OCount << " " << XCount << " " << OWins << " " << XWins << endl;
		if (OCount > XCount) IsValid = false;
		else if (abs (OCount - XCount) > 1) IsValid = false;
		else if (OWins && OCount != XCount) IsValid = false;
		else if (XWins && OWins) IsValid = false;
		else if (XWins && (XCount == OCount)) IsValid = false;
		printf ("%s\n", IsValid?"yes":"no");
	}
	return 0;
}