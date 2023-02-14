##
## EPITECH PROJECT, 2022
## B-OOP-400-MAR-4-1-tekspice-thibaut.tran
## File description:
## Makefile
##

SRC	=	NanoTekSpice.cpp

OBJ	=	$(SRC:.cpp=.o)

NAME	= nanotekspice

all	:	$(NAME)	$(SRC)

$(NAME)	:
	@printf "\x1B[1;34m\r[Compiling]               %$(SPACES)c\x1B[1;0m" ' '
	@sleep 0.3
	@g++	-o $(NAME) $(SRC) -g3	-std=c++20
	@printf "\x1B[1;32m\r[Compilation terminated]%$(SPACES)c\n\x1B[1;0m" ' '
	@sleep 0.3

clean :
	@rm	-f	$(OBJ)

fclean :
	@printf "\x1B[1;31m\r[Cleaning]                %$(SPACES)c\x1B[1;0m" ' '
	@sleep 0.3
	@rm	-f	$(NAME)
	@printf "\x1B[1;32m\r[Clean terminated]%$(SPACES)c\n\x1B[1;0m" ' '
	@sleep 0.3

re :	fclean	clean
	@printf "\x1B[1;33m\r[Recompiling]             %$(SPACES)c\x1B[1;0m" ' '
	@sleep 0.3
	@g++	-o $(NAME) $(SRC) -g3	-std=c++20
	@printf "\x1B[1;32m\r[Recompilation terminated]%$(SPACES)c\n\x1B[1;0m" ' '
	@sleep 0.3
