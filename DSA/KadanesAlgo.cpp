#include <iostream>
#include <vector>
#include <algorithm> // for max()
using namespace std;

int maxSubArray(vector<int>& nums) {
    int maxSum = nums[0], curr = nums[0];
    for(int i = 1; i < nums.size(); i++) {
        curr = max(nums[i], curr + nums[i]);
        maxSum = max(maxSum, curr);
    }
    return maxSum;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Maximum Subarray Sum = " << maxSubArray(nums) << endl;
    return 0;
}
