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
#include <limits>
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
class FixedPointTheorem
{
public:
	double cycleRange(double R)
	{
		double res, X = 0.25, mini = numeric_limits<double>::max(), maxi = numeric_limits<double>::min();
		for (int i = 0; i < 200000; i++)
			X = (double)R * (double)X * (1 - (double)X);
		for (int i = 0; i < 1000; i++)
		{
			X = (double)R * (double)X * (1 - (double)X);
			mini = min (mini, X);
			maxi = max (maxi, X);
		}
		res = maxi - mini;
		return res;
	}

};
// BEGIN CUT HERE
int main( int argc, char* argv[] )
{
stderr=freopen("Scratch.txt", "w", stderr);
fclose(stdout);
stdout=stderr;
    {
        FixedPointTheorem theObject;
        eq(0, theObject.cycleRange(0.1),0.0);
    }
    {
        FixedPointTheorem theObject;
        eq(1, theObject.cycleRange(3.05),0.14754098360655865);
    }
    {
        FixedPointTheorem theObject;
        eq(2, theObject.cycleRange(3.4499),0.4175631735867292);
    }
    {
        FixedPointTheorem theObject;
        eq(3, theObject.cycleRange(3.55),0.5325704489850351);
    }
    {
        FixedPointTheorem theObject;
        eq(4, theObject.cycleRange(3.565),0.5454276003030636);
    }
    {
        FixedPointTheorem theObject;
        eq(5, theObject.cycleRange(3.5689),0.5489996297493569);
    }
    {
        FixedPointTheorem theObject;
        eq(6, theObject.cycleRange(3.00005),0.004713996108955176);
    }
}
// END CUT HERE
