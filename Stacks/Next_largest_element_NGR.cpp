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
// 1 3 2 4
// 3 4 4 -1 output 

// Stack banao aur usme piche se number daalo 
// Ek ans vector banao aur usme reverse me number store honge 
/*
    Stack  ->  Empty hai pahle , first ka ans is -1 and then number add hoga  
    Numbers hai 4 2 3 1  reverse me likha hai 
    Stack me first jaega 4 aur iska ans will be -1 coz last element ka ams is -1
    Ans -> -1 

    Stack ->  4 
    Numbner to check 2 
    ans -> -1  4 as 2 ka bada element is 4

    Stack -> 2 4 
    Numbner to check 3 
    ans -> -1  4 4 as 3 ka bada element is 4 and POP 2
    Stack -> 3  4 

    Stack -> 3 4 
    Numbner to check 1 
    ans -> -1  4 4 3 as 1 ka bada element is 3

    And done ans vect is -1 4 4 3 Isko reverse akro aur print karo 

*/


vector<int> v; 
stack <int> s; 
for(int i= n-1; i>=0 ; i--){
   

    while(!s.empty() && s.top()<=a[i]){
        s.pop();  // Jab tak bada nahi mile ans is -1 
    }

    if(s.empty()){
        v.push_back(-1);  // Empty hai to ans = -1 
    }else{
        v.push_back(s.top());  // Nahi to ans is uska top element 
    }

    s.push(a[i]);   // Iteration ke baad daalna tp padega hi element 

}

// For Next_largest from left wale ka hai ye code 
for(int i =0 ; i<n ; i++){
    if(s.size()==0){
        v.push_back(-1); // Agar empty hai to ans me add karo nahi to next else if loop 
    }else if(s.size()>0  && s.top()>a[i]){
        v.push_back(s.top());  // Agar numhber valid hai to add karo nahi to next loop 
    }else if(s.size()>0  && s.top()<=a[i]){ 
        while(s.size()>0  && s.top()<=a[i]){
            s.pop();  // Jab tak chota number na mile tab tak number ko remove karo 
        }
        if(s.size()==0){
            v.push_back(-1); // Kuch na bache to ofc -1 daal do as ans 
        }else{
            v.push_back(s.top()); // Agar bach gaya koi number to usko daal do ans me 
        }
    }
    s.push(a[i]);
}




reverse(v.begin(),v.end()); 
for(auto i =0 ; i<n ;i++){
    cout<<v[i]<<" ";
}




return 0;}