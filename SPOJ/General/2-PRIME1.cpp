# include <iostream>
# include <vector>
# include <cmath>
# include <ctime>
using namespace std;
vector <unsigned int> prime_data;
bool is_Prime (unsigned int num)
{
	if (num == 1) return false;
	unsigned int j = sqrt ((long double)num) + 1;
	unsigned int x = prime_data.size();
	unsigned int i = 0;
	while (prime_data[i] <= j && i < x)
	{
		if ((num % prime_data[i]) == 0 && prime_data[i] != num)
		{
			return false;
		}
		++i;
	}
	return true;
}

/*void generate_prime_numbers (unsigned int num)
{
	unsigned int maxi = sqrt ((long double)num) + 1;
	prime_data.push_back (2);
	prime_data.push_back (3);
	for (unsigned int i = 5; i <= maxi; i+=2)
	{
		if (is_Prime (i))
		{
			prime_data.push_back (i);
			cout << "Prime " << i << endl;
		}
	}
}*/

void generate_prime_numbers (unsigned int num)
{
	unsigned int sqmaxi = sqrt ((long double)num) + 1;
	prime_data.push_back (2);
	prime_data.push_back (3);
	int mini, maxi;
	for (unsigned int i = 1, mini = (i*6)-1; mini <= sqmaxi; i++, mini = (i*6)-1)
	{
		maxi = (i*6)+1;
		if (is_Prime (mini))
		{
			prime_data.push_back (mini);
			//cout << "Prime " << mini << endl;
		}
		if (is_Prime (maxi))
		{
			prime_data.push_back (maxi);
			//cout << "Prime " << maxi << endl;
		}
	}
}

int main ()
{
	int total = 0;
	cin >> total;
	generate_prime_numbers (1000000000);
	for (int i = 0; i < total; i++)
	{
		unsigned int istart, iend;
		cin >> istart >> iend;
		for (unsigned int j = istart; j <= iend; j++)
		{
			if (is_Prime (j))
			{
				cout << j << endl;
			}
		}
		cout << endl;
	}
	return 0;
}
