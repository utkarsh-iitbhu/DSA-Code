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

vector<int> g[100005];
int vis[100005];
int shortest_path[100005];

void bfs(int v){
    queue<int> q;
    q.push(v);
    vis[v] = 1;

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int child : g[v]){
            if(!vis[child]){
                vis[child] = 1;
                q.push(child);
                shortest_path[child] = shortest_path[curr] + 1;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n , m  ;
    cin >> n >> m ;
    while(m--){
        ll u,v;
        cin>>u>>v;
        g[u].PB(v);
        g[v].PB(u);
    }
    bfs(1);
    int x; cin>>x; 
    cout<<shortest_path[x]<<endl; 
        cout<<shortest_path[0]<<endl; 
return 0;}