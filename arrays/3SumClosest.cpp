class Solution {
public:
    /*
     * In this, the brute face way is two try every combination of three elements which will take O(n3) time
     * In order to optimise, I will try to use Sorting O(nlogn) and then fix one element and look for other two using two pointers {O(n.n) = O(n^2)}
     * When I have a sum of three elemnts, I will check if the absolute difference between the target and sum 
     * is lesser than the global least difference till now. Initially the global least difference will be the highest integer value.
     * Now, if the difference is lower, then this is currently the closest sum to target.
     * Now, in order to proceed towards a more optimal solution,We will check if the sum is greater or  lesser than target
     * If the sum is greater than target, then we decrease the right pointer which will decrease the sum and might bring us to a better solution    
     * If the sum is lesser than target, then we increase the left pointer which will increase the sum and might bring us to a better solution   
     * If the sum is equa to the target, then we have the closest solution possible. Hence, we return immediately in the case 
     */
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int output = nums[0]+nums[1]+nums[2], minDiff = INT_MAX;
        for(int i = 0; i<n-1; i++) {
            int left = i+1;
            int right = n-1;
            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                int currentDiff = abs(target-sum);
                if(currentDiff < minDiff){
                    output = sum;
                    minDiff = currentDiff;
                }
                if(sum > target) {
                    right--;
                } else if(sum < target)
                    left++;
                else
                    return sum;
            }
        }
        return output;
    }
};