#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimization ('unroll-loops')
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 10  e9 + 7
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
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    /* Bit Manipulation 
     We know basic of gate operation 
     Key points for different operations 
     & -> AND ; if BOTH BIT ARE 1 THEN WE GET 1 AS OUTPUT   ( 1 & 1 = 1) ( 1 | 0 = 0)
     | -> OR ; if ANY BIT ARE 1 THEN WE GET 1 AS OUTPUT     ( 1 | 0 = 1) ( 1 | 1 = 1)
     ^ -> XOR ; if BOTH BIT ARE DIFFERENT THEN WE GET 1 AS OUTPUT  ( 1 ^ 0 = 1) ( 1 ^ 1 = 0)
    >> -> RIGHT SHIFT ; WE GET RIGHT SHIFTED BIT AS OUTPUT ( 12 >> 1 = 6) ( 12 >> 2 = 3) // Used for division by 2
    << -> LEFT SHIFT ; WE GET LEFT SHIFTED BIT AS OUTPUT  ( 12 << 1 = 24) ( 12 << 2 = 48) // Used for multiplication by 2
    
    Check wether number is divisible by 2 or not
    if(n & 1) == 0 then n is divisible by 2 // 
    Ex: 7 -> 111 ; 7&1 -> 111 & 001 -> ANS = 001 = 1 i.e 7 is divisible by 2
    Ex: 6 -> 110 ; 6&1 -> 110 & 001 -> ANS = 000 = 0 i.e 6 is not divisible by 2
    Take AND with 1 and check wether it is 0 or not (If 0 then n is divisible by 2)

    Swap two numbers without using third variable or rather using bits
    Ex: a = 10 , b = 20
    a = a^b ; 
    b = a^b ; 
    a = a^b ;
    Done numbers are swapped 

    */
    int a = 5 ; 
    int b =  6; 
     
     (a&1) == 0 ? cout<<"a is divisible by 2"<<endl : cout<<"a is not divisible by 2"<<endl ;
     (b&1) == 0 ? cout<<"b is divisible by 2"<<endl : cout<<"b is not divisible by 2"<<endl ;

     a = a^b;
     b = a^b;
     a = a^b;
     cout<<a<<" "<<b<<endl;

    /*
      Find ith Bit of a number wether it is 1 or 0 
      Shifting of 1 to ith place and operating is known as masking 
      What we can do is to check wether ith bit is 1 or 0 by using AND operation
        Ex: n = 10 , i = 2
        n = 10 & (1<<i) = 10 & 2 = 0 ; 1 will get left shifted i times and fir AND liya
        If ans is 0 then ith bit is 0 else ith bit is 1

    */

   int n = 10 , i = 3 ; // 10 -> 1010 
    (n&(1<<i)) == 0 ? cout<<"ith bit is 0"<<endl : cout<<"ith bit is 1"<<endl ;

    /* Set ith Bit 
        Now we want to change the ith bit of a number to 1 
        We can do this by using OR operation
        i.e n OR (1<<i) ; number is 10 => 1010 and we have to set ith bit to 1 => 1110 
        Ex: n = 10 , i = 2
        mask = 1 << i ; mask = 4
        n = n | (1<<i) = 10 | mask = 1110 i.e 14 
    */
   
   int n1 = 10 , i1 = 2; // 10 -> 1010 
    n1 = n1  |  (1 << i1);
    cout<<"After bitmasking setting ith bit to 1 : "<<n1<<endl;

    /* Set ith bit as 0
        Now we want to change the ith bit of a number to 0 
        We can do this by using AND operation
        i.e n AND ~(1<<i) ; number is 10 => 1010 and we have to set ith bit to 0 => 1000 here i=1 
        Ex: n = 10 , i = 1
        mask = 1 << 2 ; mask = 2 [000..0010]
        Now take compliment [111..111101] is compliment of 2
        n = 10 -> 1010 & ..1101 everything remains same except the ith bit switches to 0 as (1&0 && 0&0) = 0
        n = n & ~(1<<i) = 10 & mask = 1010 i.e 10
    */
   int n3 = 10 , i3=1; 
   int mask3 = 1<<i3;
   int compliment = ~mask3;
    n3 = n3 & compliment;
    cout<<"After bitmasking setting ith bit to 0 : "<<n3<<endl;

    /* Number of bits required to change a number from a to b 
        Ex: 1101 and 1010 So her we have to change three bits of index 0,1,2 
        Here we will take XOR of two numbers as we know XOR of two numbers will give us the number of bits that are different
        Ex: 1101 XOR 1010 = 0111, Now we have to simply count number of 1's in this number
        Here we already knew we had to change 3 bits so we can simply count number of 1's in this number
        Ex: 0111 = 3(number of 1 in this number)
        We can use a while loop to count number of 1's in this number by checking its last bit
        For 0111 Perform right shift operation by 1 and check wether it is 1 or not
        0 1 1 1 -> count =0 
        0 0 1 1 -> count =1
        0 0 0 1 -> count =2
        0 0 0 0 -> count =3
        So we can simply count number of 1's in this number by checking its last bit and until it is 0
        BUT THIS WILL TAKE A LOT OF TIME IN TERMS OF COMPLEXITY 

        SHORT CUT : 
        WE CAN USE { n ^ (n-1) } to count number of 1's in this number
        Untill we get 0 then we know number of 1's in this number
        Lets Implement 
    */
    int n4 = 13 , n5 = 10 ; // 13 10
    int n6 = n4 ^ n5 ; // 0111
    int count = 0 ;
    while(n6){
        n6 = n6 & (n6-1);
        count++;
    }
    cout<<"Number of bits required to change : "<<count<<endl;


return 0;}