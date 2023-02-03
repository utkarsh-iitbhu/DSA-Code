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
    int T; cin >> T; while (T--) {
string s ; cin>>s;
ll k; cin >> k;
ll l = s.size();
vector<ll> p(l) ; 

for(int i=1 ; i<l ;i++){
    ll j = p[i-1] ;
    while(j>0 && s[i]!=s[j]){
        j = p[j-1]; 
    }
    if(s[i]==s[j]){
        j++;
    }
    p[i] = j ;
}

ll ans = (l-p[l-1])*(k-1) + l ;
if(l==1){
    cout<<k<<endl;
}else{
cout<<ans<<endl;
}


    }
return 0;}