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

bool should_i_swap(pair<int,int> a , pair<int,int> b){
    // F ko ascending me b ko descending me
    // 1 2 , 1 3 , 2 5
    // 1 3 , 1 2 , 2 5 // Aise hoga sort krna padega
    if(a.first != b.first){
        if(a.first > b.first){
            return true ;
        }return false; 
    }else{
        if(a.second < b.second){
            return true;
    }return false; 
}
}

bool comparator(pair<int,int> a , pair<int,int> b){
    // F ko ascending me S ko descending me
    // 1 2 , 1 3 , 2 5
    // 1 3 , 1 2 , 2 5 // Aise hoga sort krna padega
    // if(a.first != b.first){
    //     if(a.first > b.first){
    //         return false ; // Ulta kar do T and F ko 
    //     }return true;  // See its important
    // }else{
    //     if(a.second < b.second){
    //         return false;
    // }return true; 

    // SHORTCUT TAREEKA BHI HAI JO CHAHIYE WO RETURN KARO
    if(a.first != b.first){
    return a.first<b.first;
    }
    return a.second>b.second;
}

bool decreasing_cmp(int a , int b){
    return a>b; // decreasing order
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

ll n; cin >> n;
vector<pair<int,int>> a(n);
FOR(i, n){
    cin >> a[i].F >> a[i].S;
}

sort(a.begin(), a.end(), comparator);
/* Comparator function ulta chalta hai 
   Agar swap karna hai to mujhe FALSE return krna padega
   Agar nahi karna to mujhe TRUE return krna padega
   ULTA HAI DONT GET CONFUSED  

*/

// for(int i=0 ; i<n ; i++){
//     for(int j=i+1 ; j<n ; j++){
//         if(should_i_swap(a[i],a[j])){
//             swap(a[i], a[j]);
//         }
//     }
// }
for(int i=0 ; i<n ; i++){
    cout<<a[i].F<<" "<<a[i].S<<endl;
}



return 0;}