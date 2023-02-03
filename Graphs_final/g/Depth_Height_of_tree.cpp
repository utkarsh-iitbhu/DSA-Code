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

vector<int> g[1001];
int vis[1001];
int height[1001];
int depth[1001];


void  dfs(int v , int par=0){
    for(auto child : g[v]){
        if(child==par) continue ;        
        depth[child] = depth[v] + 1;
         dfs(child, v);
         height[v] = max(height[v], height[child] + 1);
        
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
ll n ; cin>>n ; 
ll m ; cin>>m ;
while(m--){
    ll u , v; cin>>u>>v; 
    g[u].PB(v);
    g[v].PB(u);
}

dfs(1);

for(int i=1; i<=n ;i++){
    cout<<i<<" "<<depth[i]<<" "<<height[i]<<endl;
}

return 0;}