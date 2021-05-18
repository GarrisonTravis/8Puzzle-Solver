//Garrison Travis
//8Puzzle Solver

#include "Node.h"

//Function to generate the child nodes
priority_queue<Node*, vector<Node*>, CompareNodes> Node::expand(priority_queue<Node*, vector<Node*>, CompareNodes> frontier, vector<string>& visited, Node* goalState, bool& goalFound) {
    
    if (checkMove("UP")) {
        Node* newNode = applyMove("UP");
        newNode->setHeuristic(newNode->manDistance(goalState->getState()));

        //If state is not in visited, then add to frontier
        if (find(visited.begin(), visited.end(), newNode->state) == visited.end()) {
            frontier.push(newNode);
            visited.push_back(newNode->state);

            newNode->path.push_back(pair<string, Node*>("UP", newNode));
        }

        //Check if at goal state
        if (goalState->getState() == newNode->getState()) {
            newNode->printPathToGoal();
            goalFound = true;
        }
    }
    if (checkMove("DOWN")) {
        Node* newNode = applyMove("DOWN");
        newNode->setHeuristic(newNode->manDistance(goalState->getState()));

        //If state is not in visited, then add to frontier
        if (find(visited.begin(), visited.end(), newNode->state) == visited.end()) {
            frontier.push(newNode);
            visited.push_back(newNode->state);

            newNode->path.push_back(pair<string, Node*>("DOWN", newNode));
        }

        //Check if at goal state
        if (goalState->getState() == newNode->getState()) {
            newNode->printPathToGoal();
            goalFound = true;
        }
    }
    if (checkMove("LEFT")) {
        Node* newNode = applyMove("LEFT");
        newNode->setHeuristic(newNode->manDistance(goalState->getState()));

        //If state is not in visited, then add to frontier
        if (find(visited.begin(), visited.end(), newNode->state) == visited.end()) {
            frontier.push(newNode);
            visited.push_back(newNode->state);

            newNode->path.push_back(pair<string, Node*>("LEFT", newNode));
        }

        //Check if at goal state
        if (goalState->getState() == newNode->getState()) {
            newNode->printPathToGoal();
            goalFound = true;
        }
    }
    if (checkMove("RIGHT")) {
        Node* newNode = applyMove("RIGHT");
        newNode->setHeuristic(newNode->manDistance(goalState->getState()));

        //If state is not in visited, then add to frontier
        if (find(visited.begin(), visited.end(), newNode->state) == visited.end()) {
            frontier.push(newNode);
            visited.push_back(newNode->state);

            newNode->path.push_back(pair<string, Node*>("RIGHT", newNode));
        }

        //Check if at goal state
        if (goalState->getState() == newNode->getState()) {
            newNode->printPathToGoal();
            goalFound = true;
        }
    }

    return frontier;
}

//Function to get the Manhattan Distance heuristic for a state
int Node::manDistance(string goalState) {
    int goalX = -1, goalY = -1, stateX = -1, stateY = -1;
    int manDistance = 0;
    int totalManDistance = 0;
    int goalIndex = -1, stateIndex = -1;

    for (int i = 0; i < BOARD_SIZE; i++) {

        //Get the location of each number on the current state and the goal state
        goalIndex = getLocation(goalState, '0' + i);
        stateIndex = getLocation(state, '0' + i);

        //Get the index in the form of a coordinate point
        goalX = goalIndex / 3;
        goalY = goalIndex % 3;
        stateX = stateIndex / 3;
        stateY = stateIndex % 3;

        //Perform abs(x1 - x2) + abs(y1 - y2) to get Manhattan Distance
        manDistance = abs(goalX - stateX) + abs(goalY - stateY);

        totalManDistance += manDistance;
    }

    return totalManDistance;
}

//Function to get the location of the blank tile
size_t Node::getLocation(string state, char val) {
    size_t loc = state.find(val);
    if (loc != string::npos)
        return loc;

	return -1;
}

//Function to push all available moves onto a vector
bool Node::checkMove(string move) {
	int blank = getLocation(state, '0');
	
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
    int blank = getLocation(state, '0');

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

    Node* newNode = new Node(newState, depth + 1, path);

    return newNode;
}

//Function to print the path to the goal state
void Node::printPathToGoal() {

    cout << "SUCCESS!" << endl;
    cout << "Path:" << endl;
    cout << "-----" << endl << endl;

    for (int i = 0; i < path.size(); i++) {
        cout << path.at(i).first << endl;
        cout << "Depth = " << path.at(i).second->depth << endl;
        path.at(i).second->printState();
        cout << endl;
    }
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