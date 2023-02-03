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

unordered_map <string, bool> m ;

bool scrambled_string(string a , string b){
    if(a.compare(b)==0) return true;
    if(a.length()<=1) return false;
    int n = a.length();
    bool flag  = false; 
    for(int i =0 ; i<n ; i++){
    if(scrambled_string(a.substr(0,i),b.substr(n-i,i))==true || scrambled_string(a.substr(i,n-i),b.substr(0,n-i))==true         
           &&
        scrambled_string(a.substr(0,i),b.substr(0,i))==true || scrambled_string(a.substr(i,n-i),b.substr(i,n-i))==true
    ){
        flag = true; 
        break ;
    }
    }
    return flag;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
 string a,b; cin>>a>>b;
m.clear() ; 
if(a.length() != b.length()){
    return 0 ;
}
if(a.empty() && b.empty()){
    return 1 ;
}

cout<<scrambled_string(a,b)<<endl;

return 0;}
