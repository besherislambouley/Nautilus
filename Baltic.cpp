/*
 * you can do the dp[n][m][t] solution in a smarter way using bitset , consedering bitset<509>dp[n][t] -> dp[n][0...m][t]
 * now you can use & , | , << , >> opperation to get the final answer 
*/
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#include <bits/stdc++.h>
using namespace std;
#define sqr 547
#define mid (l+r)/2
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define era erase
#define C continue
#define mem(dp,i) memset(dp,i,sizeof(dp))
#define mset multiset
typedef long long ll;
typedef short int si;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
const ll inf=1e18;
const ld pai=acos(-1);
int n , m , t ;
bitset<509>dp[509][5009] , sea[509] ;
int main () {
        cin >> n >> m >> t ;
        for ( int i = 1 ; i <= n ; i ++ ) {
                string x;
                cin >> x;
                for ( int j = 0 ; j < m ; j ++ ) {
                        sea[i][j] = dp[i][0][j] = ( x[j] == '.' ) ;
                }
        }
        string ret;
        cin >> ret;
        ret = " " + ret ;
        for ( int it = 1 ; it < ret.size() ; it ++ ) {
                for ( int i = 1 ; i <= n ; i ++ ) {
                        if ( ret[it] == 'N' || ret[it] == '?' ) {
                                dp [i][it]  |= ( dp[i+1][it-1] & sea[i] ) ;
                        }
                        if ( ret[it] == 'S' || ret[it] == '?' ) {
                                dp [i][it]  |= ( dp[i-1][it-1] & sea[i] ) ;
                        }
                        if ( ret[it] == 'E' || ret[it] == '?' ) {
                                dp [i][it]  |= ( ( dp[i][it-1] << 1 ) & sea[i] ) ;
                        }
                        if ( ret[it] == 'W' || ret[it] == '?' ) {
                                dp [i][it]  |= ( ( dp[i][it-1] >> 1 ) & sea[i] ) ;
                        }
                }
        }
        int ans = 0 ;
        for ( int i = 1 ; i <= n ; i ++ ) {
                ans += dp[i][t].count() ;
        }
        cout << ans << endl ;
}
