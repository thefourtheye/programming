# include <iostream>
# include <cstdio>
# include <cstdlib>
using namespace std;
# define MAXVALUE 101
int Y, X, N, MX1, MY1, CX1, CY1, CX2, CY2;
bool IsGettable = false;
int main(int argc, char const *argv[])
{
	//freopen ("1418_CATM_input.txt",  "r", stdin);
	//freopen ("1418_CATM_output.txt", "w", stdout);
	cin >> X >> Y >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> MX1 >> MY1 >> CX1 >> CY1 >> CX2 >> CY2;
		IsGettable = false;
		if (abs (CX1 - CX2) == abs(CY1 - CY2) && abs (MX1 - CX2) == abs (MY1 - CY2) && MX1 < max (CX1, CX2) && MX1 > min (CX1, CX2))
			IsGettable = true;
		cout << (IsGettable?"NO":"YES") << endl;
	}
	return 0;
}