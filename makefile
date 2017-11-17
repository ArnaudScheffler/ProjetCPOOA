#Les configurations du compilateur
C = g++
CFLAGS = -Wall

FILE = Cours.o

all : console

console: Cours.o console.cpp
	$(C) $(CFLAGS) -o $@ $^

%.o: %.cpp %.hpp
	$(C) $(CFLAGS) -c $<

clean:
	rm -f $(FILE)

mrproper: clean
	rm -f console

#Affichage des varriables
print-%  : ; @echo $* = $($*)
