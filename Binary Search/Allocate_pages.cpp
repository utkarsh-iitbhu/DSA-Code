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

bool isValid(ll a[], ll n , ll k, ll max_page){
int s = 1 ;
int sum =0 ; 
for(int i=0 ; i<n ; i++){
    
    // if(sum>max_page){
    //     s++; 
    //     sum = a[i]; 
    // }else{
    //     sum = sum + a[i];
    // }
    // if(s>k){
    //     return false; 
    // }

      sum += a[i] ; 
    if(sum>max_page){
        sum = a[i] ; 
        s++  ;
    }

}
if(s>k) return false; 
return true; 



}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

ll n; cin >> n;
ll k ; cin>>k ;
ll a[n];
FOR(i, n)
cin >> a[i];

int l = *max_element(a,a+n);
int r = accumulate(a,a+n,0);
int sum = accumulate(a,a+n,0);
int res=-1 ;
while(l<=r){
    int mid = l + (r-l)/2 ; 
    if(n<k){
        cout<<-1<<endl;
        break;
        
    }
    if(isValid(a,n,k,mid)==true){
        res = mid ; 
        r = mid-1 ;
    }else{
        l = mid+1 ; 
    }
}
    int ans = sum - res ; 
    cout<<res<<endl;
cout<<ans<<endl;




return 0;}