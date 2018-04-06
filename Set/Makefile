STRUCT=set
CC=gcc
$(STRUCT): $(STRUCT).o $(STRUCT)_test.o
	$(CC) $(STRUCT).o $(STRUCT)_test.o -o $(STRUCT)
$(STRUCT).o: $(STRUCT).h $(STRUCT).c
	$(CC) -c $(STRUCT).c
$(STRUCT)_test.o: $(STRUCT)_test.c
	$(CC) -c $(STRUCT)_test.c


clean:
	rm -rf *.o $(STRUCT)
