void *__gxx_personality_v0;
#include <iostream>
#include "BST.h" 

int main(){

	/* MA TODO: Implement */
	/* Create a BST string tree (bst_test) ; add the following string values to the bst_test in order: "C", "p", "t", "s", "2", "3" , "B", "S", "T"*/
      BST<int> *bst = new BST<int>();
    bst->add(11);
    bst->add(1);
    bst->add(6);
    bst->add(-1);
    bst->add(-10);
    bst->add(100);
    bst->print();
    cout<<endl;
    bst->printLevelOrder();
   
    cout << "100 in BST? true (1) or false (0): " << bst->contains(100) << endl;
    cout << "9 in BST? true (1) or false (0): " << bst->contains(9) << endl;
    cout<<"Nodes count: "<<bst->nodesCount();
    cout<<endl;
    cout<<"Height: "<<bst->height();
    cout<<endl;
    cout<<"Max path: ";
    bst->printMaxPath();
    cout<<endl;
    bst->deleteValue(11);
    cout<<"After 11 removed: ";
    bst->print();
    cout<<endl;
    bst->printLevelOrder();
    cout<<"Nodes count: "<<bst->nodesCount();
    cout<<endl;
    delete bst;
    return 0;


	return 0;
}
