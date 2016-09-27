#pragma once

#include <fstream>
#include <string>

#include "HuffmanTree.h"

enum CompressionMode { Dynamic, Statical };

class HuffmanCoding {
public:
	HuffmanCoding(std::string filename) : path(filename) {}
	void compress(CompressionMode mode);
	void decompress();
private:
	void generateStatically();
	void generateDynamically();
	std::fstream& read();
private:
	std::map<char, std::string> huffmanCodes;
	std::string path;
};