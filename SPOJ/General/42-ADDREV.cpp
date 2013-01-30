# include <iostream>
# include <cmath>
using namespace std;
int reverse (int X)
{
	int Y = 0, pos = 0;
	while (X)
	{
		Y *= 10;
		Y += (X % 10);
		X /= 10;
	}
	return Y;
}
int main()
{
	int total, num1, num2;
	cin >> total;
	while (total--)
	{
		cin >> num1 >> num2;
		cout << reverse (reverse (num1) + reverse(num2)) << endl;
	}
}