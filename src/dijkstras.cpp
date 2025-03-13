#include "dijkstras.h"

struct EdgeComparer{
	bool operator()(const Edge& lhs, const Edge &rhs){
		return lhs.weight > rhs.weight;
	}
};

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous){
	int numv = G.numVertices;
	vector<int> distance(numv, INF);
	vector<bool> visited(numv, false);
	previous.resize(numv, -1);

	priority_queue<Edge, vector<Edge>, EdgeComparer> pq; 
	pq.push(Edge(source, 0));
	distance[source] = 0;
	while(!pq.empty()){
		int u = pq.top().src; 
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
				pq.push(e);
			}
				
		}

	}
	return distance; 
	
} 
vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int destination){
	int prev = previous[destination];
	vector<int> out; 
	out.push_back(prev);
	while(prev != -1){
		prev = previous[prev];
		out.push_back(prev);
	}
	return out;
}
void print_path(const vector<int>& v, int total){
	for(auto s : v){
		cout << s << ' ';
		total -= s;
		if(total > 0)
			break;
	}
}
