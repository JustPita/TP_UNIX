TARGET = library

library_type:@read -p "Voulez-vous créer une bibliothèque statique ou dynamique? (static/dynamic): " type;
	$(MAKE) $$type

static:gcc -c -o lib.o lib.c
	ar rcs lib$(TARGET).a lib.o

dynamic:gcc -fPIC -c -o lib.o lib.c
	gcc -shared -o lib$(TARGET).so lib.o
