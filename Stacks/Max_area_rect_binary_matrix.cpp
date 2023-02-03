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

int mah(vector<int> a , int n , int m){
    
vector <int> nsl , nsr ; 
stack <pair<int,int>> s,sl; 
int ans  = INT_MIN;  
for(int i=0 ; i<n ; i++){
if(s.empty()){
    nsl.push_back(-1);    
}else if(!s.empty() && s.top().first<a[i]){
    nsl.push_back(s.top().second);
}
else if(!s.empty() && s.top().first>=a[i]){
    while(!s.empty() && s.top().first>=a[i]){
        s.pop();
    }
    if(s.empty()){
        nsl.push_back(-1);
    }else{
        nsl.push_back(s.top().second);
    }
}
s.push({a[i],i});
}

///

// for (int i = 0; i < n; i++)
// {
//     cout<<nsl[i]<<" ";
// }cout<<endl;

////


for(int i=n-1 ; i>=0 ; i--){
if(sl.empty()){
    nsr.push_back(n);    
}else if(!sl.empty() && sl.top().first<a[i]){
    nsr.push_back(sl.top().second);
}
else if(!sl.empty() && sl.top().first>=a[i]){
    while(!sl.empty() && sl.top().first>=a[i]){
        sl.pop();
    }
    if(sl.empty()){
        nsr.push_back(n);
    }else{
        nsr.push_back(sl.top().second);
    }
}
sl.push({a[i],i});
}


reverse(nsr.begin(),nsr.end());
// for (int i = 0; i < n; i++)
// {
//     cout<<nsr[i]<<" ";
// }cout<<endl;

vector <int> width ; 
for(int i=0 ; i<n ; i++){
    width.push_back(nsr[i]-nsl[i]-1);
}

// for(int i=0 ; i<n ; i++){
//     cout<<width[i]<<" ";
// }cout<<endl;

for(int i=0 ; i<n ; i++){
    ans = max(ans,width[i]*a[i]);
}
return ans; 
    
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

ll n; cin >> n;
ll m ; cin>>m ; 
ll a[n][m];
FOR(i, n){
FOR(j,m){
cin >> a[i][j];
}}

vector<int> v; 
for(int j=0 ; j<m ; j++){
    v.push_back(a[0][j]);
}
int mx = mah(v,n,m);

for(int i=0 ; i<n ; i++){
    for(int j=0 ; j<m ; j++){
         if(a[i][j]==0){
             v[j] = 0;
         }else{
             v[j] = v[j] + a[i][j] ;
         }
     }
        mx = max(mx,mah(v,n,m));
}
cout<<mx<<endl; 



return 0;}