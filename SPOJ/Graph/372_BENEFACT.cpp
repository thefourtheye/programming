# include <iostream>
# include <cstdio>
# include <limits>
# include <bitset>
# include <algorithm>
# include <utility>
# include <map>
# include <queue>
# include <stack>
using namespace std;
# define MAXVALUE 50001
unsigned long long MAXIMUM = numeric_limits <unsigned long long>::max();
unsigned long long MINIMUM = numeric_limits <unsigned long long>::min();
bitset <MAXVALUE> Visited;
map <int, vector <pair <int, unsigned long long> > > Pairs;
/*struct Node
{
	Node (int x = 0, int y = 0, unsigned long long dist = MAXIMUM) {X = x; Y = y; Distance = dist;}
	int X, Y,; unsigned long long Distance;
};*/
/*struct Node
{
	Node (int y = 0, unsigned long long dist = MAXIMUM) {Y = y; Distance = dist;}
	int Y; unsigned long long Distance;
};*/
stack <pair <int, unsigned long long> > Q;
int main(int argc, char const *argv[])
{
	//freopen ("372_BENEFACT_input.txt",  "r", stdin);
	//freopen ("372_BENEFACT_output.txt", "w", stdout);
	int t, NPlaces, A, B, C;
	scanf ("%d", &t);
	//cout << "Read T : " << t << endl;
	while (t--)
	{
		Visited.reset(); Pairs.clear();
		scanf ("%d", &NPlaces);
		//cout << "Read NPlaces : " << NPlaces << endl;
		for (int XX = 0; XX < NPlaces - 1; XX++)
		{
			scanf ("%d%d%d", &A, &B, &C);
			Pairs[A].push_back (make_pair (B, C));
			Pairs[B].push_back (make_pair (A, C));
		}
		//cout << "Read Inputs" << endl;
		pair <int, unsigned long long> BestNode, Current;
		BestNode = make_pair (1, MINIMUM);
		Q.push (make_pair (1, 0));
		while (!Q.empty())
		{
			//Current = Q.front(); Q.pop();
			Current = Q.top(); Q.pop();
			if (Visited [Current.first]) continue;
			if (Current.second > BestNode.second) BestNode = Current;
		//	cout << "Popping " << Current.first << ", " << Current.second << endl;
			Visited [Current.first] = true;
			for (vector <pair <int, unsigned long long> >::iterator it = Pairs[Current.first].begin(); it != Pairs[Current.first].end(); it++)
				Q.push (make_pair ((*it).first, (*it).second + Current.second));
		}
		//cout << "MAXIMUM : " << BestNode.first << "," << BestNode.second << endl;
		Visited.reset();
		BestNode.second = 0;Q.push (BestNode);BestNode.second = MINIMUM;
		while (!Q.empty())
		{
			//Current = Q.front(); Q.pop();
			Current = Q.top(); Q.pop();
			if (Visited [Current.first]) continue;
			if (Current.second > BestNode.second) BestNode = Current;
			//cout << "Popping 1 " << Current.first << ", " << Current.second << endl;
			Visited [Current.first] = true;
			for (vector <pair <int, unsigned long long> >::iterator it = Pairs[Current.first].begin(); it != Pairs[Current.first].end(); it++)
				Q.push (make_pair ((*it).first, (*it).second + Current.second));
		}
		cout << BestNode.second << endl;
	}
	return 0;
}