#pragma once

template<typename T>
class Node
{
	public:
		Node(T value) 
			:m_value(value)
		{
		}
		
		Node(T value, Node<T>* leftChild, Node<T>* rightChild)
			:m_value(value)
			, m_rightChild(rightChild)
			, m_leftChild(leftChild)
		{
			this->m_leftChild->m_parengt = this->m_rightChild->m_parengt = this;
		}

		~Node() 
		{
			if (m_leftChild)	delete m_leftChild;
			if (m_rightChild)	delete m_rightChild;
		}
	private:
		T m_value = T();
		Node<T>* m_leftChild{nullptr};
		Node<T>* m_rightChild{nullptr };
		Node<T>* m_parengt{nullptr};
};



template<typename T>
class BinaryTree
{
public:
	BinaryTree(Node<T> *root) 
		:m_root(root)
	{}
	~BinaryTree() {}

	template<typename U>
	class iterator
	{
	public:
		iterator(Node<U>* current)
			:m_current(current)
		{
	
		}

		iterator& o

		~iterator() {};
	private:
		Node<U>* m_current;
	};

	iterator<T> begin()
	{
		Node<T>* p = m_root;
		while (p->m_leftChild)
		{
			p = p->m_leftChild;
		}
		return iterator{ p };
	}

	iterator<T> end()
	{
		return iterator{ nullptr };
	}

private:
	Node<T> *m_root{nullptr}
};
