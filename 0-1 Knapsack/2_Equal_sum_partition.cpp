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

bool equal_partitiuon(ll a[] , ll s , ll n){
    bool t[n+1][s+1];
    for(int i=0 ; i<n+1 ; i++){
        for(int j=0 ; j<s+1 ; j++){
            if(i==0){
                t[i][j]= 1  ;
            }
            if(j==0){
                t[i][j]= 0; 
            }
        }
    }

    for(int i=0 ; i<n+1 ; i++){
        for(int j=0 ; j<s+1 ; j++){
            // wt[]-> j   ||  n->i
            if(a[i-1]<=j){
                t[i][j] = t[i-1][j-a[i-1]] || t[i-1][j];
            }else if(a[i-1]>j){
                t[i][j] = t[i-1][j];            
                }
        }
    }
     return t[n][s];
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
ll n; cin >> n;
ll sum =0 ; 

ll a[n];
FOR(i, n){
cin >> a[i];
sum += a[i];
}

if(sum%2!=0){
    cout<<"NO"<<endl;
}else{
    cout<<equal_partitiuon(a,sum/2,n)<<endl;
    }





return 0;}