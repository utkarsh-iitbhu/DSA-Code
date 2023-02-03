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

// DSU consistes of three main function 
/*
    1. Make -> New node
    2. Find -> Find the parent of the node or gropu
    3. Union -> Union of two nodes (a,b)

    Bada tree jaake chote se na jude so we use union by rank or size 
    And also we use path compression
*/


int size[501];
int parent[501];

void make(int v){
    parent[v] = v;
    size[v] = 1; // size 
}

int find(int v){
    if(v==parent[v]){
        return v;
    }
    // while(v==parent[v]){
    //     v = parent[v];
    // }
    // return find(parent[v]);
    return parent[v] = find(parent[v]); // This is path compression assign bhi hote jaega 
}

void Union(int a, int b){
    // root se root joodta hai 
    a = find(a);
    b = find(b);
    if(a!=b){ // Ab b ko jodenge a ke niche 
        if(size[a]<size[b]){ // size we are swapping 
            swap(a,b);  // we want small one shoulg get connected to the big one    
        }
        parent[b] = a; // Ab b ka parent bhi a ho gaya simple
        size[a] += size[b]; // size of a is increased by size of b
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k ;
    cin >> n >> k ;

    vector<pair<int, pair<int,int>>> edges;

    for(int i=1 ; i<=n ; i++){
        make(i); // sab ban gaye ab node 
    }
    while(k--){
        int u, v , w; 
        cin>>u>>v>>w;
        edges.push_back(MP(w,MP(u,v))); 
        // Union(u,v); // u aur v ko jodna hai 
    }
    sort(edges.begin(), edges.end());
int total_cost =0 ; 
for(auto &e : edges){
    int wt = e.F;
    int u = e.S.F;
    int v = e.S.S;
    if(find(u)!=find(v)){
        Union(u,v);
        total_cost += wt;
        cout<<u<<" "<<v<<" "<<wt<<endl; 
    }
}
cout<<total_cost<<endl;



return 0;}