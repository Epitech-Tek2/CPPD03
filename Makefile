##
## EPITECH PROJECT, 2021
## B-CPP-300-STG-3-1-CPPD03-clement.muth
## File description:
## Makefile
##

SUCCESS				=	/bin/echo -e "\x1b[1m\x1b[33m\#\#\x1b[32m $1\x1b[0m"
WARNING				=	/bin/echo -e "\x1b[1m\x1b[33m\#\#\x1b[33m $1\x1b[0m"
ERROR				=	/bin/echo -e "\x1b[1m\x1b[33m\#\#\x1b[31m $1\x1b[0m"
DONE				=	/bin/echo -e "\x1b[1m\x1b[33m\#\#\x1b[34m $1\x1b[0m"

LIB 				=	libstring.a

## ==============================SOURCE STRING=============================== ##
PATH_STRING			=	./
SRC_STRING			=	string_utils.c	\
						string_setter.c	\
						string_finder.c	\
						string_action.c	\
						string_cast.c	\
						print.c

SRC					=	$(addprefix $(PATH_STRING), $(SRC_STRING))

CFLAGS 				=	-Wall -std=gnu11 -Wextra -Werror

AR 					=	ar rc

MV					=	mv

LIB_OBJ 			=	$(SRC:.c=.o)

all:					$(LIB)

$(LIB):					$(LIB_OBJ)
						$(AR) $(LIB) $(LIB_OBJ)

clean_lib:
						$(RM) $(LIB)

clean:
						$(RM) $(LIB_OBJ)

fclean:					clean
						$(RM) $(LIB)

re:						fclean all

tests_run:
						gcc  *.c tests/*.c -o unit_tests --coverage -lcriterion
						- ./unit_tests

.PHONY:					all clean fclean re