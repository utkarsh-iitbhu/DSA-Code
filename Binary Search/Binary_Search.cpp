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
    
int n; cin >> n;
int x ; cin>>x; 
int a[n];
for(int i=0; i<n ; i++)
cin >> a[i];

// Array is given sorted hai and we have to find a given element in it.
sort(a,a+n); // Inbuilt sort method to sort any array 


int l =0 , r=n-1; 
// Start your left and right index

int ans = -1 ; 
// Initialsie ans as -1 if element not present in array 

while(l<=r){ // Jab tak l<=r tak tab chalao fir break kar do mila to sahi nahi to ans=-1
    ll mid = (l+r)/2;
    ll mid_to_stop_overflow = l + (r-l)/2 ; 
    // As we wont be storing int + int anywhere 
    // instead of storing mid as l+r/2 
    // We must store it like l + (r-l)/2

    if(a[mid]>x){ // Array is sorted so if mid element is greater than x
                  // then it will be in left side of array
        r = mid-1; // right pointer ko mid -1 kar do  
    
    }else if(a[mid]<x){ // Vice versa for element less than x
        l = mid+1;
    }else{
        ans = mid; // If a[mid]==x return index asn break the while loop
        break ; 
    }
}
cout<<ans<<endl; 


return 0;}