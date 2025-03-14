#include "dijkstras.h"
int main(){
	Graph graph;
	vector<int> prev;
	file_to_graph("src/largest.txt", graph);
	vector<int> d = dijkstra_shortest_path(graph, 0, prev);
	for(auto i : extract_shortest_path(d, prev, 99))
		cout << i << " ";
	return 0;
}