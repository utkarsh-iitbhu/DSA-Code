#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimization ('unroll-loops')
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
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

const int INF = 1e9+10;
vector<pair<int,int>> g[100005];
int vis[100005];
vector <int> lev(100005,INF);
ll n; 

int bfs(){
    deque <int> q; // Coz ab hame front me bhi daalna bai and back me bhi
    q.push_back(1);
    lev[1] = 0 ; 
    while(!q.empty()){
        int curr = q.front();
        q.pop_front();
    for(auto &child : g[curr]){
        int chl = child.first;
        int wt = child.second;  
        if(lev[curr]+ wt< lev[chl]){ // Dekho curr lvl aaega parent + wt of that node
        // Tabh hi queue me daalenge aur wo // lev[chl] pahle INF tha 

        // Ye kara initialise weight ko 
            lev[chl] = lev[curr] + wt ;
            
        // Agar wt 1 hai to piche se daalo 
        if(wt==1){
            q.push_back(chl);

        // agae wt 0 hai to front se daalna hai 
        }else{
            q.push_front(chl);
        }
        }
    }
    }
    return lev[n] == INF?-1:lev[n];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll m  ;
    cin >> n >> m ;
    while(m--){
        ll u,v;
        cin>>u>>v;
        if(u==v) continue; 
        g[u].PB({v,0});
        g[v].PB({u,1});
    }
    cout<<bfs()<<endl;
    
return 0;}