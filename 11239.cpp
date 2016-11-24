#include <iostream>
#include <unordered_map>
#include <set>
#include <utility>
#include <algorithm>
#include <vector>

/**
Author: Marcus Adamsson
Problem: https://uva.onlinejudge.org/external/111/11136.pdf
**/

/*
Used to sort the result
*/
bool compare(const std::pair<std::string,int>& p1, const std::pair<std::string,int>& p2){
	if(p1.second != p2.second) return p1.second > p2.second;
	return p1.first < p2.first;
}


bool solve(){
	// Use a map to track number of project a student signed up for.
	// studentid -> project_name
	std::unordered_map<std::string,std::set<std::string> > student_proj;

	// Use a map to track number of students in each project.
	// project_name -> students
	std::unordered_map<std::string,std::set<std::string> > proj_map;

	std::string project;
	std::string userid;
	std::string line;

	/*
	If the input contains uppcase it's a project,
	if it cotians lowercase it's a studentid.
	else it's end of current testcase.
	*/
	while(true){
		std::getline(std::cin,line);
		if(line == "1"||line == "0") break;
		if(isupper(line[0])){
			project = line;
			proj_map[project];
		}
		else{
			userid = line;
			proj_map[project].insert(userid);
			student_proj[userid].insert(project);
		}
	}
	// If the input is 0 it's the end of all test cases.
	if(line == "0") return false;

	/*
	Store result in vector based on number of students 
	in each project. If a student have signed up for
	more than one project he should not be included.
	*/
	std::vector<std::pair<std::string,int> > result;
	for(auto it = proj_map.begin() ; it != proj_map.end(); it++){
		int num_students = (*it).second.size();
		for(auto itt = (*it).second.begin() ; itt != (*it).second.end(); itt++){
			if(student_proj[(*itt)].size() > 1) num_students--;
		}
		result.push_back(std::make_pair((*it).first, num_students));
	}

	// Sort and print out the result
	std::sort(result.begin(),result.end(),compare);
	for(int i = 0; i != result.size(); i++){
		std::cout << result[i].first << " " << result[i].second << "\n";
	}
	return true;

}

int main(){
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	while(solve());
}