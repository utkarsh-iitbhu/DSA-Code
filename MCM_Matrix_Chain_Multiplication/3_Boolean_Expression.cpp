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

unordered_map <string, int> m ; 
// i_j_bool , int will be stored in this map 
int boolean_exp_to_true(string s, int i , int j , bool istrue){
        // Evaluate expression to true 
     if(i>j){ // Empty string 
         return 0 ; 
     }

     if(i==j){
         if(istrue==true){
             if( s[i] == 'T'){
             return 1; 
             }else{
             return 0 ; 
                 }
         }else{
             if( s[i] == 'F'){
             return 1 ;
             }else{
             return 0;
             }
         }
     }

    string temp  = to_string(i);
    temp.push_back(' ');
    temp.append(to_string(j));
    temp.push_back(' ');
    temp.append(to_string(istrue));

    if(m.find(temp) != m.end()){
        return m[temp];
    }


    int ans = 0 ;
     // T | F ^ T & F
     //   |       |  this interval k will lie
     for(int k=i+1 ; k<=j-1 ; k=k+2){
         int lT = boolean_exp_to_true(s,i,k-1,true);
         int rT = boolean_exp_to_true(s,k+1,j,true);
         int lF = boolean_exp_to_true(s,i,k-1,false);
         int rF = boolean_exp_to_true(s,k+1,j,false);
        
            if(s[k]=='|'){
                if(istrue==true){
                    ans  = ans + lT*rT + lT*rF + lF*rT; 
                }else{
                    ans = ans + lF*rF;
                }
                }

                else if(s[k]=='&'){
                if(istrue==true){
                    ans  = ans + lT*rT;
                }else{
                    ans = ans + lF*rF + lT*rF + lF*rT; 
                    
                }
                }

                else if(s[k]=='^'){
                if(istrue==true){
                    ans  = ans + lT*rF + rT*lF ;
                }else{
                    ans = ans + lF*rF + lT*rT; 
                }
                }
     } 
            m[temp] = ans%1003;
     return m[temp] ; 
    }

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s; 
    cin>>s; 
    int i =0 , j = s.size()-1;
    m.clear();
cout<<boolean_exp_to_true(s,i,j,true)<<endl;

return 0;}