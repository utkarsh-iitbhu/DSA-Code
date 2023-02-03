// #include <bits/stdc++.h>
// using namespace std;
// //#include <ext/pb_ds/assoc_container.hpp>
// //#include <ext/pb_ds/tree_policy.hpp>
// //using namespace __gnu_pbds;
// #pragma GCC optimization ('unroll-loops')
// #define max(a, b) (a < b ? b : a)
// #define min(a, b) ((a > b) ? b : a)
// #define mod 1000000007
// #define set_bits __builtin_popcountll
// #define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
// #define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
// #define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
// #define INF 1e18
// typedef long long int ll;
// typedef unsigned long long ull;
// typedef long double lld;
// //typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
// typedef priority_queue<ll, vector<ll>, greater<ll>>  minhp;
// typedef priority_queue<ll> maxhp;
// typedef vector<ll> vi;
// typedef pair<int, int> pi;
// typedef priority_queue <pi , vector<pi> , greater<pi>> minhppi;
// #define sz(x) (int)(x).size()
// #define F first
// #define S second
// #define PB push_back
// #define POB pop_back
// #define MP make_pair
// #define all(x) (x).begin(), (x).end()

// #ifndef ONLINE_JUDGE
// #define dbg(x) cerr<<#x<<' ';_print(x);cerr<<endl;
// #else
// #define dbg(x)
// #endif

// void _print(int a) {cerr << a << ' ';}
// void _print(string a) {cerr << a << ' ';}
// void _print(bool a) {cerr << a << ' ';}
// void _print(char a) {cerr << a << ' ';}
// void _print(ll a) {cerr << a << ' ';}
// void _print(float a) {cerr << a << ' ';}
// void _print(ull a) {cerr << a << ' ';}
// void _print(lld a) {cerr << a << ' ';}
// void _print(double a) {cerr << a << ' ';}

// template <class T, class V> void _print(pair <T, V> p);
// template <class T> void _print(vector <T> v);
// template <class T> void _print(set <T> v);
// template <class T, class V> void _print(map <T, V> v);
// template <class T> void _print(multiset <T> v);
// template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}";}
// template<class T> void _print(vector<T> v){cerr<<"[ ";for(T i: v){_print(i);cerr<<", ";}cerr<<"]"<<endl;}
// template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}


// void solve(){
//     ll n; cin >> n;
//     ll a[n];
//     FOR(i, n)
//     cin >> a[i];

// map<int,int> m; 
// for(int i=0 ;i<n ; i++){
//     if(m.find(a[i]) != m.end()){
//         if(m[a[i]] == 2) {cout<<a[i]<<endl ;return ;}
//     }
//         m[a[i]]++;
        
//     }
//     cout<<-1<<endl;
//     return ; 
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);

// #ifndef ONLINE_JUDGE
// freopen("Error.txt", "w", stderr);
// #endif

// int T; cin >> T; while (T--) {
// solve(); 
// }
// return 0;}

#include <bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
#pragma GCC optimization ('unroll-loops')
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
typedef priority_queue <pi , vector<pi> , greater<pi>> minhppi;
#define sz(x) (int)(x).size()
#define F first
#define S second
#define PB push_back
#define POB pop_back
#define MP make_pair
#define all(x) (x).begin(), (x).end()

#ifndef ONLINE_JUDGE
#define dbg(x) cerr<<#x<<' ';_print(x);cerr<<endl;
#else
#define dbg(x)
#endif

void _print(int a) {cerr << a << ' ';}
void _print(string a) {cerr << a << ' ';}
void _print(bool a) {cerr << a << ' ';}
void _print(char a) {cerr << a << ' ';}
void _print(ll a) {cerr << a << ' ';}
void _print(float a) {cerr << a << ' ';}
void _print(ull a) {cerr << a << ' ';}
void _print(lld a) {cerr << a << ' ';}
void _print(double a) {cerr << a << ' ';}

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
// Int to array dp 

void solve(){
    // ll n; cin >> n;
    // // ll dp[n][n]; 
    // vector<vi>dp(n, vi(n, 0));
    // FOR(i,n){
    //     FOR(j,n){
    //         cin>>dp[i][j];
    //     dbg(dp);
    //     }
    // }
// ll a[n]; 
// FOR(i,n) cin>>a[i];
int m = 5; 
    auto fib=[&](ll idx, auto fib)->ll{
        if(idx==1) return 1 ;
        dbg(idx)
        return idx + fib(idx-1,fib); 

    };
    // cout<<fib(1,fib)<<endl;
    auto sum = [&](int x, int y){
         return x+y ;
    };
    int d = 5; 
    auto fact = [&](int n , auto&& fact)->ll{
        if(n==1) return  1  ;
        return n*fact(n-1,fact);  
    };
    cout<<fact(5,fact)<<endl; 

// int n = 12 ; 
// vi col(n);
// col[0] = 0;

// auto dfs = [&](int u, int p, auto&& dfs) -> void {
// 	for (int v : adj[u])
// 		if (v != p) {
// 			col[v] = col[u] ^ 1;
// 			dfs(v, u, dfs);
// 		}
// };

// dfs(0, -1, dfs);


// cout<<sum(3,4)<<endl;

// vector<int> v = {1,2,3,4,5};
// vector<pair<int,int>> p = {{1,2},{3,4},{3,6}};
// sort(all(v),[](int x, int y){return x>y;});
// sort(all(p),[](pair<int,int>x, pair<int,int> y){
//     if(x.F==y.F) return x.S>y.S;
//     return x.F<y.F;
// });

// FOR(i,sz(v)){
//     cout<<v[i]<<" ";
// }cout<<endl;
// FOR(i,sz(p)){
//     cout<<p[i].F<<" "<<p[i].S<<endl;
// }

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

#ifndef ONLINE_JUDGE
freopen("Error.txt", "w", stderr);
#endif

int T; cin >> T; while (T--) {
solve(); 
}
return 0;}