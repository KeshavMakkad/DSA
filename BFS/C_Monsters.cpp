#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <string>
#include <bitset>
#include <utility>
#include <algorithm>
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

bool isValid(int x, int y, int nx, int ny, v<v<char>>& arr, v<v<int>>& ch){
    if(nx > -1 && ny > -1 && nx < arr.size() && ny < arr[0].size() && arr[nx][ny] == '.' && ch[x][y] + 1 < ch[nx][ny]) return true;
    return false;
}

const int INF = 1e9;

void solve()
{
    int n, m; cin >> n >> m;
    v<v<char>> arr(n, v<char>(m));
    cin >> arr;
    
    auto valid = [&](int x, int y)
    {
        return x >= 0 and x < n and y >= 0 and y < m;
    };

    auto bfs = [&](int ch) -> pair<v<v<int>>, v<v<pii>>>
    {
        v<v<int>> dist(n, v<int>(m, INF));
        v<v<pii>> parent(n, v<pii>(m, {-1, -1}));

        queue<pii> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(arr[i][j] == ch){
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }

        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++){
                int nx = x + dx[i], ny = y + dy[i];
                if(valid(nx, ny) and dist[nx][ny] == INF and arr[nx][ny] == '.'){
                    q.push({nx, ny});
                    dist[nx][ny] = dist[x][y] + 1;
                    parent[nx][ny] = {x, y};
                }
            }
        }

        return { dist,  parent };
    };


    auto [human, parent] = bfs('A');
    auto [monsters, _] = bfs('M');

    auto path = [&](int x, int y) -> void {
        string path = "";
        while(human[x][y] != 0){
            debug(parent[x][y])
            auto [px, py] = parent[x][y];
            if(x - px == 1)path += "D";
            else if(x-px == -1) path += "U";
            else if(y-py == -1) path += "L";
            else path += "R";
            x = px; y = py;
        }
        cout << "YES" << endl;
        cout << path.size() << endl;
        reverse(all(path));
        cout << path << endl;
    };

    // debug(human);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i == 0 || j == 0 || i == n-1 || j == m-1){
                if(human[i][j] < monsters[i][j]){
                    path(i, j);
                    return;
                }
            }
        }
    }


    cout << "NO" << endl;
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
