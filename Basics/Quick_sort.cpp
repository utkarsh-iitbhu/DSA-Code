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

int n ; 
int a[100] ;


void swap(int a[], int i, int j){
        a[i]= a[i]+a[j];
        a[j]= a[i]-a[j];
        a[i]= a[i]-a[j];
    }
    


int partition(int l , int h ){
   int i=l;
        int pivot= a[l];
        int j=h;
      
        while (i<j){
            
            while(a[i] <= pivot && i<h) i++;
            
            while(a[j] >= pivot && j>l) j--;
            
            if(i<j)
                swap(a, i, j);
        }
        
        if(j!=l)    
            swap(a, j, l);
        
        return j;
}

void quick_sort( int l , int r ){
    
    if(l<r){  // Array is of minimum size 2 
        int p = partition(l,r);
        quick_sort( l , p-1 );
        quick_sort( p+1 , r );
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

// Quick Sort jo bhi mijhse chota hai aage jao aur jo badha hai piche jaao
 cin >> n;
// int a[n];
FOR(i, n)
cin >> a[i];

int l =0  , r=n-1; 
quick_sort( l,r);
// partition(l,r);

for(int i=0 ;i<n ; i++){
    cout<<a[i]<<" ";
}







return 0;}