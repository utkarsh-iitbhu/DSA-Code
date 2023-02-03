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


void bfs(int v,vector<int> g[],vector<int> &vis,vector<int> &parent,
vector<int> &shortest_path){
    queue<int> q;
    q.push(v);
    vis[v] = 1;

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        // g[curr] me check kar rahe hai bhai glti mat karna
        for(int child : g[curr]){
            if(!vis[child]){
                vis[child] = 1;
                parent[child] = curr; 
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
vector<int> g[100005];
vector<int> vis(100005,0);
// Ye sidha minimum path dega
vector<int> shortest_path(100005,0);
// Ye parents se marks kar ke backtrack kar ke ssp dega
vector<int> parent(100005,0);


    while(m--){
        ll u,v;
        cin>>u>>v;
        g[u].PB(v);
        g[v].PB(u);
    }
    // Keep 1 as src
    parent[1] = -1; 
    bfs(1,g,vis,parent,shortest_path);
    int x; cin>>x; 
    cout<<"Shortest path to all node: "<<endl;
    for(int i=1 ; i<=n ; i++){
        cout<<shortest_path[i]<<" ";
    }cout<<endl;
    cout<<"Shortest path to dest: "<<endl;
    cout<<shortest_path[x]<<endl; 
        // cout<<shortest_path[0]<<endl; 

    cout<<"Using parent :"<<endl;
    vector<int> ans; 
    int curnode = x; 
    ans.push_back(curnode);
    // 1 here is source node
    // cout<<"dfs"<<endl;
    while(curnode!=1){
        // cout<<"dfs1"<<endl;   
        curnode = parent[curnode];
        ans.push_back(curnode);
    }
reverse(begin(ans),end(ans));
    cout<<"Ans vector ssp :"<<endl;
    FOR(i,ans.size()) cout<<ans[i]<<" ";cout<<endl;

    cout<<"Parent vector : "<<endl;
    for(int i=1; i<=n ;i++){
         cout<<parent[i]<<" ";
    }

return 0;}