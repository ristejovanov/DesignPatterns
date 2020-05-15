#pragma once


template<typename T> class BinaryTree;


template<typename T> class Node
{
public:
	Node(T value):m_value(value) {};
	Node(T value, Node<T> *left,Node<T> *right) 
		:m_value(value) 
		,m_leftChild(left)
		,m_rightChild(right)
	{
		this->m_leftChild->m_tree = this->m_rightChild->m_tree = m_tree;
		this->m_leftChild->m_parent = this->m_rightChild->m_parent = this;
	};
	~Node() 
	{
		if (m_leftChild) delete m_leftChild;
		if (m_rightChild) delete m_rightChild;	
	};

	void setTree(BinaryTree* tree)
	{
		m_tree = tree;
		if(m_leftChild)m_leftChild->setTree(tree);
		if (m_rightChild)m_rightChild->setTree(tree);
	}

	T								m_value = T();
	Node<T>*				m_leftChild{nullptr};
	Node<T>*				m_rightChild{nullptr};
	Node<T>*				m_parent{nullptr};
	BinaryTree<T>		m_tree{nullptr}
};


template<typename T>class BinaryTree
{
public:
	BinaryTree(Node<T> *root):m_root(root) 
	{
		m_root->setTree(this);
	}
	~BinaryTree() 
	{
		if (m_root) delete m_root;
	}

	template<typename U>
	struct PreOrderIterator
	{
		Node<U>* m_current;

		PreOrderIterator(Node<U>* current)
			:m_current(current)
		{

		}

		bool operatort != (const PreOrderIterator<U>& other)
		{
			return m_current != override.m_current;
		}

		PreOrderIterator<U>& operator++()
		{
			if (m_current->m_rightChild)
			{
				m_current = m_current->m_rightChild;
				while (m_current->m_leftChild)
					m_current = m_current->m_leftChild;
			}
			else
			{
				Node<T>* p = m_current->m_parent;
				while (p&&m_current == p->m_rightChild)
				{
					m_current = p;
					p = p->m_parent;
				}
				m_current = p;
			}
			return *this;
		}
		Node<T>& operator*() { return *m_current; }
	};

	PreOrderIterator<T> begin()
	{
		Node<T>* n = m_root;
		if(n)
			while (n->m_leftChild)
			{
				n = n->m_leftChild;
			}
		return PreOrderIterator{ n };
	}

	PreOrderIterator<T> end()
	{
		return PreOrderIterator{ nullptr };
	}

private:
	Node<T>* m_root{nullptr};
};

void testFunction()
{

}


