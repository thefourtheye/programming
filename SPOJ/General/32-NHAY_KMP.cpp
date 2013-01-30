# include <iostream>
# include <string>
# include <cstdlib>
# include <cstdio>
using namespace std;
#define uint unsigned int
class RapidIO
{
private:
	//const static uint max_read_buffer_size  = 16777216;
	//const static uint max_write_buffer_size = 16777216;
	const static uint max_read_buffer_size  = 35536;
	const static uint max_write_buffer_size = 35536;
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
	void writeline (unsigned long long num, bool new_line_at_end = true)
	{
		unsigned long long num1 = num;
		string str = "";
		if (num1 == 0)
			str = "0";
		while (num1)
		{
			str.insert (0,  string(1, (char)(num1 % 10)+48));
			num1 /= 10;
		}
		writeline (str.c_str(), str.length(), new_line_at_end);
	}
	void writeline (string str, bool new_line_at_end = true)
	{
		//cout << "String : " << str << ", Length : " << str.length() << endl;
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
int TArray[10000] = {0};
int main(int argc, char const *argv[])
{
	freopen ("input_nhay.txt","r",stdin);
	freopen ("output_nhay.txt","w",stdout);
	RapidIO io;
	while (1)
	{
		string total_str = io.getline();
		//cout << "total_str : " << total_str << endl;
		//io.writeline (total_str);
		if (total_str == "")
			break;
		string sub_string = io.getline();
		string ori_string = io.getline();
		//cout << (sub_string + " " + ori_string) << endl;
		//io.writeline (sub_string + " " + ori_string);
		if (sub_string.length() > ori_string.length())
		{
			io.writeline ("");
			continue;
		}
		bool match = false;
		int current_sub_str_index = 0, current_org_str_index = 0, len_sub = sub_string.length(), len_org = ori_string.length();
		TArray [0] = -1;
		int temp = 0;
		if (len_sub > 2)
		{
			current_sub_str_index = 2;
			while (current_sub_str_index + temp < len_sub)
			{
				if (sub_string [current_sub_str_index + temp] == sub_string [temp])
				{
					TArray [current_sub_str_index + temp] = temp;
					temp++;
				}
				else
				{
					if (temp == 0)
						current_sub_str_index++;
					else
					{
						current_sub_str_index += temp;
						TArray [current_sub_str_index] = temp;
						temp = TArray [temp];
					}
				}
			}
		}
		/*for (int i = 0; i < len_sub; i++)
			cout << TArray [i];
		cout << endl;*/
		current_sub_str_index = 0;
		current_org_str_index = 0;
		temp = 0;
		match = false;
		while (current_org_str_index + temp < len_org)
		{
			if (current_sub_str_index < len_sub && ori_string[current_org_str_index + temp] == sub_string[current_sub_str_index])
			{
				if (current_sub_str_index == len_sub - 1)
				{
					//cout << "Solution : " << current_org_str_index << endl;
					io.writeline (current_org_str_index);
					current_org_str_index += TArray[temp] + 1;
					current_sub_str_index = 0;
					temp = 0;
					match = true;
				}
				else
				{
					temp++;
					current_sub_str_index++;
				}
			}
			else
			{
				current_org_str_index += temp - TArray [current_sub_str_index];
				if (current_sub_str_index > 0)
					current_sub_str_index = TArray [current_sub_str_index];
			}
		}
		//cout << current_sub_str_index << " " << temp << " " << current_org_str_index << " " << sub_string << endl;
		/*if ((ori_string[current_org_str_index + temp - 1] == sub_string[current_sub_str_index - 1]) && (current_sub_str_index == len_sub))
		{
			io.writeline (current_org_str_index);
			match = true;
		}*/
		if (!match)
		{
			io.writeline ("");
		}
	}
	io.flush();
	return 0;
}