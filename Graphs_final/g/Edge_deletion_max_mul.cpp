#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimization ('unroll-loops')
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
const int  mod = 1e9 + 7 ;
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

vector<int> a[100005];
int vis[100005];
int subtree[100005]; 
int val[100005];

void dfs(int v , int par){
    vis[v] = 1;
    subtree[v] += val[v-1];// Zero based indexing
    for(auto i : a[v]){
        if(i == par){
            dfs(i,v);
            subtree[v] += subtree[i];
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

ll n; cin >> n;
ll m ; cin>>m; 
while(m--){
    ll u , v; cin>>u>>v; 
    a[u].PB(v);
    a[v].PB(u);
}

dfs(1,0);
ll ans =0 ; 
for(int i=2 ; i<=n ; i++){
    int part1 = subtree[i] ;
    int part2 = subtree[1] - subtree[i]; 
    ans = max(ans , part1*1LL*part2)%mod;
}
cout<<ans<<endl;




return 0;}