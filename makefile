TARGET=my_printf 
SRC=my_printf.c functions.c
CFLAGS=-Wall -Wextra -Werror
OBJ=my_printf.o

all : $(TARGET)

$(TARGET) : 
	gcc $(CFLAGS) -o $(TARGET) $(SRC)

#$(OBJ) : $(SRC)
#	gcc $(CFLAGS) -c $(SRC)

clean:
	rm -f *.o


fclean: clean
	rm -f $(TARGET)

re: fclean all