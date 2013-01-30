# include <iostream>
# include <bitset>
# include <map>
# include <cstdio>
# include <queue>
using namespace std;
# define MAXVALUE 2001
bitset <MAXVALUE> Marked;
bitset <MAXVALUE> Color;
map <int, vector <int> > Table ;
queue <int> Queue;
int main(int argc, char const *argv[])
{
	//freopen ("3377_BUGLIFE_input.txt",  "r", stdin);
	//freopen ("3377_BUGLIFE_output.txt", "w", stdout);
	int N, Bugs, Interactions, A, B; bool Homo = false;
	scanf ("%d", &N);
	for (int i = 0; i < N; i++)
	{
		Marked.reset(); Color.reset(); Table.clear();
		scanf ("%d%d", &Bugs, &Interactions);
		Homo = false;
		for (int j = 0; j < Interactions; j++)
		{
			scanf ("%d%d", &A, &B);
			Table [A].push_back (B);
			Table [B].push_back (A);
		}
		for (map <int, vector <int> >::iterator it1 = Table.begin(); it1 != Table.end() && !Homo; it1++)
		{
			if (Marked [it1->first]) continue;
			Marked [it1->first] = true;
			Queue.push (it1->first);
			while (!Queue.empty() && !Homo)
			{
				int current = Queue.front();
				Queue.pop();
				//cout << "Current : " << current << endl;
				for (vector<int>::iterator it = Table[current].begin(); it != Table[current].end() && !Homo; it++)
				{
					//cout << "Neighbour : " << *it << endl;
					if (Marked[*it])
						Homo = (Color [current] == Color [*it]);
					else
					{
						//cout << "Marking : " << *it << " with " << !Color [current] << endl;
						Color [*it] = !Color [current];
						Marked[*it] = true;
						Queue.push (*it);
					}
				}
			}
		}
		while (!Queue.empty()) Queue.pop();
		printf ("Scenario #%d:\n", i+1);
		if (Homo)
			printf ("Suspicious bugs found!\n");
		else
			printf ("No suspicious bugs found!\n");
	}
	return 0;
}