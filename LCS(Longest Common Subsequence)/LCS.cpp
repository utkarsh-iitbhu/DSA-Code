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

ll recursion_LCS(string a , string b, ll al , ll bl){
    if(al==0 || bl ==0 ){
        return 0 ; 
    }
        if(a[al-1]==b[bl-1]){
            return 1+recursion_LCS(a,b,al-1,bl-1);
        }else{
            return max(recursion_LCS(a,b,al,bl-1),recursion_LCS(a,b,al-1,bl));
        }
}

ll recursion_Memory_LCS(string a , string b, ll al , ll bl){
    ll t[al+1][bl+1];    
    memset(t,-1,sizeof(t));
    if(al==0 || bl==0){
        return 0;
    }
   if(t[al][bl] != -1){
       return t[al][bl];
   }

            if(a[al-1]==b[bl-1]){
                return t[al][bl] = 1 + recursion_Memory_LCS(a,b,al-1,bl-1);
                }
                else{
                    return t[al][bl] = max(recursion_Memory_LCS(a,b,al-1,bl),
                                        recursion_Memory_LCS(a,b,al,bl-1));
                }
        
    
    return t[al][bl];
}

ll dp_LCS(string a, string b, ll al ,ll bl){
    ll t[al+1][bl+1];
    for(int i=0 ; i<al+1 ; i++){
        for(int j=0 ; j<bl+1 ; j++){
            if(i==0 || j==0){
                t[i][j] = 0 ;
            }
        }
    }

    for(int i=1; i<al+1 ; i++){
        for(int j=1 ;j<bl+1 ; j++){
            if(a[i-1]==b[j-1]){
                t[i][j] = 1 +  t[i-1][j-1];
            }else{
                t[i][j] = max(t[i-1][j],t[i][j-1]);
            }
        }
    }
    return t[al][bl];
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
string a,b; 
cin>>a>>b;


// cout<<recursion_LCS(a,b,a.size(),b.size())<<endl;
// cout<<recursion_Memory_LCS(a,b,a.size(),b.size())<<endl;
cout<<dp_LCS(a,b,a.size(),b.size())<<endl;




return 0;}