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
class CCipher {
public:
    string decode(string cipherText, int shift) {
        string res;
		  /*for (int i = 0; i < cipherText.size(); i++)
		  {
			  int diff = cipherText[i] - shift - 'A';
			  if (diff < 0)
				  res += ('Z' + diff + 1);
			  else
				  res += (char)cipherText[i] - shift;
		  }*/
		  for (int i = 0; i < cipherText.size(); i++)
			  res += (char)(((cipherText[i]-'A' - shift + 26) % 26) + 'A');
        return res;
    }

};
// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        CCipher theObject;
        eq(0, theObject.decode("VQREQFGT", 2),"TOPCODER");
    }
    {
        CCipher theObject;
        eq(1, theObject.decode("ABCDEFGHIJKLMNOPQRSTUVWXYZ", 10),"QRSTUVWXYZABCDEFGHIJKLMNOP");
    }
    {
        CCipher theObject;
        eq(2, theObject.decode("TOPCODER", 0),"TOPCODER");
    }
    {
        CCipher theObject;
        eq(3, theObject.decode("ZWBGLZ", 25),"AXCHMA");
    }
    {
        CCipher theObject;
        eq(4, theObject.decode("DBNPCBQ", 1),"CAMOBAP");
    }
    {
        CCipher theObject;
        eq(5, theObject.decode("LIPPSASVPH", 4),"HELLOWORLD");
    }
}
// END CUT HERE
