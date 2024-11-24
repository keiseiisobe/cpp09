#ifndef VECTORPMERGEME_HPP
#define VECTORPMERGEME_HPP

#include <vector>
#include <algorithm>

#include <utility>
#include <iostream>

class VectorPmergeMe
{
public:
	VectorPmergeMe(std::vector<size_t>&);
	~VectorPmergeMe();
	const std::vector<size_t>& getSeq() const;
	void swapValue(int index1, int index2);
	void binaryInsertion();
	std::vector<std::pair<size_t, size_t> > makePairVector();
	void createNewSeq(std::vector<std::pair<size_t, size_t> >&);
	std::vector<std::pair<size_t, size_t> > sortPair(std::vector<std::pair<size_t, size_t> >&);
	void sort();
private:
	std::vector<size_t> seq_;
};

#endif
