#include <stack>
#include <iostream>
#include <vector>



int main(){
	int num;
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	while(true){
		std::cin >> num;
		if(num == 0) break;
		std::vector<std::vector<int> > wanted_order;
		while(true){
			/*
			Store the trains and read in the
			differnt permutations.
			*/
			int current_train;
			std::cin >> current_train;
			if(current_train == 0) break;
			std::vector<int> current_per;
			current_per.push_back(current_train);

			for(int i = 1; i != num; i++){
				int current_train;
				std::cin >> current_train;
				current_per.push_back(current_train);
			}
			wanted_order.push_back(current_per);
		}

		/*
		Go through each wanted permutation and try to arrange
		the current permutation 1,2,..,N in that order. If there
		the stations is not empty then we it's not possible
		to arrange in wanted order.
		*/
		for(int i = 0; i != wanted_order.size(); i++){
			int j = 0;
			std::stack<int> station;
			for(int current_train = 1; current_train <= num; current_train++){
				station.push(current_train);
				while(station.top() == wanted_order[i][j]){
					station.pop();
					j++;
					if(station.empty()) break;
				}
			}
			if(station.size() == 0){
				std::cout << "Yes" << "\n";
			}else{
				std::cout << "No" << "\n";
			}
		}
		std::cout << "\n";
	}
}


