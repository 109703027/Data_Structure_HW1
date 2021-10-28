CC = g++
CPPFLAGS = -lm
EXE = main.exe
OBJS = main.o public.o Merge_sort.o Heap_sort.o Lomuto_Partition.o Hoare_Partition.o  Dutch_Flag_Partition.o

$(EXE) : $(OBJS)
	$(CC) $(CPPFLAGS) -o $(EXE) $(OBJS)

%.o : %.cpp 
	$(CC) $(CPPFLAGS) -c -o $@ $<

clean:
	rm $(EXE) $(OBJS)
