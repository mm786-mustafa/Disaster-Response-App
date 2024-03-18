// EmergencyTree.h
//emergencies in city tree
#ifndef EmergencyTree_h
#define EmergencyTree_h

#include <iostream>
#include <string>
using namespace std;

class EmergencyTree 
{
	private:
	    struct Node {
	        string emergency;
	        Node* left;
	        Node* right;
	
	        Node(const string& value) : emergency(value), left(NULL), right(NULL) {}
	    };
	
	    Node* root;
	
	public:
	    EmergencyTree() : root(NULL) {}
	
	    void displayEmergencies() const {
	        cout << "------------------EMERGENCIES IN ISLAMABAD------------------\n";
	        displayEmergenciesHelper(root);
	    }
	
	    void addEmergency(const string& emergency) {
	        root = addEmergencyHelper(root, emergency);
	        cout << "EMERGENCY ADDED SUCCESSFULLY: " << emergency << endl;
	    }
	
	    void deleteEmergency(const string& emergency) {
	        root = deleteEmergencyHelper(root, emergency);
	        cout << "EMERGENCY DELETED SUCCESSFULLY: " << emergency << endl;
	    }
	
	private:
	    void displayEmergenciesHelper(Node* node) const 
		{
	        if (node != NULL) 
			{
	            cout << node->emergency << endl;
	            displayEmergenciesHelper(node->left);
	            displayEmergenciesHelper(node->right);
	        }
	    }
	
	    Node* addEmergencyHelper(Node* node, const string& emergency) 
		{
	        if (node == NULL) 
			{
	            return new Node(emergency);
	        }
	
	        if (emergency < node->emergency) 
			{
	            node->left = addEmergencyHelper(node->left, emergency);
	        } else if (emergency > node->emergency) 
			{
	            node->right = addEmergencyHelper(node->right, emergency);
	        }
	
	        return node;
	    }
	
	    Node* deleteEmergencyHelper(Node* node, const string& emergency) 
		{
	        if (node == NULL) 
			{
	            return node;
	        }
	
	        if (emergency < node->emergency) 
			{
	            node->left = deleteEmergencyHelper(node->left, emergency);
	        } 
			else if (emergency > node->emergency) 
			{
	            node->right = deleteEmergencyHelper(node->right, emergency);
	        } 
			else 
			{
	            // Node with only one child or no child
	            if (node->left == NULL) 
				{
	                Node* temp = node->right;
	                delete node;
	                return temp;
	            } else if (node->right == NULL) 
				{
	                Node* temp = node->left;
	                delete node;
	                return temp;
	            }
	
	            // Node with two children: Get the inorder successor (smallest in the right subtree)
	            Node* temp = minValueNode(node->right);
	
	            // Copy the inorder successor's content to this node
	            node->emergency = temp->emergency;
	
	            // Delete the inorder successor
	            node->right = deleteEmergencyHelper(node->right, temp->emergency);
	        }
	
	        return node;
	    }
	
	    Node* minValueNode(Node* node) 
		{
	        Node* current = node;
	        while (current->left != NULL) 
			{
	            current = current->left;
	        }
	        return current;
	    }
};



#endif

