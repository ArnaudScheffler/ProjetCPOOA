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
	
	Etudiant etu1 = Etudiant("log","pass");


	//On construit notre enseignant
	en1.proposerUnCours(c1);
	en1.proposerUnCours(c2);
	en1.proposerUnCours(c3);

	
	etu1.inscrire(c1);
	etu1.inscrire(c2);

	
	std::cout << en1.getLogin() << std::endl;
	std::cout << en1.verifMDP("pass") << std::endl;
	std::cout << en1.verifMDP("fake") << std::endl;
	/*
	for(auto c : c1.getPremierEtudiant()){
	  std::cout << c << std::endl;
	  }*/
        
	//On construit notre etudiant

	std::cout << "Etudiant :" << et1.getLogin() << std::endl;
	std::cout << et1.afficherCours() << std::endl;

}


