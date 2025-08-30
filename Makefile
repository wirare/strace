include Sources.mk
NAME			:= ft_strace

DIR_LIB			:= lib
DIR_HEADERS     := headers
DIR_SOURCES     := srcs
DIR_OBJS        := .objs

OBJS            := $(addprefix $(DIR_OBJS)/, $(SRCS:%.c=%.o))

CC              := clang
OPT				:= -O3 -mavx2 -mfma -march=native -mtune=native -funroll-loops -fvectorize -ffp-contract=fast  -freciprocal-math -ffast-math -fstrict-aliasing  -fomit-frame-pointer -flto=full -mprefer-vector-width=256
CFLAGS          := -Wall -Wextra -Werror #$(OPT)
IFLAGS          := -I $(DIR_HEADERS)

GREEN            = \033[0;32m
RED              = \033[0;31m
END              = \033[0m
DIR_DUP          = mkdir -p $(@D)


all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(IFLAGS) $(OBJS) -o $(NAME)
	@printf "$(GREEN)$(NAME) compiled$(END)\n"

$(DIR_OBJS)/%.o: $(DIR_SOURCES)/%.c
	@$(DIR_DUP)
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	@rm -rf $(DIR_OBJS)
	@printf "$(RED)$(NAME) cleaned objs$(END)\n"

fclean: clean
	@rm -f $(NAME)
	@printf "$(RED)$(NAME) removed$(END)\n"

re: fclean all

.PHONY: clean fclean re all
