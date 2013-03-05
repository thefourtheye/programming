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
class YahtzeeScore {
public:
    int maxPoints(vector <int> toss) {
        int res = -1, last = 0, current = -1;
		  sort (toss.begin(), toss.end());
		  for (int i = 0; i < toss.size(); i++)
		  {
			  if (last == toss[i]) current += last;
			  else
			  {
				  res = max (res, current);
				  current = toss[i];
				  last = current;
			  }
		  }
			res = max (res, current);
        return res;
    }

};
// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        int tossARRAY[] = { 2, 2, 3, 5, 4 };
        vector <int> toss( tossARRAY, tossARRAY+ARRSIZE(tossARRAY) );
        YahtzeeScore theObject;
        eq(0, theObject.maxPoints(toss),5);
    }
    {
        int tossARRAY[] = { 6, 4, 1, 1, 3 };
        vector <int> toss( tossARRAY, tossARRAY+ARRSIZE(tossARRAY) );
        YahtzeeScore theObject;
        eq(1, theObject.maxPoints(toss),6);
    }
    {
        int tossARRAY[] = { 5, 3, 5, 3, 3 };
        vector <int> toss( tossARRAY, tossARRAY+ARRSIZE(tossARRAY) );
        YahtzeeScore theObject;
        eq(2, theObject.maxPoints(toss),10);
    }
}
// END CUT HERE
