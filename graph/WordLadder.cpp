class Solution {
public:
    /*
     * What I want to do in this question is to think of words not as words but as vertices of a graph.
     * With words which have only only letter different as connected vertices.
     * After this, this problem just reduces to finding minimum distancxe from start vertex to end vertex.
     *
     * Now, we need to do some pre processing to find out the nodes with distances 1 with each other.
     * One thing we can do is, for each word, check the distance with the other word 
     * and build a matrix which has edges only if distance is 1. 
     * The Time Complexity of This approach will be O(n^2 * L) where n is no of words and L is length of eah word. 
     *
     * Another way is that, we can compute intermediate stages to which words can be transformed.
     * For eg :- CAT, MAT and BAT can be transformed into *AT 
     * So, for each word in the list, we can have L such stages(replacing a single charachter with a*).  
     * and for  the whole list we can have L * M stages. Making of each stage will also take O(L) time.
     * Hence, time complexity of this approach will be O(L^2 * n).
     *
     * Now this is a BFS problem in which for each node of the queue, we will create all stages O(L^2) Time,
     * and try to visit all unvisited words O(n). We push each unvisited adjacent node in the queue 
     * along with a distance 1 greater than the current distance.
     * When we reach the endWord, we have the answer.  
     */
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int L = beginWord.size();
        unordered_map<string, vector<string>> map;
        for(int i = 0; i < wordList.size(); i++) {
            string word = wordList[i];
            for(int i = 0; i<L; i++) {
                string transformation = word.substr(0, i) + "*" + word.substr(i+1, L);
                map[transformation].push_back(word);
            }          
        }
        queue<pair<string, int>> Q;
        unordered_map<string, bool> visited;
        Q.push({beginWord, 1});
        visited[beginWord] = true;
        while(!Q.empty()) {
            pair<string, int> p = Q.front(); Q.pop();
            string word = p.first;
            int level = p.second;
            for(int i = 0; i< L; ++i) {
                string transformation = word.substr(0, i) + "*" + word.substr(i+1, L);
                vector<string> adjacentList = map[transformation];
                for(int j = 0; j<adjacentList.size(); ++j) {
                    string nextWord = adjacentList[j];
                    if(!visited[nextWord]) {
                        if(nextWord == endWord) {
                            return level + 1;
                        }
                        Q.push({nextWord, level + 1});
                        visited[nextWord] = true;
                    }                    
                }
            }
        }
        return 0;
    }
};