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

ll using_i_and_j(ll a[], ll n , ll k){
    ll sum =0 ; 
    ll j =0 , i=0 ; 
    ll mx = INT_MIN; 
    while(j<n){
        sum = sum + a[j]; 
        if(j-i+1<k){
            j++;
        }else if(j-i+1==k){
            mx = max(mx,sum) ; 
            sum = sum - a[i];
            i++ ; 
            j++ ;
        }
    }
    return mx ; 
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

ll n; cin >> n;
ll k ; cin>>k ; 
ll a[n];
FOR(i, n)
cin >> a[i];

ll sum = 0 ; 
for(int i=0 ; i<k ;i++){
    sum += a[i];
}
ll mx = sum ; 
for(int i=k ; i<n ;i++){
    sum += a[i] - a[i-k];
    mx  = max(sum,mx);
}
// cout<<mx<<endl;
cout<<using_i_and_j(a,n,k)<<endl;



return 0;}