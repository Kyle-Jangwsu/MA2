void *__gxx_personality_v0;
#include <iostream>
#include "BST.h" 

int main(){

	/* MA TODO: Implement */

      BST<int> *bst = new BST<int>();
    bst->add(11);
    bst->add(1);
    bst->add(6);
    bst->add(-1);
    bst->add(-10);
    bst->add(100);
    bst->print();
    cout<<endl;
    bst->printLevelOrder(); // prints in level order should be 11 / 1,100 / -1,6 / -10
   
    cout << "100 in BST? true (1) or false (0): " << bst->contains(100) << endl;
    cout << "9 in BST? true (1) or false (0): " << bst->contains(9) << endl;
    cout<<"Nodes count: "<<bst->nodesCount(); // counts how many nodes
    cout<<endl;
    cout<<"Height: "<<bst->height();  // finds height of the tree
    cout<<endl;
    cout<<"Max path: ";
    bst->printMaxPath();
    cout<<endl;
    bst->deleteValue(11);
    cout<<"After 11 removed: ";
    bst->print();
    cout<<endl;
    bst->printLevelOrder(); // should print 100 / 1/ -1,6 / -10
    cout<<"Nodes count: "<<bst->nodesCount();
    cout<<endl;
    bst->~BST(); // deconstructor
    delete bst;
    return 0;


	return 0;
}
