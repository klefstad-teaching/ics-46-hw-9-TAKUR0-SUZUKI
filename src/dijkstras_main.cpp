#include "dijkstras.h"
int main(){
	Graph graph;
	vector<int> prev;
	file_to_graph("src/largest.txt", graph);
	vector<int> d = dijkstra_shortest_path(graph, 0, prev);

	for(int j  = 0; j < graph.numVertices; ++j){
		cout << "j = " << j << endl;
		print_path(extract_shortest_path(d, prev, j), 0);

		cout << endl;
	}
	
	return 0;
}