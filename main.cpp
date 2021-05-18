//Garrison Travis
//8Puzzle Solver

#include "Node.h"

//Function to perform aStar search to find the goalState
bool aStar(Node* initialState, Node* goalState) {

	priority_queue<Node*, vector<Node*>, CompareNodes> frontier;
	vector<string> visited;
	bool goalFound = false;

	//Add initial state to the frontier and visited list
	frontier.push(initialState);
	visited.push_back(initialState->getState());

	//While the frontier is not empty, pop the top of the queue and expand
	while (!frontier.empty()) {
		Node* currentNode = frontier.top();
		frontier.pop();

		frontier = currentNode->expand(frontier, visited, goalState, goalFound);

		if (goalFound)
			return true;
	}

	return false;
}

int main() {
	//Node* goalState = new Node("123456780");
	//Node* initialState = new Node("867254301");

	Node* goalState = new Node("123456780");
	Node* initialState = new Node("123405678");

	cout << "Initial State:" << endl;
	cout << "--------------" << endl;
	initialState->printState();
	cout << endl;

	cout << "Goal State:" << endl;
	cout << "--------------" << endl;
	goalState->printState();
	cout << endl;

	if (!aStar(initialState, goalState)) 
		cout << "Failure! Solution could not be found." << endl;
}