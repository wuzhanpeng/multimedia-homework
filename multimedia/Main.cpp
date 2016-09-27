#include <iostream>
#include <map>
#include "HuffmanTree.h"

int main() {
	//std::cout << "Multimedia Homework" << std::endl;
	// Priority queue test
	std::priority_queue<Node*, std::vector<Node*>, NodeCompare> forest;
	forest.push(new Node(1));
	forest.push(new Node(2));
	forest.push(new Node(3));
	forest.push(new Node(4));
	forest.push(new Node(5));
	std::cout << forest.top()->weight; forest.pop();
	std::cout << forest.top()->weight; forest.pop();
	std::cout << forest.top()->weight; forest.pop();
	std::cout << forest.top()->weight; forest.pop();
	std::cout << forest.top()->weight; forest.pop();
	std::cout << std::endl;
	// Test data
	FrequencyMap fMap;
	fMap['F'] = 2;
	fMap['O'] = 3;
	fMap['R'] = 4;
	fMap['G'] = 4;
	fMap['E'] = 5;
	fMap['T'] = 7;
	HuffmanTree htree;
	htree.buildTree(fMap);
	for (FrequencyMap::iterator it = fMap.begin();
		it != fMap.end(); ++it) {
		std::cout << it->first << ":" << htree.getSymbolCode(it->first) << std::endl;
	}
	// Statical table
	FrequencyMap sfMap;
	sfMap[' '] = 27182;
	sfMap['a'] = 8167;
	sfMap['A'] = 8167;
	sfMap['b'] = 1492;
	sfMap['B'] = 1492;
	sfMap['c'] = 2782;
	sfMap['C'] = 2782;
	sfMap['d'] = 4253;
	sfMap['D'] = 4253;
	sfMap['e'] = 12702;
	sfMap['E'] = 12702;
	sfMap['f'] = 2228;
	sfMap['F'] = 2228;
	sfMap['g'] = 2015;
	sfMap['G'] = 2015;
	sfMap['h'] = 6094;
	sfMap['H'] = 6094;
	sfMap['i'] = 6966;
	sfMap['I'] = 6966;
	sfMap['j'] = 153;
	sfMap['J'] = 153;
	sfMap['k'] = 772;
	sfMap['K'] = 772;
	sfMap['l'] = 4025;
	sfMap['L'] = 4025;
	sfMap['m'] = 2406;
	sfMap['M'] = 2406;
	sfMap['n'] = 6749;
	sfMap['N'] = 6749;
	sfMap['o'] = 7507;
	sfMap['O'] = 7507;
	sfMap['p'] = 1929;
	sfMap['P'] = 1929;
	sfMap['q'] = 95;
	sfMap['Q'] = 95;
	sfMap['r'] = 5987;
	sfMap['R'] = 5987;
	sfMap['s'] = 6327;
	sfMap['S'] = 6327;
	sfMap['t'] = 9056;
	sfMap['T'] = 9056;
	sfMap['u'] = 2758;
	sfMap['U'] = 2758;
	sfMap['v'] = 978;
	sfMap['V'] = 978;
	sfMap['w'] = 2360;
	sfMap['W'] = 2360;
	sfMap['x'] = 150;
	sfMap['X'] = 150;
	sfMap['y'] = 1974;
	sfMap['Y'] = 1974;
	sfMap['z'] = 74;
	sfMap['Z'] = 74;

	htree.buildTree(sfMap);
	for (FrequencyMap::iterator it = sfMap.begin();
		it != sfMap.end(); ++it) {
		std::cout << it->first << ":" << htree.getSymbolCode(it->first) << std::endl;
	}

	return 0;
}