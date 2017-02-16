NAME = liboc.a
SDIR	= ./sources/
SRCS		= bag.c	\
		string.c	\
		new.c		\

SRC		= $(addprefix $(SDIR), $(SRCS))
ODIR	= ./obj/
OBJ 	= $(addprefix $(ODIR),$(SRCS:.c=.o))
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
INC		= -I./includes
RM		= @/bin/rm -rf

all: $(NAME)

$(NAME): $(ODIR) $(OBJ)
	ar rc $(NAME) $(OBJ)
	$(CC) $(CFLAGS) main.c -o test $(INC) $(NAME)

$(ODIR):
	mkdir -p $(ODIR)

$(ODIR)%.o:$(SDIR)%.c
	$(CC) $(CFLAGS) $(INC) -c -o $@ $^

clean:
	$(RM) $(ODIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all
