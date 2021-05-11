// BST.h
#ifndef H_BST
#define H_BST
#include <iostream>

using std::cout;
using std::endl;

/**
 * @brief Node to hold data and connections to other nodes
 * struct name nodeType
 * Defining node types pointer using template
 *
 * @tparam T
 */
template <class T>
struct nodeType
{
	/// Data of type T
	T data;

	/// Ptr to the left branch of node
	nodeType<T> *left;

	/// Ptr to the right branch of node
	nodeType<T> *right;
};

/**
 * @class BST
 * @brief template class
 *
 * @tparam T
 */
template <class T>
class BST
{
public:
	/**
	 * @brief Construct a new empty BST object
	 *
	 */
	BST();

	/**
	 * @brief Destroy the BST object
	 *
	 */
	~BST();

	/**
	 * @brief Adds items into tree
	 *
	 * @param insertItem
	 * @return void
	 */
	void insert(const T &insertItem);

	/**
	 * @brief search items in tree and return found or not
	 *
	 * @param searchItem
	 * @return true
	 * @return false
	 */
	bool search(const T &searchItem) const;

	/**
	 * @brief Traverse through the contents of tree in order.
	 *
	 * @return void
	 */
	void inorderTraversal(void (*fptr)(T &item)) const;

	/**
	 * @brief Traverse through the contents of tree in pre order.
	 *
	 * @return void
	 */
	void preorderTraversal(void (*fptr)(T &item)) const;

	/**
	 * @brief Traverse through the contents of tree in post order.
	 *
	 * @return void
	 */
	void postorderTraversal(void (*fptr)(T &item)) const;

private:
	/**
	 * @brief Traverse through the contents of tree in order.
	 *
	 * @param p
	 * @return void
	 */
	void inorder(nodeType<T> *p, void (*fptr)(T &item)) const;

	/**
	 * @brief Traverse through the contents of tree in pre order.
	 *
	 * @param p
	 * @return void
	 */
	void preorder(nodeType<T> *p, void (*fptr)(T &item)) const;

	/**
	 * @brief Traverse through the contents of tree in post order.
	 *
	 * @param p
	 * @return void
	 */
	void postorder(nodeType<T> *p, void (*fptr)(T &item)) const;

	/**
	 * @brief Deletes tree if it is null
	 *
	 * @param p
	 * @return void
	 */
	void deleteTree(nodeType<T> *&p);

	/**
	 * @brief delete node item
	 *
	 * @param deleteItem
	 * @return void
	 */
	void deleteNode(const T &deleteItem);

	/**
	 * @brief check if the node is empty
	 *
	 * @return true
	 * @return false
	 */
	bool isEmpty() const;

	/**
	 * @brief Get the Root object
	 *
	 * @return nodeType<T>
	 */
	nodeType<T> getRoot() const;

	/**
	 * @brief Get the data object
	 *
	 * @param searchItem
	 * @return nodeType<T>
	 */
	nodeType<T> getdata(const T &searchItem);

	/**
	 * @brief Root node of the tree
	 *
	 * @return nodeType<T>
	 */
	nodeType<T> *root;
};

// Implementation

// Construct a new BST<T>::BST object and sets root to null
template <class T>
BST<T>::BST()
{
	// root = NULL;
}

// Destroy the BST<T>::BST object and calls delete tree function
template <class T>
BST<T>::~BST()
{
	deleteTree(root);
}

template <class T>
void BST<T>::inorderTraversal(void (*fptr)(T &item)) const
{
	inorder(root, *fptr);
}

template <class T>
void BST<T>::preorderTraversal(void (*fptr)(T &item)) const
{
	preorder(root, *fptr);
}

template <class T>
void BST<T>::postorderTraversal(void (*fptr)(T &item)) const
{
	postorder(root, *fptr);
}

// Insert item is address to a struct
// Invoke default construct
template <class T>
void BST<T>::insert(const T &insertItem)
{
	nodeType<T> *current;
	nodeType<T> *trailCurrent = NULL;
	nodeType<T> *newNode;

	newNode = new nodeType<T>;
	newNode->data = insertItem;

	newNode->left = NULL;
	newNode->right = NULL;

	// printf("\nInsert item data: ", insertItem, "\n");
	// printf("\nInsert newnodsew data: ", newNode->left, "\n");
	// printf("\nInsert newnodsew data: ", newNode->data, "\n");

	if (root == NULL)
		root = newNode;
	else
	{
		current = root;

		// printf("\nInsert BST data: ", insertItem, "\n");
		// return;

		while (current != NULL)
		{
			trailCurrent = current;

			if (insertItem == current->data)
			{
				cout << "dupplicate are not allowed" << endl;
				return;
			}
			else if (insertItem < current->data)
			{
				current = current->left;
			}
			else
				current = current->right;
		}

		if (insertItem < trailCurrent->data)
			trailCurrent->left = newNode;
		else
			trailCurrent->right = newNode;
	}
}

/**
 * @brief search items in a tree
 *
 * @tparam T
 * @param searchItem
 * @return true
 * @return false
 */
template <class T>
bool BST<T>::search(const T &searchItem) const
{
	nodeType<T> *current;
	bool found = false;

	if (root == NULL)
		cout << "cannot search empty tree" << endl;
	else
	{
		cout << "searching in tree..................." << endl;

		current = root;

		while (current != NULL && !found)
		{
			if (searchItem == current->data)
				found = true;
			else if (searchItem < current->data)
				current = current->left;
			else
				current = current->right;
		}
	}
	return found;
}

/**
 * @brief delete empty node from tree
 *
 * @tparam T
 * @param deleteItem
 */
template <class T>
void BST<T>::deleteNode(const T &deleteItem)
{
	nodeType<T> *current;
	current = root;
	if (root == NULL)
	{
		cout << "empty node " << endl;
	}
	else
	{
		while (current != NULL)
		{
			if (deleteItem == current->data)
				current->data = NULL;
			else if (deleteItem < current->data)
				current = current->left;
			else
				current = current->right;
		}
	}
}

/**
 * @brief Check if the elm type is empty
 *
 * @tparam T
 * @return true
 * @return false
 */
template <class T>
bool BST<T>::isEmpty() const
{
	return (root == NULL);
}

/**
 * @brief check in order node type
 *
 * @tparam T
 * @param p
 * @return void
 */
template <class T>
void BST<T>::inorder(nodeType<T> *p, void (*fptr)(T &item)) const
{
	// cout << "Inord in tree..................." << endl;

	if (p != nullptr)
	{
		inorder(p->left, *fptr);
		(*fptr)(p->data);
		inorder(p->right, *fptr);
	}
}

/**
 * @brief check pre order node type
 *
 * @tparam T
 * @param p
 * @return void
 */
template <class T>
void BST<T>::preorder(nodeType<T> *p, void (*fptr)(T &item)) const
{
	// cout << "preord in tree..................." << endl;

	if (p != NULL)
	{
		//cout << p->data << " ";
		(*fptr)(p->data);
		preorder(p->left, *fptr);
		preorder(p->right, *fptr);
	}
}

/**
 * @brief check post order node type
 *
 * @tparam T
 * @param p
 * @return void
 */
template <class T>
void BST<T>::postorder(nodeType<T> *p, void (*fptr)(T &item)) const
{
	// cout << "postord in tree..................." << endl;

	if (p != NULL)
	{
		postorder(p->left, *fptr);
		postorder(p->right, *fptr);
		(*fptr)(p->data);

		// cout << "PreOrder data: " << p->data << " ";
	}
}

// Delete the node type if the p is null
template <class T>
void BST<T>::deleteTree(nodeType<T> *&p)
{
	if (p != NULL)
	{
		deleteTree(p->left);
		deleteTree(p->right);
		delete p;
		p = NULL;
	}
}

/**
 * @brief extract root
 *
 * @tparam T
 * @return nodeType<T>
 */
template <class T>
nodeType<T> BST<T>::getRoot() const
{
	return *root;
}

#endif //BST_H
