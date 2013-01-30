#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
 
#define EPS 1e-11
#define inf ( 1LL << 31 ) - 1
#define LL long long
 
#define abs(x) (((x)< 0) ? (-(x)) : (x))
#define all(x) (x).begin(), (x).end()
#define ms(x, a) memset((x), (a), sizeof(x))
 
#define mp make_pair
#define pb push_back
#define sz(k) (int)(k).size()

using namespace std;

typedef vector <int> vi;
stack <char> charstack;
int main ()
{
	int total;
	cin >> total;
	while (total-- > 0)
	{
		string expn;
		cin >> expn;
		for (int i = 0; i < expn.length(); i++)
		{
			if (expn[i] >= 'a' && expn[i] <= 'z')
			{
				cout << expn[i];
			}
			else if (expn[i] == ')')
			{
				while (charstack.top() != '(')
				{
					cout << charstack.top();
					charstack.pop();
				}
				charstack.pop();
			}
			else
			{
				charstack.push (expn[i]);
			}
		}
		while (!charstack.empty())
		{
			cout << charstack.top();
			charstack.pop();
		}
		cout << endl;
	}
	return 0;
}
