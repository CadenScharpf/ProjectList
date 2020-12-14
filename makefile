CC=clang++

all: ProjectManager

ProjectManager: main.cpp
	$(CC) -o ProjectManager main.cpp -I. 
clean:
	rm ProjectManager ProjectManager.o
