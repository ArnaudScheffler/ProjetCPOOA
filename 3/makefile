#Les configurations du compilateur
C = g++
CFLAGS = -Wall -std=c++11

FILE = Cours.o

console: Cours.o console.cpp
	$(C) $(CFLAGS) -o $@ $^

%.o: %.cpp %.hpp
	$(C) $(CFLAGS) -c $<

clean:
	rm -f $(FILE) console

#Affichage des varriables
print-%  : ; @echo $* = $($*)
