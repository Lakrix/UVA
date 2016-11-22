#include <map>
#include <iostream>
#include <iomanip>   

/**
Author: Marcus Adamsson
Problem: https://uva.onlinejudge.org/external/102/10226.pdf
**/

void solve(){

	// Use a map to store the number of each tree.
	std::string line;
	std::map<std::string,double> tree_map;
	double total_trees = 0;
	while(std::getline(std::cin,line)){
		if(line == "") break;
		total_trees++;
		if(tree_map.count(line) == 0)tree_map[line] = 1;
		else tree_map[line]++;
	}

	// print out the percentage.
	for(auto it = tree_map.begin() ; it != tree_map.end(); it++){
		std::cout << (*it).first << " " << (*it).second/total_trees * 100<< "\n";
	}
}

int main(){
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	std::string line;
	int num_tests;

	// Set wanted precision
	std::cout << std::fixed<< std::setprecision(4);
	std::cin >> num_tests;
	std::getline(std::cin,line);
	std::getline(std::cin,line);
	int num = 0;
	while(num_tests--){
		if(num != 0) std::cout << "\n";
		solve();
		num++;
	}

}