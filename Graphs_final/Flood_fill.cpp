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

int vis[100005];
void dfs(int i, int j , int initialclr , int newColor ,vector<vector<int>>& image ){
int n  = image.size();
int m = image[0].size();
if(i<0 ||j<0)return ;
if(i>=n || j>=m)return ;
if(image[i][j] != initialclr)return ; 
image[i][j] = newColor;
dfs(i-1,j,initialclr,newColor,image);
dfs(i+1,j,initialclr,newColor,image);
dfs(i,j-1,initialclr,newColor,image);
dfs(i,j+1,initialclr,newColor,image);
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
int initialclr = image[sr][sc];
if(initialclr != newColor)
dfs(sr,sc,initialclr,newColor,image);
return image;
    }


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T; while (T--) {
ll n; cin >> n;
ll a[n];
FOR(i, n)
cin >> a[i];





}
return 0;}