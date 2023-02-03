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

int find(int arr[], int n, int x)
{
    int st = 0, ed = n - 1;
    while (st <= ed)
    {
        int mid = (st + ed) / 2;
        if (arr[mid] == x)
            return mid;
        if (mid > 0 && arr[mid - 1] == x)
            return mid - 1;
        if (mid < n - 1 && arr[mid + 1] == x)
            return mid + 1;

        if (arr[mid] > x)
        {
            ed = mid - 2;
        }
        else
        {
            st = mid + 2;
        }
    }
    // Not Found
    return -1;
}



int search_in_nearly_sorted_array(int a[] , int l , int r, int x){
    
if(l<=r){
    int mid = l - (r-l)/2 ;
    if(a[mid]==x){
        return mid ; 
        // break ;
    } if(mid-1>=l  && a[mid-1]==x){
        return mid -1; 
        // break; 
    } if(mid+1<=r && a[mid+1]==x){
        return mid+1;  
        // break ;
    } if(a[mid]<x){
        // l = mid+2 ;
       return  search_in_nearly_sorted_array(a,mid+2,r,x); 
    } if(a[mid]>x){
        // r = mid-2 ; 
        return search_in_nearly_sorted_array(a,l,mid-2,x);
    }
}
return -1; 
}

vector<int> solve(vector<vector<int>>& e) {
    int n = e.size();
    vector<int> g[n+1];
    vector<bool> vis(false,n+1);

    for(int i=0 ; i<n ; i++){
        g[e[i][0]].push_back(e[i][1]);
    }
    
    
vector<int> ans; 
    for(int i=0 ; i<=n ; i++){
        if(!vis[i]){
            auto d = [&](int v, auto &&d)->void{
            vis[v] = true;
            for(auto ch:g[v]){
                if(!vis[ch]){
                    d(ch,d);
                }
            }
        };
            ans.push_back(i);
            d(i,d);
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
int n; cin >> n;
int x ; cin>>x; 
 
int a[n];  
FOR(i, n)
cin >> a[i];

// int ans = search_in_nearly_sorted_array(a,0,n-1,x);
// cout<<ans<<endl;
// (ans==-1)?cout<<-1<<endl:cout<<ans<<endl;

cout<<find(a,n,x)<<endl;
return 0;}