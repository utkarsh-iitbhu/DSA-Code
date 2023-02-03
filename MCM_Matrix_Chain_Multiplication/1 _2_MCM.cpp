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

// Print matrix chain multiplication

int t[501][501];

int mcm(ll arr[], ll i, ll j){
    
    if(i>=j){
        return 0;
    }
    if(t[i][j]!=-1){ return t[i][j]; }

    int ans = INT_MAX ; 
    for (int k = i; k <= j-1; k++)
    {
        int temp = mcm(arr, i, k) + mcm(arr, k+1, j) + (arr[i-1]*arr[k]*arr[j]);
        if(temp < ans){
            ans = temp ; 
        }
    }
    // return ans ;
    return t[i][j]  = ans ; 
        
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
ll n; cin >> n;
ll a[n];
FOR(i, n)
cin >> a[i];
// 10 30 20 40 10
// It has (n-1) matrix 
// 10*30 30*20 20*40 40*10
// i=1 ; j=n-1
memset(t,-1,sizeof(t));
int i= 1, j=n-1 ; 
cout<<mcm(a,i,j)<<endl;




return 0;}