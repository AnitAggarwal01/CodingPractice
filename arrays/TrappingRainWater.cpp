class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), output = 0;
        if(n<=2)
            return output;
        vector<pair<int, int>> sideMax(n, {0,0});
        
        for(int i = 1; i <n-1; i++) {
            sideMax[i].first = max(sideMax[i-1].first, height[i-1]);
            sideMax[n-1-i].second = max(sideMax[n-i].second, height[n-i]);
        }

        for(int i = 0; i<n; i++) {
            pair<int, int> &p = sideMax[i];
            output += max(min(p.first, p.second) - height[i], 0);        }
        return output;
    }
};