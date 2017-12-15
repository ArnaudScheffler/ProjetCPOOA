#Les configurations du compilateur
C = g++
CFLAGS = -Wall -std=c++11

FILE = Cours.o
PRO_FILE = ProjetCPOOA.pro

console: Cours.o console.cpp
	$(C) $(CFLAGS) -o $@ $^

gui:
	qmake $(PRO_FILE)
	make

%.o: %.cpp %.hpp
	$(C) $(CFLAGS) -c $<

doc:
	doxygen

clean: clean_doc
	rm -f $(FILE) console
	[ -f ./Makefile ] && make distclean || true

clean_doc:
	rm -rf html/

#Affichage des varriables
print-%  : ; @echo $* = $($*)
