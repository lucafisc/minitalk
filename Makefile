F_SERVER = ./src/server.c ./src/utils.c
F_CLIENT = ./src/client.c
O_SERVER = $(F_SERVER:.c=.o)
O_CLIENT = $(F_CLIENT:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -ggdb3
SERVER = server
CLIENT = client
PRINTF = ft_printf/ft_printf.a
LIBFT = libft/libft.a
INCLUDES = -I ft_printf/includes -I libft/includes
MAKE = make

all: $(SERVER) $(CLIENT)

$(SERVER): $(PRINTF) $(LIBFT) $(O_SERVER)
	$(CC) $(CFLAGS) $(O_SERVER) $(PRINTF) $(LIBFT) $(INCLUDES) -o $(SERVER)

$(CLIENT): $(PRINTF) $(LIBFT) $(O_CLIENT)
	$(CC) $(CFLAGS) $(O_CLIENT) $(PRINTF) $(LIBFT) $(INCLUDES) -o $(CLIENT)

$(PRINTF):
	$(MAKE) -C ft_printf

$(LIBFT):
	$(MAKE) -C libft

%.o: %.c
	$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

clean:
	$(MAKE) -C ft_printf clean
	$(MAKE) -C libft clean
	rm -f $(O_SERVER) $(O_CLIENT)

fclean: clean
	$(MAKE) -C ft_printf fclean
	$(MAKE) -C libft fclean
	rm -f $(SERVER) $(CLIENT)

re: fclean
	$(MAKE) all