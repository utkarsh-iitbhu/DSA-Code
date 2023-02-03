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
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

ll n; cin >> n;
ll k ; cin>>k ;
ll a[n];
FOR(i, n)
cin >> a[i];

vector<ll> ans; 
// ll curr = *max_element(a, a+k);
ll curr =0 ; 
// ans.push_back(curr);
for(int i=0 ; i<n-k ;i++){
    if(*max_element(a+i,a+i+k) >curr){
        ans.push_back(*max_element(a+k-i+1,a+i));
    }else{
        ans.push_back(curr);
    }
}
for(int i=0 ; i<ans.size() ; i++){
    cout<<ans[i]<<" ";
}





return 0;}