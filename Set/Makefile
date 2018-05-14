STRUCT=set
CC=gcc
$(STRUCT): $(STRUCT).o $(STRUCT)_test.o
	$(CC) -g $(STRUCT).o $(STRUCT)_test.o -o $(STRUCT)
$(STRUCT).o: $(STRUCT).h $(STRUCT).c
	$(CC) -g -c $(STRUCT).c
$(STRUCT)_test.o: $(STRUCT)_test.c
	$(CC) -g -c $(STRUCT)_test.c


clean:
	rm -rf *.o $(STRUCT)

open:
	vim $(STRUCT).c $(STRUCT).h $(STRUCT)_test.c
