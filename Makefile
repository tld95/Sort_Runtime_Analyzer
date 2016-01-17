sort: sort_data.o IO.o sorts.o
	gcc -o sort sort_data.o IO.o sorts.o

sort_data.o: sort_data.c sorts.h IO.h
	gcc -c sort_data.c

IO.o: IO.c IO.h
	gcc -c IO.c

sorts.o: sorts.c sorts.h
	gcc -c sorts.c
