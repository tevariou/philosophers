NAME	:=	philo_three

CC		:=	gcc
CFLAGS	:=	-Wall -Werror -Wextra
SRC_DIR :=	srcs
OBJ_DIR	:=	objs
INC_DIR :=	includes
SRCS	:=	philo_three.c \
			config.c \
			monitor.c \
			philosopher.c \
			print.c \
			time.c \
			utils1.c \
			utils2.c
INCS	:=	$(INC_DIR)/philo_three.h
OBJS	:=	$(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

MK		:= make -C
MK_C	:= make clean -C
MK_FC	:= make fclean -C
RM		:= rm -rf
MD		:= mkdir -p

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCS)
	@$(MD) $(OBJ_DIR)
	@$(CC) $(CFLAGS) -o $@ -c $< -I $(INC_DIR)

clean:
	@$(RM) $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

