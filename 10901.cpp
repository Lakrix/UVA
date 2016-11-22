#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#include <limits>
/**
Author: Marcus Adamsson
Problem: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=21&page=show_problem&problem=1842
**/

/*
Used to sort the result based on arrival of the car
*/
bool compare(const std::pair<int,int>& p1, const std::pair<int,int>& p2){
	return p1.first < p2.first;
}

void solve(int n, int t, int m){

	// Use two queues to keep track of right and left side.
	std::queue<std::pair<int,int> >* cars_arrival = new std::queue<std::pair<int,int> >[2];
	std::string location;
	int time_;
	int car = 0;
	while(m--){
		std::cin >> time_ >> location;
		if(location == "left"){
			cars_arrival[0].push(std::make_pair(car,time_));
		}else{
			cars_arrival[1].push(std::make_pair(car,time_));
		}
		car++;
	}

	// ferry postion 0 is left and 1 is right.
	int ferry_position = 0;
	int current_time = 0;

	// Store result as <car,time> because we want to
	// sort the vector based on car.
	std::vector<std::pair<int,int> > result;
	while(true) {

	 	if(cars_arrival[0].size() == 0&&cars_arrival[1].size() ==0)break;

	 	int time;
	 	int spots = n;

	 	// Check car front car in queueq that has lowest arrival time.
	 	if(cars_arrival[0].size() > 0) time = cars_arrival[0].front().second;
	 	if(cars_arrival[1].size() > 0){
	 		if(cars_arrival[0].size() == 0) time = cars_arrival[1].front().second;
	 		else time = std::min(cars_arrival[1].front().second, time);
	 	}
	 	current_time = std::max(current_time,(int)time);

	 	// Fetch the cars that where the ferry's at if the time
	 	// is less than the current time.
	 	while(spots != 0&&!cars_arrival[ferry_position].empty()){
	 		if(current_time < cars_arrival[ferry_position].front().second) break;
	 		result.push_back(std::make_pair(cars_arrival[ferry_position].front().first,current_time+t));
	 		cars_arrival[ferry_position].pop();
	 		spots--;
	 	}

	 	current_time += t;
		ferry_position = ( ferry_position + 1) % 2;	
	}
	//Sort based on car arrival to the ferry.
	std::sort(result.begin(),result.end(), compare);
	for(auto& elem: result){
		std::cout <<elem.second << "\n";
	}
}


int main(){
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int num_tests;
	std::cin >> num_tests;
	int n;
	int t;
	int m;
	int num = 0;

	// solve each testcase
	while(num_tests--){
		std::cin >> n >> t >> m;
		if(num > 0) std::cout << "\n";
		solve(n,t,m);
		num++;
	}
}