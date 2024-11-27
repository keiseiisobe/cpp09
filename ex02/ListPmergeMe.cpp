#include "ListPmergeMe.hpp"

ListPmergeMe::ListPmergeMe(std::vector<size_t>& seq)
	: numOfComparison(0), rangeLast_(0)
{
	seq_ = std::list<size_t>(seq.begin(), seq.end());
}

ListPmergeMe::~ListPmergeMe()
{
}

size_t& ListPmergeMe::operator[](size_t i)
{
	std::list<size_t>::iterator it = seq_.begin();
	for (;it != seq_.end();it++)
	{
		if (i == 0)
			break;
		i--;
	}
	if (it == seq_.end())
		throw std::out_of_range("out_of_range in list");
	return *it;
}

const size_t& ListPmergeMe::operator[](size_t i) const
{
	std::list<size_t>::const_iterator it = seq_.begin();
	for (;it != seq_.end();it++)
	{
		if (i == 0)
			break;
		i--;
	}
	if (it == seq_.end())
		throw std::out_of_range("out_of_range in list");
	return *it;
}

std::list<size_t>::iterator ListPmergeMe::operator+(size_t n)
{
	std::list<size_t>::iterator it = seq_.begin();
	for (;it != seq_.end();it++)
	{
		if (n == 0)
			break;
		n--;
	}
	return it;
}

size_t ListPmergeMe::diff(std::list<size_t>::iterator it1, std::list<size_t>::iterator it2)
{
	size_t count = 0;
	for (;it1 != it2;it1--)
	{
		count++;
	}
	return count;
}

size_t ListPmergeMe::diff(std::list<std::pair<size_t, size_t> >::iterator it1, std::list<std::pair<size_t, size_t> >::iterator it2)
{
	size_t count = 0;
	for (;it1 != it2;it1--)
	{
		count++;
	}
	return count;
}

static std::pair<size_t, size_t>& get(std::list<std::pair<size_t, size_t> >& p, size_t i)
{
	std::list<std::pair<size_t, size_t> >::iterator it = p.begin();
	for (;it != p.end();it++)
	{
		if (i == 0)
			break;
		i--;
	}
	if (it == p.end())
		throw std::out_of_range("out_of_range in list");
	return *it;
}

const std::list<size_t>& ListPmergeMe::getSeq() const
{
	return seq_;
}

void ListPmergeMe::swapValue(int index1, int index2)
{
	size_t tmp = (*this)[index1];
	(*this)[index1] = (*this)[index2];
    (*this)[index2] = tmp;
}

void ListPmergeMe::smallBinaryInsertion()
{
	switch (seq_.size())
	{
	case 1:
		return;
	case 2:
	case 3:
	case 4:
#ifdef TEST
		numOfComparison++;
#endif
		if ((*this)[0] > (*this)[1])
			swapValue(0, 1);
		if (seq_.size() == 2)
			return;
#ifdef TEST
		numOfComparison++;
#endif
		if ((*this)[0] > (*this)[2])
		{
			swapValue(1, 2);
			swapValue(0, 1);
		}
		else // (seq_[0] < seq_[2])
		{
#ifdef TEST
			numOfComparison++;
#endif
			if ((*this)[1] > (*this)[2])
				swapValue(1, 2);
		}
		if (seq_.size() == 3)
			return;
#ifdef TEST
		numOfComparison++;
#endif
		if ((*this)[1] > (*this)[3])
		{
			swapValue(2, 3);
			swapValue(1, 2);
#ifdef TEST
			numOfComparison++;
#endif
			if ((*this)[0] > (*this)[1])
				swapValue(0, 1);
		}
		else // seq_[1] < seq_[3]
		{
#ifdef TEST
			numOfComparison++;
#endif
			if ((*this)[2] > (*this)[3])
				swapValue(2, 3);
		}
	}
}

std::list<std::pair<size_t, size_t> > ListPmergeMe::makePairList()
{
	std::list<std::pair<size_t, size_t> > v;
	size_t n = seq_.size() % 2 == 0 ? seq_.size() : seq_.size() - 1;
	for (size_t i = 0;i < n;i += 2)
	{
		// p.first -> bigger one
		// p.second -> smaller one
		std::pair<size_t, size_t> p;
#ifdef TEST
		numOfComparison++;
#endif
		if ((*this)[i] > (*this)[i + 1])
			p = std::make_pair((*this)[i], (*this)[i + 1]);
		else
			p = std::make_pair((*this)[i + 1], (*this)[i]);
		v.push_back(p);
	}
	return v;
}

void ListPmergeMe::createNewSeq(std::list<std::pair<size_t, size_t> >& p)
{
	seq_.clear();
	std::list<std::pair<size_t, size_t> >::iterator it = p.begin();
	for (;it != p.end();it++)
	{
		seq_.push_back(it->first);
	}
}

std::list<std::pair<size_t, size_t> > ListPmergeMe::sortPair(std::list<std::pair<size_t, size_t> >& p)
{
	std::list<std::pair<size_t, size_t> > sortedP;
	std::list<size_t>::iterator it = seq_.begin();
	for (;it != seq_.end();it++)
	{
		std::list<std::pair<size_t, size_t> >::iterator pit = p.begin();
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

// insert "value" among "range" of "seq"
void ListPmergeMe::binaryInsertion(size_t value)
{
#ifdef DEBUG
	std::cout << "binaryinsertion" << std::endl;
	std::cout << "going to insert " << value << std::endl;
#endif
	size_t diff = range_.second - range_.first;
	if (diff <= 1)
	{
		if (diff == 1)
		{
#ifdef TEST
			numOfComparison++;
#endif
			if (value < (*this)[range_.first])
				seq_.insert((*this) + range_.first, value);
			else
			{
#ifdef TEST
				numOfComparison++;
#endif
				if (value < (*this)[range_.second])
					seq_.insert((*this) + range_.second, value);
				else
					seq_.insert((*this) + (range_.second + 1), value);
			}
		}
		else
		{
#ifdef TEST
			numOfComparison++;
#endif
			if (value < (*this)[range_.first])
				seq_.insert((*this) + range_.first, value);
			else
				seq_.insert((*this) + (range_.first + 1), value);
		}
#ifdef DEBUG
		std::cout << "after insertion" << std::endl;
		std::list<size_t>::iterator d1 = seq_.begin();
		for (;d1 != seq_.end();d1++)
			std::cout << *d1 << " ";
		std::cout << std::endl;
#endif
		return;
	}
	size_t i = range_.first + (diff / 2);
#ifdef DEBUG
	std::cout << "going to compare at seq[" << i << "]" << std::endl;
#endif
#ifdef TEST
	numOfComparison++;
#endif
	if (value < (*this)[i])
	{
#ifdef DEBUG
		std::cout << value << " is smaller than " << seq_[i] << std::endl;
#endif
		range_.second = i - 1;
	}
	else
	{
#ifdef DEBUG
		std::cout << value << " is larger than " << seq_[i] << std::endl;
#endif
		range_.first = i + 1;
	}
#ifdef DEBUG
	std::cout << "range(" << range_.first << ", " << range_.second << ")" << std::endl;
#endif
	binaryInsertion(value);
}

void ListPmergeMe::sortInternal(std::list<std::pair<size_t, size_t> >& p, ssize_t remain, size_t size)
{
#ifdef DEBUG
	std::cout << "sortInternal" << std::endl;
	std::cout << "max size: " << size << std::endl;
	std::cout << "----seq.size(): " << seq_.size() << std::endl;
	std::list<size_t>::iterator d1 = seq_.begin();
	for (;d1 != seq_.end();d1++)
		std::cout << *d1 << " ";
	std::cout << std::endl;
	std::cout << "----p.size(): " << p.size() << std::endl;
	std::list<std::pair<size_t, size_t> >::iterator d2 = p.begin();
	for (;d2 != p.end();d2++)
		std::cout << "(" << d2->first << " " << d2->second << ")" << std::endl;
	if (remain != -1)
		std::cout << remain << std::endl;
	std::cout << "----------" << std::endl;
#endif
	size_t nSquare = 2 * 2;
	// beginning of insertion process
	ssize_t begin = nSquare - 1;
	ssize_t end = 1;
	for (;seq_.size() < size;)
	{
		if (seq_.size() <= static_cast<size_t>(begin))
		{
			if (!(remain != -1 && (seq_.size() == static_cast<size_t>(begin))))
			{
				begin--;
				continue;
			}
		}
		std::list<std::pair<size_t, size_t> >::iterator it = p.begin();
		for (;it != p.end();it++)
		{
			if (seq_.size() <= static_cast<size_t>(begin))
			{
				it = p.end();
				break;
			}
			if (it->first == (*this)[begin])
				break;
		}
		begin = diff(it, p.begin());
		size_t beginTmp = begin;
		for (;begin >= end;begin--)
		{
			if (p.size() <= static_cast<size_t>(begin))
			{
#ifdef DEBUG
				std::cout << "going to insert remain " << remain << std::endl;
#endif
				range_.first = 0;
				range_.second = seq_.size() - 1;
				rangeLast_ = range_.second;
				binaryInsertion(remain);
			}
			else
			{
				range_.first = 0;
				std::list<size_t>::iterator pos = std::lower_bound(seq_.begin(), seq_.end(), get(p, begin).first);
				range_.second = diff(--pos, seq_.begin());
				rangeLast_ =  range_.second;
#ifdef DEBUG
				std::cout << "range(0, " << range_.second << ")" << std::endl;
				std::cout << "going to insert " << p[begin].second << std::endl;
#endif
				binaryInsertion(get(p, begin).second);
			}
		}
		nSquare *= 2;
		begin = nSquare - 1;
		end = beginTmp + 1;
#ifdef DEBUG		
		std::cout << "max size: " << size << std::endl;
		std::cout << "seq.size(): " << seq_.size() << std::endl;
		std::vector<size_t>::iterator d2 = seq_.begin();
		for (;d2 != seq_.end();d2++)
			std::cout << *d2 << " ";
		std::cout << std::endl;
#endif
	}
}

void ListPmergeMe::sort()
{
#ifdef DEBUG
	std::cout << "sort" << std::endl;
	std::cout << "----seq.size(): " << seq_.size() << std::endl;
	std::list<size_t>::iterator d1 = seq_.begin();
	for (;d1 != seq_.end();d1++)
		std::cout << *d1 << " ";
	std::cout << std::endl;
#endif
	if (seq_.size() <= 4)
	{
		smallBinaryInsertion();
		return;
	}
	size_t size = seq_.size();
	ssize_t remain = -1;
	if (seq_.size() % 2 != 0)
		remain = (*this)[seq_.size() - 1];
	std::list<std::pair<size_t, size_t> > tmp = makePairList();
	createNewSeq(tmp);
	sort();
	std::list<std::pair<size_t, size_t> > sortedTmp = sortPair(tmp);
	// create main chain
	seq_.insert(seq_.begin(), get(sortedTmp, 0).second);
	// sort main chain
	sortInternal(sortedTmp, remain, size);
}
