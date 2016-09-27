#include "HuffmanTree.h"

void HuffmanTree::buildTree(FrequencyMap fMap) {
	std::priority_queue<Node*, std::vector<Node*>, NodeCompare> forest;
	// build forest
	for (std::map<char, unsigned>::const_iterator iter = fMap.begin();
		iter != fMap.end(); ++iter) {
		forest.push(new LeafNode(iter->first, iter->second));
	}
	// build Huffman Tree
	while (1 < forest.size()) {
		Node *lChild = forest.top();
		forest.pop();

		Node *rChild = forest.top();
		forest.pop();

		Node *parent = new InternalNode(lChild, rChild);
		forest.push(parent);
	}
	root = forest.top();
	// generate Huffman codes
	generateHuffmanCodes(root, std::string());
}

std::string HuffmanTree::getSymbolCode(char symbol) {
	return table[symbol];
}

void HuffmanTree::generateHuffmanCodes(Node *node, std::string &prefix) {
	// DFS
	// equivalent of `instanceof` in JAVA
	if (LeafNode *lNode = dynamic_cast<LeafNode*>(node)) {
		table.insert(std::map<char, std::string>::value_type(lNode->symbol, prefix));
		return;
	}
	InternalNode *iNode = dynamic_cast<InternalNode*>(node);
	generateHuffmanCodes(iNode->lChild, prefix + '0');
	generateHuffmanCodes(iNode->rChild, prefix + '1');
}