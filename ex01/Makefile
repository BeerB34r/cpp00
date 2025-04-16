CXX				=	c++
CXXFLAGS		=	-Wall -Wextra -Werror -g
SRC				=	main.cpp Contact.cpp PhoneBook.cpp
OBJ				=	$(SRC:.cpp=.o)
NAME			=	TheYellowPages

.DEFAULT_GOAL	=	$(NAME)

all				:	$(NAME)

$(NAME)			:	$(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean			:
	$(RM) $(OBJ)

fclean			:
	$(MAKE) clean
	$(RM) $(NAME)

re				:
	$(MAKE) fclean
	$(MAKE)


.PHONY			:	clean fclean re all
