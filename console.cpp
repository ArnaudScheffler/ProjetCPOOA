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

void pause(){
	std::cout << "Appuyez sur une touche pour continuer..." << std::endl;
    std::cin.clear();
	std::cin.get();
}

int main(int argc, char **argv) {
	bool quit = false;
	int choice = 0;
	Enseignant endef = Enseignant("Gautier", "pass");
	Etudiant etudef = Etudiant("this4u","labddcdur");
	Cours coudef = Cours("CPOOA", "10/10/10", "10/10/10", "10/10/10", 20);
	coudef.setEnseignant(endef);
	while (!quit){
		std::cout << "\nBienvenue dans notre menu ! Choisissez votre action :"
				<< "\n\t [1] - Quitter"
                << "\n\t [2] - Créer un Enseignant"
                << "\n\t [3] - Créer un Etudiant"
                << "\n\t [4] - Créer un Cours"
                << "\n\t [5] - Faire proposer le Cours par défaut l'enseignant par défaut"
				<< "\n\t [6] - Faire s'inscrire a un Cours l'etudiant par defaut"
				<< "\n\t [7] - Faire se desinscrire a un Cours l'etudiant par defaut"
				<< "\n\t [8] - Afficher les cours propose par l'enseignant par defaut"
				<< "\n\t [9] - Afficher les cours de l'etudiant par defaut"
				<< std::endl;
		std::cin >> choice ;

		switch (choice){
			case 1:{
				std::cout << "Au revoir." << std::endl;
				quit = true;
				break;
			}
			case 2:{
				Enseignant *entest;
				std::string login = "";
				std::string mdp = "";
                std::cout << "Compris !\nEntrez le login de l'Enseignant : ";
				std::cin >> login;
                std::cout << "Entrez le mot de passe de l'Enseignant : ";
				std::cin >> mdp;
				entest = new Enseignant(login, mdp);
				std::cout << "Votre enseignant : \nLogin : " << entest->getLogin() <<"\nMDP : " << entest->getMDP() << std::endl;
				delete entest;
				pause();
				break;
			}
			case 3:{
				Etudiant *etutest;
				std::string login = "";
				std::string mdp = "";
                std::cout << "Compris !\nEntrez le login de l'Etudiant : ";
				std::cin >> login;
                std::cout << "Entrez le mot de passe de l'Etudiant : ";
				std::cin >> mdp;
				etutest = new Etudiant(login, mdp);
				std::cout << "Votre etudiant : \nLogin : " << etutest->getLogin() <<"\nMDP : " << etutest->getMDP() << std::endl;
				delete etutest;
				pause();
				break;
			}
			case 4:{
				Cours *coutest;
				std::string nom = "";
				std::string datedeb = "";
				std::string datefin = "";
				std::string datefininsc = "";
				int nbplace = 0;
				std::cout << "Compris !\nEntrez le nom du Cours." << std::endl;
				std::cin >> nom;
				std::cout << "Entrez la date du debut du Cours. (JJ/MM/AAAA)" << std::endl;
				std::cin >> datedeb;
				std::cout << "Entrez la date de fin du Cours. (JJ/MM/AAAA)" << std::endl;
				std::cin >> datefin;
				std::cout << "Entrez la date de fin d'inscription du Cours. (JJ/MM/AAAA)" << std::endl;
				std::cin >> datefininsc;
				std::cout << "Entrez le nombre de place pour ce Cours." << std::endl;
				std::cin >> nbplace;
				coutest = new Cours(nom, datedeb,datefin,datefininsc,nbplace);
				coutest->setEnseignant(endef);
				std::cout << "Votre Cours : \nNom : " << coutest->getNom() <<"\nEnseingant auteur : " << coutest->getLoginEnseignant() << std::endl;
				delete coutest;
				pause();
				break;
			}
			case 5:{
				std::cout << "Compris !" << std::endl;
				endef.proposerUnCours(coudef);
				std::cout << "Resultat :\n" << endef.getLogin()<< " a les cours :\n" <<endef.afficherCoursPropose() << std::endl;
				pause();
				break;
			}
			case 6:{
				std::cout << "Compris !" << std::endl;
				etudef.inscrire(coudef);
				std::cout << "Resultat :\n" << etudef.getLogin()<< " a les cours :\n" << etudef.afficherCours() << std::endl;
				pause();
				break;
			}
			case 7:{
				std::cout << "Compris !" << std::endl;
				etudef.desinscrire(coudef);
				std::cout << "Resultat :\n" << etudef.getLogin()<< " a les cours :\n" << etudef.afficherCours() << std::endl;
				pause();
				break;
			}
			case 8:{
				std::cout << "Cours de l'enseignant par defaut:\n" << endef.afficherCoursPropose() << std::endl;
				pause();
				break;
			}
			case 9:{
				std::cout << "Cours de l'etudiant par defaut :\n" << etudef.afficherCours() << std::endl;
				pause();
				break;
			}
			default:{
                std::cout << "Entrée non reconnue, veuillez réessayer." << std::endl;
				pause();
			}
		}
	}
	return 0;
}


