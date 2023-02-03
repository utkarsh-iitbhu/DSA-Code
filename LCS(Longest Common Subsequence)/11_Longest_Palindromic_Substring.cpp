// // Given a string s, return the longest palindromic substring in s.

 

// // Example 1:

// // Input: s = "babad"
// // Output: "bab"
// // Explanation: "aba" is also a valid answer.
// // Example 2:

// // Input: s = "cbbd"
// // Output: "bb"

// class Solution {

// string expandAroundCenter(string s, int left, int right) {
//     int l = 0, r = 0;
//     int len = s.length();
//     int start = 0, end = 0;
//     int maxLen = 0;
//     while (l < len && r < len) {
//         if (s[l] == s[r]) {
//             l++;
//             r++;
//         } else {
//             l = 0;
//             r = 0;
//         }
//         if (r - l > maxLen) {
//             start = l;
//             end = r;
//             maxLen = r - l;
//         }
//     }
//     return s.substring(start, end);
// }

// public:
//     string longestPalindrome(string s) {
//         int n = s.size();
//         if(n == 0) return "";
//         int start = 0, end = 0;
//         for(int i = 0; i < n; i++) {
//             int len1 = expandAroundCenter(s, i, i);
//             int len2 = expandAroundCenter(s, i, i + 1);
//             int len = max(len1, len2);
//             if(len > end - start) {
//                 start = i - (len - 1) / 2;
//                 end = i + len / 2;
//             }
//         }
//         return s.substr(start, end - start + 1);
//     }
        
//     }
// };
 
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

string substring(string a, string b, ll al , ll bl){
    ll t[al+1][bl+1] ;
        for(int i=0 ; i<al+1 ; i++){
            for(int j=0 ; j<bl+1 ; j++){
                if(i==0 || j==0){
                    t[i][j] =0 ;
            }else if(a[i-1] == b[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
            }else{
                // t[i][j] = max(t[i-1][j],t[i][j-1]);
                t[i][j] = 0;
            }
        }
}

// for (int i = 0; i < al+1; i++)
// {
//     for (int j = 0; j < bl+1; j++)
//     {
//             cout<<t[i][j]<<" ";
//     }cout<<endl;
    
// }




ll mx = INT_MIN; 
        for(int i=0 ; i<al+1; i++){
        for(int j=0; j<bl+1 ; j++){
            mx  = max(mx,t[i][j]);
        }
        }
        
        

string ans = "";
for (int i = 1; i < al+1; i++)
{
    for (int j = 1; j < bl+1; j++)
    {
            if(t[i][j]==mx){
                ans += a[i-1];

                while((i>0 || j>0) && a[i-1]==b[j-1]){
                    i--;
                    j--;
                    ans += a[i];
                }
                
            }
        }
    }
 return ans ;

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T; while (T--) {
string a ;
cin>>a;
string b=a; 
reverse(b.begin(),b.end());
cout<<substring(a,b,a.size(),b.size())<<endl;




}
return 0;}

