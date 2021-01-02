class Solution {
public:
    /*
     * In this, what I want to do is that I fix one element a and find two elements b and c
     * such that a = -(b+c), I will fix every element and 
     * look for pairs b and c. To make the process easy 
     * I will sort the array and use two pointer technique to reach the desired sum 
     */
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> output;
        if(n<=2)
            return output;
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i<n; i++) {
            if(i != 0) {
                /*
                 * This is required to discard triplets starting with the same element
                 * lying on different indices in the array.
                 */
                while(i<n && nums[i] == nums[i-1])
                    i++;
                if(i >= n-2)
                    break;
            }
            int left = i+1;
            int right = n-1;
            int requiredSum = -nums[i];
            while(left < right) {
                int currentSum = nums[left] + nums[right];
                if(currentSum == requiredSum) {
                    output.push_back({nums[i], nums[left], nums[right]});
                    while(left < right && nums[left] == nums[left+1])
                        left++;
                    while(left < right && nums[right] == nums[right-1])
                        right--;
                    left++;right--;
                } else if(currentSum > requiredSum) {
                    right--;
                } else {
                    left++;
                }
            }
        }
        
        return output;
    }
};