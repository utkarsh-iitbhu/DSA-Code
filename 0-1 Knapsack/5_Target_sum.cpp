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


ll target_sum(ll a[] , ll s1 , ll n){
    ll t[n+1][s1+1];        
    for(int i=0 ; i<n+1; i++){
        for(int j=0 ; j<s1+1 ;j++){
            if(i==0){
                t[i][j]=0;
            }
            if(j==0){
                t[i][j]=1;
            }
        
        }}

        for(int i=1 ; i<n+1; i++){
        for(int j=1 ; j<s1+1 ;j++){
            if(a[i-1]<=j){
                t[i][j] = t[i-1][j-a[i-1]] + t[i-1][j];
            }else{
                t[i][j] = t[i-1][j] ;
            }
        }}

        return t[n][s1];
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
ll n,d; cin >> n>>d;
ll a[n];
ll s=0 ; 
FOR(i, n){
cin >> a[i];
s+= a[i];
}

ll s1 = (d+s)/2;
cout<<target_sum(a,s1,n)<<endl;

// Target sum 
// 1 1 2 3
// U have to add either + / - sign
// +1 -1 -2 +3
// -1 +1 -2 +3
// +1 +1 +2 -3




return 0;}