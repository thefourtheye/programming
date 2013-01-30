//Classic Vertex Cover Problem
# include <iostream>
# include <cstring>
# include <cstdio>
# include <vector>
# include <limits>
# include <queue>
using namespace std;
vector <int> Nodes [100000];
int Degrees [100000];
int main(int argc, char const *argv[])
{
	//freopen ("1435_PT07X_input.txt",  "r", stdin);
	//freopen ("1435_PT07X_output.txt",  "w", stdout);
	int N, A, B, Ans;
	cin >> N;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> A >> B;
		A--; B--;Nodes [A].push_back (B); Nodes [B].push_back (A); Degrees [A]++; Degrees [B]++;
	}
	int Result = 0;
	queue <int> Queue;
	for (int i = 0; i < N; i++)
		if (Degrees [i] == 1) Queue.push (i);
	while (!Queue.empty())
	{
		int current = Queue.front(); Queue.pop();
		if (Degrees [current] != 1) continue;
		Result++;
		int Parent = -1;
		for(int i = 0; i < (int)Nodes[current].size(); i++)
			if(Degrees [Nodes[current][i]] > 0)
				Parent = Nodes[current][i];
		//assert(Parent != -1);
		Degrees [Parent] = 0;
		for (int i = 0; i < Nodes [Parent].size(); i++)
			if (--Degrees [Nodes[Parent][i]])
				Queue.push (Nodes[Parent][i]);
	}
	cout << Result << endl;
}