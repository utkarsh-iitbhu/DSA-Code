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
    
int n; cin >> n;
int x ; cin>>x; 
int a[n];
FOR(i, n)
cin >> a[i];

// We dont know what will be our end number as our array is infinte in size
// 1 2 3 4 5 6 7 8 9 10
// l r
// l=0 , r=1
int  l =0 , r= 1 ; 
while(x>a[r]){
    l = r ; 
    r = r*2 ;
}

 ll ans = -1 ; 
while(l<=r){
    ll mid = (l+r)/2;
    ll mid_to_stop_overflow = l + (r-l)/2 ; 
    if(a[mid]>x){
        r = mid-1;
    }else if(a[mid]<x){
        l = mid+1;
    }else{
        ans = mid; 
        break ; 
    }
}
cout<<ans<<endl; 



return 0;}