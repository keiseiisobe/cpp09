#ifndef VECTORPMERGEME_HPP
#define VECTORPMERGEME_HPP

#include <vector>
#include <algorithm>

#include <utility>
#include <iostream>

enum state
{
	start = 0,
	firstInsert
};


class VectorPmergeMe
{
public:
	VectorPmergeMe(std::vector<size_t>&);
	~VectorPmergeMe();
	const std::vector<size_t>& getSeq() const;
	void swapValue(int index1, int index2);
	void smallBinaryInsertion();
	std::vector<std::pair<size_t, size_t> > makePairVector();
	void createNewSeq(std::vector<std::pair<size_t, size_t> >&);
	std::vector<std::pair<size_t, size_t> > sortPair(std::vector<std::pair<size_t, size_t> >&);
	void binaryInsertion(size_t value);
	void sortInternal(std::vector<std::pair<size_t, size_t> >& p, ssize_t remain, size_t size);
	void sort();
private:
	std::vector<size_t> seq_;
	size_t currentPos_;
	size_t beginPos_;
	size_t prePos_;
	std::pair<size_t, size_t> range_;
	size_t rangeLast_;
};
#endif
