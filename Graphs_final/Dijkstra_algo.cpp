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

vector <pair<int,int>> g[100005]; // Graph me wt second hai 
 // Chahe to priority queue bhi use kar sakte hai 
// int dist[100005];
// int vis[100005]; 

vector<int> dijsktra(int src){
    vector<int> dist(100005, INT_MAX);
    vector<int> vis(100005, 0);
    set<pair<int,int>>  s;  // Isme wt pahle jaega yaad rakhna bhai     
    s.insert({0,src}); // Pahle wt fir node, wt here is 0 or rather dist from root node of root node
    dist[src] = 0;
    while(!s.empty()){
        auto node = *s.begin(); // To iterate first element in set IMP
        // int v = *s.begin().S; // IS WRONG
        int v = node.S;
        int v_dist = node.F;
        s.erase(s.begin()); // Ek baar travel karke nikalna bhi to hai  
        //Not neccesary 
        // if(vis[v]==1) continue; // If already visited then continue

        vis[v] = 1; 
        for(auto child : g[v]){// Iske under ab sab child pe traversal chal raha hai 
            int child_wt = child.F; // Ye child ka wt node hai // ab child mee gaye hai
            int child_dist = child.S; // Ye child ka wt distance hai 
            // ch.S + dist[v] < dist[ch.F]
            // v_dist is same as dist[v]
            // Current node ka dist + child ke saath dist < dist array of that child
            if(child_dist + v_dist/*ALERT*/ < dist[child_wt]){
                dist[child_wt] = child_dist + /*ALERT*/dist[v] ; 
                s.insert({dist[child_wt], child_wt});

            }
        }
    }
    return dist;
    // for(int i=1 ; i<=5 ; i++) cout<<dist[i]<<" ";cout<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n , m ; 
    cin >> n >> m ;
    while (m--){
        ll a , b , c ;
        cin >> a >> b >> c ;
        g[a].PB(MP(b, c)); // Bhai weighted hai ek hi side se lenge
        g[b].PB(MP(a, c));
    }

int V = n;
int s = 1;
vector<int>vis(V,0);
       vector<int>dis(V,1e9);
       dis[s]=0;
       priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
       pq.push({0,s});
       while(!pq.empty())
       {
           auto p=pq.top();
           pq.pop();
        //   if(!vis[p.second]){
           for(auto it:g[p.second])
           {
               if(dis[it.F]>it.S+p.first)
               {
                   dis[it.F]=it.S+p.first;
                   pq.push({dis[it.F],it.F});
               }
           }
        //   }
           vis[p.second]=1;
       }
    //    FOR(i,6) cout<<dis[i]<<" ";
    //    cout<<endl;

vector<vector<int>> res; 
for(int i=1 ; i<=5 ; i++) res.push_back(dijsktra(i));
    // dijsktra(1);
    
    for(int i=0 ; i<6; i++){
        FOR(j,6) cout<<res[i][j]<<" ";
        cout<<endl;
    }


    // vector<int> ans; 
    // set<pair<int,int>> s; 
    // vector<int> vis(100005, 0);                             
    // vector<int> dist(100005, INT_MAX);
    // s.insert({0,1});
    // dist[1] = 0;
    // vis[1] = 1; 
    // while(!s.size()){
    //     auto it = *s.begin();
    //     int ndDist = it.F;
    //     int topNode = it.S;
    //     // vis[node] = 1 ;
    //     s.erase(it);
    //     for(auto ch:g[topNode]){
    //        if(ndDist + ch.S < dist[ch.F]){

    //        }
    //     }
    // }

    // for(int i=1; i<=n ; i++){
    //     cout<<dist[i]<<" ";
    // }



return 0;}