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
int dist[1001];

void dfs(int v, int par=-1){
    for(int child:g[v]){
        if(child==par) continue;
        dist[child] = dist[v]+1;
            dfs(child, v);
         
    }
}


int dfs_new(int v, int par=-1){
    for(int child:g[v]){
        if(child==par) continue;
        dist[child] = dist[v]+1;
            dfs(child, v);
         
    }
    return *max_element(dist,dist+20);
}
   
   


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, m ; 
    cin>>n>>m;
    while(m--){
        ll u , v; cin>>u>>v; 
        g[u].PB(v);
        g[v].PB(u);
    }

int x = dfs_new(1); 
cout<<x<<endl;
cout<<dfs_new(x)<<endl;
dfs(1);
int maxdept = -1 , maxnode  ; 
for(int i=1; i <=n ; i++){
    if(maxdept<dist[i]){
        maxdept = dist[i];
        maxnode = i;
    }
    dist[i] = 0 ;
}
cout<<maxnode<<endl;
dfs(maxnode); 
maxdept = -1; 
for(int i=1; i<=n ;i++){
    if(maxdept<dist[i]){
        maxdept = dist[i];
    }
}
cout<<maxdept<<endl;

return 0;}