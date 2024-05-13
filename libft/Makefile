# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/08 10:23:30 by agheredi          #+#    #+#              #
#    Updated: 2024/05/13 15:00:12 by agheredi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

FLAGS = -Wall -Werror -Wextra

SRCS = ft_atoi.c \
	   ft_bzero.c \
	   ft_calloc.c \
	   ft_isalnum.c \
	   ft_isalpha.c \
	   ft_isascii.c \
	   ft_isdigit.c \
	   ft_isprint.c \
	   ft_itoa.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_memcpy.c \
	   ft_memmove.c \
	   ft_memset.c \
	   ft_putchar_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c \
	   ft_putstr_fd.c \
	   ft_split.c \
	   ft_strchr.c \
	   ft_strdup.c \
	   ft_striteri.c \
	   ft_strjoin.c \
	   ft_strlcat.c \
	   ft_strlcpy.c \
	   ft_strlen.c \
	   ft_strmapi.c \
	   ft_strncmp.c \
	   ft_strnstr.c \
	   ft_strrchr.c \
	   ft_strtrim.c \
	   ft_substr.c \
	   ft_tolower.c \
	   ft_toupper.c \
	   get_next_line.c \
	   get_next_line_utils.c \
	   ft_printf.c \
	   pf_read_text.c \
	   pf_search_arg.c \
	   pf_arg_c.c \
	   pf_arg_d.c \
	   pf_arg_p.c \
	   pf_arg_s.c \
	   pf_arg_u.c \
	   pf_arg_x.c \
	   pf_nbrlen.c \
	   pf_putchar.c \
	   pf_putnbr.c \
	   pf_strlen.c \
	   pf_putstr.c \
	   ft_atoibase.c \

OBJS = $(SRCS:.c=.o)

HEADER = libft.h

all : $(NAME)

$(NAME) : $(OBJS) $(HEADER)
	@ar -rcs $(NAME) $(OBJS)
	
%.o : %.c $(HEADER)
	@$(CC) $(FLAGS) -c $< -o $@

clean : 
	@rm -rf $(OBJS)

fclean : clean 
	@rm -rf $(NAME) 

re : fclean all

.PHONY : re clean fclean all
.SILENT: re clean fclean all