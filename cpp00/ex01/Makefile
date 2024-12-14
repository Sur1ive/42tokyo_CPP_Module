NAME		= phonebook
SRC_DIR 	= src/
SRCS		= main.cpp Contact.cpp PhoneBook.cpp utils.cpp
SRCS		:= $(addprefix $(SRC_DIR), $(SRCS))
OBJS		= $(SRCS:.cpp=.o)
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -Iinclude

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
