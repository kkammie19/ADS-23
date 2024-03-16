#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int minSubarrayLength(vector<int>& nums, int k) {
    int n = nums.size();
    int left = 0;
    int minLen = INT_MAX;
    int currentSum = 0;

    for (int right = 0; right < n; right++) {
        currentSum += nums[right];

        while (currentSum >= k) {
            minLen = min(minLen, right - left + 1);
            currentSum -= nums[left];
            left++;
        }
    }

    return (minLen == INT_MAX) ? 0 : minLen;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = minSubarrayLength(nums, k);
    cout << result << endl;

    return 0;
}

