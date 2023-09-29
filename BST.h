
#ifndef __BST_H
#define __BST_H

#include <iostream>
#include <cstring>		// strcmp
#include <vector>
#include <queue>
#include <initializer_list>
#include <queue>

using namespace std;


template <typename T>
struct Node {
public:
	T value;
	Node* left;
	Node* right;

	static int nodeCount;

	Node(T val) {
		this->value = val;
		this->left = nullptr;
		this->right = nullptr;
		nodeCount++;
	}

	Node(T val, Node<T>* setLeft, Node<T>* setRight) {
		this->value = val;
		this->left = setLeft;
		this->right = setRight;
		nodeCount++;
	}

	~Node()
	{
		this->left = nullptr;
		this->right = nullptr;
		nodeCount--;
	}
	
	// getter ans setter methods
	T getValue () {
		return value;
	}

	void setValue(T val) {
		value = val;
	}
};

// Initialize the static class variable for counting nodes to zero
template <typename T>
int Node<T>::nodeCount = 0;


template <typename T>
class BST {
Node<T>* _root;         // Root of the tree nodes
bool _debug = false;    // Enable extra output
protected:

	void makeEmptyHelper(Node<T>* t) {
		if (t != nullptr) {
			makeEmptyHelper(t->left);
			makeEmptyHelper(t->right);
			delete t;
		}
	}


	void addHelper(Node<T>* root, T val) {
		if (root->value > val) {
			if (!root->left) {
				root->left = new Node<T>(val);
			}
			else {
				addHelper(root->left, val);
			}
		}
		else {
			if (!root->right) {
				root->right = new Node<T>(val);
			}
			else {
				addHelper(root->right, val);
			}
		}
	}


 void printHelper(Node<T> *root) {
        if (!root) return;
        printHelper(root->left);
        cout<<root->value<<' ';
        printHelper(root->right);
    }

	
	void printLevelOrderHelper(Node<T>* root, std::ostream& out) {
		out << endl;
	int h = height(root);
	int i;
	for (i = 1; i <= h;i++)
	{
		if(root == null)
		{
			return 0;
		}
		if (root == 1)
		{
			cout << _root->value << endl;
		}
		else if (i > 1)
		{
			printLevelOrderHelper(root->left);
			printLevelOrderHelper(root->right);
			i -1;
		}
	}

	}

void destructor(Node<T>* root){
if (Node)
{
	destructor(this->left);
	destructor(this->right);
	delete this;
}
}


	int nodesCountHelper(Node<T>* root) {
		if (!root) {
			return 0;
		}
		else {
			return 1 + nodesCountHelper(root->left) + nodesCountHelper(root->right);
		}
	}


	int heightHelper(Node<T>* root) {
		if (!root) {
			return -1;
		}
		else {
			return 1 + max(heightHelper(root->left), heightHelper(root->right));
		}
	}


	void printMaxPathHelper(Node<T>* root) {
		if (!root) return;
		cout << root->value << ' ';
		if (heightHelper(root->left) > heightHelper(root->right)) {
			printMaxPathHelper(root->left);
		}
		else {
			printMaxPathHelper(root->right);
		}
	}


	bool deleteValueHelper(Node<T>* parent, Node<T>* current, T value) {
		if (!current) return false;
		if (current->value == value) {
			if (current->left == nullptr || current->right == nullptr) {
				Node<T>* temp = current->left;
				if (current->right) temp = current->right;
				if (parent) {
					if (parent->left == current) {
						parent->left = temp;
					}
					else {
						parent->right = temp;
					}
				}
				else {
					this->_root = temp;
				}
			}
			else {
				Node<T>* validSubs = current->right;
				while (validSubs->left) {
					validSubs = validSubs->left;
				}
				T temp = current->value;
				current->value = validSubs->value;
				validSubs->value = temp;
				return deleteValueHelper(current, current->right, temp);
			}
			delete current;
			return true;
		}
		return deleteValueHelper(current, current->left, value) ||
			deleteValueHelper(current, current->right, value);
	}

	bool containsHelper(Node<T>* root, T val) {
		if (root == nullptr)
			return(false);
		else if (root->value == val)
			return(true);
		else if (root->value > val) // Search left
			return(containsHelper(root->left, val));
		else
			return(containsHelper(root->right, val));
	}


	Node<T>*  getNodeHelper(Node<T>* root, T val) {
		if (root == nullptr)
			return(nullptr);
		else if (root->getValue() == val)
			return(root);
		else if (root->getValue() > val) // Search left
			return(getNodeHelper(root->left, val));
		else
			return(getNodeHelper(root->right, val));
	}

 // public API
public:

	BST() : _root(nullptr) { }               // Basic initialization constructor

	BST(initializer_list<T> vals) : _root(nullptr) {
		for (auto val : vals)
		{
			this->add(val);
		}
	}

 void print() {
        printHelper(this->_root);
    }

	~BST() {
		if (this->_debug) {
			cout << " TODO: Implement destructor to free *whole* tree. " << endl;
			deconstructor(this); // goes to the destructor helper up top
		}
	}

	

	 // PUBLIC API
	void makeEmpty() {
		if (this->_root)
			this->makeEmptyHelper(this->_root);
		this->_root = nullptr;
	}

	void add(T val) {
		if (this->_root) {
			this->addHelper(this->_root, val);
		}
		else {
			this->_root = new Node<T>(val);
		}
	}

	bool empty() {
		return(this->_root == nullptr);
	}

	

	void printLevelOrder(std::ostream& out = std::cout) {
		printLevelOrderHelper(this->_root, out);
	}

	vector<T>& returnLevelOrder() {
		return returnLevelOrderHelper(this->_root);
	}

	int size() {
		return nodesCount();
	}
	int nodesCount() {
		return nodesCountHelper(this->_root);
	}

	int height() {
		return heightHelper(this->_root);
	}

	void printMaxPath() {
		printMaxPathHelper(this->_root);
	}

	bool deleteValue(T value) {
		return this->deleteValueHelper(nullptr, this->_root, value);
	}

	bool contains(T value) {
		return containsHelper(this->_root, value);
	}

	Node<T>*  getNode(T value) {
		return getNodeHelper(this->_root, value);
	}

	void debug_on() {
		this->_debug = true;
	}

	void debug_off() {
		this->_debug = false;
	}
};


#endif 
