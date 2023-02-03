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
 
 ll a[n];
 FOR(i, n)
 cin >> a[i];
 
 // To find number of rotations we can find the minimum element
 // Uske index se pata chal jaega hame ki kitna rotate hua hai 
 // Left / right rptate ke liye a[mid] or a[n-mid] lagega as ans  
 
 // How can we find minimum element 
 // We know prev and next number will be greter then the smallest number and this will always hold true
 // As we are having a rotated sorted array 
 // 2 3 4 5 -> 4 5 2 3 only this cond holds true for number 2  
 
 // 11 12 15 18 2 5 6 8 a[mid] -> 18 here 
 // Split the array 11 12 15 18 && 18 2 5 6 8
 // Now check wether first and last element is greater or lesser than a[mid]
 // MINIMUM ELEMENT WILL ALWAYS LIE IN THE UNSORTED ARRAY i.e 18 2 5 6 8 here not in 11 12 15 18
 // 11 12 15 18 here a[0] < a[mid] that means first half is sorted so minimum will bw present in the second half
 // 18 2 5 6 8 here a[mid]<a[n-1] so this is unsorted part and it will be having the minimum element 
 
 ll l=0 , r=n-1 ; 
 ll ans = -1 ; 
 while(l<=r){
     ll mid = l + (r-l)/2; 
     if(a[0]<a[n-1]){
         ans = 0 ; 
         break; 
     }
     else if(a[mid]<a[(mid+1)%n] && a[mid]<a[(mid-1+n)%n]){   // To check for smallest number  
        ans  = mid; 
        break ; 
     }
     else if(a[0]<=a[mid]){
         l = mid+1; 
     }
     else if(a[mid]<=a[n-1]){
         r = mid-1; 
     }
 }

 cout<<ans<<endl; 
 
 
 return 0;}