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

int knapsack(int wt[] , int val[] , int w , int n){
    if(n==0 || w==0){
        return 0; 
    }
    if(wt[n-1]<=w){
        return max(val[n-1]+knapsack(wt,val,w-wt[n-1],n-1),knapsack(wt,val,w,n-1));
    }else if(wt[n-1]>w){
        return knapsack(wt,val,w,n-1);
    }
}

int t[10][10] ;


int top_down_knapsack(int wt[] , int val[] , int w , int n){
    if(n==0 || w==0){
        return 0; 
    }
    if(t[n][w] != -1){
        return t[n][w]; 
    }
    if(wt[n-1]<=w){
        return t[n][w] = max(val[n-1]+knapsack(wt,val,w-wt[n-1],n-1),knapsack(wt,val,w,n-1));
    }else if(wt[n-1]>w){
        return t[n][w] = knapsack(wt,val,w,n-1);
    }
}


int dp_approach_for_knapsack(int wt[] , int val[] ,int n, int w){
    for(int i=0 ; i<n+1; i++ ){
        for(int j=0 ; j<w+1 ; j++){
            if(i==0 || j==0){
                t[i][j]=0;
            }
        }
    }

    for(int i=1 ; i<n+1; i++ ){
        for(int j=1 ; j<w+1 ; j++){
            if(wt[i-1]<=j){
                t[i][j] = max(val[i-1] + t[i-1][j-wt[i-1]], t[i-1][j]);
            }else if(wt[i-1] > j){
                t[i][j] = t[i-1][j];
            }
        }
    }

    return t[n][w];

}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // memset(t,-1,sizeof(t));
int n; cin >> n;
int w; cin>>w; 
int wt[n],val[n];
FOR(i, n)
cin >> wt[i];

FOR(i, n)
cin >> val[i];

// cout<<knapsack(wt,val,w,n)<<endl;
// cout<<top_down_knapsack(wt,val,w,n)<<endl;
cout<<dp_approach_for_knapsack(wt,val,n,w)<<endl;
FOR(i,6){
    FOR(j,8){
        cout<<t[i][j]<<"  ";
    }cout<<endl;
}




return 0;}