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



bool subset_sum(int a[] , int n, int s){
bool t[n+1][s+1];
    for (int i = 0; i <= n; i++)
        t[i][0] = true;
 
    for (int i = 1; i <= s; i++)
        t[0][i] = false;

    for(int i= 1; i<n+1 ; i++){
        for(int j=1 ; j<s+1 ; j++){
            if(j>=a[i-1]){
            t[i][j] = t[i-1][j-a[i-1]] || t[i-1][j];
              }
              if(j<a[i-1]){
                  t[i][j] = t[i-1][j];
              }
        }
    }
return t[n][s];

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
int n,s; cin >> n>>s;
int a[n];
FOR(i, n)
cin >> a[i];

cout<<subset_sum(a,n,s)<<endl;

return 0;}