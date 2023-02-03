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
const int N = 500;
const int INF = 1e9+10; 
int dist[N][N];
vector<pair<int,int>> g[100005]; // Graph me wt second hai

// Floyd Warshall works for negative weights 
// BUT NOT FOR NEGATIVE GRAPH i.e SUM OF WEIGHTS IS NEGATIVE
// LOOP KHATAM HI NAHI HOGA WO CHALTE RAHEGA COZ KAM KAM MILTE RAHEGA


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i=0 ; i<N ; i++){
        for(int j=0 ; j<N ; j++){
            if(i==j) dist[i][j] = 0 ; 
            else
            dist[i][j] = INF;
        }
    }   
    ll n , m ; 
    cin >> n >> m ;
    while(m--){
        ll u , v , w ; 
        cin >> u >> v >> w ; 
        g[u].PB({v,w});
        dist[u][v] = w; 
    }

    for(int k=1 ; k<=n ; k++){
        for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=n ; j++){
            if(dist[i][k]!=INF && dist[k][j]!=INF ) // For negative numbers 
            dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
        }
    }   
    }

    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=n ; j++){
            if(dist[i][j]==INF){
                cout<<"I"<<" ";
            }else{
                cout<<dist[i][j]<<" ";
            }
        }
        cout<<endl;
    }   

return 0;}