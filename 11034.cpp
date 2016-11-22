#include <iostream>
#include <queue>
#include <utility>
/**
Author: Marcus Adamsson
Problem: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1975
**/

void solve(int l,int m){
	// Use two queues to keep track of right and left side.
	std::queue<int>* cars_arrival = new std::queue<int >[2];
	std::string location;
	int length;
	while(m--){
		std::cin >> length >> location;
		if(location == "left"){
			cars_arrival[0].push(length);
		}else{
			cars_arrival[1].push(length);
		}
	}
	
	/*
	Keep track of ferry's current position
	and number of turns.
	*/
	int num_turns = 0;
	int ferry_position = 0;
	while(true){
		if(cars_arrival[0].size() == 0&&cars_arrival[1].size() ==0)break;

		int length_left = l;
		// Load the ferry as long as the side is not empty
		// or the ferry can't take on more cars.
		while(!cars_arrival[ferry_position].empty()){
	 		if((length_left - cars_arrival[ferry_position].front())< 0) break;
			length_left = length_left - cars_arrival[ferry_position].front();
	 		cars_arrival[ferry_position].pop();
	 	}
	 	num_turns++;
	 	ferry_position = ( ferry_position + 1) % 2;	
	}
	std::cout << num_turns << std::endl;

}


int main(){
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int num_tests;
	std::cin >> num_tests;
	int l;
	int m;
	int num = 0;

	// solve each testcase
	while(num_tests--){
		std::cin >> l >> m;
		solve(l*100,m);
		num++;
	}
}