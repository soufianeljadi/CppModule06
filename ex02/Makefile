CXX = c++
SRC = main.cpp Base.cpp A.cpp B.cpp C.cpp 
OBJ = $(SRC:.cpp=.o)
RM = rm -rf
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = Base

all: $(NAME)

$(NAME): $(OBJ) Base.hpp A.hpp B.hpp C.hpp 
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: clean  