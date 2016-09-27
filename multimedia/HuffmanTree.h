#pragma once

#include <queue>
#include <map>
#include <string>

typedef std::map<char, unsigned> FrequencyMap;
typedef std::map<char, std::string> CodesMap;

class Node {
public:
	Node(unsigned w) : weight(w) {}
	// need at least one virtual method in base class
	// for run-time type information (RTTI)
	virtual ~Node() {}
public:
	unsigned weight;
};

class NodeCompare {
public:
	bool operator() (const Node* t, const Node* o) {
		return t->weight > o->weight;
	}
};

class InternalNode : public Node {
public:
	InternalNode(Node *l, Node *r) : Node(l->weight + r->weight), lChild(l), rChild(r) {}
public:
	Node *lChild, *rChild;
};

class LeafNode : public Node {
public:
	LeafNode(char c, unsigned w) : symbol(c), Node(w) {}
public:
	char symbol;
};

class HuffmanTree {
public:
	void buildTree(FrequencyMap symbols);
	std::string getSymbolCode(char symbol);
private:
	void generateHuffmanCodes(Node *node, std::string &prefix);
private:
	CodesMap table;
	Node* root;
};