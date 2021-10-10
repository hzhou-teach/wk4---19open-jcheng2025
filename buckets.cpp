/*
Name: Jonathan C
Difficulty: 5/10
USACO Test Cases: ********** 10/10
Time: 31 min
Description: Really hard working out if statements
*/
#include <bits/stdc++.h>

using namespace std;

int main() {

	int bx, by;
	int lx, ly;
	int rx, ry;

	ifstream fin("buckets.in");
	ofstream fout("buckets.out");

	for(int i = 0; i < 10; i++) {
		string l;
		fin >> l;
		for(int e = 0; e < 10; e++) {
			if(l.at(e) == 'B') {
				bx = i;
				by = e;
			}

			if(l.at(e) == 'L') {
				lx = i;
				ly = e;
			}

			if(l.at(e) == 'R') {
				rx = i;
				ry = e;
			}
		}
	}

	//if bucket and farm forms a straight line and the rock intersects that path, add 2 to the total path to work around it
	if((bx == lx && rx == bx && ((ry > by && ry < ly) || (ry < by && ry > ly))) || (by == ly && by == ry && ((rx > bx && rx < lx) || (rx < bx && rx > lx)))) {
		fout << abs(bx-lx) + abs(by-ly)+1;
	} else {
		fout << abs(bx-lx) + abs(by-ly)-1;
	}

	fout << "\n";
	return 0;
}
