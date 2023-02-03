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

int find_the_only_non_repeating_element(int a[], int n){
    // We have a array 5 3 4 1 4 5 1; so our ans will be 3 as it is the only non repeating element
    // res is initialised with 0; so res^a[i] will be a[i] itself
    // This is how numbers will be stored in res 
    // res = 5^3^4^1^4^5^1 and now we know a^a=0 ; 
    // So 5 4 1 gets cancelled out and we remain with 3 as our output in res
    int res = 0 ;
    for(int i=0 ;i<n ;i++){
        res = res ^ a[i];
    }
    cout<<"Only non repeating element is "<<res<<endl;
}

int find_the_two_non_repeating_element(int a[], int n){
    /* 5 4 1 4 3 5 1 2 here ans is 3 and 2 as they are the only non repeating elements
       res is initialised with 0; so res^a[i] will be a[i] itself
       Take xor of all the numbers so res = 3^2 as our output
       Now we have to seapaate the numbers from each other
       res = 3^2 -> 11^10 -> 01 number 1
       Now split the array and check for number whose right most bit is one (rather odd number)
       and then rnu xor of all the numbers in that array
       res = 3^2 and the array will be 5 1 3 5 1 
       ans  = res^5^1^3^5^1 = 3^5^1 = 2
       so we got ans = 2; this is our first number 
       Now take res ^ ans -> 3^2^2 -> 3 
       This will give our second number
    */
    int res = 0 ;
    for(int i=0 ;i<n ;i++){
        res = res ^ a[i];
    }
    vector<int> v; 
    for(int i=0 ;i<n ;i++){
        if((a[i] & 1)==1){ // odd number 
            v.PB(a[i]);
        }
    }
    int ans =0 ; 
    for(int i=0 ;i<sz(v) ;i++){
        ans = ans ^ v[i];
    }
    int sec = res^ans ;
    cout<<"First number is : "<<ans<<endl;
    cout<<"Second number is : "<<sec<<endl;
    

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
/* XOR Why do we use it alot 
    PROPERTIES OF XOR : 
    1. XOR of same number is zero(0) ; 5^5 -> 101^101 -> 0 [Same bits are zero in XOR]
    2. XOR of any number with zero is the number itself(5^0 -> 5) ; 5^0 -> 101^000 -> 101
    3. Ordering of XOR doesnt matter 2^3^1 == 1^3^2
    4. XOR of close numbers is always less than XOR of far numbers (5^4 < 5^3) 
AS NUMBERS WILL HAVE SIMILAR NUMBER OF BITS 5-> 101 and 4->100 XOR lo -> 101^100 -> 011[3] and 5->101 XOR 3->011 = 100[4]
    5. 

*/ 

int a[] = {5,3,4,1,4,5,1};
int b[] = {5,3,4,1,4,5,1,2};
int n = sizeof(a)/sizeof(a[0]);
int m = sizeof(b)/sizeof(b[0]);
find_the_only_non_repeating_element(a,n);
find_the_two_non_repeating_element(b,m);
return 0;}  