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
class CeyKaps
{
public:
	string decipher(string typed, vector <string> switches)
	{
		string res;
		char Arr[26] ;
		for (int i = 0; i < 26; i++) Arr[i] = 'A' + i;
		/*for (int i = 0; i < 26; i++) fprintf (stderr, "%c", Arr[i]);
		fprintf (stderr, "\n");*/
		for (int i = 0; i < switches.size(); i++)
		{
			int first = 0, second = 0;
			for (int j = 0; j < 26; j++)
				if (Arr[j] == switches[i][0]) first = j;
				else if (Arr[j] == switches[i][2]) second = j;
			char temp = Arr[second];
			Arr[second] = Arr[first];
			Arr[first] = temp;
		}
		/*for (int i = 0; i < 26; i++) fprintf (stderr, "%c", Arr[i]);
		fprintf (stderr, "\n");*/
		for (int i = 0; i < typed.size(); i++)
			res += (char)Arr[typed[i]-'A'];
		return res;
	}

};
// BEGIN CUT HERE
int main( int argc, char* argv[] )
{
freopen ("Scratch.txt", "w", stderr);
freopen ("Scratch.txt", "w", stdout);
    {
        string switchesARRAY[] = {"A:B","B:C","A:D"};
        vector <string> switches( switchesARRAY, switchesARRAY+ARRSIZE(switchesARRAY) );
        CeyKaps theObject;
        eq(0, theObject.decipher("AAAAA", switches),"CCCCC");
    }
    {
        string switchesARRAY[] = {"A:B","B:C","C:D","D:E","E:A"};
        vector <string> switches( switchesARRAY, switchesARRAY+ARRSIZE(switchesARRAY) );
        CeyKaps theObject;
        eq(1, theObject.decipher("ABCDE", switches),"AEBCD");
    }
    {
        string switchesARRAY[] = {"W:O","W:I"};
        vector <string> switches( switchesARRAY, switchesARRAY+ARRSIZE(switchesARRAY) );
        CeyKaps theObject;
        eq(2, theObject.decipher("IHWSIOTCHEDMYKEYCAPSARWUND", switches),"WHOSWITCHEDMYKEYCAPSAROUND");
    }
}
// END CUT HERE
