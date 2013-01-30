# include <iostream>
using namespace std;

int idx = 199, result_digits [101][200] = {0};
unsigned long carry = 0, temp;
int main(int argc, char const *argv[])
{
	result_digits[0][199] = 1;
	result_digits[1][199] = 1;
	result_digits[2][199] = 2;
	result_digits[3][199] = 6;
	for (int num = 4; num <= 100; num++)
	{
		carry = 0;
		for (int i = 199; i >= 0; i--)
		{
			temp = result_digits[num-1][i] * num + carry;
			result_digits[num][i] = temp % 10;
			carry = temp / 10;
		}
	}
	int total, num;
	cin >> total;
	while (total--)
	{
		cin >> num;
		bool begun = false;
		for (int i = 0; i < 200; i++)
		{
			if (result_digits[num][i] != 0 && !begun) begun = true;
			if (begun) cout << result_digits[num][i];
		}
		cout << endl;
	}
	return 0;
}