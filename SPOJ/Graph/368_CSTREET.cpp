# include <iostream>
# include <cstdio>
# include <map>
# include <vector>
# include <set>
# include <bitset>
# include <utility>
# include <queue>
# include <algorithm>
# include <limits>
# define uint unsigned int
using namespace std;
map <uint, vector <pair <uint, uint> > > Edges;
bitset <1001> Visited;
uint Distances [10001];
uint T, Price, Buildings, Streets, A, B, C, ResultPrice = 0;
bool FindLesserPair (pair <int, int> A, pair <int, int> B)
{
	if (!Visited [B.first] && !Visited[A.first])
	{
		return (A.second < B.second);
	}
	return !Visited [A.first];
}
struct FindGreaterObject
{
	bool operator () (pair <uint, pair <uint, int> > & A, pair <uint, pair <uint, int> > & B) const
	{
		return A.first > B.first;
	}
};
priority_queue< pair <uint, pair <uint, int> >, vector<pair <uint, pair <uint, int> > >, FindGreaterObject > MinPriorityQueue;
int main(int argc, char const *argv[])
{
	//freopen ("368_CSTREET_input.txt", "r", stdin);
	//freopen ("368_CSTREET_output.txt", "w", stdout);
	scanf ("%d", &T);
	for (uint i = 0; i < T; i++)
	{
		scanf ("%d%d%d", &Price, &Buildings, &Streets);
		while (!MinPriorityQueue.empty()) MinPriorityQueue.pop();
		Edges.clear(); Visited.reset(); ResultPrice = 0;
		fill (Distances, Distances + 10001, numeric_limits<uint>::max());
		for (uint j = 0; j < Streets; j++)
		{
			scanf ("%d%d%d", &A, &B, &C);
			Edges [A].push_back (make_pair (B, C));
			Edges [B].push_back (make_pair (A, C));
		}
		Visited [1] = true;
		Distances [1] = 0;
		//pair<int, int> MinPair = *min_element (Edges [1].begin(), Edges [1].end(), FindLesserPair);
		//cout << "MinPair for " << 1 << " is [" << MinPair.first << "," << MinPair.second << "]" << endl;
		for (vector <pair <uint, uint> >::iterator it = Edges [1].begin(); it != Edges [1].end(); it++)
			MinPriorityQueue.push (make_pair ((*it).second, make_pair (1, (*it).first)));
		while (!MinPriorityQueue.empty())
		{
			pair <uint, pair <uint, uint> > current = MinPriorityQueue.top();
			MinPriorityQueue.pop();
			if (Visited [current.second.first] && Visited [current.second.second]) continue;
			//cout << "Popping [" << current.second.first << "," << current.second.second << "]" << endl;
			Visited [current.second.first]  = true;
			Visited [current.second.second] = true;
			Distances [current.second.second] = current.first;
			//MinPair = *min_element (Edges [current.second.second].begin(), Edges [current.second.second].end(), FindLesserPair);
			//cout << "MinPair for " << current.second.second << " is [" << MinPair.first << "," << MinPair.second << "]" << endl;
			for (vector <pair <uint, uint> >::iterator it = Edges [current.second.second].begin(); it != Edges [current.second.second].end(); it++)
				if (!Visited [(*it).first])
					MinPriorityQueue.push (make_pair ((*it).second, make_pair (current.second.second, (*it).first)));
				//MinPriorityQueue.push (make_pair (MinPair.second, make_pair (current.second.second, MinPair.first)));
		}
		uint VisitedCount = 0, CurrentPrice, Sz;
		for (int i = 1; i <= Buildings; i++)
		{
			//cout << Distances [i] << endl;
			ResultPrice += Distances [i];
		}
		printf ("%u\n", (ResultPrice * Price));
	}
	return 0;
}