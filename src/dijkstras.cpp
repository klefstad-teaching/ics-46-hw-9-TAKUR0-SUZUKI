#include "dijkstras.h"

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous){
	int numv = G.numVertices;
	vector<int> distance(numv, INF);
	vector<bool> visited(numv, false);
	previous.assign(numv, -1);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
	pq.push({source, 0});
	distance[source] = 0;
	while(!pq.empty()){
		int u = pq.top().first; 
		//cout << "u = " << u << endl;
		pq.pop();
		if(visited[u])
			continue;
		visited[u] = true;

		for(auto e : G[u]){
			int v = e.dst;
			int weight = e.weight;
			if(!visited[v] && distance[u] + weight < distance[v]){
				distance[v] = distance[u] + weight;
				previous[v] = u;
				pq.push({v, distance[v]});
			}
				
		}

	}
	
	return distance; 
	
} 
vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int destination){
	int prev = destination;
	vector<int> out; 
	while(prev != -1){
		//cout << "Prev = " << prev << endl;
		out.push_back(prev);
		prev = previous[prev];
	}
	return out;
}
void print_path(const vector<int>& v, int total){
	for(auto s : v){
		cout << s << ' ';
	}
	cout << endl << "Total cost = " << total << endl;
}
