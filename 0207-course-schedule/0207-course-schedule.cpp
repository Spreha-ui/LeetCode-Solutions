class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
		vector<vector<int>> adj(numCourses);
		
		for (auto edge: prerequisites) {
			int u = edge[0];
			int v = edge[1];
			
			indegree[u]++;
			adj[v].push_back(u);
		}
		
		queue<int> q;
		
		for (int i = 0; i < numCourses; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}
		
		int count = 0;
		
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			
			for (auto temp : adj[node]) {
				indegree[temp]--;
				
				if (indegree[temp] == 0) {
					q.push(temp);
				}
			}
			
			count++;
		}
		
		if(count < numCourses) {
		    return false; //cycle exists, cannot form toposort
		} else {
		    return true;
		}
    }
};