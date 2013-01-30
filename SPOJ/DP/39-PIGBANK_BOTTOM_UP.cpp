# include <iostream>
# include <limits>
# include <map>
# include <limits>
# include <cstring>
# include <fstream>
using namespace std;
long long temp_res [500001], wt [500001], pr [500001], solution [500001];
/*ifstream fin  ("input_PIGBANK_original.txt");
ofstream fout ("output_PIGBANK.txt");
# define cin fin
# define cout fout*/
int main(int argc, char const *argv[])
{
	int total;
	cin >> total;
	while (total--)
	{
		int mini, maxi, nett, counter;
		cin >> mini >> maxi;
		cin >> counter;
		//cout << "Min : " << mini << ", Maxi : " << maxi << ", Test Data Length : " << counter << endl;
		nett = maxi - mini;
		//cout << "Mini : " << mini << ", Maxi : " << maxi << ", Nett : " << nett << endl;
		memset (temp_res, 0, 500001);
		memset (solution, 0, 500001);
		for (int i = 0; i < counter; i++)
		{
			//int temp1, temp2;
			//cin >> temp1 >> temp2;
			//data[temp2] = temp1;
			cin >> pr [i] >> wt [i];
			/*if (counter == 19)
			{
				cout << pr [i] << " " << wt [i] << endl;;
			}*/
			//cout << "data[" << temp1 << "] : " << temp2 << endl;
		}
		temp_res [0] = 0;
		for (int i = 1; i <= nett; i++)
		{
			long long res = numeric_limits<int>::max();
			for (int j = 0; j < counter; j++)
			{
				//cout << "Looping : data[" << j << "] : " << data[j] << ", temp_res [" << i - j << "] : " << temp_res [i - j] <<endl;
				if (i - wt[j] >= 0 && temp_res[i - wt[j]] >= 0)
				//if (data[j])
				{
					//cout << "Before:res : " << res << ", data[" << j << "] : " << data[j] << ", temp_res [" << i - j << "] : " << temp_res [i - j] <<endl;
					//cout << "Before: j : " << j << ", i : " << i << ", wt : " << wt[j] << ", res : " << res << ", pr[" << j << "] : " << pr[j] << ", temp_res [" << i - wt[j] << "] : " << temp_res [i - wt[j]] <<endl;
					
					int old_res = res;
					//res = min(res, data[j] + temp_res [i - j]);
					res = min(res, pr[j] + temp_res [i - wt[j]]);
					if (res != old_res)
					{
						solution[i] = wt[j];
						//cout << "Solution[" << i << "] : " << wt[j] << endl;
					}
					//cout << "After :res : " << res << ", data[" << j << "] : " << data[j] << ", temp_res [" << i - j << "] : " << temp_res [i - j] <<endl;
				}
			}
			if (res == numeric_limits<int>::max()) res = -1;
			temp_res [i] = res;
			//cout << "temp_res[" << i << "] : " << res << endl;
		}
		long long temp = nett, total_weight = 0;
		while (temp > 0 && solution [temp])
		{
			total_weight += solution [temp];
			temp -= solution [temp];
		}
		if (total_weight == nett && nett != 0)
			cout << "The minimum amount of money in the piggy-bank is " << temp_res [nett] << "." << endl;
		else
			cout << "This is impossible." << endl;
	}
	return 0;
}