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


 int findPlatform(ll arr[], ll dep[], ll n)
    {
    	int i=1 , j =0 ; 
    	int curr=1 ; 
    	int ans = 1; 
    	sort(arr,arr+n); 
    	sort(dep, dep+n);
        while(i<n && j<n){
            if(arr[i]<=dep[j]){
            curr++;
            i++;
            }
            else if(arr[i]>dep[j]){
                curr--;
                j++;
            }
            if(curr>ans){
                ans = curr; 
            }
            
        }
        return ans ;
    }


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
ll n; cin >> n;
ll a[n];
FOR(i, n)
cin >> a[i];
ll dep[n];
FOR(i, n)
cin >> dep[i];

cout<<findPlatform(a,dep,n)<<endl;






return 0;}