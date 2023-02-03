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

struct Item{
    int value;
    int weight;
};
   
bool comp(Item a , Item b){
    double l1 = (double)a.value/(double)a.weight;
    double l2 = (double)b.value/(double)b.weight;
    return l1>l2;
}

    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr,arr+n,comp);
        int currw = 0 ;
        double ans = 0.0 ; 
        for(int i=0 ; i<n ; i++){
            if(currw + arr[i].weight <= W){
                currw +=  arr[i].weight ; 
                ans +=  arr[i].value ; 
            }else{
                int rem = W - currw ; 
                ans += (arr[i].value / (double)arr[i].weight)*(double)rem; 
                break;
            }
        }
        return ans ; 
        
    }



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

int n; cin >> n;
int W ; cin>>W ;
Item arr[n];

FOR(i, n){
cin >> arr[i].value >> arr[i].weight ;
}

cout<<fractionalKnapsack(W,arr,n)<<endl;





return 0;}