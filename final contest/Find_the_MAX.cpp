#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;

    unordered_map<int, int> freq_map; // To store frequency of each element
    vector<int> v; // To maintain the order of elements

    while (q--) {
        int c;
        cin >> c;
        
        if (c == 1) {
            int x;
            cin >> x;
            freq_map[x]++;
            v.push_back(x);
        } else if (c == 2) {
            if (v.empty()) {
                cout << "empty\n";
            } else {
                int max_freq = 0;
                int max_val = v[0]; // Initialize to first value

                // Find the value with maximum frequency
                for (int val : v) {
                    if (freq_map[val] > max_freq || (freq_map[val] == max_freq && val > max_val)) {
                        max_freq = freq_map[val];
                        max_val = val;
                    }
                }

                cout << max_val << "\n";

                // Erase all occurrences of max_val from v
                v.erase(remove(v.begin(), v.end(), max_val), v.end());
                
                // Reset the frequency of max_val
                freq_map[max_val] = 0;
            }
        }
    }

    return 0;
}
