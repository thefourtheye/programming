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
class ImageDithering {
public:
    int count(string dithered, vector <string> screen) {
        int res = 0;
		  for (int i = 0; i < dithered.size(); i++)
			  for (int j = 0; j < screen.size(); j++)
				  res += std::count (screen[j].begin(), screen[j].end(), dithered[i]);
        return res;
    }

};
// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        string screenARRAY[] = {"AAAAAAAA",
            "ABWBWBWA",
            "AWBWBWBA",
            "ABWBWBWA",
            "AWBWBWBA",
            "AAAAAAAA"};
        vector <string> screen( screenARRAY, screenARRAY+ARRSIZE(screenARRAY) );
        ImageDithering theObject;
        eq(0, theObject.count("BW", screen),24);
    }
    {
        string screenARRAY[] = {"BBBBBBBB",
            "BBWBWBWB",
            "BWBWBWBB",
            "BBWBWBWB",
            "BWBWBWBB",
            "BBBBBBBB"};
        vector <string> screen( screenARRAY, screenARRAY+ARRSIZE(screenARRAY) );
        ImageDithering theObject;
        eq(1, theObject.count("BW", screen),48);
    }
    {
        string screenARRAY[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
            "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
            "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
            "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
            "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
            "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX"};
        vector <string> screen( screenARRAY, screenARRAY+ARRSIZE(screenARRAY) );
        ImageDithering theObject;
        eq(2, theObject.count("ACEGIKMOQSUWY", screen),150);
    }
    {
        string screenARRAY[] = {"BBBBBBB",
            "BBBBBBB",
            "BBBBBBB"};
        vector <string> screen( screenARRAY, screenARRAY+ARRSIZE(screenARRAY) );
        ImageDithering theObject;
        eq(3, theObject.count("CA", screen),0);
    }
    {
        string screenARRAY[] = {"ACBD"};
        vector <string> screen( screenARRAY, screenARRAY+ARRSIZE(screenARRAY) );
        ImageDithering theObject;
        eq(4, theObject.count("DCBA", screen),4);
    }
}
// END CUT HERE
