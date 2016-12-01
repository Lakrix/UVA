#include <iostream>
#include <vector>
/**
Author: Marcus Adamsson
Problem: https://uva.onlinejudge.org/external/4/459.pdf
**/


// Disjoint set structure and methods
std::vector<int> ds(1000);

void init(int size){
	ds.resize(size);
	for(int i = 0; i != size; i++){
		ds[i] = i;
	}
}

int findSet(int i){
	if(ds[i] != i) return findSet(ds[i]);
	return ds[i];
} 

bool isSame(int i , int j){
	if(findSet(i) == findSet(j)) return true;
	return false;
}

void unionSet(int i, int j ){
	ds[findSet(i)] = findSet(j);
}

void solve(){
	std::string line;
	char node;

	// read the size of the network
	std::cin >> node;
	int size = (node - 'A') ;
	size++;
	init(size);
	std::getline(std::cin,line);

	/**
	Read in each connection. Convert each
	so 'A' = 0, 'B' = 1, ..., Z = '25'
	**/
	while(std::getline(std::cin,line)){
		if(line == "") break;
		int from = line[0] - 'A';
		int to = line[1] - 'A' ;
		if(!isSame(f,t)){
			unionSet(f,t);
			size--;
		}
	}
	//
	std::cout << size << std::endl;
}


int main(){
	// Read in and store the input data.
	int tests;
	std::string line;

	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	std::cin >> tests;
	std::getline(std::cin,line);
	int num = 0;
	while(tests--){
		if(num > 0 ) std::cout << "\n";
		solve();
		num++;

	}
}