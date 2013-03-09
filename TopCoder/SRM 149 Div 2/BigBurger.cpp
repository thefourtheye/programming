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
class BigBurger
{
public:
	int maxWait(vector <int> arrival, vector <int> service)
	{
		int res = 0, temp = 0;
		temp = arrival[0] + service[0];
			//fprintf (stderr, "%d\n", temp);
		for (int i = 1; i < arrival.size(); i++)
		{
			res = max (res, temp - arrival[i]);
			temp = (arrival[i]>temp?arrival[i]:temp) + service[i];
			//fprintf (stderr, "%d\n", temp);
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
        int arrivalARRAY[] = {3,3,9};
        vector <int> arrival( arrivalARRAY, arrivalARRAY+ARRSIZE(arrivalARRAY) );
        int serviceARRAY[] = {2,15,14};
        vector <int> service( serviceARRAY, serviceARRAY+ARRSIZE(serviceARRAY) );
        BigBurger theObject;
        eq(0, theObject.maxWait(arrival, service),11);
    }
    {
        int arrivalARRAY[] = {182};
        vector <int> arrival( arrivalARRAY, arrivalARRAY+ARRSIZE(arrivalARRAY) );
        int serviceARRAY[] = {11};
        vector <int> service( serviceARRAY, serviceARRAY+ARRSIZE(serviceARRAY) );
        BigBurger theObject;
        eq(1, theObject.maxWait(arrival, service),0);
    }
    {
        int arrivalARRAY[] = {2,10,11};
        vector <int> arrival( arrivalARRAY, arrivalARRAY+ARRSIZE(arrivalARRAY) );
        int serviceARRAY[] = {3,4,3};
        vector <int> service( serviceARRAY, serviceARRAY+ARRSIZE(serviceARRAY) );
        BigBurger theObject;
        eq(2, theObject.maxWait(arrival, service),3);
    }
    {
        int arrivalARRAY[] = {2,10,12};
        vector <int> arrival( arrivalARRAY, arrivalARRAY+ARRSIZE(arrivalARRAY) );
        int serviceARRAY[] = {15,1,15};
        vector <int> service( serviceARRAY, serviceARRAY+ARRSIZE(serviceARRAY) );
        BigBurger theObject;
        eq(3, theObject.maxWait(arrival, service),7);
    }
}
// END CUT HERE
