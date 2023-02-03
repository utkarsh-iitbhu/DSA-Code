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
ll t[20][20];
ll rod_cuttiing (ll p[] , ll len[] ,ll n , ll l){
    
    for(int i=0 ;i<n+1 ; i++){
     for(int j=0 ;j<n+1 ; j++){        
         if(i==0 || j==0){
             t[i][j]=0;
         }
         
        }   
    }

    for(int i=1 ;i<n+1 ; i++){
        for(int j=1 ;j<l+1 ; j++){        
            if(len[i-1]<=j){
                t[i][j] = max(p[i-1] + t[i][j-len[i-1]],t[i-1][j]);
            }else{
                t[i][j] = t[i-1][j];
            }
        }
    }

//     FOR(i,n+1){
//     FOR(j,n+1){
//         cout<<t[i][j]<<" ";
//     }cout<<endl;
// }

    return t[n][l];

}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); 
    
ll n; cin >> n;

ll p[n] , len[n];
FOR(i, n)
cin >> p[i];
FOR(i,n)
cin>>len[i] ;
ll l ; cin>>l;



cout<<rod_cuttiing(p,len,n,l)<<endl;






return 0;}