/*
 * Link :- https://leetcode.com/problems/number-of-provinces/submissions/
 * What I will do is that I will find the number of connected components of a graph
 * For that, I will keep a track if I have visited a node or not 
 * as a node can be part of only one connected component  
 * When I visit an unvisited node, I will store all the adjacent nodes to it in a queue
 * to track down indirect connections. This is BFS way and we can also store the nodes in a stack  
 * to carry the search in DFS fashion.
 * After the stack/queue is empty, we finish marking the nodes of one component as visited.
 * We then check for the remaining visited nodes until either we visit all nodes or visitedNodesCounter  = numNodes;
 */
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n, 0);
        int visitedCities = 0;
        int numProvinces = 0;
        for(int i = 0; i<n && visitedCities < n; i++) {
            if(visited[i] == 1) {
                continue;
            }
            numProvinces++;
            queue<int> cities;
            cities.push(i);
            visited[i] = 1;
            visitedCities++;
            while(!cities.empty()) {
                int city = cities.front();
                cities.pop();           
                for(int j = 0; j<n; j++) {
                    if(!visited[j] && isConnected[city][j]) {
                        cities.push(j);
                        visited[j] =1;
                        visitedCities++;
                    }
                }
                
            }
        }
        return numProvinces;
    }
};