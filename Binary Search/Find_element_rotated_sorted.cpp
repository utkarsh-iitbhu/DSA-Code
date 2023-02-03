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

int binary_search(int a[] , int l , int r , int x){
    
    while(l<=r){
        int mid  = l + (r-l)/2 ;
        if(a[mid]==x){
            return mid; 
        }else if(a[mid]>x){
            r = mid -1; 
        }else if(a[mid]<x){
            l = mid + 1 ; 
        }
    }
    return -1; 
}

int minimum_element_in_rotated_sorted(int a[] , int n){
    int  l =0 ; 
    int r = n-1 ;
    while(l<=r){
        int mid = l + (r-l)/2; 
        if(a[0]<a[n-1]){
            return 0 ; 
        }
        else if(a[mid]<=a[(mid+1)%n]  &&  a[mid]<=a[(mid-1+n)%n]  ){
            return mid ; 
        }else if(a[0]<=a[mid]){
            l = mid+1 ;
        }else if(a[n-1]>=a[mid]){
            l = mid+1 ; 
        }
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

int n; cin >> n;
int x; cin>>x; 
int a[n];
FOR(i, n)
cin >> a[i];

//  80 98   2 5 6 9
//  Minimum index se element hamesa sorted rahta hai 
// 80 98 is sorted and 2 5 6 9 is sorted
// binary_serarch(arr,start,end) make a function like thsi and get the ans 
// binary_search(arr,0,min-1) && bianry_search(arr,min,n-1) and if both give -1 then number not present 

int ind = minimum_element_in_rotated_sorted(a,n);
// cout<<ind<<endl;     
cout<<max(binary_search(a,0,ind-1,x),binary_search(a,ind,n-1,x))<<endl;

return 0;}