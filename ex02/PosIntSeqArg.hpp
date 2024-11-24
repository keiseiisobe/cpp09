#ifndef POSINTSEQARG_HPP
#define POSINTSEQARG_HPP

#include <algorithm>
#include <vector>
#include <string>
#include <cctype>
#include <cstdlib>
#include "Arg.hpp"

class PosIntSeqArg : public Arg
{
public:
	PosIntSeqArg(const int argc, const char *argv[]);
	~PosIntSeqArg();
	bool noDuplication() const;
	const std::vector<size_t>& getSeq() const;
private:
	bool isPosInt(const int argc, const char *argv[]) const;
	std::vector<size_t> seq;
};

#endif
