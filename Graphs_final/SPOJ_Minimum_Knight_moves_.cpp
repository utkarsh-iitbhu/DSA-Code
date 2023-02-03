#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimization ('unroll-loops')
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define INF 100000009
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
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

int getX(string s){
    return s[0] - 'a'; 
}

int getY(string s){
    return s[1] - '1'; 
}

int vis[8][8];
int lvl[8][8]; 

vector<pair<int,int>> movments = {
    {-2, -1},
    {-2, 1},
    {-1, -2},
    {-1, 2},
    {1, -2},
    {1, 2},
    {2, -1},
    {2, 1}
};

bool isValid(int x, int y){
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

int bfs(string src , string dest){
    int srcx = getX(src);
    int srcy = getY(src);
    int destx = getX(dest);
    int desty = getY(dest);

    queue<pair<int,int>> q ;
    q.push(MP(srcx,srcy));
    vis[srcx][srcy] = 1;
    lvl[srcx][srcy] = 0;

    while(!q.empty()){
        pair<int,int> v = q.front();
        int x = v.F , y = v.S;
        q.pop(); 
        for(auto moves : movments){
            int childx = x + moves.F;
            int childy = y + moves.S;
            if(!isValid(childx,childy)) continue;
            if(!vis[childx][childy] ){
                q.push(MP(childx,childy));
                lvl[childx][childy] = lvl[x][y] + 1;
                vis[childx][childy] = 1;
            }
        }
    // if(lvl[destx][desty] == INF){
    //     break; 
    // }
    }
    return lvl[destx][desty];
}

void reset(){ // Baar baar chalege to reset kar do dono arrays ko 
    for(int i=0 ; i<8 ; i++){
        for(int j=0 ; j<8 ; j++){
            vis[i][j] = 0;
            lvl[i][j] = INF;
        }
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n ;  cin>>n ; 
    while(n--){
        reset();
        string s1 , s2 ; 
        cin>>s1>>s2;
        cout<<bfs(s1,s2)<<endl;
        }
return 0;}