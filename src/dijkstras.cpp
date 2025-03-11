vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous){
	int numv = G.numVertices;
	vector<int> distance(numv, INF);
	vector<bool> visited(numv, false);
	previous.resize(numv, -1);

	priority_queue<pair<int, int>, vector<pair<int, int>, greater<pair<int, int>>> pq; 
	pq.push({source, 0});
	graph.distance[source] = 0;
	while(!pq.empty()){
		int u = pq.pop().first; 
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
		cout << v << ' ';
		total -= v;
		if(total > 0)
			break;
	}
}
