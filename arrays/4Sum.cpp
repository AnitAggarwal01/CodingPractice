class Solution {
public:
	/*
	* In this, the brute force solution is to check all the possible combinations of four elements(TC :O(n^4))
	* check which has target sum, store the correct ones in the output array as well as a map(SC : O(n^4)) for checking
	* duplicacy.
	*
	* In order to optimise TC, we need some sort of ordering in the elements in order to utilise the two pointer approach
	* for finding a pair of elemnts. We will sort the array( TC: O(nlogn)) and then fix two elements and then traverse the
	* rest of the array using two pointers technique in order to save one inner loop. 
	* 
	* In order to reduce the space complexity, we will skip all duplicate occurences of the fixed elements (nums[i] and nums[j])
	* using a simple condition after traversing the loop once with them.
	*
	* In order to further reduce the run time, we can do pruning. After fixing the outermost element, we can find the maximum
	* and minimum obtainable sum then. If the target is smaller than the minimum sum, we won't get any answer now as everything
	* will be bigger even in next iterations(we sorted array) and we can return the output. If the maxSum is less than the target, 
	* then we won't find an answer in this iteration. So, we can continue to the next value of i
	* Similarly, we can prune the second fixed element. If the minSum there is greater than target, we won't find an answer in any of 
	* the next iterations for the secnd element(we sorted the array). So, we can move to the next value of i.
	* If we find that the maxSum < target, we won;t find an answer in this iteration of the inner loop. So, we can continue
	* to the next value of j.  
	*/
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        if(n <= 3) 
            return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> output;
        for(int i = 0; i<n-3; i++) {
            int maxSum = nums[i] + nums[n-3] + nums[n-2] + nums[n-1];
                int minSum = nums[i] + nums[i+1] + nums[i+2] + nums[i+3];
                if(maxSum < target)
                    continue;
                if(minSum > target)
                    break;
            for(int j = i+1; j<n-2; ++j) {
                maxSum = nums[i] + nums[j] + nums[n-2] + nums[n-1];
                minSum = nums[i] + nums[j] + nums[j+1] + nums[j+2];
                if(maxSum < target)
                    continue;
                if(minSum > target)
                    break;
                int x = j+1, y = n-1;
                while(x < y) {
                    int sum = nums[i] + nums[j] + nums[x] + nums[y];
                    if(sum == target) {
                        output.push_back({nums[i], nums[j], nums[x], nums[y]});
                        while(x < y && nums[x] == nums[x+1])
                            x++;
                        while(x < y && nums[y] == nums[y-1])
                            y--;
                        x++; y--;
                    } else if(sum > target) 
                        y--;
                    else
                        x++;
                }
                while(j < n-1 && nums[j] == nums[j+1])
                    j++;
            }
                while(i < n-1 && nums[i] == nums[i+1])
                    i++;
        }
        return output;
    }
};