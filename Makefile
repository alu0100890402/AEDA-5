CC = g++
CFLAGS = -std=c++11
OBJDIR = target/obj
TARGET = target/Ordenacion

all::	$(TARGET);

$(TARGET):	$(OBJDIR)/DNI.o $(OBJDIR)/Funciones.o $(OBJDIR)/main.o
	$(CC) $^ -o $@ $(CFLAGS)

$(OBJDIR)/Funciones.o:	entities/Funciones/Funciones.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

$(OBJDIR)/DNI.o:	entities/DNI/DNI.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

$(OBJDIR)/main.o: main/main.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm $(TARGET) $(OBJDIR)/*;
