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

// 100 80 60 70 60 75 85
//   1  1  1  2  1  4  6  // Consecutive is important 
// Give count of stocks jo usse chota hai from previous CONSECUTIVE days including it 
// Basically hum log isme nearest greater to left hi niukal rahe hai
// Jab tak bada number nahi mil raha tab tak wo stocks me add hoga 
// NGL(intdex) - i will ne pour answer 
vector <int> v ; 
stack <int > s ; 
stack < pair<int , int> > p ;  // NGL and doosre me uska index
int c=1 ; 
for(int i =0 ; i<n ; i++){
    if(p.size()==0){
        v.push_back(-1); // Agar empty hai to ans me add karo nahi to next else if loop 
    }else if(p.size()>0  && p.top().first>a[i]){
        v.push_back(p.top().second);  // Agar numhber valid hai to add karo nahi to next loop 
    }else if(p.size()>0  && p.top().first<=a[i]){ 
        while(p.size()>0  && p.top().first<=a[i]){
            p.pop();  // Jab tak chota number na mile tab tak number ko remove karo 
        }
        if(p.size()==0){
            v.push_back(-1); // Kuch na bache to ofc -1 daal do as ans 
        }else{
            v.push_back(p.top().second); // Agar bach gaya koi number to usko daal do ans me 
        }
    }
    p.push({a[i] , i}); // Push the number and index in stack
}


for (int i = 0; i < n; i++)
{
    cout<<abs(v[i]-i)<<" ";
}





return 0;}