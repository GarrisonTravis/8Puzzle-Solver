//Garrison Travis
//8Puzzle Solver

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

#define BOARD_SIZE 9

//Forward Declaration of comparator struct
struct CompareNodes;

class Node {
private:
	string state;
	int depth;
	int h;
	vector<pair<string, Node*>> path;

public:
	Node(string state) : state(state), depth(0), h(0), path(NULL) {}
	Node(string state, int depth, vector<pair<string, Node*>> path) : state(state), depth(depth), h(0), path(path) {}

	int getDepth() { return depth; }
	string getState() { return state; }
	void setHeuristic(int h) { this->h = h; }
	int getHeuristic() const { return h; }

	priority_queue<Node*, vector<Node*>, CompareNodes> expand(priority_queue<Node*, vector<Node*>, CompareNodes> frontier, vector<string>& visited, Node* goalState, bool& goalFound);
	int manDistance(string goalState);
	size_t getLocation(string state, char val);
	bool checkMove(string move);
	Node* applyMove(string move);
	void printPathToGoal();
	void printState();
};

//Struct to compare two ResPairs
struct CompareNodes {
	bool operator()(Node* n1, Node* n2) {
		return n1->getHeuristic() > n2->getHeuristic();
	}
};

#endif