CC = gcc
ISDLFLAGS = -I/usr/include/SDL2
CFLAGS = -g -Wall -W -Werror -Wpedantic -pedantic-errors -Wimplicit-fallthrough=0
LDLIBS = -lSDL2 -lm -lSDL2_image
OBJ = Graphics.o timer.o App_manager.o exo4.o memory.o \
 inputManager.o mathHelper.o common.o array.o hashtable.o \
 texture.o entity.o assetManager.o
 
exo4.exe : $(OBJ)
	$(CC) $(OBJ) -o  exo4.exe  $(LDLIBS)

exo4.o : App_manager.h exo4.c
	$(CC) $(CFLAGS) $(ISDLFLAGS) -c exo4.c

assetManager.o : assetManager.h assetManager.c
	$(CC) $(CFLAGS) $(ISDLFLAGS) -c assetManager.c

texture.o : texture.h  texture.c
	$(CC) $(CFLAGS) $(ISDLFLAGS) -c texture.c

common.o : common.h common.c
	$(CC) $(CFLAGS) $(ISDLFLAGS) -c common.c

array.o : common.h array.h array.c
	$(CC) $(CFLAGS) $(ISDLFLAGS) -c array.c

hashtable.o : common.h array.h hashtable.h hashtable.c
	$(CC) $(CFLAGS) $(ISDLFLAGS) -c hashtable.c

mathHelper.o : mathHelper.c mathHelper.h
	$(CC) $(CFLAGS) $(ISDLFLAGS) -c mathHelper.c

inputManager.o : inputManager.c inputManager.h
	$(CC) $(CFLAGS) $(ISDLFLAGS) -c inputManager.c

timer.o : timer.c timer.h
	$(CC) $(CFLAGS) $(ISDLFLAGS) -c timer.c

Graphics.o : Graphics.c Graphics.h
	$(CC) $(CFLAGS) $(ISDLFLAGS) -c Graphics.c

App_manager.o :  App_manager.c App_manager.h
	$(CC) $(CFLAGS) $(ISDLFLAGS) -c App_manager.c

memory.o : memory.c memory.h
	$(CC) $(CFLAGS)  -c memory.c



clean :
	rm -f *.o exo4.exe