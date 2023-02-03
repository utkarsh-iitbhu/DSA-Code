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
ll x ; cin>>x ; 
ll a[n][n];
FOR(i, n){
    FOR(j,n){
cin >> a[i][j];
}}

int i = 0 , j = n-1 ; 
while(i>=0 && j>=0 && i<n && j<n){
    if(a[i][j] == x){
        cout<<i<<" "<<j<<endl;
        break;
    }else if(a[i][j] < x){
        i++;
    }else{
        j--;
    }
}

cout<<-1<<endl;



return 0;}