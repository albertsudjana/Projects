#ifndef BST_H_
#define BST_H_
#include <assert.h>
#include <cstddef>
#include <iostream>
#include<stdlib.h>
#include <string>
#include "Shoes.h"
#include "Shoes2.h"

using namespace std;

template <class bstdata>
class BST
{
    private:
        struct Node
        {
                bstdata data;
                Node* left;
                Node* right;

                Node(bstdata newdata): data(newdata), left(NULL), right(NULL) {}
        };

        typedef struct Node* NodePtr;
        NodePtr root;

        /**Private helper functions*/

        void insertHelper(NodePtr root, bstdata value);
        //private helper function for insert
        //recursively inserts a value into the BST

        void destructorHelper(NodePtr root);
        //private helper function for the destructor
        //recursively frees the memory in the BST

        void inOrderPrintHelper(NodePtr root);
                //private helper function for inOrderPrint
                //recursively prints tree values in order from smallest to largest

       void preOrderPrintHelper(NodePtr root);
                //private helper function for preOrderPrint
                //recursively prints tree values in preorder

       void postOrderPrintHelper(NodePtr root);
                //private helper function for postOrderPrint
                //recursively prints tree values in postorder
        void inOrderPrintHelper(NodePtr root, ostream& output);
        //private helper function for inOrderPrint
        //recursively prints tree values in order from smallest to largest

        void preOrderPrintHelper(NodePtr root, ostream& output);
        //private helper function for preOrderPrint
        //recursively prints tree values in preorder

        void postOrderPrintHelper(NodePtr root, ostream& output);
        //private helper function for postOrderPrint
        //recursively prints tree values in postorder

        bstdata maximumHelper(NodePtr root);
        //recursively searches for the maximum value in the Binary Search Tree

        bstdata minimumHelper(NodePtr root);
        //recursively locates the minimum value in the tree
        //returns this value once it is located

        void getSizeHelper(NodePtr root, int& size);
        //recursively calculates the size of the tree

        int getHeightHelper(NodePtr root);
        //recursively calculates the height of the tree

        bool findHelper(NodePtr root, bstdata value);
        //recursively searches for value in the tree

        NodePtr removeHelper(NodePtr root, bstdata value);
        //recursively removes the specified value from the tree

        void copyHelper(NodePtr copy);
        //recursively makes a deep copy of a binary search tree

        double findPriceHelper(NodePtr root, bstdata value);

        bool findToRemoveHelper(NodePtr root, bstdata value);

        int findIdHelper(NodePtr root, bstdata value);

        /**Public functions*/

    public:
        BST();
        //Instantiates a new Binary Search Tree
        //post: a new Binary Search Tree object

        ~BST();
        //frees the memory of the BST object
        //All memory has been deallocated

        BST(const BST& tree);
        //makes a deep copy of tree
        //Calls the copyHelper function to make a copy recursively

        /**Accessors*/
        bool isEmpty();
        //determines whether the Binary Search Tree is empty

        bstdata getRoot();
        //returns the value stored at the root of the Binary Search Tree
        //pre: the Binary Search Tree is not empty

        bstdata maximum();
        //finds the maximum value in the Binary Search Tree and returns it
        //calls the maximumHelper function to search for the max recursively
        //pre: !isEmpty()

        bstdata minimum();
        //calls the minimumHelper function to return the minimum value in the tree
        //Pre: the tree is not empty

        int getSize();
        //returns the size of the tree
        //calls the getSizeHelper function to calculate the size recursively

        int getHeight();
        //recursively finds the height of the tree and returns it
        //calls the getHeight helper function to calculate the height recursively
        //returns -1 if the tree is empty

        bool find(bstdata value);
        //returns whether the value is in the tree
        //calls the findHelper function to search for the value recursively
        //Pre: !isEmpty()

        double findPrice(bstdata value);

        bool findToRemove(bstdata value);

        int findId(bstdata value);

        /**Manipulators*/

        void insert(bstdata value);
        //inserts a new value into the Binary Search Tree
        //post: a new value inserted into the Binary Search Tree

        void remove(bstdata value);
        //removes the specified value from the tree
        //Pre: !isEmpty()
        //Pre: The value is contained in the Binary Search Tree
        //If the value is not in the Binary Search Tree, the tree is left unchanged

        void inOrderPrint();
                //calls the inOrderPrintHelper function to print out the values
                //stored in the Binary Search Tree
                //If the tree is empty, prints nothing

        void preOrderPrint();
                //calls the preOrderPrintHelper function to print out the values
                //stored in the Binary Search Tree
                //If the tree is empty, prints nothing

        void postOrderPrint();
                //calls the postOrderPrintHelper function to print out the values
                //stored in the Binary Search Tree
                //If the tree is empty, prints nothing
        void inOrderPrint(ostream& output);
        //calls the inOrderPrintHelper function to print out the values
        //stored in the Binary Search Tree
        //If the tree is empty, prints nothing

        void preOrderPrint(ostream& output);
        //calls the preOrderPrintHelper function to print out the values
        //stored in the Binary Search Tree
        //If the tree is empty, prints nothing

        void postOrderPrint(ostream& output);
        //calls the postOrderPrintHelper function to print out the values
        //stored in the Binary Search Tree
        //If the tree is empty, prints nothing

};
//////////////////////////////////////////////////////////////////////////////
template<class bstdata>
BST<bstdata>::BST() : root(NULL){}
template<class bstdata>
BST<bstdata>::~BST()
{
	destructorHelper(root);
}
template<class bstdata>
void BST<bstdata>::destructorHelper(NodePtr root)
{
	if(root->left != NULL)
	{
		destructorHelper(root->left);
	}
	if(root->right != NULL)
	{
		destructorHelper(root->right);
	}
	delete root;
	root = NULL;
}
template <class bstdata>
BST<bstdata>::BST(BST const& tree)
{
	root = NULL;
	copyHelper(tree.root);
}
template <class bstdata>
void BST<bstdata>::copyHelper(NodePtr copy)
{
	if(copy)
	{
		insert(copy->data);
		copyHelper(copy->left);
		copyHelper(copy->right);
	}
}
template <class bstdata>
bstdata BST<bstdata>::maximum()
{
	assert(!isEmpty());
	NodePtr temp = root;
	bstdata max = root->data;
	if (isEmpty()){
		cout << "maximum(): BST is empty, cannot find maximum value" << endl;
		exit(-1);
	}
	while(temp!=NULL){
		max = temp->data;
		temp = temp->right;
	}
	return max;
}
template <class bstdata>
bstdata BST<bstdata>::maximumHelper(NodePtr root)
{
	if (root->right==NULL){
		return root->data;
		} else
		return (maximumHelper(root->right));
}
template <class bstdata>
bstdata BST<bstdata>::minimum()
{
	assert(!isEmpty());
	NodePtr temp = root;
	bstdata min = root->data;
	if (isEmpty()){
		cout << "minimum(): BST is empty, cannot find minimum value" << endl;
		exit(-1);
	}
	while(temp!=NULL){
		min = temp->data;
		temp = temp->left;
	}
return min;
}
template <class bstdata>
bstdata BST<bstdata>::minimumHelper(NodePtr root)
{
	if (root->left==NULL){
	return root->data;
	} else
	return (minimumHelper(root->left));
}
template <class bstdata>
bool BST<bstdata>::isEmpty()
{
 return (root == NULL);
}
template<class bstdata>
bstdata BST<bstdata>::getRoot()
{
	assert(root!=NULL);
	return root->data;
}
template <class bstdata>
int BST<bstdata>::getSize()
{
	int size =0;
	getSizeHelper(root, size);
	return size;
}
template <class bstdata>
void BST<bstdata>::getSizeHelper(NodePtr root, int& size)
{

	if (root!=NULL){
		size++;
		getSizeHelper(root->left, size);
		getSizeHelper(root->right, size);
	}
}
template <class bstdata>
int BST<bstdata>::getHeight(){
	if(isEmpty())
		return -1;
	else
		return getHeightHelper(root)-1;
}
template <class bstdata>
int BST<bstdata>::getHeightHelper(NodePtr root){
int height=0;
if (root != NULL){
if (getHeightHelper(root->left) > getHeightHelper(root->right)){
height = getHeightHelper(root->left) + 1;
} else {
height = getHeightHelper(root->right) + 1;
}
return height;
}
return height;
}
template <class bstdata>
bool BST<bstdata>::find(bstdata value)
{
	if (isEmpty()) return false;
	if (value == root->data){
		cout << root->data << endl;
		return true;
	}
	else
		return findHelper(root, value);
}
template <class bstdata>
bool BST<bstdata>::findHelper(NodePtr root, bstdata value)
{
	if (value == root->data){
	cout << root->data << endl;
	return true;
	}

	if (value < root->data){
	if (root->left == NULL){
	return false;
	} else {
	return findHelper(root->left, value);
	}
	} else {
	if (root->right == NULL){
	return false;
	} else {
	return findHelper(root->right, value);
	}
	}
	return false;
}

template <class bstdata>
double BST<bstdata>::findPrice(bstdata value)
{
	if (isEmpty()) return false;
	if (value == root->data){
		return root->data.get_price();
	}
	else
		return findPriceHelper(root, value);
}
template <class bstdata>
double BST<bstdata>::findPriceHelper(NodePtr root, bstdata value)
{
	if (value == root->data){
	return root->data.get_price();
	}

	if (value < root->data){
	if (root->left == NULL){
	return false;
	} else {
	return findPriceHelper(root->left, value);
	}
	} else {
	if (root->right == NULL){
	return false;
	} else {
	return findPriceHelper(root->right, value);
	}
	}
	return false;
}

template <class bstdata>
int BST<bstdata>::findId(bstdata value)
{
	if (isEmpty()) return false;
	if (value == root->data){
		return root->data.get_idNum();
	}
	else
		return findIdHelper(root, value);
}
template <class bstdata>
int BST<bstdata>::findIdHelper(NodePtr root, bstdata value)
{
	if (value == root->data){
	return root->data.get_idNum();
	}

	if (value < root->data){
	if (root->left == NULL){
	return false;
	} else {
	return findIdHelper(root->left, value);
	}
	} else {
	if (root->right == NULL){
	return false;
	} else {
	return findIdHelper(root->right, value);
	}
	}
	return false;
}

template <class bstdata>
bool BST<bstdata>::findToRemove(bstdata value)
{
	if (isEmpty()) return false;
	if (value == root->data){
		return true;
	}
	else
		return findToRemoveHelper(root, value);
}
template <class bstdata>
bool BST<bstdata>::findToRemoveHelper(NodePtr root, bstdata value)
{
	if (value == root->data){
	return true;
	}

	if (value < root->data){
	if (root->left == NULL){
	return false;
	} else {
	return findToRemoveHelper(root->left, value);
	}
	} else {
	if (root->right == NULL){
	return false;
	} else {
	return findToRemoveHelper(root->right, value);
	}
	}
	return false;
}

template<class bstdata>
void BST<bstdata>::insertHelper(NodePtr root, bstdata value)
{

	if (value == root->data){
		return;
		} else if (value < root->data){
			if (root->left == NULL){
				root->left = new Node(value);
			} else {
				insertHelper(root->left, value);
			}
		} else {
			if (root->right == NULL){
				root->right = new Node(value);
			} else {
				insertHelper(root->right, value);
			}
		}

}
template <class bstdata>
void BST<bstdata>::insert(bstdata value)
{
    if (root == NULL)

    {
        root = new Node(value); //if the tree is empty insert the value at the root

    }
    else
    	insertHelper(root, value); //otherwise call the helper function, passing it the root

}
template <class bstdata>
void BST<bstdata>::remove(bstdata value)
{
	assert(!isEmpty());
	{
	root = removeHelper(root, value);
	}
}
template <class bstdata>
typename BST<bstdata>::NodePtr BST<bstdata>::removeHelper(NodePtr root, bstdata value)
{
	 if(root == NULL)
	    {
	        return root;
	    }
	    else if (value < root->data)
	    {
	        root->left = removeHelper(root->left, value);
	    }
	    else if (value > root->data)
	    {
	        root->right = removeHelper(root->right, value);
	    }
	    else
	    {
	        if(root->left == NULL and root->right == NULL)
	        {
	            delete root;
	            root = NULL;
	        }
	        else if (root->right == NULL)
	        {
	            NodePtr temp = root;
	            root = root->left;
	            delete temp;
	        }
	        else if (root->left == NULL)
	        {
	            NodePtr temp = root;
	            root = root->right;
	            delete temp;
	        }
	        else
	        {
	            root->data = minimumHelper(root->right);
	            root->right = removeHelper(root->right, minimumHelper(root->right));
	        }
	    }
	    return root;
	/*if(root==NULL) return root;
	else if (value < root->data){
		root->left = removeHelper(root->left, value);
	} else if (value > root->data){
		root->right = removeHelper(root->right, value);
	} else {
		if (root->left == NULL && root->right == NULL){
			delete root;
			root = NULL;
		} else if (root->right==NULL){
			NodePtr temp = root;
			root = root->left;
			delete temp;
		} else if (root->left==NULL){
			NodePtr temp = root;
			root = root->right;
			delete temp;
		}
		else {
			bstdata min = minimumHelper(root->right);
			root->data = min;
			root->right = removeHelper(root->right, min);
		}
	}
	return root;*/
}
template <class bstdata>
void BST<bstdata>::inOrderPrint()
{
	inOrderPrintHelper(root);
	cout << endl;
}
template <class bstdata>
void BST<bstdata>::inOrderPrint(ostream& output)
{
	inOrderPrintHelper(root, output);
	output << endl;
}
template <class bstdata>
void BST<bstdata>::inOrderPrintHelper(NodePtr root)
{
	if (root != NULL)
	{
		inOrderPrintHelper(root->left);
		cout << root->data << endl ;
		inOrderPrintHelper(root->right);
	}
}
template <class bstdata>
void BST<bstdata>::inOrderPrintHelper(NodePtr root,ostream& output)
{
	if (root != NULL)
	{
		inOrderPrintHelper(root->left,output);
		output << root->data << "\n";
		inOrderPrintHelper(root->right,output);
	}
}
template <class bstdata>
void BST<bstdata>::preOrderPrint()
{
	preOrderPrintHelper(root);
	cout << endl;
}
template <class bstdata>
void BST<bstdata>::preOrderPrint(ostream& output)
{
	preOrderPrintHelper(root, output);
	output << endl;
}
template <class bstdata>
void BST<bstdata>::preOrderPrintHelper(NodePtr root)
{
	if (root != NULL)
	{
		cout << root->data << " ";
		preOrderPrintHelper(root->left);
		preOrderPrintHelper(root->right);
	}
}
template <class bstdata>
void BST<bstdata>::preOrderPrintHelper(NodePtr root,ostream& output)
{
	if (root != NULL)
	{
		output << root->data << "\n";
		preOrderPrintHelper(root->left, output);
		preOrderPrintHelper(root->right, output);
	}
}
template <class bstdata>
void BST<bstdata>::postOrderPrint()
{
	postOrderPrintHelper(root);
	cout << endl;
}
template <class bstdata>
void BST<bstdata>::postOrderPrint(ostream& output)
{
	postOrderPrintHelper(root, output);
	output << endl;
}
template <class bstdata>
void BST<bstdata>::postOrderPrintHelper(NodePtr root, ostream& output)
{
	if (root != NULL)
	{
		postOrderPrintHelper(root->left, output);
		postOrderPrintHelper(root->right, output);
		output << root->data << "\n";
	}
}
template <class bstdata>
void BST<bstdata>::postOrderPrintHelper(NodePtr root)
{
	if (root != NULL)
	{
		postOrderPrintHelper(root->left);
		postOrderPrintHelper(root->right);
		cout << root->data << " ";
	}
}

#endif /* BST_H_ */
