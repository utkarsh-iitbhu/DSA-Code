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

// Isse related ek aur question hai BITONIC araay ka 
// 2 4 5 12 8 5 3
// Increase and then decreases monotonically 

// we have to find that maximum element to we are actually finding the peak only  


ll n; cin >> n;
ll a[n];
FOR(i, n)
cin >> a[i];

int l=0 , r=n-1;
while(l<=r){
    int mid = l + (r-l)/2 ;
    if(mid<n-1 && mid>0){
        if(a[mid]>a[mid-1] && a[mid]>a[mid+1]){
            cout<< mid<<endl;
            break;
        }else if(a[mid-1]>a[mid]){
            r = mid-1 ;
        }else{
            l = mid+1 ;
        }
    }else if(mid==0){
         (a[1]>a[0]) ? cout<< 1 : cout<< 0  ;
         break;
    }else if(mid==n-1 ){
         (a[n-1]>a[n-2]) ? cout<<n-1 : cout<<n-2;
         break ;
    }
}




return 0;}