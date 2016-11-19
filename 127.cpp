#include <iostream>
#include <stack>
#include <vector>


// Author Marcus Adamsson



// My solutions to https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=3&page=show_problem&problem=63



//Check if the cards are a match.
bool isMatch(char* c1, char* c2){

	if(c1[0] == c2[0]) return true;
	if(c1[1] == c2[1]) return true;

	return false;
}

int main(){
	int num = 52;
	
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	while(true){
		bool end_of_game = false;;
		std::vector<std::stack<char*> > piles;

		
		// Read in each card deck
		for(int j = 0; j != 52; j++){
			char* card = new char[2];
			std::cin >> card;
			if(card[0] == '#'){
				end_of_game = true;
				break;
			}
			if(end_of_game) break;
			std::stack<char*> new_stack;
			new_stack.push((card));
			piles.push_back(new_stack);

			
			// While it's possible to move a card to left
			// do it.
			while(true){
				bool moved = false;
				for(int i = 1; i < piles.size(); i++){
					if(i >= 3){
						// Try move the card to the pile which is 
						// 3 piles to the left.
						if(isMatch(piles[i].top(),piles[i-3].top())){
							char* removed_card =  piles[i].top();
							piles[i-3].push(removed_card);
							piles[i].pop();
							moved = true;
							if(piles[i].size() == 0){
								piles.erase(piles.begin()+i);
							}
						}
					}
					if(moved) break;
					// Try move the card to the left pile.
					if(isMatch(piles[i].top(),piles[i-1].top())){
						char* removed_card =  piles[i].top();
						piles[i-1].push(removed_card);
						piles[i].pop();
						moved = true;
						if(piles[i].size() == 0){
							piles.erase(piles.begin()+i);
						}
					
					}
					if(moved) break;
				}
				if(!moved) break;
			}
		}
		if(end_of_game) break;

		// Print out the number of piles 
		// and thier size
		std::cout << piles.size() ;
		if(piles.size() > 1) std::cout << " piles remaining: ";
		else std::cout << " pile remaining: ";

		for(int i = 0; i != piles.size(); i++){
			if(i != 0) std::cout << " ";
			std::cout << piles[i].size();
		}
		std::cout << "\n";

	}


}