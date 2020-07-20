CC = gcc
CCFLAGS = -Wall -Werror -Wextra
SOURCE = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
INCDIR = ./includes/
TARGET = libft.a
OBJECT = $(SOURCE:.c=.o)
.c.o:
	$(CC) $(CCFLAGS) -c $< -o $(<:.c=.o) -I $(INCDIR)
$(TARGET) : $(OBJECT)
	ar rcs $(TARGET) $(OBJECT)
all : $(TARGET)
clean :
	rm -f $(OBJECT)
fclean : clean
	rm -f $(TARGET)
re : fclean all
