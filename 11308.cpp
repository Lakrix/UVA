#include <unordered_map>
#include <iostream>
#include <iomanip>   
#include <utility>
#include <algorithm>
#include <vector>
#include <ctype.h>
/**
Author: Marcus Adamsson
Problem: https://uva.onlinejudge.org/external/113/11308.pdf
**/

/**
Used to sort based on price and if the price is the same
we will sort based on lexicographical order. 
**/
bool compare(const std::pair<std::string,int>& p1, const std::pair<std::string,int>& p2){
	if(p1.second != p2.second) return p1.second < p2.second;
	return p1.first < p2.first;
}

void solve(int m, int n, int b,std::string title){
	std::string line;
	int price;
	std::string ingredient;

	/**
	Read in the different increidents and thier price
	store them in a map, <ingrident,price>
	**/
	std::unordered_map<std::string,double> ingredients;
	while(m--){
		std::cin >> ingredient >> price;
		ingredients[ingredient] = price;
	}
	
	/*
	For the number of recipes we want to find out the
	total cost. 
	*/
	std::vector<std::pair<std::string,int> > result;
	while(n--){
		std::getline(std::cin, line);
		std::getline(std::cin, line);
		double total = 0;
		int num_ingridents;
		int num;
		std::cin >> num_ingridents;
		while(num_ingridents--){
			std::cin >> ingredient >> num;
			total += (ingredients[ingredient]*num);
		}
	
		if(b >= total) result.push_back(std::make_pair(line,total));
	}
	
	/**
	Print title in uppercase and then print the name 
	of the recipes which is in the given budget. If
	no recipe was found then print "To expensive!".
	**/
	std::transform(title.begin(),title.end(),title.begin(),::toupper);
	std::cout << title;
	std::cout << "\n";
	std::sort(result.begin(), result.end(), compare);
	for(auto it = result.begin(); it != result.end(); it++){
		std::cout << (*it).first << std::endl;
	}
	if(result.size() == 0) std::cout << "Too expensive!" << "\n";
}


int main(){
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	std::string line;
	int num_tests;
	int num = 0;
	int m,n,b;
	std::cin >> num_tests;
	// Read in and sovle the number of test cases
	while(num_tests--){
		std::getline(std::cin,line);
		std::getline(std::cin,line);
		std::cin >> m >> n >> b;
		solve(m,n,b,line);
		num++;
		std::cout << "\n";
		std::cout.flush();
	}
	
}