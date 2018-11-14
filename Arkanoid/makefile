# définition des cibles particulières
.PHONY: clean, mrproper

# désactivation des règles implicites
#.SUFFIXES:

# définition des variables
CXX=g++
CFLAGS=-c -g -W -Wall -Wextra -Werror -Wmissing-declarations -Wmissing-prototypes -Wredundant-decls -Wshadow -Wbad-function-cast -Wcast-qual -O3
LDFLAGS=-g -W -Wall -Wextra -Werror -Wmissing-declarations -Wmissing-prototypes -Wredundant-decls -Wshadow -Wbad-function-cast -Wcast-qual -O3
#nom du programme exécutable
EXEC = prog
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

# création de l'exécutable
all : $(EXEC)

$(EXEC) : $(OBJ)
	@ $(CXX) -o $@ $^ $(LDFLAGS)
%.o : %.c
	@ $(CXX) $(CFLAGS) $< -o $*.o

# suppression des fichiers temporaires
clean:
	@ rm -rf $(OBJ)
	
# suppression de tous les fichiers, sauf les sources,
# en vue d'une reconstruction complète
mrproper: clean
	@ rm -rf $(EXEC)
