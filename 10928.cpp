#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>


/**
Author: Marcus Adamsson
Problem: https://uva.onlinejudge.org/external/109/10928.pdf
**/


// Store each node with theier neighbor list.
struct Node{
	int node;
	std::vector<int> neighbours;
	Node(int node){
		this->node = node;
	}

};

// sort based on number of neighbors.
bool compare(const Node* n1, const Node* n2){
	if(n1->neighbours.size() != n2->neighbours.size()){
		return n1->neighbours.size() < n2->neighbours.size();
	}
	return n1->node < n2->node;
}

void solve(int P){
	std::string line;
	std::vector<Node*> node_list;

	std::getline(std::cin,line);

	// Read each node and the neighbors to that node
	// create a new struct and store the information.
	for(int i = 1; i <= P ; i++){
		Node* node = new Node(i);

		std::getline(std::cin,line);
		std::vector<int> line_vec;
		std::stringstream ss;
		std::string elem;
		ss.str(line);

		while(std::getline(ss,elem,' ')){
			int a = atoi(elem.c_str());
			line_vec.push_back(a);
		}
		node->neighbours = line_vec;
		node_list.push_back(node);
	}

	/**
	Sort the list based on number of neighbors in 
	increasing order. Print out the nodes that have
	the minimum number of neighbors.
	**/
	std::sort(node_list.begin(), node_list.end(),compare);
	int biggest_size = node_list[0]->neighbours.size();
	std::cout << node_list[0]->node;
	for(int i = 1; i != node_list.size(); i++){
		if(node_list[i]->neighbours.size() == biggest_size){
			std::cout << " " << node_list[i]->node;
		}else break;
	}
	std::cout << "\n";
}

int main(){
	// Fetch and store input;
	int n;
	int P;
	std::string line;

	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	std::cin >> n;
	while(n--){
		std::cin >> P;
		solve(P);
	}
}