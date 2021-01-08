class Solution {
public:
    /*
     * What I want to do is, check the first element, then find it's last occurence in the array.
     * I will mark start and end as beginning index and end index of the current patition;
     * I will traverse the array from 0 to n. While traversing,
     * I might find elements whose firstIndex is after start and lastIndex is after end.
     * So, we need to increase the end to the lastIndex of this element.   
     * When we reach the an index i such that the lastIndex of the current element is i itself,
     * We get a complete partition from S[start..end]. 
     * The reason is that the end of the currentPartition is >= the ast occurence of all elements
     * occuring in this partition. 
    **/
    vector<int> partitionLabels(string S) {
        int n = S.size();
        if(n == 1)
            return {1};
        int lastOccurence[26] = {0};
        for(int i = 0; i<n; i++) {
            lastOccurence[S[i]-'a'] = i;
        }
        vector<int> output;
        int start = 0, end = lastOccurence[S[0]-'a'];
        for(int i = 0; i<n; i++) {
            int lastOccurenceCurrentElement = lastOccurence[S[i]-'a'];
            if(lastOccurenceCurrentElement > end) {
                end = lastOccurenceCurrentElement;
                if(end == n-1) {
                    output.push_back(end-start+1);
                    return output;
                }
            }
            if(end == i) {
                output.push_back(end-start+1);
                start = end+1;
                end = start;
            }
        }
        return output;
    }
};