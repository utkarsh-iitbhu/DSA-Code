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

ll dist(ll x, ll y){
    return pow(sqrt(x*x + y*y),2);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

ll n; cin >> n;
ll k ; cin>> k; 
ll a[n][2];
FOR(i, n)
cin>>a[i][0]>>a[i][1];
// pair < ll , pair<ll,ll> > mp ; 
priority_queue <pair <ll ,pair<ll,ll>> > mx ;
priority_queue <pair <ll ,pair<ll,ll>> > mxh ;
FOR(i, n){
    mx.push({a[i][0]*a[i][0] + a[i][1]*a[i][1] , {a[i][0] , a[i][1]}});
    if(mx.size()>k){
        mx.pop();
    }

}

while(mx.size()>0){
    cout<<mx.top().S.F<<" "<<mx.top().S.S<<" "<<endl;
    mx.pop();
    
}




return 0;}