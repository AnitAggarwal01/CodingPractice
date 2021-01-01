class Solution {
public:
    pair<int,int> growthAroundCenters(string& s, int l, int r){
        int n = s.size();
        while(l>=0 && r < s.size() && s[l] == s[r]){l--;r++;}
        return make_pair(l,r); 
    }
    string longestPalindrome(string s) {
        int n = s.size();
        if(n<=1)
            return s;
        int len = -1;
        string output = "";
        for(int i=0;i<n;i++){
            pair<int,int> o1 = growthAroundCenters(s,i,i);
            pair<int,int> o2 = growthAroundCenters(s,i,i+1);
            int len1 = o1.second-o1.first-1;
            int len2 = o2.second-o2.first-1;
            len = max(len, max(len1, len2));
            if(len == len1){
                output = s.substr(o1.first+1,len1);
            }else if(len == len2){
                output = s.substr(o2.first+1,len2);
            }
        }
        return output;
    }
};