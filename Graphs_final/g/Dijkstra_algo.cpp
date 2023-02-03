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

void dijsktra(int src){
    vector<int> dist(100005, INF);
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
            int child_v = child.F; // Ye child ka wt node hai // ab child mee gaye hai
            int wt = child.S; // Ye child ka wt distance hai 
            if(wt + dist[v] < dist[child_v]){
                dist[child_v] = wt + dist[v] ; 
                s.insert({dist[child_v], child_v});

            }
        }
    }
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
    }
    
    
return 0;}