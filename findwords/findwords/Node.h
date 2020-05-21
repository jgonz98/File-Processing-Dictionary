#include <string>
#ifndef NODE_H
#define NODE_H

class Node
{
public:
	Node(std::string n, int c)
	{
		this->word = n;
		this->count = c;
		left = right = nullptr;
	}

	std::string word;
	int count;
	Node* left;
	Node* right;
};

#endif


