#include <iostream>
#include <vector>
#include <map> // Changed from <unordered_map> to <map>
#include <algorithm>

/**
 * @brief Solves the CSES Playlist problem (Longest Subarray with Distinct Elements).
 * * This solution uses the sliding window technique with guaranteed O(N log N) time complexity.
 * We switched from unordered_map to std::map to avoid worst-case O(N^2) hash collisions 
 * that can cause TLE in competitive programming environments.
 */
void solve() {
    // Optimization for fast C++ I/O (Crucial for TLE avoidance)
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    // Read the number of songs
    if (!(std::cin >> N)) return;

    std::vector<int> arr(N);
    // Read the song IDs into the vector
    for (int i = 0; i < N; ++i) {
        std::cin >> arr[i];
    }

    // Stores the last seen index of each song ID.
    // std::map guarantees O(log N) lookups/insertions, preventing worst-case TLE.
    // Key: Song ID (int), Value: Last seen index (int)
    std::map<int, int> last_index; 
    
    // 'start' pointer of the sliding window
    int start = 0;
    
    // Tracks the maximum length found so far
    int max_length = 0;

    // The 'end' pointer iterates through the entire array
    for (int end = 0; end < N; ++end) {
        int current_song = arr[end];

        // 1. Check for duplicates within the current window [start...end]
        // This occurs if:
        //    a) The song has been seen before (last_index.count(current_song)).
        //    b) Its last seen index is greater than or equal to the current 'start'.
        
        // Use count() and direct access via [] for efficiency with std::map
        if (last_index.count(current_song) && last_index[current_song] >= start) {
            // A duplicate was found *inside* the current window.
            // The new window must start immediately after the last occurrence 
            // of the duplicated song to maintain uniqueness.
            start = last_index[current_song] + 1;
        }

        // 2. Update the last seen index for the current song
        last_index[current_song] = end;

        // 3. Calculate and update the maximum length
        // Current length = end - start + 1
        max_length = std::max(max_length, end - start + 1);
    }

    // Print the final result
    std::cout << max_length << "\n";
}

int main() {
    solve();
    return 0;
}
