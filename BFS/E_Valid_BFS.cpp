#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

// #include <bits/stdc++.h> // Not portable, use only on some platforms
#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <utility>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
using namespace std;

#ifdef TOWRIST
    #define debug(...) cout << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__);
#else
    #define debug(...);
#endif

template <typename T> std::ostream &operator<<(std::ostream &stream, const vector<T> &vec) {for (size_t i = 0; i < vec.size(); i++) { stream << vec[i]; if (i != vec.size() - 1) stream << ' '; }; return stream; } template <typename T> std::istream &operator>>(std::istream &stream, vector<T> &vec) {for (T &x : vec) stream >> x; return stream; } template <typename T, typename U> std::ostream &operator<<(std::ostream &stream, const pair<T, U> &pr) {stream << pr.first << ' ' << pr.second; return stream; } template <typename T, typename U> std::istream &operator>>(std::istream &stream, pair<T, U> &pr) {stream >> pr.first >> pr.second; return stream; } template <typename A, typename B> string to_string(pair<A, B> p); template <typename A, typename B, typename C> string to_string(tuple<A, B, C> p); template <typename A, typename B, typename C, typename D> string to_string(tuple<A, B, C, D> p); string to_string(const string &s) { return '"' + s + '"'; } string to_string(char c) {string s; s += c; return s; } string to_string(const char *s) { return to_string((string)s); } string to_string(bool b) { return (b ? "1" : "0"); } string to_string(vector<bool> v) {bool first = true; string res = "{"; for (int i = 0; i < static_cast<int>(v.size()); i++) {if (!first) {res += ", "; } first = false; res += to_string(v[i]); } res += "}"; return res; } template <size_t N> string to_string(bitset<N> v) {string res = ""; for (size_t i = 0; i < N; i++) {res += static_cast<char>('0' + v[i]); } return res; } template <typename A> string to_string(A v) {bool first = true; string res = "{"; for (const auto &x : v) {if (!first) {res += ", "; } first = false; res += to_string(x); } res += "}"; return res; } template <typename A, typename B> string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; } template <typename A, typename B, typename C> string to_string(tuple<A, B, C> p) { return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")"; } template <typename A, typename B, typename C, typename D> string to_string(tuple<A, B, C, D> p) { return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")"; } void debug_out() { cout << endl; } template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {cout << " " << to_string(H); debug_out(T...); }

#define int             long long
#define all(x)          x.begin(), x.end()
#define double          long double
#define endl            '\n'
#define ff              first
#define ss              second
#define v               vector
#define pb              push_back
#define bit(num, i)     (num & (1ll << i))

using pii = pair<int, int>;
const bool multipleTestCases = false;
v<int> dx{1, -1, 0, 0, 1, 1, -1, -1};
v<int> dy{0, 0, 1, -1, 1, -1, 1, -1};
string dir = "DURL";

void solve()
{
    int n; cin >> n;
    v<unordered_set<int>> adj(n+1, unordered_set<int>());
    for(int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    v<int> bfs(n);
    for(int i = 0; i < n; i++) cin >> bfs[i];

    if(bfs[0] != 1) {
        cout << "No" << endl;
        return;
    }

    queue<int> q;
    v<bool> visited(n+1, false);
    q.push(1);
    visited[1] = true;
    int idx = 1;

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        int children = 0;
        for(int neighbor : adj[curr]){
            if(!visited[neighbor]){
                children++;
            }
        }
        for(int j = 0; j < children; j++){
            if(idx >= n || visited[bfs[idx]] || adj[curr].find(bfs[idx]) == adj[curr].end()){
                cout << "No" << endl;
                return;
            }
            visited[bfs[idx]] = true;
            q.push(bfs[idx]);
            idx++;
        }
    }
    if(idx == n)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}  

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int t = 1;
    multipleTestCases and cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}
