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

ll minimum_no_of_coin_change(ll a[] , ll n , ll s){
    ll t[n+1][s+1];
    for(int i=0 ; i< n+1 ; i++){
        for(int j=0 ; j<s+1 ; j++){
            if(j==0){
                t[i][j] = 0 ;
            }
            if(i==0){
                t[i][j] = INT_MAX - 1;
            }
        }
    }

    // For second row, we have to fill either INT_MAX-1 or number of coins
    // Coz ar[1]: for say sum =1; a[]=(3 ...) and sum = 1 
    // It requires infinite amount of coins
    // SO check for j/a[0] == 0  
        for(int j=0 ; j<s+1 ; j++){
            if(j%a[0]==0){
                t[1][j] = j/a[0];
            }else{
                t[1][j] = INT_MAX - 1 ; 
            }
        }
    

    for(int i=2 ; i< n+1 ; i++){
        for(int j=1 ; j<s+1 ; j++){
            if(a[i-1]<=j){
                t[i][j] = min(1+t[i][j-a[i-1]],t[i-1][j]);
            }else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][s]; 
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
ll n, sum; cin >> n>>sum;
ll a[n];
FOR(i, n)
cin >> a[i];

cout<<minimum_no_of_coin_change(a,n,sum)<<endl;







return 0;}