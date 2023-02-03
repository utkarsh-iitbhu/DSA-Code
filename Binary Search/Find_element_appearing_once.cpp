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
ll a[n];
FOR(i, n)
cin >> a[i];

int l =0, r = n-1;
while(l<=r){
    int mid = l + (r-l)/2;
    if(a[mid]!=a[mid+1] && a[mid]!=a[mid-1]){
        cout<<mid<<endl;
        break; 
    }
    else if(((a[mid]==a[mid-1]) && mid%2!=0) || (a[mid]==a[mid+1]) && mid%2==0){
        l = mid+1;
    }else{
        r = mid-1;
    }
}
    




return 0;}