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
class FormatAmt
{
public:
	string amount(int dollars, int cents)
	{
		string res = "", str_cents = "";
		int total = 0;
		if (dollars == 0) res = "0";
		while (dollars)
		{
			if (total == 3)
			{
				total = 0;
				res = "," + res;
			}
			res = (char)('0'+(dollars % 10)) + res;
			dollars /= 10;
			total++;
		}
		res += ".";
		if (cents == 0) str_cents = "00";
		else if (cents < 10)
		{
			str_cents += "0";
			str_cents += (char)('0' + cents);
		}
		else
		{
			stringstream ss;
			ss << cents;
			ss >> str_cents;
		}
		return "$" + res + str_cents;
	}

};
// BEGIN CUT HERE
int main( int argc, char* argv[] )
{
stderr=freopen("Scratch.txt", "w", stderr);
fclose(stdout);
stdout=stderr;
    {
        FormatAmt theObject;
        eq(0, theObject.amount(123456, 0),"$123,456.00");
    }
    {
        FormatAmt theObject;
        eq(1, theObject.amount(49734321, 9),"$49,734,321.09");
    }
    {
        FormatAmt theObject;
        eq(2, theObject.amount(0, 99),"$0.99");
    }
    {
        FormatAmt theObject;
        eq(3, theObject.amount(249, 30),"$249.30");
    }
    {
        FormatAmt theObject;
        eq(4, theObject.amount(1000, 1),"$1,000.01");
    }
}
// END CUT HERE
