#include "VectorPmergeMe.hpp"

VectorPmergeMe::VectorPmergeMe(std::vector<size_t>& seq)
	: seq_(seq)
{
}

VectorPmergeMe::~VectorPmergeMe()
{
}

const std::vector<size_t>& VectorPmergeMe::getSeq() const
{
	return seq_;
}

void VectorPmergeMe::swapValue(int index1, int index2)
{
	size_t tmp = seq_[index1];
	seq_[index1] = seq_[index2];
    seq_[index2] = tmp;
}

void VectorPmergeMe::binaryInsertion()
{
	switch (seq_.size())
	{
	case 1:
		return;
	case 2:
	case 3:
	case 4:
		if (seq_[0] > seq_[1])
			swapValue(0, 1);
		if (seq_.size() == 2)
			return;
		if (seq_[0] > seq_[2])
		{
			swapValue(1, 2);
			swapValue(0, 1);
		}
		else // (seq_[0] < seq_[2])
		{
			if (seq_[1] > seq_[2])
				swapValue(1, 2);
		}
		if (seq_.size() == 3)
			return;
		if (seq_[1] > seq_[3])
		{
			swapValue(2, 3);
			swapValue(1, 2);
			if (seq_[0] > seq_[1])
				swapValue(0, 1);
		}
		else // seq_[1] < seq_[3]
		{
			if (seq_[2] > seq_[3])
				swapValue(2, 3);
		}
	}
}

std::vector<std::pair<size_t, size_t> > VectorPmergeMe::makePairVector()
{
	std::vector<std::pair<size_t, size_t> > v;
	size_t n = seq_.size() % 2 == 0 ? seq_.size() : seq_.size() - 1;
	for (size_t i = 0;i < n;i += 2)
	{
		// p.first -> bigger one
		// p.second -> smaller one
		std::pair<size_t, size_t> p;
		if (seq_[i] > seq_[i + 1])
			p = std::make_pair(seq_[i], seq_[i + 1]);
		else
			p = std::make_pair(seq_[i + 1], seq_[i]);
		v.push_back(p);
	}
	return v;
}

void VectorPmergeMe::createNewSeq(std::vector<std::pair<size_t, size_t> >& p)
{
	seq_.clear();
	std::vector<std::pair<size_t, size_t> >::iterator it = p.begin();
	for (;it != p.end();it++)
	{
		seq_.push_back(it->first);
	}
}

std::vector<std::pair<size_t, size_t> > VectorPmergeMe::sortPair(std::vector<std::pair<size_t, size_t> >& p)
{
	std::vector<std::pair<size_t, size_t> > sortedP;
	std::vector<size_t>::iterator it = seq_.begin();
	for (;it != seq_.end();it++)
	{
		std::vector<std::pair<size_t, size_t> >::iterator pit = p.begin();
		for (;pit != p.end();pit++)
		{
			if (pit->first == *it)
			{
				sortedP.push_back(*pit);
				break;
			}
		}
	}
	return sortedP;
}

void VectorPmergeMe::sort()
{
	if (seq_.size() <= 4)
	{
		binaryInsertion();
		return;
	}
	ssize_t remain = -1;
	(void)remain;
	if (seq_.size() % 2 != 0)
		remain = seq_[seq_.size() - 1];
	std::vector<std::pair<size_t, size_t> > tmp = makePairVector();
	createNewSeq(tmp);
	sort();
	std::vector<std::pair<size_t, size_t> > sortedTmp = sortPair(tmp);
#ifdef DEBUG
	std::vector<std::pair<size_t, size_t> >::iterator it = sortedTmp.begin();
	for (;it != sortedTmp.end();it++)
	{
		std::cout << it->first << " " << it->second << std::endl;
	}
#endif
}
