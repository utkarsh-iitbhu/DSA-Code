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

ll t[12][12];
ll count_of_subset_sum(ll a[] , ll s, ll n){
    // ll t[n+1][s+1];
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
                t[i][j] = t[i-1][j-a[i-1]] + t[i-1][j];
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
ll n,s; cin >> n>>s;
ll a[n];
FOR(i, n)
cin >> a[i];

cout<<count_of_subset_sum(a,s,n)<<endl;

FOR(i,n+1){
    FOR(j,s+1){
        cout<<t[i][j]<<" ";
    }cout<<endl;
}




return 0;}