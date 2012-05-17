#pragma once

#include <iostream>
#include "arraystack.h"

/** Class Bag provides multyset based on a red black tree.
 *  Elements that are being added to a Bag must have implemented
 *  operators ==, != and <
 */
template<class T>
class Bag
{
public:
	enum Color { Red, Black };

	Bag()
		: root(NULL) 
		, mSize(0)
	{}
	~Bag()
	{ erase(root); }
	/// Inserts key into the Bag
	void add(T const &key)
	{ 
		root = add(root, key); 
		root->color = Black;
		mSize++;
	}
	/// Adds all the keys of second into the Bag
	void add(Bag<T> const &second);
	bool isEmpty() const 
	{ return mSize == 0; }
	int size() const
	{ return mSize; }
	/// Removes key from the Bag
	void remove(const T &key);

	/// Returns the union of the Bag and second
	Bag<T> unite(Bag<T> const &second);
	/// Returns the intersection of the Bag and second
	Bag<T> intersect(Bag<T> const &second);
 
protected:
	/// Node of the red black tree
	struct Node
	{
		T key;
		Color color;
		/** I use an array of children pointers instead of
		 *  two separate pointers because it is easier and shorter to go
		 *  through symmetric cases of deletion and inserting that way.
		 *  Those cases are being treated depending on direction of needed
		 *  action
		 */
		Node* children[2];
		int number; ///< Number of elements that are equal key

		Node(T value)
			: key(value)
			, color(Red)
			, number(1)
		{
			for (int i = 0; i < 2; i++)
				children[i] = NULL;
		}
    };

	Node* root;
	int mSize;

	/// NULL pointers at the leaves are considered black for convenience
	bool isRed(Node* node)
	{ return node != NULL && node->color == Red; }
	Node* add(Node* node, T const &key);
	/// Rotations are used for rebalancing
	Node* singleRotation(Node* node, int direction);
	Node* doubleRotation(Node* node, int direction);
	/** Removes key from subtree node. When done is true rebalance is not
	 *  needed anymore and removal get finished
	 */
	Node* remove(Node* node, T const &key, bool &done);
	/** Rebalances a tree when removing a key. Child is an index of a subtree
	 *  that caused debalance
	 */
	Node* removeBalance(Node* node, int child, bool &done);

	/// Deletes the Bag. Called by destructor
	void erase(Node* node);
	
public:
	/** Inorder iterator. Traverses bask and forward around a Bag.
	 *  If some node contains several equal elements then it gives
	 *  them sequentually one by one
	 */
	class Iterator
	{
	public:
		void next()
		{ iterate(1); }
		void prev()
		{ iterate(0); }

		void operator++()
		{ return next(); }
		void operator--()
		{ return prev(); }

		T operator*() const 
		{ return cursor->key; }

		bool operator==(Iterator const &sec) const 
		{ return cursor == sec.cursor; }
		bool operator!=(Iterator const &sec) const
		{ return cursor != sec.cursor; }

		/// Returns a number of elements in the node under iterator
		int elements()
		{ 
			if (cursor == NULL)
				return 0;
			return cursor->number; 
		}
	
	protected:
		/** Protected because no one except the Bag must have access
		 *  to the constructor
		 */
		Iterator()
			: cursor(NULL)
		{
			for (int i = 0; i < 2; i++) 	// Initial values don't matter
				instanceInDirection[i] = i; // because they are set by the Bag
									// in every method that creates Iterator
		}
 
		Node* cursor;
		/** Stores number of current element in the current node when moving 
		 *  forward or backward around the tree - under indexes 
		 *  1 and 0, respectively
		 */
		int instanceInDirection[2];
		ArrayStack<Node*> previous; ///< Nodes on the simple path to the root

		/** Moves iterator in the next (when direction == 1) of previous
		 *  (direction == 0) position
		 */
		void iterate(int direction);
		/// Two helper functions used by iterate()
		void goUp(int direction);
		void goDown(int direction);

	friend class Bag; ///< This line must be here because of poor syntax =(
	};

	/// Returns minimum of the Bag's elements
	Iterator begin() const
	{ return uttermost(0); }
	/// Returns maximum of the Bag's elements
	Iterator last() const
	{ return uttermost(1); }
	/// Returns Iterator that signals that iteration is over
	Iterator end() const
	{ return Iterator(); }

	/// Returns Iterator on the first element in the node containing key
	Iterator find(T const &key) const;
	bool hasKey(T const &key) const 
	{ return find(key) != end(); }
	/// Returns number of elements that are equal key
	int numberOf(T const &key) const
	{
		Iterator it = find(key);
		return it.elements();
	}

protected:
	/** Returns:
	 *		leftmost element if direction is 0
	 *		rightmost element if direction is 1
	 */
	Iterator uttermost(int direction) const;
};

template<class T>
typename Bag<T>::Node* Bag<T>::add(Node* node, T const &key)
{
	// New node when being returned from method gets connected to
	// its parent so it won't just 'hang in the air' without pointer
	if (node == NULL)
		node = new Node(key);
	else if (key == node->key)
		++(node->number);
	else
	{
		int child = node->key < key; // Getting a direction into which we must
							// insert key to handle symmetric cases identically
		node->children[child] = add(node->children[child], key);

		// Reducing red violations. Black violations won't
		// occure when adding because the color of new added node is always red.
		if (isRed(node->children[child]))
		{ 										// Case 1: both children are red
			if (isRed(node->children[1 - child]))
			{									// This may cause red violation
				node->color = Red;				// up the tree
				node->children[0]->color = Black;
				node->children[1]->color = Black;
			}
			else if (node->children[child] != NULL)
			{
				// Case 2 and 3: outer or child of a node that could cause 
				// violation is red. We reduce it by rotations and all violation
				// is avoided
				if (isRed(node->children[child]->children[child]))
					node = singleRotation(node, 1 - child);
				else if (isRed(node->children[child]->children[1 - child]))
					node = doubleRotation(node, 1 - child);
			}
		}
	}

	return node;
}

template<class T>
typename Bag<T>::Node* Bag<T>::singleRotation(Node* node, int direction)
{
	// Performing left (direction == 0) or right (1) petit rotation
	Node* tmp = node->children[1 - direction];
	node->children[1 - direction] = tmp->children[direction];
	tmp->children[direction] = node;

	// Recoloring to make functions of adding and removing elements
	// shorter and simpler
	node->color = Red;
	tmp->color = Black;

	// Returns new root of the rotated group of nodes
	return tmp;
}

template<class T>
typename Bag<T>::Node* Bag<T>::doubleRotation(Node* node, int direction)
{
	node->children[1 - direction] = 
			singleRotation(node->children[1 - direction], 1 - direction);
	// New root of the rotated subtree
	return singleRotation(node, direction);
}

template<class T>
void Bag<T>::remove(T const &key)
{
	bool done = false;

	root = remove(root, key, done);
	if (root != NULL)
		root->color = Black;
	mSize--;
}

template<class T>
typename Bag<T>::Node* Bag<T>::remove(Node* node, T const &key, bool &done)
{
	if (node == NULL)
		done = true;
	else
	{
		T data(key);
		if (node->key == key)
		{
			--(node->number);
			if (node->number != 0)
			{
				done = true;
				return node;
			}

			// If one of node's children is NULL
			if (node->children[0] == NULL || node->children[1] == NULL)
			{
				// If left child exists then tmp is left child, else right one
				Node* tmp = node->children[node->children[0] == NULL];

				if (isRed(node)) 	// We don't need to rebalance if deleted
					done = true;	// node is red (this causes no prolems)
				else if (isRed(tmp))
				{
					tmp->color = Black;
					done = true;
				}
				delete node;
								// Recolored black node that will replace 
				return tmp; 	// removed one is returned
			}
			else 
			{
				// If node has two not-NULL children search for predecessor
				// and place its key in the node then remove ex-predecessor
				Node* prev = node->children[0];				// recursively
				while (prev->children[1] != NULL)
					prev = prev->children[1];
				node->key = prev->key;
				node->number = 1;
				data = prev->key;
			}
		}
		int child = node->key < data;
		node->children[child] = remove(node->children[child], data, done);
		if (!done)
			root = removeBalance(node, child, done);
	}
	// Returning subtree with removed key
	return node;
}

template<class T>
typename Bag<T>::Node* Bag<T>::removeBalance(Node* node, int child, bool &done)
{
	Node* parent = node;
	Node* sibling = node->children[1 - child];

	// If a sibling of the node is red we make it black and rotate to restore
	// black height of all subtrees
	if (isRed(sibling))
	{
		node = singleRotation(node, child);
		sibling = parent->children[1 - child];
	}

	if (sibling != NULL)
	{
		// Both children of sibling are black: making parent black and
		// sibling red
		if (!isRed(sibling->children[0]) && !isRed(sibling->children[1]))
		{
			if (isRed(parent))
				done = true;
			parent->color = Black;
			sibling->color = Red;
		}
		else
		{
			Color pColor = parent->color;
			bool rootChanged = node == parent; // root of this group
					// could change if the node's sibling was red
					// so we must know it to return correctly from recursion

			// If the outer sibling's child is red then we need just one
			// single rotatione, else - a double one
			if (isRed(sibling->children[1 - child]))
				parent = singleRotation(parent, child);
			else
				parent = doubleRotation(parent, child);

			parent->color = pColor;
			parent->children[0]->color = Black;
			parent->children[1]->color = Black;

			if (rootChanged)
				node = parent;
			else
				node->children[child] = parent;

			done = true;
		}
	}

	return node;
}

template<class T>
typename Bag<T>::Iterator Bag<T>::uttermost(int direction) const
{
	Iterator it;
	if (isEmpty())
		return it;

	it.cursor = root;
	it.instanceInDirection[direction] = it.cursor->number;
	it.instanceInDirection[1 - direction] = 1;
	while (it.cursor->children[direction] != NULL)
	{
		it.previous.push(it.cursor);
		it.cursor = it.cursor->children[direction];
	}
	return it;
}

template<class T>
void Bag<T>::Iterator::iterate(int direction)
{
	instanceInDirection[1 - direction]--;
	instanceInDirection[direction]++;
	if (instanceInDirection[direction] <= cursor->number)
		return;

	if (cursor->children[direction] != NULL)
		goDown(direction);
	else
		goUp(direction);

	if (cursor != NULL)
	{
		instanceInDirection[1 - direction] = cursor->number;
		instanceInDirection[direction] = 1;
	}
}

template<class T>
void Bag<T>::Iterator::goDown(int direction)
{
	previous.push(cursor);
	cursor = cursor->children[direction];
	while (cursor->children[1 - direction] != NULL)
	{
		previous.push(cursor);
		cursor = cursor->children[1 - direction];
	}
}

template<class T>
void Bag<T>::Iterator::goUp(int direction) 
{
	while (!previous.isEmpty() && cursor == previous.top()->children[direction])
		cursor = previous.pop();
	if (previous.isEmpty())
		cursor = NULL;
	else
		cursor = previous.pop();
}

template<class T>
typename Bag<T>::Iterator Bag<T>::find(T const &key) const
{
	Iterator it;
	it.cursor = root;

	while (it.cursor != NULL && it.cursor->key != key)
	{
		int child = it.cursor->key < key;
		it.previous.push(it.cursor);
		it.cursor = it.cursor->children[child];
	}

	if (it.cursor != NULL)
	{
		it.instanceInDirection[0] = it.cursor->number; // Placing iterator
		it.instanceInDirection[1] = 1;	// on the first element in the node
	}

	return it;
}

template<class T>
void Bag<T>::add(Bag<T> const &second)
{
	// It's quite inefficient. I'm going to fix it somewhen
	for (Iterator it = second.begin(); it != second.end(); ++it)
		add(*it);
}

template<class T>
Bag<T> Bag<T>::unite(Bag<T> const &second)
{
	Bag<T> result;
	result.add(*this);
	result.add(second);
	return result;
}

template<class T>
Bag<T> Bag<T>::intersect(Bag<T> const &second)
{
	Bag<T> result;
	for (Iterator it = begin(); it != end(); ++it)
	{
		int num = second.numberOf(*it);
		if (num > it.elements()) // Intersection has minimum equal elements
			num = it.elements(); // of two bags

		for (int i = 0; i < num; i++)
			result.add(*it);
		it.instanceInDirection[1] = it.elements(); // Skipping equal elements
		it.instanceInDirection[0] = 1;
	}
	return result;
}

template<class T>
void Bag<T>::erase(Node* node)
{
	if (node != NULL)
	{
		erase(node->children[0]);
		erase(node->children[1]);
		delete node;
	}
}
