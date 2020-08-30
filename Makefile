NAME = ft_containers

SRC = main.cpp

INC = list.hpp

$(NAME): $(SRC) $(INC)
	clang++ main.cpp -o $(NAME)

exe: $(NAME)
	./$(NAME)

clean:

fclean: clean
	rm -f $(NAME)

push: fclean
	git add Makefile $(SRC) $(INC)
	git commit -m "ft_containers"
	git push origin master