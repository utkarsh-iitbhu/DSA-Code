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

/*  My approach of solving this problem
      // k = i ;
        // while(k<=j){
        //     if(a[k]<0){
        //         cout<<a[k]<<" ";
        //         break;
        //     }
        //     k++;
        // }
        //   i++;
        //     j++;



*/

void func( ll A[], ll N, ll K){
      queue<long long> q;
    vector<long long> ans;
    long long i = 0,j = 0;
    
    while(j<N){
        if(A[j]<0)
            q.push(A[j]);
        if(j-i+1 < K){
            j++;
        }
        else{
            if(q.empty()) ans.push_back(0);
            else{
                ans.push_back(q.front());
                if(q.front() == A[i])
                    q.pop();
            }
            i++;j++;
        }
    }
    for(int i=0 ; i<ans.size() ; i++){
        cout<<ans[i]<<" ";
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
ll n; cin >> n;
ll w ; cin>>w;
ll a[n];
FOR(i, n)
cin >> a[i];

ll i =0, j= 0; 
ll sum = 0  ; 
vector<ll> v; 
queue <ll> q ;
while(j<n){
    if(a[j]<0){
        q.push(a[j]);
    }
    if(j-i+1<w){
        j++;
    }else{
      
    if(q.empty()==true){
        v.push_back(0);
    }else{
        v.push_back(q.front());
        if(q.front()==a[i]){
            q.pop();
   }     
    }
        i++ ;
        j++; 
    
}

}
for(int i=0 ; i<v.size() ; i++){
    cout<<v[i]<<" ";
}

// func(a, n, w);


return 0;}