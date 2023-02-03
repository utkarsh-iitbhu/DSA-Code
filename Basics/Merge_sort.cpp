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

int b[100] ;
void merge_func(int a[] , int l , int mid  , int r){
    int i = l , j = mid+1 , k = l;
    while(i<=mid && j<=r){
        if(a[i]<a[j]){
            b[k] = a[i]; // As a[i] < a[j] to pahle a[i] ko b[k] me store krna hai  
            i++; 
        }else{
            b[k] = a[j];
            j++;    
        }
        k++;
    }
    if(i>mid){  // El array poora finish ho gaya 
    // Bache hue doosre array ko daal do 
        while(j<=r){
            b[k] = a[j];
            j++;
            k++;
        }
    }else if(j>r){
        while(i<=mid){
            b[k] = a[i];
            i++;
            k++;
        }
    }
    for (int k=l ; k<=r ; k++){
        a[k] = b[k]; 
    }

}

void merge_sort(int a[], int l, int r){
    if(l<r){
        int mid = l + (r-l)/2;
        merge_sort(a, l, mid);
        merge_sort(a, mid+1, r);
        merge_func(a,l,mid,r);
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

int  n; cin >> n;
int a[n];
FOR(i, n)
cin >> a[i];
merge_sort(a, 0, n-1);
for(int i=0; i<n; i++){
    cout << a[i] << " ";
}







return 0;}