CC=g++
CFLAGS=-c -g -Wall
LDFLAGS=-g

TASK1=task1
TASK2=task2

all: $(TASK1) $(TASK2)
	
$(TASK1): list.cpp test1.cpp
	$(CC) $(LDFLAGS) list.cpp test1.cpp -o $@

$(TASK2): list.cpp stack.cpp queue.cpp test2.cpp
	$(CC) $(LDFLAGS) list.cpp stack.cpp queue.cpp test2.cpp -o $@

clean:
	rm -rf *o $(TASK1) $(TASK2)
