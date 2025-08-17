#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

bool canPartition(vector<int>& nums) {
    int total = accumulate(nums.begin(), nums.end(), 0);

    
    if (total % 2 != 0) return false;

    int target = total / 2;

   
    vector<bool> dp(target + 1, false);
    dp[0] = true; 

    for (int num : nums) {
        for (int s = target; s >= num; s--) {
            if (dp[s - num]) {
                dp[s] = true;
            }
        }
    }

    return dp[target];
}

int main() {
    vector<int> nums = {1, 5, 11, 5};

    if (canPartition(nums)) {
        cout << "Partition is possible." << endl;
    } else {
        cout << "Partition is not possible." << endl;
    }

    return 0;
}
