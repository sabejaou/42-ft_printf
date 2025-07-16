# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sabejaou <sabejaou@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/04 15:56:34 by sabejaou          #+#    #+#              #
#    Updated: 2023/11/08 11:05:03 by sabejaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

# Dossiers
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = includes

# Trouver tous les fichiers .c dans les sous-dossiers
SRCS = $(shell find $(SRC_DIR) -name "*.c")

# Créer les chemins des objets correspondants
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Compilateur et flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I$(INC_DIR)

# Règles
all: $(NAME)

$(NAME): $(OBJS)
	@echo "Création de la bibliothèque $(NAME)..."
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "Bibliothèque $(NAME) créée avec succès !"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@echo "Compilation de $<..."
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@echo "Nettoyage des fichiers objets..."
	@rm -rf $(OBJ_DIR)
	@echo "Nettoyage terminé !"

fclean: clean
	@echo "Nettoyage complet..."
	@rm -f $(NAME)
	@echo "Nettoyage complet terminé !"

re: fclean all

.PHONY: all clean fclean re 