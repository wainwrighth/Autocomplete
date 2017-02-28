# set objects for PA4
OBJECTS = main.o Term.o Autocomplete.o

# set headers for PA4
HEADERS = Term.h Autocomplete.h

# compile the objects
PA3: $(OBJECTS)
	g++ $^ -o PA4

# compare .cpp with .h to find matches
%.o: %.cpp $(HEADERS)
	g++ -c $< -o $@

# clean to clear .o and exec files
clean:
	rm -i *.o PA4
