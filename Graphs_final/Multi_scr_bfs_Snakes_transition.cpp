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
const int n = 10002;    
int N, m ; 
const int INFI = 1e9 + 10 ; 

int val[n][n] ; 
int vis[n][n] ; 
int lvl[n][n] ; 
vector<pair<int,int>> movement = {{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}} ;

bool isValid(int x, int y){
    return (x >= 0 && x < N && y >= 0 && y < m) ; 
}

int bfs(){
    int mx = 0 ; 
    FOR(i,N){ 
        FOR(j,m) {
            if(val[i][j]>mx){
                mx = val[i][j] ; 
            }

        }}
queue <pair<int,int> > q ; 
        FOR(i,N){ 
        FOR(j,m) {
          if(val[i][j]==mx){
            q.push(MP(i,j)) ;
            vis[i][j] = 1 ; 
            lvl[i][j] = 0 ;
          }
        }}
int ans = 0 ; 
        while(!q.empty()){
            int curx = q.front().F ;
            int cury = q.front().S ;
            q.pop() ;
           for(auto move : movement){
               int childx = curx + move.F ;
                int childy = cury + move.S ;
                if(!isValid(childx,childy)){
                    continue ; 
                }
                if(vis[childx][childy]) continue ;
                q.push(MP(childx,childy)) ;
                lvl[childx][childy] = lvl[curx][cury] + 1 ;
                vis[childx][childy] = 1 ;
                ans = max(ans,lvl[childx][childy]) ;
           }
        }
        return ans ;
}



void reset(){
    FOR(i,N){ FOR(j,m) {vis[i][j] = 0 ; lvl[i][j]=INFI ; }}
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T; while (T--) {
        reset(); 
cin >> N;
cin >> m ;
FOR(i,N){ FOR(j,m) {cin >> val[i][j] ; }}

cout<<bfs()<<endl;

}



return 0;}