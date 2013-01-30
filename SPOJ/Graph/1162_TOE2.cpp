# include <iostream>
# include <algorithm>
# include <cstdio>
# include <cstring>
using namespace std;

char Board [9];
bool isWin (char chr)
{
	if (Board[0] + Board[3] + Board[6] == 3*chr) return true;
	if (Board[1] + Board[4] + Board[7] == 3*chr) return true;
	if (Board[2] + Board[5] + Board[8] == 3*chr) return true;
	if (Board[0] + Board[1] + Board[2] == 3*chr) return true;
	if (Board[3] + Board[4] + Board[5] == 3*chr) return true;
	if (Board[6] + Board[7] + Board[8] == 3*chr) return true;
	if (Board[0] + Board[4] + Board[8] == 3*chr) return true;
	if (Board[2] + Board[4] + Board[6] == 3*chr) return true;
	return false;
}
int main(int argc, char const *argv[])
{
	//freopen ("1162_TOE2_input.txt",  "r", stdin);
	//freopen ("1162_TOE2_output.txt", "w", stdout);
	while (cin >> Board && strncmp (Board, "end", 3))
	{
		//cout << Board << endl;
		bool Valid = true; int XCount, OCount;
		bool XWins = isWin ('X'), OWins = isWin ('O');
		XCount = count (Board, Board + 9, 'X');
		OCount = count (Board, Board + 9, 'O');
		if (OCount > XCount) Valid = false;
		else if (XCount - OCount > 1) Valid = false;
		else if (XCount < 3 && OCount < 3) Valid = false;
		else if (OWins && XCount > OCount) Valid = false;
		else if (XWins && XCount == OCount) Valid = false;
		else if (!OWins && !XWins && (XCount + OCount != 9)) Valid = false;
		if (Valid) cout << "valid" << endl;
		else cout << "invalid" << endl;
	}
	return 0;
}
