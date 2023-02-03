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

vector <int> g[1001]; 
int vis[1001]; 
int par[1001];

void dfs(int v, int p=-1){
    par[v] = p; // Har ba   ar dfs me par ka value change hoga 
    for(int child:g[v]){
        if(child==p) continue;
        dfs(child, v);
    }
}

vector<int> path(int v){
    vector<int> ans; 
    while(v != -1){
        ans.push_back(v);  // Isme store reverse way me hoga 
        v = par[v];   
    }
    reverse(ans.begin(), ans.end());
    return ans;
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n , m  ; 
    cin>>n >>m ; 
    while(m--){
        ll u , v; cin>>u>>v; 
        g[u].PB(v);
        g[v].PB(u);
    }
    dfs(1);
    int x, y; 
    cin>>x>>y;
    vector<int> path_x = path(x);
    vector<int> path_y = path(y);
int mn = min(path_x.size(),path_y.size()); 
int lca = -1; 
for(int i=0 ; i<mn; i++){
    if(path_x[i]==path_y[i]){
        lca=path_x[i];
        
    }else{
        break;
    }

}

// for(int i=0 ; i<path_x.size() ; i++){
//     cout<<path_x[i]<<" ";
// }cout<<endl;
// for(int i=0 ; i<path_y.size() ; i++){
//     cout<<path_y[i]<<" ";
// }cout<<endl;
cout<<lca<<endl;


return 0;}