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

ll minimum_subset_dif(ll a[] , ll s, ll n){
    ll t[n+1][s+1];
      for(int i=0 ; i<n+1; i++){
        for(int j=0 ; j<s+1 ;j++){
            if(i==0){
                t[i][j]=0;
            }
            if(j==0){
                t[i][j]=1;
            }
        }
    }

    for(int i=1 ; i<n+1; i++){
        for(int j=1 ; j<s+1 ;j++){
            if(a[i-1]<=j){
                t[i][j] = t[i-1][j-a[i-1]] || t[i-1][j];
            }else{
                t[i][j] = t[i-1][j];
            }
            
            }
    }

    // FOR(i,n+1){
    //     FOR(j,s+1){
    //         cout<<t[i][j]<<" ";
    //     }cout<<endl;
    // }
vector <ll> v; 
    
        for(int j=0 ; j<=(s+1)/2 ;j++){
            if(t[n][j]==1){
                v.push_back(j);
    
        }
        }

        ll mn = INT_MAX ; 
        for(int i=0 ; i<v.size(); i++ ){
            mn = min(mn,abs(s-2*v[i]));
        }

return mn; 


}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
ll n; cin >> n;
ll a[n];
ll sum=0 ; 
FOR(i, n){
cin >> a[i];
sum += a[i];
}
// 1 2 7
// Range -> 0,10 i.e sum // Range = 10 
// n-> n , wt or sum = Range

cout<<minimum_subset_dif(a,sum,n)<<endl;



return 0;}