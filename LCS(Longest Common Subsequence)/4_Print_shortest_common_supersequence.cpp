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

string lcs(string a , string b , ll al , ll bl){
      ll t[al+1][bl+1];
    for(int i=0 ; i<al+1 ; i++){
        for(int j=0 ; j<bl+1 ; j++){
            if(i==0 || j==0){
                t[i][j] = 0 ; 
            }

            else if(a[i-1]==b[j-1]){
                t[i][j] = 1 + t[i-1][j-1]; 
            }else{
                t[i][j] = max(t[i-1][j],t[i][j-1]);
            }
        }
    }

ll i = al , j =bl ; 
string ans = "";
while(i>0 && j>0){
         if(a[i-1]==b[j-1]){
            ans.push_back(a[i-1]);
            i--;
            j--;
        }else{
            if(t[i-1][j]>t[i][j-1]){
                i--;
            }else{
                j--;
            
        }
    }
}
reverse(ans.begin(),ans.end());
return ans ;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
string a,b;
cin>>a>>b; 

string sub = lcs(a,b,a.size(),b.size()) ;

// cout<<sub<<endl; 
string ans  = "";
// Now we need three pointers 
ll p1 = 0 , p2 =0 ; 
for(auto c : sub){
    while(a[p1] != c){
        ans += a[p1];
        p1++;
    }
    while(b[p2] != c){
        ans += b[p2];
        p2++;
    }
    ans += c;
    p1++;
    p2++;
}

ans  += a.substr(p1);
ans  += b.substr(p2);

cout<<ans<<endl;







return 0;}