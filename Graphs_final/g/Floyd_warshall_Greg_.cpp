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
ll dist[501][501];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
 ll n ; cin>>n ; 
for(int i=1 ; i <=n ; i++){
    for(int j=1 ;j<=n ; j++){
        cin>>dist[i][j];
    }
}
vector<int> del(n);
for(int i=0 ; i<n ; i++){
    cin>>del[i];
}
reverse(del.begin(),del.end());
vector<ll> ans ;
for(int k=0;  k<n ; k++){
        int kk = del[k];
    for(int i=1 ; i<=n ;i++){
        for(int j=1 ; j<=n ; j++){
            dist[i][j] = min(dist[i][j],dist[i][kk]+dist[kk][j]);
        }
    }

    ll sum =0 ;
    for(int i=0 ; i<=k ;i++){
        for(int j=0 ; j<=k ; j++){
            sum += dist[del[i]][del[j]];
        }
    }
    ans.push_back(sum); 
}
reverse(ans.begin(),ans.end());
for(int i=0 ; i<n ; i++){
    cout<<ans[i]<<" ";
}


return 0;}