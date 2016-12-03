#include <iostream>
#include <vector>
#include <sstream>

/**
Author: Marcus Adamsson
Problem: https://uva.onlinejudge.org/external/115/11503.pdf
**/



/*
Using disjoint set to keep
track of each set of connected
computers.
*/
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

bool isSameSet(int i, int j){
	if(findSet(i) == findSet(j)) return true;
	return false;
}

void unionSet(int i, int j){
	ds[findSet(i)] = findSet(j);
}


/*
If the line starts with 'c' we
should connect the computers
if the line starts with 'q' we 
should check if the computers are 
connected.
*/
void solve(){
	std::string line;
	std::stringstream ss;
	int num_success = 0;
	int num_fail = 0;
	while(std::getline(std::cin,line)){

		if(line == "")break;
		ss.clear();
		ss.str(line);

		std::string elem;
		std::vector<std::string> line_vector;
		while(std::getline(ss,elem,' ')){
			line_vector.push_back(elem);
		}
		int i = atoi(line_vector[1].c_str());
		int j = atoi(line_vector[2].c_str());
		if(line_vector[0] == "c")unionSet(i,j);
		else{
			if(isSameSet(i, j)) num_success++;
			else num_fail++;
		}
	}
	std::cout << num_success <<"," << num_fail << "\n";


}

int main(){
	std::string line;
	int tests;
	int computers;
	int num = 0;

	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	std::getline(std::cin,line);
	tests = atoi(line.c_str());
	std::getline(std::cin,line);
	while(tests--){
		if(num > 0) std::cout << "\n";
		std::getline(std::cin,line);
		computers = atoi(line.c_str());
		computers++;
		init(computers);
		solve();
		num++;
	}
}