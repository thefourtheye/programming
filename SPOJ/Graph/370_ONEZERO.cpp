# include <iostream>
# include <cstdio>
# include <queue>
# include <vector>
# include <limits>
# include <ios>
# include <iomanip>
# include <set>
# include <cstring>
using namespace std;
int Input;
const int BASE = 100000;
bool Visited [20000];
struct Node
{
	Node (const char number[], int len = 0, int Rem = 0)
	{
		Len = len;
		Remainder = Rem;
		strcpy (Number, number);
	}
	char Number [50];
	int Len;
	int Remainder;
};
int main(int argc, char const *argv[])
{
	//freopen ("370_ONEZERO_input.txt",  "r", stdin);
	//freopen ("370_ONEZERO_output.txt", "w", stdout);
	int N;
	cin >> N;
	Node current ("");
	queue <Node> Queue;
	for (int i = 0; i < N; i++)
	{
		cin >> Input;
		if (Input == 1) {cout << "1" << endl; continue;}
		memset(Visited, false, sizeof(Visited));
		Queue.push (Node ( "10", 2, 10 % Input));
		Queue.push (Node ( "11", 2, 11 % Input));
		while (!Queue.empty())
		{
			current = Queue.front(); Queue.pop();
			//cout << "Popping " << current.Number << endl;
			if (Visited[current.Remainder]) continue;
			Visited[current.Remainder] = true;
			if (current.Remainder)
			{
				current.Number[current.Len++] = '0';
				current.Remainder *= 10;
				current.Remainder %= Input;
				current.Number[current.Len] = '\0';
				Queue.push (current);
				current.Number[current.Len-1] = '1';
				current.Remainder = (current.Remainder + 1) % Input;
				Queue.push (current);
			}
			else
			{
				current.Number [current.Len] = '\0';
				cout << current.Number << endl;
				while (!Queue.empty()) Queue.pop();
			}
		}
	}
	return 0;
}