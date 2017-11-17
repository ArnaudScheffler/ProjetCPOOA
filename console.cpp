/*
 * main.cpp
 *
 *  Created on: 1 nov. 2017
 *      Author: EVA
 */

#include <iostream>

#include "Cours.hpp"
#include "Enseignant.hpp"

int main(int argc, char **argv) {

	Enseignant en1 = Enseignant("Gautier", "pass");
	Etudiant et1 = Etudiant("this4u","labddcdur");

	Cours c1 = Cours("CPOOA", "10/10/10", "10/10/10", "10/10/10", 20);
	Cours c2 = Cours("Anglais", "10/10/10", "10/10/10", "10/10/10", 20);
	Cours c3 = Cours("Toucan", "10/10/10", "10/10/10", "10/10/10", 20);

	//On construit notre enseignant
	en1.proposerUnCours(c1);
	en1.proposerUnCours(c2);
	en1.proposerUnCours(c3);
	//On construit notre etudiant
	et1.inscrire(c1);
	et1.inscrire(c2);


	std::cout << "Enseignant :" <<en1.getLogin() << std::endl;
	std::cout << en1.verifMDP("pass") << std::endl;
	std::cout << en1.verifMDP("fake") << std::endl;
	std::cout << en1.afficherCours() << std::endl;

	std::cout << "Etudiant :" << et1.getLogin() << std::endl;
	std::cout << et1.afficherCours() << std::endl;
}
