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
# include <ctime>
using namespace std;
#define uint unsigned int
class RapidIO
{
private:
	const static uint max_read_buffer_size  = 16777216;
	const static uint max_write_buffer_size = 16777216;
	//const static uint max_read_buffer_size  = 16;
	//const static uint max_write_buffer_size = 16;
	uint current_read_position;
	uint current_write_position;
	uint bytes_read_last_time;
	uint8_t * read_buffer;
	uint8_t * write_buffer;
	FILE * in, * out;
	void read_stream()
	{
		//cout << "Entering read_stream with current_read_position : " << current_read_position << ", bytes_read_last_time : " << bytes_read_last_time << endl;
		if (current_read_position >= bytes_read_last_time)
		{
			current_read_position = 0;
			bytes_read_last_time = fread (read_buffer, 1, max_read_buffer_size-1, in);
		}
		//cout << "Leaving read_stream with current_read_position : " << current_read_position << ", bytes_read_last_time : " << bytes_read_last_time << endl;
	}
	void write_stream(bool flushed = false)
	{
		if (current_write_position >= max_write_buffer_size)
		{
			fwrite (write_buffer, 1, max_write_buffer_size, out);
			current_write_position = 0;
		}
		else if (flushed)
		{
			fwrite (write_buffer, 1, current_write_position - 1, out);
			current_write_position = 0;
		}
	}
public:
	~RapidIO()
	{
		delete read_buffer;
		delete write_buffer;
	}
	RapidIO(FILE * _in = stdin, FILE * _out = stdout)
	{
		current_read_position  = 0;
		bytes_read_last_time   = 0;
		current_write_position = 0;
		read_buffer  = new uint8_t[max_read_buffer_size];
		write_buffer = new uint8_t[max_write_buffer_size];
		in  = _in;
		out = _out;
	}
	char getchar(string invalid_chars = "\n")
	{
		//cout << "Entering getchar with current_read_position : " << current_read_position << ", bytes_read_last_time : " << bytes_read_last_time << endl;
		string return_value   = "";
		bool   reached_end    = false;
		uint   len_separators = invalid_chars.size();
		while (!reached_end)
		{
			read_stream();
			for (;current_read_position < bytes_read_last_time && !reached_end; current_read_position++)
			{
				bool found_invalid = false;
				for (int i = 0; i < len_separators; i++)
				{
					if (read_buffer[current_read_position] == invalid_chars[i])
					{
						found_invalid = true;
						break;
					}
				}
				if (!found_invalid)
				{
					//cout << "Leaving getchar with current_read_position : " << current_read_position << ", bytes_read_last_time : " << bytes_read_last_time << endl;
					return read_buffer[current_read_position++];
				}
			}
		}
	}
	string getline(string str_sep = "\n")
	{
		//cout << "Entering getline with current_read_position : " << current_read_position << ", bytes_read_last_time : " << bytes_read_last_time << endl;
		string return_value   = "";
		bool   reached_end    = false;
		uint   len_separators = str_sep.size();
		while (!reached_end)
		{
			read_stream();
			if (current_read_position == bytes_read_last_time) break;
			for (;current_read_position < bytes_read_last_time && !reached_end; current_read_position++)
			{
				for (int i = 0; i < len_separators; i++)
				{
					if (read_buffer[current_read_position] == str_sep[i])
					{
						reached_end = true;
						break;
					}
				}
				if (!reached_end)
					return_value.push_back (read_buffer[current_read_position]);
			}
		}
		if (read_buffer[current_read_position - 1] != '\n') current_read_position--;
		//cout << "Leaving getline with current_read_position : " << current_read_position << ", bytes_read_last_time : " << bytes_read_last_time << endl;
		return return_value;
	}
	void writeline (string str, bool new_line_at_end = true)
	{
		writeline (str.c_str(), str.length(), new_line_at_end);
	}
	void writeline (const char * str, int len, bool new_line_at_end = true)
	{
		for (int i = 0; i < len; i++)
		{
			if (current_write_position >= max_write_buffer_size)
				write_stream();
			write_buffer[current_write_position++] = str[i];
		}
		if (new_line_at_end)
		{
			if (current_write_position >= max_write_buffer_size)
				write_stream();
			write_buffer[current_write_position++] = '\n';
		}
	}
	void flush()
	{
		write_stream (true);
	}
};

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
	FILE * fp = fopen ("input.txt", "r");
	FILE * fp1 = fopen ("output.txt", "w");
	RapidIO io (fp, fp1);
	unsigned long start_time = clock();
	cout << "Starting at " << start_time << endl;
	//RapidIO io;
	string total_lines = io.getline ();
	int total = atoi (total_lines.c_str());
	//scanf ("%d", &total); //cin >> total;
	//cin.clear();
	string result;
	while (total-- > 0)
	{
		//char str_temp[1024];
		//string input;
		//cin >> input;
		//gets (str_temp);
		//string input(str_temp);
		//string input = io.getline();
		string num1 = io.getline("*-+");
		char op = io.getchar();
		string num2 = io.getline();

		/*if (input.find ("+") != string::npos)
			op = '+';
		else if (input.find ("-") != string::npos)
			op = '-';
		else if (input.find ("*") != string::npos)
			op = '*';
		stringstream ss (input);
		getline (ss, num1, op);
		getline (ss, num2, op);*/
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
			//result += res[i] + "\n";
			//printf("%s\n", res[i].c_str());
			io.writeline (res[i]);
		}
		io.writeline ("");
	}
	io.writeline ("");
	io.flush();
	//unsigned int len = result.size();
	//write (1, result.c_str(), len);
	//cout << endl;
	unsigned long end_time = clock();
	cout << "Ending at " << end_time << endl;
	cout << "Actual Time Taken : " << (end_time - start_time) << " Ticks" << endl;
	fclose(fp1);
	fclose(fp);
	return 0;
}