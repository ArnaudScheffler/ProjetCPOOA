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

    // On ajoute les cours à l'enseignant
	en1.proposerUnCours(c1);
	en1.proposerUnCours(c2);
	en1.proposerUnCours(c3);

    // On ajoute les étudiants aux cours
    et1.inscrire(c1);
    et1.inscrire(c2);
    et1.inscrire(c3);

    // Affiche toutes les informations
    std::cout << "Liste des cours :" << std::endl << p.afficherCours() << std::endl;
    std::cout << "Liste des enseignants :" << std::endl << p.afficherEnseignant() << std::endl;
    std::cout << "Liste des étudiants :" << std::endl << p.afficherEtudiant() << std::endl;
    std::cout << "liste des cours de " << et1.getLogin() << std::endl;
    std::cout << et1.afficherCours() << std::endl;

}


