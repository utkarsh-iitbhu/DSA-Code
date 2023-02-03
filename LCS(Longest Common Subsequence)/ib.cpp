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


struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
// Given a Binary Tree A consisting of N nodes.

// You need to find all the cousins of node B.

// NOTE:

// Siblings should not be considered as cousins.
// Try to do it in single traversal.
// You can assume that Node B is there in the tree A.
// Order doesn't matter in the output.
vector<int> solve(TreeNode* root, int b) {
     vector<int> ans ; 
    queue<pair<TreeNode*,TreeNode*>> q ; 
    q.push({NULL,root});
    while(!q.empty()){
        int l = q.size(); 
        vector<pair<int,int>> v ; 
        while(l--){
            TreeNode* par = q.front().first ; 
            TreeNode* ch  = q.front().second ;
            q.pop(); 
            if(ch->left){ 
                q.push({ch,ch->left});
                v.push_back({ch->val,ch->left->val});
            }
            if(ch->right){ 
                q.push({ch,ch->right});
                v.push_back({ch->val,ch->right->val});
            }
        }
        int parent =  -1  ; 
        for(auto i:v){
            if(i.second==b){
                parent = i.first ;
                break;  
            }
        }
        if(parent!=-1){
         for(auto i:v){
            if(i.first==parent) continue ; 
            ans.push_back(i.second);
        }   
        }
    }
    return ans; 
}

void solve(){

      int n;
  cin >> n;

  vector<int> val(n);
  for (int i = 0; i < n; i++) {
    cin >> val[i];
  }

  vector<int> weight(n);
  for (int i = 0; i < n; i++) {
    cin >> weight[i];
  }

  int cap;
  cin >> cap;
    auto f = [&](int W, vector<int>weight,vector<int>val,int n,auto&&f){
      if(n==0 || W==0) return 0;
      
      if(weight[n-1] > W){
          return f(W,weight,val,n-1,f);
      }
      else{
          return max(f(W,weight,val,n-1,f), val[n-1]+f(W-weight[n-1],weight,val,n,f));
      }
        
    };
    
    cout<<f(cap,weight,val,n,f)<<endl;

// int n; cin>>n; 
//     vector<int> a(n); 
//     for(int i=0 ; i<n; i++){
//         cin>>a[i];
//     }
//     int k ; cin>>k;
    
    bool t = false;
    int lvl =0 ; 
    // auto f = [&](int ind, int sum, auto &&f){
    //     if(ind==n) return ;
    //     if(sum>k) return ;
    //     if(sum==k){
    //         lvl++;
    //         // return 1;
    //     }
        
    //     f(ind+1,sum,f);
        
    //     sum += a[ind];
    //     f(ind,sum,f);
    //     sum -= a[ind];

    //     return ;
        
    // };
    
    // f(0,0,f);
    // cout<<lvl<<endl;
    
    // cout<<lvl<<endl;
    return ; 

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

#ifndef ONLINE_JUDGE
freopen("Error.txt", "w", stderr);
#endif

// int T; cin >> T; while (T--) {
solve(); 
// }
return 0;}