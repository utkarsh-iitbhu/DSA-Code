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
ll x; cin>>x; 
ll a[n];
FOR(i, n)
cin >> a[i];

int l=0, r=n-1 ; 
int ans ; 
while(l<=r){
    int mid = l + (r-l)/2 ;
    if(a[mid]==x){
        cout<<0<<endl; 
        return 0 ;
        
    }else if(a[mid]<x){
        l = mid+1 ;
    }else if(a[mid]>x){
        r = mid-1 ;
    }
}
cout<<l<<" "<<r<<endl;
cout<<min(abs(a[r]-x),abs(a[l]-x))<<endl;




return 0;}