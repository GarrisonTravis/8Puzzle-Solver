//Garrison Travis
//8Puzzle Solver

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

class Node {
private:
	string state;

public:
	Node(string state) : state(state) {}

	bool expand(queue<Node*>& frontier, vector<string>& visited, Node* goalState);
	int blankLocation();
	bool checkMove(string move);
	Node* applyMove(string move);
	void printState();
};

#endif