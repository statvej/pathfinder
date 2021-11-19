NAME = libmx.a

FLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

.PHONY: all clean uninstall reinstall

all: $(NAME)

$(NAME):
	mkdir obj
	clang $(FLAGS) -c src/*.c
	mv *.o obj/
	ar -rc $(NAME) obj/*.o
	ranlib $(NAME)

clean:
	rm -rf obj

uninstall: clean
	rm -rf $(NAME)

reinstall: uninstall all