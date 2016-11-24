#include <list>
#include <iostream>
#include <queue>
#include <functional>
#include <algorithm>
#include <vector>
/**
Author: Marcus Adamsson
Problem: https://uva.onlinejudge.org/external/9/908.pdf
**/

struct Edge{
	int from;
	int to;
	int cost;
};

// Compare if the cost of the edges. Used 
// in priority queue.
struct Comparator {
    bool operator()(const Edge* a, const Edge* b)
    {
        return (a->cost > b->cost);
    }
};


// Remove edges from graph
void remove(std::list<Edge*>* neighbor_list,int v){
	for(int i = 1; i != v+1; i++){
		while(!neighbor_list[i].empty()){
			delete neighbor_list[i].front();
			neighbor_list[i].pop_front();
		}
	}
}

/*
Init graph with the given input
*/
void init(std::list<Edge*>* neighbor_list, int e){
	int from;
	int to;
	int cost;
	for(int i = 0; i != e; i++){
		Edge* e = new Edge;
		std::cin >> e->from >> e->to >> e->cost;
		neighbor_list[e->from].push_back(e);
	}
}

void print_graph(std::list<Edge*>* neighbor_list,int v){
	for(int i = 1; i != v+1; i++){
		for(auto it = neighbor_list[i].begin(); it != neighbor_list[i].end(); it++){
			std::cout << (*it)->from << " " << (*it)->to << " "<< (*it)->cost << "\n";
		}
	}
}
std::vector<int> pSet(1000);

// Union Find to help kruskal detect cycles.

int findSet(int i){
	if(i != pSet[i]) return findSet(pSet[i]);
	return i;
}
bool isSameSet(int i, int j){
	if(findSet(pSet[i]) != findSet(pSet[j])) return false;
	return true;
}
void unionSet(int i, int j){
	pSet[findSet(i)] = findSet(j);
}
void initSet(int size){
	pSet.resize(size);
	for(int i = 0; i <= size;i++){
		pSet[i] = i;
	}
}



// Kruskal algorithm using a priority queue 
// based on cost of the edges. Using usion find to
// detect if adding an edges creates a cycle in the graph.
void kruskal(std::list<Edge*>* neighbor_list,int e,int v){

	std::priority_queue<Edge*, std::vector<Edge*>, Comparator> q;
	for(int i = 1; i != v+1; i++){
		for(auto it = neighbor_list[i].begin(); it != neighbor_list[i].end(); it++){
			q.push(*it);
		}
	}
	initSet(v+1);

	int total = 0;
	std::list<Edge*>* current_graph = new std::list<Edge*>[v+1];
	while(!q.empty()) {
		current_graph[q.top()->from].push_back(q.top());
		if(!isSameSet(q.top()->from,q.top()->to)){
			unionSet(q.top()->from,q.top()->to);
			total += q.top()->cost;
		}

        q.pop();
    }
    std::cout << total << std::endl;
}

// count the cost of the MST.
void count_network(std::list<Edge*>* neighbor_list,int v){
	int total = 0;
	for(int i = 1; i != v+1; i++){
		for(auto it = neighbor_list[i].begin(); it != neighbor_list[i].end(); it++){
			total += (*it)->cost;
		}
	}
	std::cout << total << "\n";
}

/**
Create and count the old MST network.
Read in the new and all the 
edges in the old network and 
create a MST.
**/
int main(){
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int v;
	int num = 0;
	while(std::cin >> v){
		if(num > 0) std::cout << "\n";
		if(v == 0) break;
		int e = v-1;
		std::list<Edge*>* neighbor_list = new std::list<Edge*>[v+1];
		init(neighbor_list,e);
		count_network(neighbor_list,v);
		remove(neighbor_list,v);

		std::cin >> e;
		init(neighbor_list,e);
		std::cin >> e;
		init(neighbor_list,e);
		kruskal(neighbor_list,e,v);
		num++;
	}
}