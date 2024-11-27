#ifndef LISTPMERGEME_HPP
#define LISTPMERGEME_HPP

#include <vector>
#include <list>
#include <algorithm>
#include "PmergeMe.hpp"
#include <utility>
#include <iostream>

class ListPmergeMe : PmergeMe
{
public:
	ListPmergeMe(std::vector<size_t>&);
	~ListPmergeMe();
	const std::list<size_t>& getSeq() const;
	void swapValue(int index1, int index2);
	void smallBinaryInsertion();
	std::list<std::pair<size_t, size_t> > makePairList();
	void createNewSeq(std::list<std::pair<size_t, size_t> >&);
	std::list<std::pair<size_t, size_t> > sortPair(std::list<std::pair<size_t, size_t> >&);
	void binaryInsertion(size_t value);
	void sortInternal(std::list<std::pair<size_t, size_t> >& p, ssize_t remain, size_t size);
	void sort();
	size_t numOfComparison;
private:
	size_t& operator[](size_t i);
	const size_t& operator[](size_t i) const;
	size_t diff(std::list<std::pair<size_t, size_t> >::iterator, std::list<std::pair<size_t, size_t> >::iterator);
	size_t diff(std::list<size_t>::iterator, std::list<size_t>::iterator);
	std::list<size_t>::iterator operator+(size_t);
	std::list<size_t> seq_;
	std::pair<size_t, size_t> range_;
	size_t rangeLast_;
};
#endif
