# include <iostream>
# include <cmath>
# include <fstream>
# define uint unsigned int
using namespace std;
/*const uint MAXI = 100;
uint data [MAXI+1], data_length = 0;
long double barycentric_weights [MAXI];
fstream fin  ("input.txt");
fstream fout ("output.txt");
//# define cin fin
//# define cout fout
void precompute_barycentric_weights(int len)
{
	for (int i = 1; i <= len; i++)
	{
		barycentric_weights [i-1] = 1;
		//long long product = 1;
		for (int j = 1; j <= len; j++)
		{
			if (i == j) continue;
			barycentric_weights [i-1] /= (long double)(i - j);
			//cout << "internal product : " << product << ", i - j = " << (i-j) << endl;
		}
		//barycentric_weights [i-1] = (long double)1/(long double)product;
		//cout << "product : " << product << ", barycentric_weights[" << (i - 1) << "] = " << barycentric_weights [i-1] << endl;
	}
}
uint do_barycentric_interpolation(int index)
{
	long double numerator = 0, denominator = 0;
	for (int i = 1; i < index; i++)
	{
		long double subresult = barycentric_weights[i-1]/(index - i);
		cout << "subresult : " << subresult << endl;
		numerator   += (subresult * data[i-1]);
		denominator += subresult;
	}
	cout << "numerator : " << numerator << ", denominator : " << denominator << endl;
	//return round ((long double)(numerator/denominator));
	return round((numerator/denominator));
}
int main(int argc, char const *argv[])
{
	uint total;
	cin >> total;
	while (total--)
	{
		uint C;
		cin >> data_length >> C;
		for (int i = 0; i < data_length; i++)
			cin >> data[i];
		precompute_barycentric_weights(data_length);
		for (int i = 1; i <= C; i++)
		{
			uint result = do_barycentric_interpolation (data_length + i);
			//data [data_length] = result;
			cout << result << " ";
		}
		cout << endl;
	}
	return 0;
}*/
/*fstream fin  ("input.txt");
fstream fout ("output.txt");
# define cin fin
# define cout fout*/

uint data [100][100];
uint S, C;
int main(int argc, char const *argv[])
{
	int total;
	cin >> total;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			data[i][j] = 0;
		}
	}
	while (total--)
	{
		cin >> S >> C;
		for (int i = 0; i < S; i++)
			cin >> data[0][i];

		for (int i = 0; i < S; i++)
			for (int j = 1; j < S; j++)
				data[i+1][j] = data[i][j] - data[i][j-1];
		for (int i = 0; i < C; i++)
		{
			for (int j = S - 2; j >= 0; j--)
			{
				data[j][S-1] = data[j][S-1] + data[j+1][S-1];
			}
			cout << data[0][S-1] << (((i+1)==C) ? "\n" : " ");
		}
	}
	return 0;
}