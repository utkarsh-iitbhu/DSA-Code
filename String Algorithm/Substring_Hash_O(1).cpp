#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimization ('unroll-loops')
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1000000007
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
#define INF 1000000000000000003
typedef long long int ll;
typedef priority_queue<ll, vector<ll>, greater<ll>>  minhp;
typedef priority_queue<ll> maxhp;
typedef vector<ll> vi;
typedef pair<int, int> pi;
typedef priority_queue <pi , vector<pi> , greater<pi>> minhppi;
#define sz(x) (int)(x).size()
#define F first
#define S second
#define PB push_back
#define POB pop_back
#define MP make_pair

ll dp[101];
string s ; 
ll inv[101];

/*  e.g. -> coding ; dp[0] stores hash of 'c' ; dp[1] stores hash of  'co' .... 
    if we want hash of 'odi' then hash = dp[3] - dp[1-1] where l = 1 and r = 3 ; "codi - co" 
    dp[0] = s[0]*p^0 // c
    dp[1] = s[0]*p^0 + s[1]*p^1  // co
    dp[2] = s[0]*p^0 + s[1]*p^1 + s[2]*p^2  // cod
    dp[3] = s[0]*p^0 + s[1]*p^1 + s[2]*p^2 + s[3]*p^3  // codi 
    dp[n] = s[0]*p^0 + s[1]*p^1 + s[2]*p^2 + s[3]*p^3 + ... + s[n-1]*p^(n-1) + s[n]*p^n  // coding

    We have to take [(dp[r] - dp[l-1] ) / p^l] % mod ; modular division is not possible so we multiple with its inverse
*/

ll power_func(ll a, ll n){ // Calculate power function 
    ll res = 1; 
    while(n){
       if(n&1) res = (res*a)%mod;

       n >>=1 ; 
       a = a*a%mod;
    }
    return res;
}


void init(string s){  // Initialize dp array
    ll p=31 , power=1 ;
    ll ans = 0 ; 
    inv[0] = 1; 
    dp[0] = s[0]-'a'+1;

    for(int i=1; i<s.size() ;i++){
        char ch = s[i]; 
        power = (power * p ) % mod ; // Storing the power of p
        inv[i] = power_func(power, mod-2); // Storing the inverse of power
        dp[i] = (dp[i-1] + (ch-'a'+1)*power )%mod; // Storing the hash value using prefix array

    }
}

ll substr_hash(ll l, ll r){
    ll res = dp[r] ;
    if(l>0) res = res-dp[l-1];
    res = (res * inv[l] ) % mod;
    return res ;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>s ; 
    init(s);
    ll tc ; cin>>tc ; 
    while(tc--){
    ll a, b ; cin>>a>>b;
    cout<<substr_hash(a, b)<<endl;
}



return 0;}