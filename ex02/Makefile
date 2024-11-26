NAME = PmergeMe
SRCS = main.cpp PosIntSeqArg.cpp VectorPmergeMe.cpp
OBJS = $(SRCS:.cpp=.o)
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

debug: CXXFLAGS += -D DEBUG
debug: $(NAME)

test: CXXFLAGS = -D TEST -std=c++20
test: $(NAME)
	cd test && pytest

.PHONY: all clean fclean re test
