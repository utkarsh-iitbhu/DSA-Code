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

int min_ele ;  
stack <ll> s; 

int get_min(){
    if(s.size()==0){
        return -1 ;
    }else{
        return min_ele ;
    }
}


void push(int x){
    if(s.size()==0){
        s.push(x);
        min_ele = x ; 
    }else{
        if(x>min_ele){   // 7 > 5 
            s.push(x);
}else if(x<min_ele){   // 3 < 5 
        s.push(2*x - min_ele);  // Yaha push ho jaega 1 , 2*3 - 5 = 1
        min_ele = x ;
}
    }
}

void pop(){
    if(s.size()==0){
        return ; 
    }else{
        if(s.top()>=min_ele){
            s.pop();
        }else if(s.top()<min_ele){
            min_ele = 2*min_ele - s.top();
            s.pop();
        }
    }
}

int top(){
    if(s.size()==0){
        return -1 ;
    }else{
        if(s.top()>=min_ele){
            return s.top();
    }else if(s.top()<min_ele){
        return min_ele; 
    }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

ll n; cin >> n;
ll a[n];
FOR(i, n)
cin >> a[i];
// O(1) space means we can only use variables any container is of size O(N)






return 0;}