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


stack <ll> s;  // Are actual stack 
stack <ll> support ; // We are using an extra stack to get minimum 

void push(ll a){
    s.push(a);
    if(support.empty() || support.top()>=a){ // >= is important as multiple elements can be pushed in the stack
        support.push(a);
        return ;
        } 
}

ll pop(){
    if(s.size()==0){
        return -1;
    }
    int ans = s.top();
    // s.pop(); if(support.top()==ans){support.pop();} return ans ; 
    if(s.top()==support.top()){
        support.pop();
        s.pop();
    }else{
        s.pop();
    }
    return ans ; 
}

ll get_minimum(){   // At any given time we will get the minimum element in the stack 
    if(support.empty()){
        return -1;
    }else{
        return support.top();
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

ll n; cin >> n;
ll a[n];
FOR(i, n)
cin >> a[i];


// We need three functions i.e pop push and to get minimum 
// Upar milenge teeno function call karne ke liye






return 0;}