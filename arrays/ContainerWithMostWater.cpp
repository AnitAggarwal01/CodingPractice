class Solution {
    
public:
    /*
     * If we have two towers of unequal lengths lets say some distance x apart, the amount of water 
     * which can be stored will be the minimum of the height among them multiplied by the distance btw them.
     * 
     * We use the same formula to coimpute the answer here using the two pointers approach.
     * Initially, we will start from left and right bein g0 and n-1. 
     * Then, we will compute the water we can trap and compare it to max.
     * In order to maximise our max, we need to adjust the height of the tower,
     * whose height is minimum among the two. so, if height[left] is less than height[right],
     * we increase left or else, we decrease right.
     * If we do so, we may or may not get a better answr, as distance also decreases here and
     * there's no gurantee that height of the previous minimum will improve
     *but this is the best shot we have If we do the opposite
     * we will have the same minimum, but decereased distance.
     */
    int maxArea(vector<int>& height) {
        int l = 0, r= height.size()-1;
        int output = 0;
        while(l < r) {
            output = max(output, (r-l)*min(height[l], height[r]));
            if(height[l] < height[r])
                l++;
            else
                r--;
        }
        return output;
    }
};