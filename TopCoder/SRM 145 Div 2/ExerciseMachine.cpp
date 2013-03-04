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

// BEGIN CUT HERE
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
class ExerciseMachine {
public:
    int getPercentages(string time) {
        int res = 0, total_seconds = 0, curr_seconds = 3600;
		  vector <int> time_int = splitInt (time, ":");
		  for (int i = 0 ; i < time_int.size(); i++)
		  {
			  total_seconds += time_int[i] * curr_seconds;
			  curr_seconds /= 60;
		  }
		  for (int i = 1; i < 100; i++)
			  if ((total_seconds * i) % 100 == 0) res++;
		  return res;
    }

};
// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        ExerciseMachine theObject;
        eq(0, theObject.getPercentages("00:30:00"),99);
    }
    {
        ExerciseMachine theObject;
        eq(1, theObject.getPercentages("00:28:00"),19);
    }
    {
        ExerciseMachine theObject;
        eq(2, theObject.getPercentages("23:59:59"),0);
    }
    {
        ExerciseMachine theObject;
        eq(3, theObject.getPercentages("00:14:10"),49);
    }
    {
        ExerciseMachine theObject;
        eq(4, theObject.getPercentages("00:19:16"),3);
    }
    {
        ExerciseMachine theObject;
        eq(5, theObject.getPercentages("00:28:00"),19);
    }
    {
        ExerciseMachine theObject;
        eq(6, theObject.getPercentages("19:43:36"),3);
    }
}
// END CUT HERE
