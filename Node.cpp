//Garrison Travis
//8Puzzle Solver

#include "Node.h"

//Function to generate the child nodes
bool Node::expand(queue<Node*>& frontier, vector<string>& visited, Node* goalState) {
    
    if (checkMove("UP")) {
        cout << "UP" << endl;
        Node* newNode = applyMove("UP");
        newNode->printState();

        if (goalState->state == newNode->state) {
            return true;
        }

        if (newNode->state != state && find(visited.begin(), visited.end(), newNode->state) == visited.end()) {
            frontier.push(newNode);
            visited.push_back(newNode->state);
        }
    }
    if (checkMove("DOWN")) {
        cout << "DOWN" << endl;
        Node* newNode = applyMove("DOWN");
        newNode->printState();

        if (goalState->state == newNode->state) {
            return true;
        }

        if (newNode->state != state && find(visited.begin(), visited.end(), newNode->state) == visited.end()) {
            frontier.push(newNode);
            visited.push_back(newNode->state);
        }
    }
    if (checkMove("LEFT")) {
        cout << "LEFT" << endl;
        Node* newNode = applyMove("LEFT");
        newNode->printState();

        if (goalState->state == newNode->state) {
            return true;
        }

        if (newNode->state != state && find(visited.begin(), visited.end(), newNode->state) == visited.end()) {
            frontier.push(newNode);
            visited.push_back(newNode->state);
        }
    }
    if (checkMove("RIGHT")) {
        cout << "RIGHT" << endl;
        Node* newNode = applyMove("RIGHT");
        newNode->printState();

        if (goalState->state == newNode->state) {
            return true;
        }

        if (newNode->state != state && find(visited.begin(), visited.end(), newNode->state) == visited.end()) {
            frontier.push(newNode);
            visited.push_back(newNode->state);
        }
    }
}

//Function to get the location of the blank tile
int Node::blankLocation() {
	for (int i = 0; i < state.size(); i++) {
		if (state[i] == '0')
			return i;
	}

	return -1;
}

//Function to push all available moves onto a vector
bool Node::checkMove(string move) {
	int blank = blankLocation();
	
    if (move == "UP") {
        if (blank >= 0 && blank <= 2)
            return false;
        else
            return true;
    }
    else if (move == "DOWN") {
        if (blank >= 6 && blank <= 8)
            return false;
        else
            return true;
    }
    else if (move == "LEFT") {
        if (blank % 3 == 0)
            return false;
        else
            return true;
    }
    else if (move == "RIGHT") {
        if (blank % 3 == 2)
            return false;
        else
            return true;
    }
    return false;
}

//Function to apply a move to a state
Node* Node::applyMove(string move) {

    string newState = state;
    int blank = blankLocation();

    if (move == "UP") {
        newState[blank] = newState[blank - 3];
        newState[blank - 3] = '0';
    }
    else if (move == "DOWN") {
        newState[blank] = newState[blank + 3];
        newState[blank + 3] = '0';
    }
    else if (move == "LEFT") {
        newState[blank] = newState[blank - 1];
        newState[blank - 1] = '0';
    }
    else if (move == "RIGHT") {
        newState[blank] = newState[blank + 1];
        newState[blank + 1] = '0';
    }

    Node* newNode = new Node(newState);

    return newNode;
}

//Function to print the state of the board
void Node::printState() {
	for (int i = 0; i < 3; i++) {
		cout << state[i] << " ";
	}
	cout << endl;
	for (int i = 3; i < 6; i++) {
		cout << state[i] << " ";
	}
	cout << endl;
	for (int i = 6; i < 9; i++) {
		cout << state[i] << " ";
	}
	cout << endl;

}