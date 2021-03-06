#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include<string.h>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<assert.h>
//#include<unordered_map>
//#include<tr1/unordered_set>
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define rep(i,a,n) for( int i=(a) ; i < (int)(n) ; i++)
#define sz(v) int(v.size())
#define mp make_pair
#define till(a) while(a--)
#define SI scanint() 
#define gc getchar_unlocked
#define MAX 10000
#define pi 3.14159265358979323846264338327950
using namespace std;
//using namespace tr1;
typedef vector<string> vs;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int , int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
inline int scanint()
{
	register int c = gc();
	register int x = 0;
	for ( ; ( c < 48 || c>57 ); c = gc() );
	for ( ; c > 47 && c < 58; c = gc() ) { x = ( x << 1 ) + ( x << 3 ) + c - 48; }
	return x;
}

ll bit[ 1000002 ];
int size;
inline void update( int ind , int val )
{
	for ( int i = ind; i <= size; i += ( i & -i ) )
		bit[ i ] += val;
}

inline ll read( int ind )
{
	ll ret = 0;
	for ( int i = ind; i > 0 ; i -= ( i & -i ) )
		ret += bit[ i ] ;
	return ret;
}

int v[ 100009 ];
int main()
{
	int t = SI;
	till( t )
	{
		rep( i , 0 , 1000002 )bit[ i ] = 0;
		int n = SI;
		rep( i , 0 , n )
		{
			v[ i ] = SI;
			size = max( size , v[ i ] );
		}
		ll ret = 0;
		rep( i , 0 , n )
		{
			ret += read( v[ i ] );
			update( v[ i ] + 1 , v[ i ] );
		}
		printf( "%lld\n" , ret );
	}

	return 0;
}
