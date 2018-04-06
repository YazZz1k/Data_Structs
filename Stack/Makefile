STRUCT=stack
CC=g++
$(STRUCT): $(STRUCT).o $(STRUCT)_test.o
	$(CC) $(STRUCT).o $(STRUCT)_test.o -o $(STRUCT)
$(STRUCT).o: $(STRUCT).hpp $(STRUCT).cpp
	$(CC) -c $(STRUCT).cpp
$(STRUCT)_test.o: $(STRUCT)_test.cpp
	$(CC) -c $(STRUCT)_test.cpp


clean:
	rm -rf *.o $(STRUCT)
