#Les configurations du compilateur
C = g++
CFLAGS = -Wall -std=c++11

FILE = Cours.o

console: Cours.o console.cpp
	$(C) $(CFLAGS) -o $@ $^

%.o: %.cpp %.hpp
	$(C) $(CFLAGS) -c $<

doc:
	doxygen

clean: clean_doc
	rm -f $(FILE) console

clean_doc:
	rm -rf html/

#Affichage des varriables
print-%  : ; @echo $* = $($*)
