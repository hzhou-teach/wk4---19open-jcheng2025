/*
Name: Jonathan C
Difficulty: 7.5/10
USACO Test Cases: ********** 10/10
Time: 1 hr 12 min
Description: First worked out a long solution before realizing that if a node has an outdegree of 0, it can be reached by every other node if no other node has an outdegree of 0
*/
#include <bits/stdc++.h>

using namespace std;

int main() {

	ifstream fin("factory.in");
	ofstream fout("factory.out");

	int N;
	fin >> N;

	int flow[N+1] = {0};

	for(int i = 0; i < N-1; i++) {
		int a, b;
		fin >> a >> b;

		flow[a]++; //keep track of outdegrees 
	}

	int ans = -1;
	for(int i = 1; i < N+1; i++) {
		if(flow[i] == 0 && ans > 0) { //if the flow is nonexistant and we already have an answer, since it is a tree, you cant reach the answer node from the current non-existant flow node.
			fout << "-1\n";
			return 0;
		} else if (flow[i] == 0) { //if the flow is nonexistant, we have reached a node in which every node can flow to the current node
			ans = i;
		}
	}

	fout << ans << "\n"; //print the node that can be flowed to
	return 0;
}
