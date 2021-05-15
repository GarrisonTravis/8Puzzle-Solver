//Garrison Travis
//8Puzzle Solver

#include "Node.h"

bool BFS(priority_queue<Node*, vector<Node*>, CompareNodes> frontier, Node* goalState) {
	vector<string> visited;
	bool goalFound = false;

	while (!frontier.empty()) {
		Node* currentNode = frontier.top();
		frontier.pop();

		//cout << "Current Node: " << endl;
		currentNode->printState();
		//cout << currentNode->getDepth() << endl;
		visited.push_back(currentNode->getState());

		frontier = currentNode->expand(frontier, visited, goalState, goalFound);

		if (goalFound)
			return true;
		
	}

	return false;
}

int main() {
	Node* goalState = new Node("123405678");
	Node* initialState = new Node("012345678");

	priority_queue<Node*, vector<Node*>, CompareNodes> frontier;
	frontier.push(initialState);

	if (!BFS(frontier, goalState)) 
		cout << "FAILURE!" << endl;
}