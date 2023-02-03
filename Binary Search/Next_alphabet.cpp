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


char find_next_alphabet(string s , char x){
    int  l =0 ; 
 int r = s.size()-1; 
 char ans ; 
 while(l<=r){
     int mid = l + (r-l)/2 ;
     if(s[mid]==x && mid<=s.size()-1){
        l = mid+1 ; // Mil bhi jae to aage badho coz next alphabet is the ans 
     }else if(s[mid]>x){
         r = mid-1; 
         ans = s[mid];  // this can be ans so  store it 
     }else if(s[mid]<x){
         l = mid+1; 
     }
 }
 return ans;
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
 string s ; cin>>s; 
 char x ;  cin>>x; 


// This approach will fail for repetitivew characters 
//  int  l =0 ; 
//  int r = s.size()-1; 
//  while(l<=r){
//      int mid = l + (r-l)/2 ;
//      if(s[mid]==x && mid<=s.size()-1){
//          cout<<s[mid+1]<<endl;
//          break;
//      }else if(s[mid]<x && s[mid+1]>x){
//          cout<<s[mid+1]<<endl;
//          break;
//      }else if(s[mid]>x && s[mid-1]<x){
//          cout<<s[mid]<<endl;
//          break;
//      }else if(s[mid]>x){
//          r = mid-1; 
//      }else if(s[mid]<x){
//          l = mid+1; 
//      }
//  }
// cout<<-1<<endl;

cout<<find_next_alphabet(s,x)<<endl;


return 0;}