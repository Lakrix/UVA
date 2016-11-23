#include <iostream>
#include <set>

/**
Author: Marcus Adamsson
Problem: https://uva.onlinejudge.org/external/111/11136.pdf
**/

void solve(int num){
	// Store the bills in a multiset.
	std::multiset<long long int> bills;
	int n;
	int days = num;
	long long int total = 0;
	while(num--){
		std::cin >> n;
		long long int current;
		while(n!= 0){
			std::cin >> current;
			bills.insert(current);
			n--;
		}
		// fetch first and last bill each day
		auto it = bills.begin();
		auto itt = bills.end();
		itt--;
		total += (*itt) - (*it);
		bills.erase(it);
		bills.erase(itt);
	}
	// Print out the total amount
	std::cout << total << std::endl;
}

int main(){
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int num;
	while(true){
		std::cin >> num;
		if(num == 0)break;
		solve(num);
	}
}