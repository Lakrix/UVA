#include <iostream>
#include <stack>
#include <cctype>

/*
Author Marcus Adamsson
problem: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=668
*/


int main(){
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	std::stack<char> operator_stack;
	
	std::string line;

	int num_tests;
	std::cin >> num_tests;
	std::getline(std::cin, line);
	std::getline(std::cin, line);
	int num = 0;
	while(num_tests--){
		if(num > 0) std::cout << "\n";
		std::string postfix_string = "";
		while(std::getline(std::cin, line)){
			if(line == "") break;

			// if input is a digit add to 
			// postfix string
			if(isdigit(line[0])){
				postfix_string += line;
			}else if(operator_stack.empty()){
				 operator_stack.push(line[0]);
			}else{
				switch(line[0]){
					case '(':
						operator_stack.push(line[0]);
						break;
					case ')':
						// Evaluate parentheses
						while(operator_stack.top() != '('){
							postfix_string += operator_stack.top();
							operator_stack.pop();
						}
						operator_stack.pop();
						break;
					case '*':
					case '/':
						// If the top has lower priority then we should we should push to stack.
						if(operator_stack.top() != '+'&&operator_stack.top() != '-'&&operator_stack.top() != '('){
							postfix_string += operator_stack.top();
							operator_stack.pop();
						}
						operator_stack.push(line[0]);
						break;
					case '+':
					case '-':
						// If the top has lower priority then we should we should push to stack.
						if(operator_stack.top() != '('){
							while(!operator_stack.empty()&&operator_stack.top() != '('){
								postfix_string += operator_stack.top();
								operator_stack.pop();
							}
						}
						operator_stack.push(line[0]);
						break;
					default:
						break;
				}
			}
		}
		// Pop what's left of the stack.
		while(!operator_stack.empty()){
			postfix_string += operator_stack.top();
			operator_stack.pop();
		}
		std::cout << postfix_string << std::endl;
		num++;	
		
	}
}