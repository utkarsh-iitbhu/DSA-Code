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
ll x; cin>>x ; 
ll a[n];
FOR(i, n)
cin >> a[i];


ll l =0 , r=n;
 ll ans = -1 ;
 ll fres , lres;   
while(l<=r){
    ll mid = (l+r)/2;
    // ll mid_to_stop_overflow = l + (r-l)/2 ; 
    // As we wont be storing int + int anywhere 
    // instead of storing mid as l+r/2 \
    // We must store it like l + (r-l)/2
    if(a[mid]>x){
        r = mid-1;
    }else if(a[mid]<x){
        l = mid+1;
    }else{
        ans = mid;
        // For first occurence we will search untill we get the first index
        fres = mid; 
        r = mid-1; 
        // We will be keeping 'r' as mid-1 and go deeper and deeper 

    // DONO KO SAATH ME UNCOMMENT NAHI KAR SAKTE BHAI SAMJHA KARO 


        // For last occurence we will search untill we get the last index
        // fres = mid; 
        // l = mid+1; 
        // We will be keeping 'l' as mid+1 and go deeper and deeper 

        // break ; 
    }
}

ll la =0 , ra=n;
while(la<=ra){
    ll mida = (la+ra)/2;
    // ll mid_to_stop_overflow = l + (r-l)/2 ; 
    // As we wont be storing int + int anywhere 
    // instead of storing mid as l+r/2 \
    // We must store it like l + (r-l)/2
    if(a[mida]>x){
        ra = mida-1;
    }else if(a[mida]<x){
        la = mida+1;
    }else{
        ans = mida;
        // For first occurence we will search untill we get the first index
        // fres = mid; 
        // r = mid-1; 
        // We will be keeping 'r' as mid-1 and go deeper and deeper 

    // DONO KO SAATH ME UNCOMMENT NAHI KAR SAKTE BHAI SAMJHA KARO 


        // For last occurence we will search untill we get the last index
        lres = mida; 
        la = mida+1; 
        // We will be keeping 'l' as mid+1 and go deeper and deeper 

        // break ; 
    }
}

cout<<"Binary Search : "<<ans<<endl;
cout<<"First occ : "<<fres<<endl;
cout<<"Last occ : "<<lres<<endl;
cout<<"Count of element : "<<lres-fres+1<<endl;
return 0;}