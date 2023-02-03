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
typedef priority_queue<pi> maxhppi;
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

ll n; cin >> n;
// 3 1 1 1 2 4 4 
// ans of sorting should be 
// 1 1 1 4 4 3 2 // Acc to frequency 
ll a[n];
FOR(i, n)
cin >> a[i];
unordered_map<ll,ll> m ;
for(int i=0 ; i<n ; i++){
    m[a[i]]++;
} 
maxhppi mp ; 
ll size = mp.size(); 
for(auto it=m.begin(); it!=m.end(); it++){
     mp.push({it->second,it->first});
}
while(mp.size()>0){
    ll freq  = mp.top().F;
    ll num = mp.top().S;
    for(int i =0 ; i<freq ; i++){
        cout<<num<<" ";
    }
    mp.pop();
}







return 0;}