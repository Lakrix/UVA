#include <iostream>
#include <unordered_map>
#include <vector>

/**
Author: Marcus Adamsson
Problem: https://uva.onlinejudge.org/external/115/11503.pdf
**/


/*
Use disjoint set to store how large a set is
and who is connected to who.
*/
std::vector<int> ds(100000);
std::vector<int> ds_size(100000);

void init(int size){
	ds.resize(size);
	ds_size.resize(size);
	for(int i = 0; i != size;i++){
		ds[i] = i;
		ds_size[i] = 1;
	}
}

int findSet(int i){
	if(i == ds[i]) return i;
	return ds[i] = findSet(ds[i]);
}

bool isSameSet(int i, int j){
	return findSet(i) == findSet(j);

}

void unionSet(int i, int j){
	int x = findSet(i);
	int y = findSet(j);

	ds_size[x] += ds_size[y];
	ds[y] = x;

}

/*
Read in the number of frendships and for
each person connected them if they are not
already connected. Print out the size of thier
friendship after they get connected.
*/
void solve(){
	int num_friendships;
	std::cin >> num_friendships;
	std::unordered_map<std::string,int> persons;
	std::string person_one;
	std::string person_two;
	int index = 0;

	init(100000);
	while(num_friendships--){
		std::cin >> person_one >> person_two;
		int p1;
		int p2;
		if(persons.count(person_one) == 0){
			persons[person_one] = index;
			p1 = index;
			index++;
		}else{
			p1 = persons[person_one];
		}

		if(persons.count(person_two) == 0){
			persons[person_two] = index;
			p2 = index;
			index++;
		}else{
			p2 = persons[person_two];
		}

		if(!isSameSet(p1,p2)) unionSet(p1,p2);
		std::cout << ds_size[findSet(p1)] << std::endl;
		
	}
}

int main(){

	// Read input
	int tests;
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	std::cin >> tests;
	while(tests--){
		solve();
	}
}
