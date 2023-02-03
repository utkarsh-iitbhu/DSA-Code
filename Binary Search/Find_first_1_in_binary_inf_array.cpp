#include <bits/stdc++.h>
using namespace std;
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
#define INF 1000000000000000003
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
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

// First we will find that chunk from inf array 
// then we will be using first index

int l=0 , r=1; 
while(1>=a[r]){
    l =r ; 
    r = r*2 ; 
}
int ans ; 
while(l<=r){
    int mid = l + (r-l)/2 ;
    if(a[mid]==1){
        ans = mid ; 
        r = mid-1 ; 
    }else if(a[mid]<1){
        l = mid+1 ;
    }
}
cout<<ans<<endl;



return 0;}