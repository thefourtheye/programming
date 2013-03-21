//{{{
// BEGIN CUT HERE

// END CUT HERE
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
using namespace std;
// BEGIN CUT HERE
vector<string> split( const string& s, const string& delim =" " ) {
    vector<string> res;
    string t;
    for ( int i = 0 ; i != s.size() ; i++ ) {
        if ( delim.find( s[i] ) != string::npos ) {
            if ( !t.empty() ) {
                res.push_back( t );
                t = "";
            }
        } else {
            t += s[i];
        }
    }
    if ( !t.empty() ) {
        res.push_back(t);
    }
    return res;
}

vector<int> splitInt( const string& s, const string& delim =" " ) {
    vector<string> tok = split( s, delim );
    vector<int> res;
    for ( int i = 0 ; i != tok.size(); i++ )
        res.push_back( atoi( tok[i].c_str() ) );
    return res;
}

#define ARRSIZE(x) (sizeof(x)/sizeof(x[0]))

template<typename T> void print( T a ) {
    cerr << a;
}
static void print( long long a ) {
    cerr << a << "L";
}
static void print( string a ) {
    cerr << '"' << a << '"';
}
template<typename T> void print( vector<T> a ) {
    cerr << "{";
    for ( int i = 0 ; i != a.size() ; i++ ) {
        if ( i != 0 ) cerr << ", ";
        print( a[i] );
    }
    cerr << "}" << endl;
}
template<typename T> void eq( int n, T have, T need ) {
    if ( have == need ) {
        cerr << "Case " << n << " passed." << endl;
    } else {
        cerr << "Case " << n << " failed: expected ";
        print( need );
        cerr << " received ";
        print( have );
        cerr << "." << endl;
    }
}
template<typename T> void eq( int n, vector<T> have, vector<T> need ) {
    if( have.size() != need.size() ) {
        cerr << "Case " << n << " failed: returned " << have.size() << " elements; expected " << need.size() << " elements.";
        print( have );
        print( need );
        return;
    }
    for( int i= 0; i < have.size(); i++ ) {
        if( have[i] != need[i] ) {
            cerr << "Case " << n << " failed. Expected and returned array differ in position " << i << ".";
            print( have );
            print( need );
            return;
        }
    }
    cerr << "Case " << n << " passed." << endl;
}
static void eq( int n, string have, string need ) {
    if ( have == need ) {
        cerr << "Case " << n << " passed." << endl;
    } else {
        cerr << "Case " << n << " failed: expected ";
        print( need );
        cerr << " received ";
        print( have );
        cerr << "." << endl;
    }
}
// END CUT HERE
//}}}
# include <limits>
class MostProfitable
{
public:
	string bestItem(vector <int> costs, vector <int> prices, vector <int> sales, vector <string> items)
	{
		int maxi = numeric_limits<int>::min();
		string res;
		for (int i = 0; i < costs.size(); i++)
		{
			if ((prices[i] - costs[i]) * sales[i] > maxi)
			{
				maxi = (prices[i] - costs[i]) * sales[i];
				res = items[i];
			}
		}
		if (maxi <= 0) res = "";
		return res;
	}
};

//{{{
// BEGIN CUT HERE
int main( int argc, char* argv[] )
{
stderr=freopen("Scratch.txt", "w", stderr);
fclose(stdout);
stdout=stderr;
    {
        int costsARRAY[] = {100,120,150,1000};
        vector <int> costs( costsARRAY, costsARRAY+ARRSIZE(costsARRAY) );
        int pricesARRAY[] = {110,110,200,2000};
        vector <int> prices( pricesARRAY, pricesARRAY+ARRSIZE(pricesARRAY) );
        int salesARRAY[] = {20,100,50,3};
        vector <int> sales( salesARRAY, salesARRAY+ARRSIZE(salesARRAY) );
        string itemsARRAY[] = {"Video Card","256M Mem","CPU/Mobo combo","Complete machine"};
        vector <string> items( itemsARRAY, itemsARRAY+ARRSIZE(itemsARRAY) );
        MostProfitable theObject;
        eq(0, theObject.bestItem(costs, prices, sales, items),"Complete machine");
    }
    {
        int costsARRAY[] = {100};
        vector <int> costs( costsARRAY, costsARRAY+ARRSIZE(costsARRAY) );
        int pricesARRAY[] = {100};
        vector <int> prices( pricesARRAY, pricesARRAY+ARRSIZE(pricesARRAY) );
        int salesARRAY[] = {134};
        vector <int> sales( salesARRAY, salesARRAY+ARRSIZE(salesARRAY) );
        string itemsARRAY[] = {"Service, at cost"};
        vector <string> items( itemsARRAY, itemsARRAY+ARRSIZE(itemsARRAY) );
        MostProfitable theObject;
        eq(1, theObject.bestItem(costs, prices, sales, items),"");
    }
    {
        int costsARRAY[] = {38,24};
        vector <int> costs( costsARRAY, costsARRAY+ARRSIZE(costsARRAY) );
        int pricesARRAY[] = {37,23};
        vector <int> prices( pricesARRAY, pricesARRAY+ARRSIZE(pricesARRAY) );
        int salesARRAY[] = {1000,643};
        vector <int> sales( salesARRAY, salesARRAY+ARRSIZE(salesARRAY) );
        string itemsARRAY[] = {"Letter","Postcard"};
        vector <string> items( itemsARRAY, itemsARRAY+ARRSIZE(itemsARRAY) );
        MostProfitable theObject;
        eq(2, theObject.bestItem(costs, prices, sales, items),"");
    }
    {
        int costsARRAY[] = {10,10};
        vector <int> costs( costsARRAY, costsARRAY+ARRSIZE(costsARRAY) );
        int pricesARRAY[] = {11,12};
        vector <int> prices( pricesARRAY, pricesARRAY+ARRSIZE(pricesARRAY) );
        int salesARRAY[] = {2,1};
        vector <int> sales( salesARRAY, salesARRAY+ARRSIZE(salesARRAY) );
        string itemsARRAY[] = {"A","B"};
        vector <string> items( itemsARRAY, itemsARRAY+ARRSIZE(itemsARRAY) );
        MostProfitable theObject;
        eq(3, theObject.bestItem(costs, prices, sales, items),"A");
    }
}
// END CUT HERE
//}}}
