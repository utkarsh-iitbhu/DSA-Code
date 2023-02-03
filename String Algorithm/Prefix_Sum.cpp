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

string s ; 
vector<int> pie(100); // This will store the prefix array.

// We want to calculate prefix array for a given string s.
// vector<int> prefiix_arry(string s){
void prefix_array(string s){
    int n = s.size() ;
    
    for(int i=0 ;i<n ;i++){
        for(int k=0 ;k<=i; k++){
            if(s.substr(0,k)==s.substr(i-k+1,k)){
                pie[i]=k;
            }
        }
    }
    // return pi ;
}


// Implement preffix array in a complexity of 0(N) time 
vector<int> pr(100);
void prefix_array_Optimised(string s){
    int n= s.size() ; 
    for(int i=1 ;i<n ;i++){
        int j = pr[i-1];
        while(j>0 && s[i]!=s[j]){
            j = pr[j-1];
        }
        if(s[i]==s[j]){
            j++;
        }else
        pr[i] = j;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

cin>>s;
prefix_array(s);
prefix_array_Optimised(s);


for(int i=0 ;i<s.size() ;i++){
    cout<<pie[i]<<" ";
}cout<<endl;

for(int i=0 ;i<s.size() ;i++){
    cout<<pr[i]<<" ";
}



return 0;}