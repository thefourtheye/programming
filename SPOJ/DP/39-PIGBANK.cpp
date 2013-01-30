# include <iostream>
# include <limits>
# include <cstring>
int p [50001], w[50001];
int total, mini, maxi, nett, count;
using namespace std;
int res_weights [50001];
int solution    [50001];
int dp (int wt)
{
	if (wt <= 0) return 0;
	if (res_weights[wt] != -1)
		return res_weights[wt];
	int mini = numeric_limits <int>::max();
	for (int i = 0; i < count; i++)
	{
		mini = min (mini, p[i] + dp (wt - w[i]));
	}
	res_weights[wt] = mini;
	return mini;
}

int main(int argc, char const *argv[])
{
	cin >> total;
	while (total--)
	{
			memset (res_weights, -1, 50001);
		cin >> mini >> maxi;
		nett = maxi - mini;
		cin >> count;
		for (int i = 0; i < count; i++)
			cin >> p[i] >> w[i];
		int res = dp(nett);
		//if (res >= nett)
			cout << "The minimum amount of money in the piggy-bank is " << res << "." << endl;
		//else
		//	cout << "This is impossible." << endl;
	}
	return 0;
}
