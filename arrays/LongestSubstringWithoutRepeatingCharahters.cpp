class Solution {
public:
   /*
    *
    * What I want to do is that, I iterate over the array and
    * maintain two pointers(both initially pointing to the first element),
    * left and right(the current element I am on in the loop)
    * I increase the right counter as I visit each element.
    * While doing so, I will keep count of each charachter in the array. O(1) memory 
    * As soon as I hit an element such that its count is > 1, i calculate the current length
    * and move the left pointer forward until i decreas the count to 1.
    *
    */
int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n <= 1)
            return n;
        int count[256] = {0};
        int left = 0, right = 0;
        int maxLength = 0;
        while(right < n) {
            count[s[right]]++;
            int& countOfCurrentElement = count[s[right]];
            if(countOfCurrentElement > 1) {
                int currentLength = right-left;
                maxLength = max(currentLength, maxLength);
                while(left <= right && countOfCurrentElement > 1) {
                    count[s[left++]]--;
                }
            }
            right++;
        }
        /* This is required to check for the last substring
            Eg: in "1234" 1234 will be the longest string
            but right will never reach a stage where count of any element is > 1
         */
        maxLength = max(right - left, maxLength);
        return maxLength;
    }
};