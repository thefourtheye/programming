# include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int total;
	cin >> total;
	while (total--)
	{
		unsigned int num, result = 0;
		cin >> num;
		while (num >= 5)
		{
			num /= 5;
			result += num;
		}
		cout << result << endl;
	}
	return 0;
}