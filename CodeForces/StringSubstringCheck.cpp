#include <iostream>
#include <string>
using namespace std;

string solve(const string& s) {
    int n = s.length();
    
    // If there are at least 3 of the same character, we can always have a valid split
    int max_count = 0;
    for (char c = 'a'; c <= 'z'; c++) {
        int count = 0;
        for (char ch : s) {
            if (ch == c) count++;
        }
        max_count = max(max_count, count);
    }
    
    if (max_count >= 3) {
        return "Yes";
    }
    
    // Check for pattern where the same character appears in both a and c
    for (int i = 0; i < n-2; i++) {
        for (int j = i+2; j < n; j++) {
            if (s[i] == s[j]) {
                return "Yes";
            }
        }
    }
    
    return "No";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        string s;
        cin >> s;
        
        cout << solve(s) << endl;
    }
    
    return 0;
}
        
        string s;
        cin >> s;
        
        cout << solve(s) << endl;
    }
    
    return 0;
}
        }
    }
    
    return "No";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        string s;
        cin >> s;
        
        cout << solve(s) << endl;
    }
    
    return 0;
}
