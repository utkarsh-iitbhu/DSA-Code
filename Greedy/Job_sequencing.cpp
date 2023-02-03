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

struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

bool comp(Job a , Job b){
        return a.profit>b.profit;
    
}

vector<int> JobScheduling(Job arr[], int n) 
    { 
        vector<int> v; 
        sort(arr,arr+n,comp);
        int mx = arr[0].dead ; 
        for(int i= 1; i<n ; i++){
            mx = max(mx,arr[i].dead);
        }
        int slot[mx+1]; 
        memset(slot,-1,sizeof(slot));
        
        int countjob = 0; 
        int jobprofit =0 ; 
        for(int i=0; i<n ; i++){
            for(int j=arr[i].dead ; j>0 ; j--){
                if(slot[j]==-1){
                    slot[j]=i ; 
                    countjob++;
                    jobprofit += arr[i].profit;
                    break;
                }
            }
        }
        
        v.push_back(countjob);
        v.push_back(jobprofit); 
        return v; 
    } 


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

ll n; cin >> n;
Job a[n];
FOR(i, n)
cin >> a[i].id;

FOR(i, n)
cin >> a[i].dead;

FOR(i, n)
cin >> a[i].profit;

vector<int> ans = JobScheduling(a,n);
cout<<ans[0]<<" "<<ans[1]<<endl;



return 0;}