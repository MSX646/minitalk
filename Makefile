SRVR = server
CLNT = client

CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRC = server.c client.c utils.c
S_SRC = server.c
C_SRC = client.c
UTIL = utils.c

S_OBJ = server.o
C_OBJ = client.o
U_OBJ = utils.o
D_FILES = $(patsubst %.c,%.d,$(SRC))

all: $(SRVR) $(CLNT)

%.o: %.c
	gcc $(CFLAGS) -o $@ -c $<

$(SRVR): $(S_OBJ) $(U_OBJ)
	gcc $(CFLAGS) $(S_OBJ) $(U_OBJ) -o $(SRVR)

$(CLNT): $(C_OBJ) $(U_OBJ)
	gcc $(CFLAGS) $(C_OBJ) $(U_OBJ) -o $(CLNT) 

clean: 
	$(RM) $(S_OBJ) $(C_OBJ) $(U_OBJ) $(D_FILES)

fclean: clean
	$(RM) $(SRVR) $(CLNT)

re: fclean all

.PHONY: all clean fclean re
