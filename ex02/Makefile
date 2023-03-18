NAME = PmergeMe
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 
RM = rm -rf
SRC = main.cpp PmergeMe.cpp
OBJ = $(SRC:.cpp=.o)
$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)
%.o : %.cpp PmergeMe.hpp
	$(CC) $(FLAGS) -c $< -o $@
all: $(NAME)
clean :
	$(RM) $(OBJ)
fclean :clean
	$(RM) $(NAME)
re : fclean all
.PHONY : re clean fclean
