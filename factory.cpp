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

		flow[a]++; //keep track of flow 
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
