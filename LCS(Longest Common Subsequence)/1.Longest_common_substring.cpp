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

ll longest_common_substr(string a, string b, ll al, ll bl){
    ll t[al+1][bl+1]; 
    for(int i=0 ; i<al+1; i++){
        for(int j=0; j<bl+1 ; j++){
            if(i==0 || j==0){
                t[i][j] =0 ; 
            }
        }
    }
    for(int i=1 ; i<al+1; i++){
        for(int j=1; j<bl+1 ; j++){
            if(a[i-1] == b[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
            }else{
                t[i][j] = 0 ;
            }
       }    
    }



    // for(int i=0 ; i<al+1; i++){
    //     for(int j=0; j<bl+1 ; j++){
    //         cout<<t[i][j]<<" ";
    //     }cout<<endl;
    //     }

ll mx = INT_MIN; 
        for(int i=0 ; i<al+1; i++){
        for(int j=0; j<bl+1 ; j++){
            mx  = max(mx,t[i][j]);
        }
        }



return mx ; 

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
int t; cin>>t ; while(t--){
string a , b; cin>>a>>b; 
cout<<longest_common_substr(a,b,a.size(),b.size())<<endl;

}



return 0;}