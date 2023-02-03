#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1000000007
#define set_bits __builtin_popcountll
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
#define INF 1e18
typedef long long int ll;
typedef unsigned long long ull;
typedef long double lld;
//typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
typedef priority_queue<ll, vector<ll>, greater<ll>>  minhp;
typedef priority_queue<ll> maxhp;
typedef vector<ll> vi;
typedef pair<int, int> pi;
typedef vector<vector<ll>> vdp;
typedef priority_queue <pi , vector<pi> , greater<pi>> minhppi;
#define sz(x) (int)(x).size()
#define F first
#define S second
#define PB push_back
#define POB pop_back
#define MP make_pair
#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
#define line cout<<endl
#define all(x) (x).begin(), (x).end()

#ifndef ONLINE_JUDGE
#define dbg(x) cerr<<#x<<' ';_print(x);cerr<<endl;
#else
#define dbg(x)
#endif

void _print(int a) {cerr << a << ' ';}
void _print(string a) {cerr << a << ' ';}
void _print(char a) {cerr << a << ' ';}
void _print(ll a) {cerr << a << ' ';}
void _print(float a) {cerr << a << ' ';}
void _print(ull a) {cerr << a << ' ';}
void _print(lld a) {cerr << a << ' ';}
void _print(double a) {cerr << a << ' ';}
void _print(const char *x) {cerr << '"' << x << '"';}
void _print(bool x) {cerr << (x ? "true" : "false");}
void _print(const string &x) {cerr << '"' << x << '"';}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template<class T> class Array;
template <class T, class V> void _print(map <T, V> v);
template <class T, class V> void _print(unordered_map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T> void _print(unordered_set <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}";}
template<class T> void _print(vector<T> v){cerr<<"[ ";for(T i: v){_print(i);cerr<<", ";}cerr<<"]"<<endl;}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <typename T>void print(vector<vector<T> >& a){cerr << "[ ";for (auto i : a){print(i);cerr << " ";}cerr << "]";}
template <typename T, typename V>void print(vector<pair<T, V> >& a){cerr << '[' << ' ';for (auto x : a){print(x.F);cerr << ":";print(x.S);cerr << ' ';}cerr << ']';}
template <class T> void _print(unordered_set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}

const int N = 1e5+2;
int a[N], tree[4*N];

// partial querry and complete querry

void build(int node, int st, int en){
    if(st==en){
        tree[node] = a[st];// a[en] && a[st] dono same hai 
        return; 
    }
    int m = (st+en)/2; 
    build(2*node, st, m);
    build(2*node+1, m+1, en);
    tree[node] = tree[2*node] + tree[2*node+1];
}

// st and en pe khelenge isme 
int querry(int node, int st, int en,  int k){
    if(st==en) return st; 
    // Ab partial overlap case wale me we go down and chose own desired range
    int m = (st+en)/2;
    // agr left child ke sum se chote hai 
    if(k<tree[2*node])
    return querry(2*node, st, m,k) ;
    else return querry(2*node+1, m+1, en,k-tree[node*2]);
}

// this will update that number and seg tree me bhi changes hoge isse
void update(int node , int st, int en, int idx){
    // index waise bhi leaf node me hi milega bro 
    if(st==en){
        if(a[st]==1){ 
            a[st]=0; 
            tree[node]=0;
        }
        else{ 
            a[st]=1;
            tree[node] = 1;
        }
        return;
    }
    int m = (st+en)/2;
    // Binary search lag raha hai to find the ind of the number
    if(idx<=m) update(2*node, st, m, idx);
    else update(2*node+1, m+1, en, idx);
    tree[node] = tree[2*node] + tree[2*node+1];
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

#ifndef ONLINE_JUDGE
freopen("Error.txt", "w", stderr);
#endif

    int n;cin>>n;
    int q;
    cin>>q;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    build(1, 0, n-1);
    // for(int i=0 ; i<4*n ; i++) cout<<tree[i+1]<<" ";
    
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int idx;
            cin>>idx;
            
            update(1, 0, n-1, idx);
        }
        else if(type==2){
            int k; cin>>k;
            cout<<querry(1, 0, n-1,k)<<endl;
        }
    }
    


return 0;}