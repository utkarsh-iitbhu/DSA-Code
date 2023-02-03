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
int t[101][101];

bool isPalindrome(string s, int i, int j ){
    bool flag = false; 
    if(i==j) return true;
    if(i>j) return true;
    while(i<j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;
        j--;
    }
        return true;
}

int palindrome_partition(string s , int i , int j){
        int left , right  ;
        if(i>=j){ return 0 ; }
        if(isPalindrome(s,i,j)){ return 0 ;}
        if(t[i][j] != -1 ) return t[i][j] ; 
        int ans = INT_MAX ; 
        for(int k= i ; k<j ; k++){
            
            if(t[i][k] != -1){
                left =  t[i][k] ;
            }else{
                left = palindrome_partition(s,i,k);
                t[i][k] = left;
            }
            
            if(t[k+1][j] != -1){
                right =  t[k+1][j] ;
            }else{
                right = palindrome_partition(s,k+1,j);
                t[k+1][j] = right;
            }
            
            //   int temp=palindrome_partition(s,i,k)
            //   +palindrome_partition(s,k+1,j);
            int temp = left + right ; 
            
            // int temp = palindrome_partition(s,i,k) 
            //           + palindrome_partition(s,k+1,j);
            ans = min(1+temp,ans);
        }
        return t[i][j] = ans ; 
    }



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s; cin>>s; 
int i =0 , j = s.size()-1;
memset(t,-1,sizeof(t));
cout<<palindrome_partition(s,i,j)<<endl;




return 0;}