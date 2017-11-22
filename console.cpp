/*
 * main.cpp
 *
 *  Created on: 1 nov. 2017
 *      Author: EVA
 */

#include <iostream>
#include <list>

#include "Cours.hpp"
#include "Enseignant.hpp"
#include "Etudiant.hpp"
#include "Plateforme.hpp"

int main(int argc, char **argv) {

	Plateforme p = Plateforme();

	Enseignant en1 = Enseignant("Gautier", "pass");

	Etudiant et1 = Etudiant("this4u","labddcdur");

	Cours c1 = Cours("CPOOA", "10/10/10", "10/10/10", "10/10/10", 20);
	Cours c2 = Cours("Anglais", "10/10/10", "10/10/10", "10/10/10", 20);
	Cours c3 = Cours("Toucan", "10/10/10", "10/10/10", "10/10/10", 20);

	p.addCours(c1);
	p.addCours(c2);
	p.addCours(c3);

	p.addEnseignant(en1);

	p.addEtudiant(et1);

	//On construit notre enseignant
	en1.proposerUnCours(c1);
	en1.proposerUnCours(c2);
	en1.proposerUnCours(c3);

	std::cout << "ici" << std::endl;
	std::cout << p.afficherCours() << std::endl;
	std::cout << p.afficherEnseignant() << std::endl;
	std::cout << p.afficherEtudiant() << std::endl;






	//On construit notre etudiant
	et1.inscrire(c1);
	et1.inscrire(c2);

	
	std::cout << "Affichages pour l'enseignant : " <<en1.getLogin() << std::endl;
	std::cout << en1.verifMDP("pass") << std::endl;
	std::cout << en1.verifMDP("fake") << std::endl;
	std::cout << "Cours de l'enseignant :\n"<< en1.afficherCoursPropose() << std::endl;
	/*
	for(auto c : c1.getPremierEtudiant()){
	  std::cout << c << std::endl;
	  }*/
        
	std::cout << "Affichages pour l'etudiant : " << et1.getLogin() << std::endl;
	std::cout << "Cours de l'etudiant :\n" << et1.afficherCours() << std::endl;

	Enseignant en2 = Enseignant("Martine", "pass");

	p.addEnseignant(en1);
	p.addEnseignant(en2);
	p.addCours(c1);

}


