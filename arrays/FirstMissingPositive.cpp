class Solution {
    /*
     * First of all, the answe must lie between [1, n+1]. (If all are present 1...n, answer will be n+1, else smaller)
     * Now, if we solve this using O(n) space, we will keep an count array of n+1 size. Then will traverse the nums array 
     * and mark the count of each positive integer ( > 0) as 1. Then we traverse the count array from 1 to n index.
     * The first element whose count is 0, will be the answer. If every element's count is 1, then the answer will be n+1.
     *
     * Now, we need to solve this with O(1) space. So, rather than using a different array to store the count
     * Will use this array to store the count. If a number n is present, we will mark the number at n-1 (0 based indexing) 
     * as negative (considering array has all positive integers). Then we check to find first element which is not negative.
     * That will be the index(i) corresponding to element(i+1), which was not present in the array to make the element negative 
     * So, we return i+1 as the answer. Also, if all elements are negative. We return n+1 as the answer.
     * If the array has non positive integers, we need to seperate them.  
     */
public:
    void seperatePositiveAndNegativeIntegers(vector<int>& arr) {
        int i = 0, j = arr.size()-1;
        while(i < j) {
            if(arr[i] > 0 && arr[j] <=0) {
                i++; j--; continue;
            }
            if(arr[i] > 0)
                i++;
            else if(arr[j] <= 0)
                j--;
            else {
                swap(arr[i], arr[j]);
            }
        }
    }
    int getCountPositive(const vector<int>& arr) {
        int i = 0;
        while(i < arr.size()) {
            if(arr[i] <= 0)
                break;
            i++;
        }
        return i;
    }
    int firstMissingPositive(vector<int>& nums) {
        seperatePositiveAndNegativeIntegers(nums);
        int countPositive = getCountPositive(nums);
        for(int i = 0; i<countPositive; i++) {
            int index = abs(nums[i]);
            if(index <= countPositive) {
                nums[index-1] = -abs(nums[index-1]);
            }
        }
        for(int i = 0; i<countPositive; i++) {
            if(nums[i] > 0)
                return i+1;
        }
        return countPositive + 1;
    }
};
