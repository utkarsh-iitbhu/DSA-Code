#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimization ('unroll-loops')
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
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
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

string a , b ;
cin>>a>>b;
string s = a + '#' + b; 
// cout<<s<<endl;
ll n = s.size();
ll pattern = a.size();
vector<ll> pie(n+1) ; 
for(int i=1 ; i<n ;i++){
    ll j = pie[i-1]; 
    while(j>0 && s[i]!=s[j]){
        j = pie[j-1];
    }
    if(s[i]==s[j]){
        j++;
    }
    pie[i] = j; 
}
ll ans = 0 ; 
for(int i=pattern ;i<s.size() ; i++){
    if(pie[i]==pattern){
        ans++;
    }
}
cout<<ans<<endl;




return 0;}