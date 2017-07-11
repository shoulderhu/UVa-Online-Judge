#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, n, m, S, T, s1, s2, node;
	struct cable { int w, sever; }Cable;

	cin >> N;

	for (int i = 1; i <= N; ++i) {

		cin >> n >> m >> S >> T;
		
		vector<int> dis(n, 199990000);
		vector<vector<struct cable>> edge(n);
		set<pair<int, int>> Set = { { 0, S } };

		dis[S] = 0;

		for (int j = 0; j < m; ++j) {

			cin >> s1 >> s2 >> Cable.w;
			Cable.sever = s1, edge[s2].push_back(Cable);
			Cable.sever = s2, edge[s1].push_back(Cable);
		}
				
		while (Set.empty() == false) {

			node = Set.begin()->second, Set.erase(Set.begin());

			if (node == T) { break; }			

			for (auto iter = edge[node].begin(); iter != edge[node].end(); ++iter) {

				if (dis[iter->sever] > dis[node] + iter->w) {

					Set.erase({ dis[iter->sever], iter->sever });
					dis[iter->sever] = dis[node] + iter->w;
					Set.insert({ dis[iter->sever], iter->sever });
				}				
			}
		}

		cout << "Case #" << i << ": ";
		dis[T] == 199990000 ? cout << "unreachable" << endl : cout << dis[T] << endl;
	}

	return 0;
}
