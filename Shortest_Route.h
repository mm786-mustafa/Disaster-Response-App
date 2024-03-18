// Shortest_Route.h
#ifndef Shortest_Route_h
#define Shortest_Route_h

#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <limits>

using namespace std;

#define INT_MAX numeric_limits<int>::max()


class Node;
class Edge;

void DijkstrasTest();

//int main() {
//    DijkstrasTest();
//    return 0;
//}

vector<Node*> nodes;
vector<Edge*> edges;

class Node {
public:
    string id;
    Node* previous;
    int distanceFromStart;

    Node(string id) : id(id), previous(NULL), distanceFromStart(INT_MAX) {
        nodes.push_back(this);
    }
};

class Edge {
public:
    Edge(Node* node1, Node* node2, int distance) : node1(node1), node2(node2), distance(distance) {
        edges.push_back(this);
    }

    bool Connects(Node* node1, Node* node2) {
        return ((node1 == this->node1 && node2 == this->node2) || (node1 == this->node2 && node2 == this->node1));
    }

    Node* node1;
    Node* node2;
    int distance;
};

void Dijkstras();

Node* ExtractSmallest(vector<Node*>& nodes);

vector<Node*>* AdjacentRemainingNodes(Node* node);

int Distance(Node* node1, Node* node2);

bool Contains(vector<Node*>& nodes, Node* node);

void PrintShortestRouteTo(Node* destination);

void Dijkstras() {
    while (!nodes.empty()) {
        Node* smallest = ExtractSmallest(nodes);
        vector<Node*>* adjacentNodes = AdjacentRemainingNodes(smallest);

        const int size = adjacentNodes->size();
        for (int i = 0; i < size; ++i) {
            Node* adjacent = adjacentNodes->at(i);
            int distance = Distance(smallest, adjacent) + smallest->distanceFromStart;

            if (distance < adjacent->distanceFromStart) {
                adjacent->distanceFromStart = distance;
                adjacent->previous = smallest;
            }
        }
        delete adjacentNodes;
    }
}

Node* ExtractSmallest(vector<Node*>& nodes) {
    int size = nodes.size();
    if (size == 0) return NULL;
    int smallestPosition = 0;
    Node* smallest = nodes.at(0);
    for (int i = 1; i < size; ++i) {
        Node* current = nodes.at(i);
        if (current->distanceFromStart < smallest->distanceFromStart) {
            smallest = current;
            smallestPosition = i;
        }
    }
    nodes.erase(nodes.begin() + smallestPosition);
    return smallest;
}

vector<Node*>* AdjacentRemainingNodes(Node* node) {
    vector<Node*>* adjacentNodes = new vector<Node*>();
    const int size = edges.size();
    for (int i = 0; i < size; ++i) {
        Edge* edge = edges.at(i);
        Node* adjacent = NULL;
        if (edge->node1 == node) {
            adjacent = edge->node2;
        } else if (edge->node2 == node) {
            adjacent = edge->node1;
        }
        if (adjacent && Contains(nodes, adjacent)) {
            adjacentNodes->push_back(adjacent);
        }
    }
    return adjacentNodes;
}

int Distance(Node* node1, Node* node2) {
    const int size = edges.size();
    for (int i = 0; i < size; ++i) {
        Edge* edge = edges.at(i);
        if (edge->Connects(node1, node2)) {
            return edge->distance;
        }
    }
    return -1;  // should never happen
}

bool Contains(vector<Node*>& nodes, Node* node) {
    const int size = nodes.size();
    for (int i = 0; i < size; ++i) {
        if (node == nodes.at(i)) {
            return true;
        }
    }
    return false;
}

void PrintShortestRouteTo(Node* destination) {
    Node* previous = destination;
    cout << "\nDISTANCE: " << destination->distanceFromStart <<" kms."<< endl;
    cout<<"HELP WILL ARRIVE IN APPROXIMATELY "<<destination->distanceFromStart*1.5<<" minutes."<<endl;
    cout << "SHORTEST ROUTE: ";
    while (previous) {
        cout << previous->id;
        if (previous->previous) {
            cout << " -> ";
        }
        previous = previous->previous;
    }
    cout << endl;
}

void DijkstrasTest(string userLocation, string EmeType) {
    // Creating nodes and edges
    Node* au = new Node("air uni");
    Node* bu = new Node("bahria uni");
    Node* paf = new Node("paf");
    Node* f10 = new Node("f10");
    Node* f8 = new Node("f8");
    Node* f7 = new Node("f7");
    Node* f6 = new Node("f6");
    Node* g9 = new Node("g9");
    Node* g8 = new Node("g8");
    Node* g7 = new Node("g7");
    Node* g6 = new Node("g6");
    Node* bluearea = new Node("blue area");
    Node* centaurus = new Node("centaurus");
    

    Edge* e1 = new Edge(au, bu, 1);
    Edge* e2 = new Edge(bu, f8, 2);
    Edge* e3 = new Edge(f8, f7, 2);
    Edge* e4 = new Edge(f7, f6, 2);
    Edge* e5 = new Edge(f6, g6, 2);
	Edge* e6 = new Edge(g6, g7, 2);
	Edge* e7 = new Edge(g7, bluearea, 1);
	Edge* e8 = new Edge(f7, bluearea, 1);
	Edge* e9 = new Edge(centaurus, bluearea, 1);
	Edge* e10 = new Edge(centaurus, f8, 1);
	Edge* e11 = new Edge(centaurus, g8, 1);
	Edge* e12 = new Edge(g8, g7, 2);
	Edge* e13 = new Edge(g8, g9, 2);
	Edge* e14 = new Edge(f8, g9, 2);
	Edge* e15 = new Edge(f8, f10, 2);
	Edge* e16 = new Edge(g9, f10, 1);
	Edge* e17 = new Edge(paf, f10, 2);
	Edge* e18 = new Edge(paf, au, 2);
	
	
    // Asking for user input
//    cout << "Enter your current location: ";
//    string userLocation;
//    getline(cin, userLocation);

    // Find the corresponding node for the user's location
    Node* userNode = NULL;
	for (size_t i = 0; i < nodes.size(); ++i) {
	    Node* node = nodes[i];
	    if (node->id == userLocation) {
	        userNode = node;
	        break;
	    }
	}


    // Validating input
    if (!userNode) {
        cout << "Invalid user location. Please check your location.\n";
        return;
    }

    // Setting destination based on the emergency type
    Node* emergencyResponseLocation;
    
    if(EmeType == "fire")
    {
    	emergencyResponseLocation = f6;  // Assuming fire brigade station is at f6
	}
	else if(EmeType == "medical")
	{
		emergencyResponseLocation = f10;  // Assuming fire brigade station is at f6
	}
    
    else if(EmeType == "electric shocks")
	{
		emergencyResponseLocation = g8 ;  // Assuming fire brigade station is at f6
	}
	
	else if(EmeType == "theft")
	{
		emergencyResponseLocation = f8 ;  // Assuming fire brigade station is at f6
	}
	
	else
	{
		cout<<"\nnot found\n";
	}
	
	
    // Running Dijkstra's algorithm
    userNode->distanceFromStart = 0;
    Dijkstras();

    // Printing the shortest route
    PrintShortestRouteTo(emergencyResponseLocation);
    cout<<endl;
    delete emergencyResponseLocation;
}


#endif

