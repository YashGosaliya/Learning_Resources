//Problem link:
//https://leetcode.com/problems/maximum-sum-circular-subarray/

class Solution {
public:
    
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int n = nums.size();

        if (n == 1)
        return nums[0];
 
        // Initialize sum variable which store total sum of the array.
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        // Initialize every variable with first value of array.
        int curr_max = nums[0], max_so_far = nums[0];
        int curr_min = nums[0], min_so_far = nums[0];

        // Concept of Kadane's Algorithm
        for (int i = 1; i < n; i++) {
            // Kadane's Algorithm to find Maximum subarray sum.
            curr_max = max(curr_max + nums[i], nums[i]);
            max_so_far = max(max_so_far, curr_max);

            // Kadane's Algorithm to find Minimum subarray sum.
            curr_min = min(curr_min + nums[i], nums[i]);
            min_so_far = min(min_so_far, curr_min);
        }
 
        if (min_so_far == sum)
            return max_so_far;

        // returning the maximum value
        return max(max_so_far, sum - min_so_far);
    }
};
