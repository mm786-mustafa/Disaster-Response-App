// EmergencyInfoTree.h
#ifndef EmergencyInfoTree_h
#define EmergencyInfoTree_h

#include <iostream>
#include <string>
using namespace std;

class EmergencyInfoTree 
{
	private:
	    struct Node {
	        string title;
	        string paragraph;
	        Node* left;
	        Node* right;
	
	        Node(const string& t, const string& p) : title(t), paragraph(p), left(NULL), right(NULL) {}
	    };
	
	    Node* root;
	
	public:
	    EmergencyInfoTree() : root(NULL) {}
	
	    void insert(const string& title, const string& paragraph) {
	        root = insertHelper(root, title, paragraph);
	    }
	
	    void search(const string& title)  {
	        Node* result = searchHelper(root, title);
	        if (result != NULL) {
	            cout << "\nTITLE: " << result->title << "\n";
	            cout << "PARAGRAPH: " << result->paragraph << "\n";
	        } else {
	            cout << "TITLE NOT FOUND.\n";
	        }
	    }
	
	private:
	    Node* insertHelper(Node* node, const string& title, const string& paragraph) {
	        if (node == NULL) {
	            return new Node(title, paragraph);
	        }
	
	        if (title < node->title) {
	            node->left = insertHelper(node->left, title, paragraph);
	        } 
			else if (title > node->title) 
			{
	            node->right = insertHelper(node->right, title, paragraph);
	        }
	
	        return node;
	    }
	
	    Node* searchHelper(Node* node, const string& title) const {
	        if (node == NULL || node->title == title) {
	            return node;
	        }
	
	        if (title < node->title) {
	            return searchHelper(node->left, title);
	        } else {
	            return searchHelper(node->right, title);
	        }
	    }
};


#endif

