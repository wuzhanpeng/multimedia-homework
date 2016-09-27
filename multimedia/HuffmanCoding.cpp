#include "HuffmanCoding.h"

std::fstream& HuffmanCoding::read() {
	std::fstream file;
	file.open(path, std::ios::in);
	if (file.is_open()) {
		return file;
	} else {
		// ERROR in open a file
		return;
	}
}

void HuffmanCoding::compress(CompressionMode mode) {

}