NAME 		= anti

SOURCES 	= $(shell find . -name "*.c")
HEADERS 	= $(shell find . -name "*.h")

OBJECTS 	= $(patsubst %.c, %.o, $(SOURCES))
DEPENDS 	= $(patsubst %.c, %.d, $(SOURCES))

CFLAGS 		= -Werror -Wall -Wextra -Wall

all: $(NAME)

%.o: %.c
	@$(CC) -Iinclude $(CFLAGS) -MMD -MP -c $< -o $@

$(NAME): $(OBJECTS)
	@echo "Dependencies Compiled !"
	@$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)
	@echo "Compiled !"

clean:
	-@$(RM) $(OBJECTS) $(DEPENDS)
	-@$(RM) $(OBJECTS)
	@echo "Everything is Cleaned !"

fclean: clean
	-@$(RM) $(NAME)

run: all
	./$(NAME)

re: clean all

.PHONY: re run fclean clean all

-include $(DEPENDS)