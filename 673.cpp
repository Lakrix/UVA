#include <iostream>
#include <stack>
/*
Author Marcus Adamsson
Problem: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=8&page=show_problem&problem=614
*/
 

// Check if it's a correct balanced string.
bool solve(std::string line){
	std::stack<char> balanced_stack;

	for(auto& elem : line){
		bool poped = false;

		// check if we can match a parentheses
		if(balanced_stack.size() != 0){
			if(balanced_stack.top() == '(' && elem == ')'){
				balanced_stack.pop();
				poped = true;
			}else if(balanced_stack.top() == '[' && elem == ']'){
				balanced_stack.pop();
				poped = true;
			}
		}

		// If we didn't have match we should
		// push the elem to stack.
		if(!poped) balanced_stack.push(elem);
	}
	// it's balanced if the stack is empty
	return (balanced_stack.size() == 0);
}

int main(){
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int num_tests;
	std::string line;
	std::cin >> num_tests;
	std::getline(std::cin,line);
	while(num_tests--){
		
		// read each line;
		std::getline(std::cin,line);

		if(solve(line)) std::cout << "Yes";
		else std::cout << "No";
		std::cout << "\n";

	}
}