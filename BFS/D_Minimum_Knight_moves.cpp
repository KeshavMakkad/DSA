#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <tuple>
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
const bool multipleTestCases = true;
// v<int> dx{1, -1, 0, 0, 1, 1, -1, -1};
v<int> dx{2, 1, -1, -2, -2, -1, 1, 2};
v<int> dy{1, 2, 2, 1, -1, -2, -2, -1};
// v<int> dy{0, 0, 1, -1, 1, -1, 1, -1};

string dir = "DURL";

bool isValid(int nr, int nc, v<v<bool>>& visited){
    if(nr >= 0 && nr < 8 && nc >= 0 && nc < 8 && !visited[nr][nc]) return true;
    return false;
}

void solve()
{
    string start, end;
    cin >> start >> end;
    
    int row = start[0] - 'a', col = start[1] - '1';

    int endr = end[0] - 'a', endc = end[1]- '1';

     if (row == endr && col == endc) {
        cout << 0 << endl;
        return;
    }
    
    int count = 0;
    queue<pii> q;
    pii start_pos = {row, col};
    v<v<bool>> visited(8, v<bool>(8, false));
    q.push(start_pos);
    while(!q.empty()){
        
        int size = q.size();
        
        for(int k = 0; k < size; k++){
            pii curr = q.front();
            q.pop();
            int r = curr.first, c = curr.second;
            if(r == endr && c == endc){
                cout << count << endl;
                return;
            }
            for(int i = 0; i < dx.size(); i++){
                int nr = r + dx[i], nc = c + dy[i];
                if(isValid(nr, nc, visited)){
                    q.push({nr, nc});
                    visited[nr][nc] = true;
                }
            }
        }
        count++;
    }
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
