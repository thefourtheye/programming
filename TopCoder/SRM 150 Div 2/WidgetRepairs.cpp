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
class WidgetRepairs
{
public:
	int days(vector <int> arrivals, int numPerDay)
	{
		int res = 0, temp = 0;
		for (int i = 0; i < arrivals.size(); i++)
		{
			temp += arrivals[i];
			if (temp) res++;
			temp -= numPerDay;
			if (temp < 0) temp = 0;
		}
		while (temp > 0)
		{
			res++;
			temp -= numPerDay;
		}
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
        int arrivalsARRAY[] = { 10, 0, 0, 4, 20 };
        vector <int> arrivals( arrivalsARRAY, arrivalsARRAY+ARRSIZE(arrivalsARRAY) );
        WidgetRepairs theObject;
        eq(0, theObject.days(arrivals, 8),6);
    }
    {
        int arrivalsARRAY[] = { 0, 0, 0 };
        vector <int> arrivals( arrivalsARRAY, arrivalsARRAY+ARRSIZE(arrivalsARRAY) );
        WidgetRepairs theObject;
        eq(1, theObject.days(arrivals, 10),0);
    }
    {
        int arrivalsARRAY[] = { 100, 100 };
        vector <int> arrivals( arrivalsARRAY, arrivalsARRAY+ARRSIZE(arrivalsARRAY) );
        WidgetRepairs theObject;
        eq(2, theObject.days(arrivals, 10),20);
    }
    {
        int arrivalsARRAY[] = { 27, 0, 0, 0, 0, 9 };
        vector <int> arrivals( arrivalsARRAY, arrivalsARRAY+ARRSIZE(arrivalsARRAY) );
        WidgetRepairs theObject;
        eq(3, theObject.days(arrivals, 9),4);
    }
    {
        int arrivalsARRAY[] = { 6, 5, 4, 3, 2, 1, 0, 0, 1, 2, 3, 4, 5, 6 };
        vector <int> arrivals( arrivalsARRAY, arrivalsARRAY+ARRSIZE(arrivalsARRAY) );
        WidgetRepairs theObject;
        eq(4, theObject.days(arrivals, 3),15);
    }
}
// END CUT HERE
