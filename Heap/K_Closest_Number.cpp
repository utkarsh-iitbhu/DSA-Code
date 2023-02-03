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
#define sz(x) (int)(x).size()
#define F first
#define S second
#define PB push_back
#define POB pop_back
#define MP make_pair
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

ll n; cin >> n;
ll x ; cin>> x; // Iske closest k numbers chahiye 
ll k ; cin>>k ; 
ll a[n];
FOR(i, n)
cin >> a[i];

// priority_queue <pi,vector<pi> , greater<pi>> minh;
priority_queue <pi> minh;   // Bigger diff (x-a[i]) ko remove karna hai 
for(int i=0 ; i<n ; i++){
    minh.push({abs(x-a[i]),i}); // a[i] is the value and i is the index
    // minh.push({abs(x-a[i]),a[i]}); // Bhi kar sakte hai 
    if(minh.size()>k){
        minh.pop();
    }
}
while(minh.size()>0){
    cout<<a[minh.top().S]<<" ";
    // cout<<minh.top().S<<" ";
    minh.pop();
}




return 0;}