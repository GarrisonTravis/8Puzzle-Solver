//Garrison Travis
//8Puzzle Solver

#include "Node.h"

bool BFS(queue<Node*>& frontier, Node* goalState) {
	vector<string> visited;

	while (!frontier.empty()) {
		Node* newNode = frontier.front();
		frontier.pop();

		newNode->printState();

		if (newNode->expand(frontier, visited, goalState))
			return true;
	}

	return false;
}

int main() {
	Node* goalState = new Node("123456078");
	Node* initialState = new Node("123456708");

	queue<Node*> frontier;
	frontier.push(initialState);

	if (BFS(frontier, goalState)) {
		cout << "SUCCESS!" << endl;
	}
	else
		cout << "FAILURE!" << endl;
}