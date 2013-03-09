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
class Birthday
{
public:
	string getNext(string date, vector <string> birthdays)
	{
		string res;
		vector <string> temp (birthdays);
		for (int i = 0; i < birthdays.size(); i++) temp.push_back (birthdays[i].substr (0, 5));
		sort (temp.begin(), temp.end());
		for (int i = 0; i < temp.size(); i++)
			if (temp[i].compare (date) >= 0) return temp[i];
		return temp[0];
	}
};
// BEGIN CUT HERE
int main( int argc, char* argv[] )
{
stderr=freopen("Scratch.txt", "w", stderr);
fclose(stdout);
stdout=stderr;
    {
        string birthdaysARRAY[] = {"02/17 Wernie", "10/12 Stefan"};
        vector <string> birthdays( birthdaysARRAY, birthdaysARRAY+ARRSIZE(birthdaysARRAY) );
        Birthday theObject;
        eq(0, theObject.getNext("06/17", birthdays),"10/12");
    }
    {
        string birthdaysARRAY[] = {"10/12 Stefan"};
        vector <string> birthdays( birthdaysARRAY, birthdaysARRAY+ARRSIZE(birthdaysARRAY) );
        Birthday theObject;
        eq(1, theObject.getNext("06/17", birthdays),"10/12");
    }
    {
        string birthdaysARRAY[] = {"02/17 Wernie", "10/12 Stefan"};
        vector <string> birthdays( birthdaysARRAY, birthdaysARRAY+ARRSIZE(birthdaysARRAY) );
        Birthday theObject;
        eq(2, theObject.getNext("02/17", birthdays),"02/17");
    }
    {
        string birthdaysARRAY[] = {"10/12 Stefan"};
        vector <string> birthdays( birthdaysARRAY, birthdaysARRAY+ARRSIZE(birthdaysARRAY) );
        Birthday theObject;
        eq(3, theObject.getNext("12/24", birthdays),"10/12");
    }
    {
        string birthdaysARRAY[] = {"02/17 Wernie",
            "10/12 Stefan",
            "02/17 MichaelJordan",
            "10/12 LucianoPavarotti",
            "05/18 WilhelmSteinitz"};
        vector <string> birthdays( birthdaysARRAY, birthdaysARRAY+ARRSIZE(birthdaysARRAY) );
        Birthday theObject;
        eq(4, theObject.getNext("01/02", birthdays),"02/17");
    }
}
// END CUT HERE
