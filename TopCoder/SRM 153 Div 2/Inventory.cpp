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

class Inventory
{
public:
	int monthlyOrder(vector <int> sales, vector <int> daysAvailable)
	{
		int zero_count = 0;
		double temp_sum = 0.0;
		for (int i = 0; i < sales.size(); i++)
		{
			if (daysAvailable[i] == 0)
			{
				zero_count++;
				continue;
			}
			double factor = 30.0f/daysAvailable[i];
			temp_sum += (sales[i] * factor);
		}
		temp_sum /= (sales.size() - zero_count);
		if (temp_sum - (int)temp_sum > 1e-9) temp_sum++;
		return (int) temp_sum;
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
        int salesARRAY[] = {5};
        vector <int> sales( salesARRAY, salesARRAY+ARRSIZE(salesARRAY) );
        int daysAvailableARRAY[] = {15};
        vector <int> daysAvailable( daysAvailableARRAY, daysAvailableARRAY+ARRSIZE(daysAvailableARRAY) );
        Inventory theObject;
        eq(0, theObject.monthlyOrder(sales, daysAvailable),10);
    }
    {
        int salesARRAY[] = {75,120,0,93};
        vector <int> sales( salesARRAY, salesARRAY+ARRSIZE(salesARRAY) );
        int daysAvailableARRAY[] = {24,30,0,30};
        vector <int> daysAvailable( daysAvailableARRAY, daysAvailableARRAY+ARRSIZE(daysAvailableARRAY) );
        Inventory theObject;
        eq(1, theObject.monthlyOrder(sales, daysAvailable),103);
    }
    {
        int salesARRAY[] = {8773};
        vector <int> sales( salesARRAY, salesARRAY+ARRSIZE(salesARRAY) );
        int daysAvailableARRAY[] = {16};
        vector <int> daysAvailable( daysAvailableARRAY, daysAvailableARRAY+ARRSIZE(daysAvailableARRAY) );
        Inventory theObject;
        eq(2, theObject.monthlyOrder(sales, daysAvailable),16450);
    }
    {
        int salesARRAY[] = {1115,7264,3206,6868,7301}
           ;
        vector <int> sales( salesARRAY, salesARRAY+ARRSIZE(salesARRAY) );
        int daysAvailableARRAY[] = {1,3,9,4,18};
        vector <int> daysAvailable( daysAvailableARRAY, daysAvailableARRAY+ARRSIZE(daysAvailableARRAY) );
        Inventory theObject;
        eq(3, theObject.monthlyOrder(sales, daysAvailable),36091);
    }
}
// END CUT HERE
//}}}
