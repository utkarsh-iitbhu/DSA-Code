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


int sizes[2003];
int parent[2003];

void make(int v){
    parent[v] = v;
    sizes[v] = 1; // size 
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
        if(sizes[a]<sizes[b]){ // size we are swapping 
            swap(a,b);  // we want small one shoulg get connected to the big one    
        }
        parent[b] = a; // Ab b ka parent bhi a ho gaya simple
        sizes[a] += sizes[b]; // size    of a is increased by size of b
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; 
    cin >> n ;

    vector <pair<int,int>> cities(n+1);
    vector<pair<ll, pair<int,int>>> edges;
    vector<int> c(n+1) , k(n+1);
    for(int i=1 ; i<=n ; i++){
        cin >> cities[i].F >> cities[i].S;
    }

    for(int i=1 ; i<=n ; i++){
        cin >> k[i];
    }
    for(int i=1 ; i<=n ; i++){
        cin >> c[i];
    }

    for(int i=1 ; i<=n ; i++){
        edges.push_back({c[i],{0,i}}); // Ye saaare node 0 se connect ho rahe hai 
    }

    for(int i=1; i<=n ; i++){
        for(int j=i+1 ; j<=n ; j++){
            ll dist  = abs(cities[i].F-cities[j].F) + abs(cities[i].S-cities[j].S);
            ll cost = dist*1LL*(k[i]+k[j]);
            edges.push_back({cost,{i,j}});
        }
    }

    for(int i=0 ; i<n ; i++){
        make(i+1);
    }
    sort(edges.begin(), edges.end());
ll total_cost =0 ; 
vector<int> powerst ; 
vector<pair<int,int>> connection ; 
for(auto &e : edges){
    int wt = e.F;
    int u = e.S.F;
    int v = e.S.S;
    if(find(u)!=find(v)){
        Union(u,v);
        total_cost += wt;

        if(u==0 || v==0){
            powerst.push_back(max(u,v));
        }else{
            connection.push_back({u,v});
        }
    }
}
cout<<total_cost<<endl;
cout<<powerst.size()<<endl;
for(int st:powerst){
    cout<<st<<" ";
}cout<<endl;

cout<<connection.size()<<endl;
for(auto &e : connection){
    cout<<e.F<<" "<<e.S<<endl;
}



return 0;}