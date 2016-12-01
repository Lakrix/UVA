#include <list>
#include <iostream>

/**
Author: Marcus Adamsson
Problem: https://uva.onlinejudge.org/external/2/291.pdf
**/

std::list<int>* adjList = new std::list<int>[6];

// Do recursion and find the different pattrens where the number
// of edges is 8. Keep track of used edges.
void solve(int current,int num, bool** vec ,std::string res){
	if(num == 8){
		std::cout << res << "\n";
	}else{
		for(auto it = adjList[current].begin(); it != adjList[current].end(); it++){
			if(!vec[current][(*it)]){
				vec[current][(*it)] = true;
				vec[(*it)][(current)] = true;
				std::string tmp = res + std::to_string((*it));
				solve((*it),num+1,vec, tmp);
				vec[current][(*it)] = false;
				vec[(*it)][(current)] = false;
			}
		}
	}
}

int main(){
	// Store the data of the house.
	adjList[1] = {2,3,5};
	adjList[2] = {1,3,5};
	adjList[3] = {1,2,4,5};
	adjList[4] = {5,3};
	adjList[5] = {1,2,3,4};
	bool** vec  = new bool*[6];
	for(int i = 0; i != 6; i++){
		vec[i] = new bool[6];
	}
	std::string res = "1";
	solve(1,0,vec,res);
}