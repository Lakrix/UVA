#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <set>
#include <utility>

/**
Author Marcus Adamsson
Problem: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=272
**/

std::vector<std::pair<std::pair<int,int>,int > > solve(int num_tests){

	/**
	Read in all nodes and store a neighbor list for each node.
	Keep a set with all available nodes visited nodes.
	**/
	std::unordered_map<int,std::vector<int> > neighbor_list;
	std::vector<std::pair<std::pair<int,int>,int > > result;
	std::set<int> nodes;
	int node_one;
	int node_two;
	while(num_tests--){
		std::cin >> node_one >> node_two;
		neighbor_list[node_one].push_back(node_two);
		neighbor_list[node_two].push_back(node_one);
		nodes.insert(node_one);
		nodes.insert(node_two);
	}
	int node;
	int TTL;

	/*
	create a queue with <node,TTL> use the nodes set
	to keep track of non_visited nodes.
	*/
	std::queue<std::pair<int,int> > queue;
	while(true){
		std::set<int> not_visited = nodes;
		int node;
		int TTL;
		std::cin >> node >> TTL;
		if(node == 0 && TTL == 0) break;

		queue.push(std::make_pair(node,TTL));
		not_visited.erase(node);

		/*
		Fetch current node and TTL if TLL is
		less than 0 we wont should not add the neighbors.
		*/
		while(!queue.empty()){
			int top_node = queue.front().first;
			int top_ttl = queue.front().second;
			queue.pop();
			top_ttl -= 1;
			if(top_ttl >= 0){
				for(int i = 0; i != neighbor_list[top_node].size(); i++){
					int neighbor = neighbor_list[top_node][i];

					if(not_visited.count(neighbor) != 0){
						queue.push(std::make_pair(neighbor,top_ttl));
						not_visited.erase(neighbor);
					}
				}
			}
		}
		/*
		Add result to vector which is <<node,TTL>, number unreachable nodes>
		*/
		result.push_back(std::make_pair(std::make_pair(node,TTL),not_visited.size()));
	}
	return result;
}

int main(){
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int num_cases = 1;
	while(true){
		int num_tests;
		std::cin >> num_tests;
		
		if(num_tests == 0) break;
		/**
		Store result as <<node,TTL>, number unreachable nodes>
		**/
		std::vector<std::pair<std::pair<int,int>,int> > unreachable = solve(num_tests);

		// print according acording to wanted ouput.
		for(int i = 0; i != unreachable.size(); i++){
			std::cout << "Case " <<  num_cases << ": ";
			std::cout << unreachable[i].second << " nodes not reachable from node ";
			std::cout << unreachable[i].first.first; 
			std::cout << " with TTL = " <<unreachable[i].first.second  <<  "."<< "\n";
			num_cases++;
		}
	}
}