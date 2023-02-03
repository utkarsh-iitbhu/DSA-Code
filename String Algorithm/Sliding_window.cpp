#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimization ('unroll-loops')
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
#define INF 1000000000000000003
typedef long long int ll;
typedef priority_queue<ll, vector<ll>, greater<ll>>  minhp;
typedef priority_queue<ll> maxhp;
typedef vector<ll> vi;
typedef pair<int, int> pi;
typedef priority_queue <pi , vector<pi> , greater<pi>> minhppi;
#define sz(x) (int)(x).size()
#define F first
#define S second
#define PB push_back
#define POB pop_back
#define MP make_pair
string a,b; 
bool match(int l, int r ,int al){
    for(int i=0 ; i<al ;i++ ){
        if(a[l+i]!=b[i]){
            return false;
        }
    }
    return true ; 
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
// string a,b; 
getline(cin,a);
getline(cin,b);

int al = a.size();
int bl = b.size();

int l=0 , r=0 ; 
ll ans = 0 ;
while(r<=al+1){
    if(r-l<=bl){
        r++;
    }else{
        if(match(l,r,bl)){
            cout<<l<<" ";
            ans++;
        }
        
        l++ ; 
        r++;
    }   
}
cout<<ans<<endl;



return 0;}