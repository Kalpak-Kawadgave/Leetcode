class Graph {
public:
	int level = -1;
	vector<bool> visited;
	unordered_set<int> unique_nums;
	unordered_map<int, list<int>> adjacent;
	unordered_map<int, int> levels{ {-1,-1} };
	vector<set<int>> coprimes{ 51 };
	vector<vector<int>> lastOccurrence{ 51 };


	static int gcd(int a, int b)
	{
		if (a == 0)
			return b;
		return gcd(b % a, a);
	}

	void resizeVisited(size_t size);
	void addEdge(vector<int> edge);
	void DFS(int root, vector<int>& nums, vector<int>& ans);

	void setUniqueNums(vector<int>& nums) {
		unique_nums.insert(nums.begin(), nums.end());
	}

	void setCoprimes() {
		coprimes[1].insert(1);
		for (auto i = unique_nums.begin(); i != unique_nums.end(); ++i) {
			auto j = i;
			++j;
			for (; j != unique_nums.end(); ++j) {
				if (gcd(*i, *j) == 1) {
					coprimes[*i].insert(*j);
					coprimes[*j].insert(*i);
				}
			}
		}
	}
};

void Graph::resizeVisited(size_t size) {
	visited.resize(size);
}

void Graph::addEdge(vector<int> edge) {
	adjacent[edge[0]].push_back(edge[1]);
	adjacent[edge[1]].push_back(edge[0]);
}

void Graph::DFS(int root, vector<int>& nums, vector<int>& ans) {
	visited[root] = true;
	++level;
	levels[root] = level;
	for (int a : coprimes[nums[root]]) {
		if (!lastOccurrence[a].empty()) {
			if (levels[lastOccurrence[a].back()] > levels[ans[root]]) {
				ans[root] = lastOccurrence[a].back();
			}
		}
	}
	lastOccurrence[nums[root]].push_back(root);
	list<int>::iterator i;
	for (i = adjacent[root].begin(); i != adjacent[root].end(); ++i) {
		if (!visited[*i]) {
			DFS(*i, nums, ans);
		}
	}
	lastOccurrence[nums[root]].pop_back();
	--level;
}



class Solution {
public:
	vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
		vector<int> ans(nums.size(),-1);
		Graph g;
		g.resizeVisited(nums.size());
		g.setUniqueNums(nums);
		sort(edges.begin(), edges.end());
		for (auto edge : edges) {
			g.addEdge(edge);
		}
		g.setCoprimes();
		g.DFS(0, nums, ans);
		return ans;
	}
};