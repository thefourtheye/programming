# include <iostream>
# include <sstream>
# include <string>
# include <vector>
# include <cstdlib>
# include <cstdio>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <inttypes.h>
using namespace std;
vector<string> subtract (string num1, string num2)
{
	vector<string> res;
	int ss1 = num1.size(), ss2 = num2.size();
	int mx = max (ss1, ss2);
	string nu1 = num1, nu2 = num2;
	if (ss1 > ss2)
	{
		string nu3 = nu2;
		nu2 = "";
		nu2.append (ss1 - ss2, '0');
		nu2.append (nu3);
	}
	int carry = 0;
	string diff = "";
	for (int i = mx - 1; i >= 0; i--)
	{
		int x = nu1[i] - nu2[i] - carry;
		if (x < 0)
		{
			carry = 1;
			x += 10;
		}
		else
		{
			carry = 0;
		}
		diff = string(1, x + 48) + diff;
	}
	ss2++;
	int new_max =  max (ss2, max (ss1, (int)diff.size()));
	string str_res = "";
	str_res.append (new_max, '-');
	num1.insert (0, new_max - ss1, ' ');
	num2 = "-" + num2;
	num2.insert (0, new_max - ss2, ' ');
	diff.insert  (0, new_max - diff.size(), ' ');
	res.push_back (num1);
	res.push_back (num2);
	res.push_back (str_res);
	int len = diff.size();
	for (int i = 0; i < len; i++)
	{
		if (diff[i] != '0' && diff[i] != ' ')
		{
			break;
		}
		diff [i] = ' ';
		if (i + 1 == len)
		{
			diff [i] = '0';
		}
	}
	res.push_back (diff);
	return res;
}
vector<string> add (string num1, string num2)
{
	vector<string> res;
	int ss1 = num1.size(), ss2 = num2.size();
	int mx = max (ss1, ss2);
	string nu1 = num1, nu2 = num2;
	if (ss1 < ss2)
	{
		string nu3 = nu1;
		nu1 = "";
		nu1.append (ss2 - ss1, '0');
		nu1.append (nu3);
	}
	else if (ss1 > ss2)
	{
		string nu3 = nu2;
		nu2 = "";
		nu2.append (ss1 - ss2, '0');
		nu2.append (nu3);
	}
	int carry = 0;
	string diff = "";
	for (int i = mx - 1; i >= 0; i--)
	{
		int x = nu1[i] + nu2[i] - 96 + carry;
		if (x > 9)
		{
			carry = 1;
			x %= 10;
		}
		else
		{
			carry = 0;
		}
		diff = string(1, x + 48) + diff;
	}
	if (carry)
	{
		diff = string(1, '1') + diff;
	}
	ss2++;
	int new_max =  max (ss2, max (ss1, (int)diff.size()));
	string str_res = "";
	str_res.append (new_max, '-');
	num1.insert (0, new_max - ss1, ' ');
	num2 = "+" + num2;
	num2.insert (0, new_max - ss2, ' ');
	diff.insert  (0, new_max - diff.size(), ' ');
	res.push_back (num1);
	res.push_back (num2);
	res.push_back (str_res);
	res.push_back (diff);
	return res;
}
void processforzero (string & str, int level)
{
	int len = str.size();
	for (int i = 0; i < len; i++)
		if (str[i] != '0' && str[i] != ' ') return;
	len = len - level - 1;
	for (int i = 0; i < len; i++)
		str[i] = ' ';
}
vector<string> multiply (string num1, string num2)
{
	vector<string> res;
	int ss1 = num1.size(), ss2 = num2.size();
	string nu1 = num1, nu2 = num2;
	int carry = 0;
	string cproduct = "", tproduct = "";
	int maxlevel = max (ss1, ss2 + 1), level = 0;
	vector<string> int_res;
	for (int i = ss2 - 1; i >= 0; i--)
	{
		carry = 0;
		cproduct = "";
		for (int j = ss1 - 1; j >= 0; j--)
		{
			int x = (nu1[j] - 48) * (nu2[i] - 48) + carry;
			if (x > 9)
			{
				carry = (x/10);
				x %= 10;
			}
			else
			{
				carry = 0;
			}
			cproduct = string(1, x + 48) + cproduct;
		}
		while (carry)
		{
			cproduct = string(1, (carry % 10) + 48) + cproduct;
			carry /= 10;
		}
		cproduct.append (level++, '0');
		int_res.push_back (cproduct);
		maxlevel = max ((int)cproduct.size(), maxlevel);
	}
	ss2++;
	int new_max =  max (ss2, max (ss1, maxlevel));
	string str_res = "";
	num2 = "*" + num2;
	if (ss2-1 == 1)
	{
		str_res.append (new_max, '-');
		num1.insert (0, new_max - ss1, ' ');
		num2.insert (0, new_max - ss2, ' ');
		str_res.insert (0, new_max - str_res.size(), ' ');
		cproduct.insert (0, new_max - cproduct.size(), ' ');
		res.push_back (num1);
		res.push_back (num2);
		res.push_back (str_res);
		res.push_back (cproduct);
	}
	else
	{
		int first_line = max (ss1, max (ss2, (int) int_res[0].size()));
		num1.insert (0, new_max - ss1, ' ');
		num2.insert (0, new_max - ss2, ' ');
		str_res.append (first_line, '-');
		str_res.insert (0, new_max - str_res.size(), ' ');
		res.push_back (num1);
		res.push_back (num2);
		res.push_back (str_res);
		string res1 = "0";
		for (int i = 0 ; i < int_res.size(); i++)
		{
			//cout << "Adding : " << tproduct << " and " << int_res[i] << endl;
			vector<string> temp_res = add (tproduct, int_res[i]);
			string temp = int_res[i];
			//cout << "Getting " << temp << endl;
			processforzero(temp, i);
			if (new_max - temp.size() > 0)
				temp.insert (0, new_max - temp.size(), ' ');
			if (i > 0)
			{
				temp.replace (temp.size()-i, i, i, ' ');
			}
			//cout << "Before Pushing " << temp << endl;
			res.push_back (temp);
			tproduct = temp_res[3];
			//cout << "Sum Result is : " << tproduct << endl;
			while (tproduct.size() > 0 && (tproduct[0] == '0' || tproduct[0] == ' '))
			{
				tproduct.erase (0,1);
			}
			if (tproduct == "") tproduct = "0";
			//cout << "Inter Sum : " << tproduct << endl;
		}
		while (tproduct.size() > 0 && (tproduct[0] == '0' || tproduct[0] == ' '))
		{
			tproduct.erase (0,1);
		}
		//cout << "Total Sum is : " << tproduct << endl;
		int new_line_size = max(new_max, max ((int)tproduct.size(), (int)int_res[(int)int_res.size()-1].size()));
		string new_line = "";
		new_line.append (new_line_size, '-');
		int xy = 0;
		int tsize = tproduct.size();
		while (xy < (new_max - tsize))
		{
			new_line [xy++] = ' ';
		}
		if (new_line_size - tsize > 0)
			tproduct.insert (0, new_line_size - tsize, ' ');
		res.push_back (new_line);
		res.push_back (tproduct);
	}
	return res;
}
int main(int argc, char const *argv[])
{
	int total ;
	char total_lines[1024];
	gets (total_lines);
	total = atoi (total_lines);
	//scanf ("%d", &total); //cin >> total;
	//cin.clear();
	string result;
	while (total-- > 0)
	{
		char str_temp[1024];
		//string input;
		//cin >> input;
		gets (str_temp);
		string input(str_temp);
		string num1, num2;
		char op;
		if (input.find ("+") != string::npos)
			op = '+';
		else if (input.find ("-") != string::npos)
			op = '-';
		else if (input.find ("*") != string::npos)
			op = '*';
		stringstream ss (input);
		getline (ss, num1, op);
		getline (ss, num2, op);
		//cout << "Input : " << input << ", Num 1 : " << num1 << ", Num 2 : " << num2 << ", Operation : " <<  op << endl;
		vector<string> res;
		if (op == '+')
			res = add (num1, num2);
		else if (op == '-')
			res = subtract (num1, num2);
		else
			res = multiply (num1, num2);
		int len = res.size();
		for (int i = 0; i < len; i++)
		{
			//cout << res[i] << endl;
			//puts (res[i].c_str());
			result += res[i] + "\n";
			//printf("%s\n", res[i].c_str());
		}
	}
	unsigned int len = result.size();
	write (1, result.c_str(), len);
	//cout << endl;
	return 0;
}