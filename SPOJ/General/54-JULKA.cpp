# include <iostream>
# include <vector>
# include <string>
# include <cstdlib>
# include <cstdio>
using namespace std;
vector<string> process(string num1, string num2)
{
	string result = "", result1 = "", result2 = "";
	int carry = 0;
	for (int x = num1.size() - 1, y = num2.size() - 1; ; x >= 0 ? x-- : x, y >= 0 ? y-- : y)
	{
		if (x < 0 && y < 0 && !carry) break;
		int x1 = 0, y1 = 0, res = 0;
		if (x >= 0) x1 = num1[x] - 48;
		if (y >= 0) y1 = num2[y] - 48;
		res = x1 + y1 + carry;
		//cout << "Add res : " << res << endl;
		carry = res / 10;
		if (carry)
			res %= 10;
		result.insert (0, string(1, res + 48));
	}
	//cout << "Add : " << result << endl;
	carry = 0;
	for (int x = 0; x < result.size(); x++)
	{
		int num = result[x] - 48;
		if (carry != 0)
		{
			num = 10;
			num += (result[x] - 48);
		}
		carry = num % 2;
		num = num / 2;
		char num_str [100];
		sprintf (num_str, "%d", num);
		//itoa (num, num_str, 10);
		//cout << "num is " << num << ", num_str is " << num_str << endl;
		result1.insert (result1.size(), num_str);
	}
	while (result1[0] == '0')
	{
		result1.erase (0, 1);
	}
	if (result1 == "")
	{
		result1 = "0";
	}
	//cout << "Divide : " << result1 << endl;
	carry = 0;
	for (int x = num1.size() - 1, y = result1.size() - 1; ; x >= 0 ? x-- : x, y >= 0 ? y-- : y)
	{
		if (x < 0 && y < 0 && !carry) break;
		int x1 = 0, y1 = 0, res = 0;
		if (x >= 0) x1 = num1[x] - 48;
		if (y >= 0) y1 = result1[y] - 48;
		res = x1 - y1 - carry;
		if (res < 0)
		{
			carry = 1;
			res += 10;
		}
		else
		{
			carry = 0;
		}
		//if (!(x <= 0 && y <= 0 && !carry))
			result2.insert (0, string (1, res + 48));
	}
	while (result2[0] == '0')
	{
		result2.erase (0, 1);
	}
	if (result2 == "")
	{
		result2 = "0";
	}
	//cout << "Subtract : " << result2 << endl;
	vector <string> res_vec;
	res_vec.push_back (result1);
	res_vec.push_back (result2);
	return res_vec;
}
int main(int argc, char const *argv[])
{
	for (int i = 0; i < 10; i++)
	{
		string num1, num2;
		cin >> num1 >> num2;
		vector <string> res = process (num1, num2);
		cout << res[0] << endl;
		cout << res[1] << endl;
	}
	return 0;
}