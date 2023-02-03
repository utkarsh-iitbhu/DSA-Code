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

string a; 
ll hash_func(string a){
    // Hash -> s[0]*p^0 +  s[1]*p^1 + s[2]*p^2 + s[3]*p^3 .... 
    // Each striong has a unique hash value
    // Chose p>character set i,e a-z(26) and p must be prime
    ll n = sz(a);
    ll ans = 0 ; 
    ll p = 31; // It is greater than 26 and prime
    ll power = 1 ;
    for(char ch  : a){
        ans = ans +  (ch - 'a' + 1)*power % mod;  // Start from 1 not 0 as 'a' is 1
        power = (power * p) % mod;     // Hash will be of form (a*pow(p,i)) % mod
    }
    return ans ;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>a;
    cout<<hash_func(a)<<endl;




return 0;}