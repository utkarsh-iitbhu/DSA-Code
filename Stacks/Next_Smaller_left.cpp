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
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

ll n; cin >> n;
ll a[n];
FOR(i, n)
cin >> a[i];

// 4   5   2  10  8  Given array 
// -1  4  -1  2   2 is our answer 


// If u want to do it from left tab kya changes aaenge 
// First -> Loop will start from the end till zero index
// Second -> Ans array ko reverse kar ke output karna padega
// Baaki kuch nahi badlega  

vector <int> v; 
stack <int> s ; 
for(int i=0 ; i<n ;i++){
    while(!s.empty() && s.top()>=a[i]){
        s.pop();
    }
    
    if(s.empty()){
        v.push_back(-1);
    }else{
        v.push_back(s.top());
    }

    s.push(a[i]);
}

for(int i=0 ; i<n ; i++){
    cout<<v[i]<<" ";
}

return 0;}