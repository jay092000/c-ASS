SRC1 = Code7.c
SRC2 = FileLib.c
SRC3 = DrawTool.c
SRC4 = ListLib.c

OBJ1 = $(SRC1:.c=.o)
OBJ2 = $(SRC2:.c=.o)
OBJ3 = $(SRC3:.c=.o)
OBJ4 = $(SRC4:.c=.o)
EXE = $(SRC1:.c=.e)

HFILES = FileLib.h
HFILES3 = DrawTool.h
HFILES4 = ListLib.h

CFLAGS = -g 

all : ${EXE}
$(EXE) : $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4)
		gcc $(CFLAGS) $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4) -o $(EXE)

$(OBJ1) : $(SRC1)  $(HFILES3) $(HFILES) $(HFILES4)
		gcc -c $(CFLAGS) $(SRC1) -o $(OBJ1)

$(OBJ2) : $(SRC2) $(HFILES)
		gcc -c $(CFLAGS) $(SRC2) -o $(OBJ2)

$(OBJ3) : $(SRC3) $(HFILES3)
		gcc -c $(CFLAGS) $(SRC3) -o $(OBJ3)

$(OBJ4) : $(SRC4) $(HFILES4)
		gcc -c $(CFLAGS) $(SRC4) -o $(OBJ4)