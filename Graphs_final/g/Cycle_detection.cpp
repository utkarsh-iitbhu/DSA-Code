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

bool dfs(int v, int par=-1){  // passing vertex and its parent vertex
    vis[v] = 1;
    int ans = 0;    
    for(auto child:g[v]){
        if(child==par){  // skipping edge to parent vertex
            continue;
        }
        if(vis[child]==0){
            if(dfs(child,v)==true){
                return true ;
            }
            
        }else{
            if(child!=par){
                return true;
            }
        }
    }return false;
    return 0;
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

ll n; cin >> n;
ll m ; cin>>m ; 
while(m--){
    ll u , v; cin>>u>>v; 
    g[u].PB(v);
    g[v].PB(u);
}

cout<<dfs(1)<<endl;




return 0;}