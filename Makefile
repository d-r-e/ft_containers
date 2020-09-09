NAME = ft_containers

SRC = main.cpp

INC = list.hpp iterator.hpp node.hpp IteratorList.hpp 

FLAGS = -Wall -Wextra -Werror -std=c++98

$(NAME): $(SRC) $(INC)
	clang++ $(FLAGS) main.cpp -o $(NAME)

x: fclean $(NAME)
	./$(NAME)

clean:

fclean: clean
	rm -f $(NAME)

push: fclean
	git add Makefile $(SRC) $(INC) .gitignore
	git commit -m "ft_containers"
	git push origin master