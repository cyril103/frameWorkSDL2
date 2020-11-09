CC = gcc
ISDLFLAGS = -I/usr/include/SDL2
CFLAGS = -g -Wall -W -Werror -Wpedantic -pedantic-errors -Wimplicit-fallthrough=0 -c
LDLIBS = -lSDL2 -lm -lSDL2_image
OBJ = Graphics.o timer.o App_manager.o exo4.o memory.o \
 inputManager.o mathHelper.o common.o array.o hashtable.o \
 texture.o entity.o assetManager.o
 
exo4.exe : $(OBJ)
	$(CC) $(OBJ) -o  exo4.exe  $(LDLIBS)

exo4.o : App_manager.h exo4.c
	$(CC) $(CFLAGS) exo4.c

entity.o : entity.h mathHelper.h memory.h entity.c
	$(CC) $(CFLAGS) entity.c

assetManager.o : assetManager.h hashtable.h assetManager.c
	$(CC) $(CFLAGS) assetManager.c

texture.o : texture.h Graphics.h entity.h assetManager.h texture.c
	$(CC) $(CFLAGS) texture.c

common.o : common.h common.c
	$(CC) $(CFLAGS) common.c

array.o : common.h array.h array.c
	$(CC) $(CFLAGS) array.c

hashtable.o : common.h array.h hashtable.h hashtable.c
	$(CC) $(CFLAGS) hashtable.c

mathHelper.o : mathHelper.c mathHelper.h
	$(CC) $(CFLAGS) mathHelper.c

inputManager.o : inputManager.c inputManager.h memory.h mathHelper.h
	$(CC) $(CFLAGS) inputManager.c

timer.o : timer.c timer.h memory.h
	$(CC) $(CFLAGS) timer.c

Graphics.o : Graphics.c Graphics.h memory.h
	$(CC) $(CFLAGS) Graphics.c

App_manager.o :  App_manager.c App_manager.h Graphics.h timer.h inputManager.h texture.h
	$(CC) $(CFLAGS) App_manager.c

memory.o : memory.c memory.h
	$(CC) $(CFLAGS) memory.c



clean :
	rm -f *.o exo4.exe