/*
 * main.cpp
 *
 *  Created on: 1 nov. 2017
 *      Author: EVA
 */

#include <iostream>
#include <list>
#include <limits>
#include <stdlib.h>
#include "Cours.hpp"
#include "Enseignant.hpp"
#include "Etudiant.hpp"
#include "Plateforme.hpp"

void pause(){
	std::cout << "Appuyez sur une touche pour continuer..." << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();
}

int main(int argc, char **argv) {
	bool quit = false;
	int choice = -1;
	Plateforme p = Plateforme();
	Enseignant endef = Enseignant("Gautier", "pass");
	while (!quit){
		std::cout << "\nBienvenue dans notre menu ! Choisissez votre action :"
				<< "\n\t [0] - Quitter"
                << "\n\t [1] - Créer un Enseignant (et l'ajouter à la plate-forme)"
                << "\n\t [2] - Créer un Etudiant (et l'ajouter à la plate-forme)"
                << "\n\t [3] - Créer un Cours (et l'ajouter à la plate-forme)"
                << "\n\t [4] - Faire proposer un Cours à un enseignant"
				<< "\n\t [5] - Faire s'inscrire a un Cours un étudiant"
				<< "\n\t [6] - Faire se desinscrire a un Cours un étudiant"
				<< "\n\t [7] - Afficher les cours propose par un enseignant"
				<< "\n\t [8] - Afficher les cours d'un étudiant"
                << "\n\t [9] - Afficher la liste des étudiants de la plate-forme"
                << "\n\t [10] - Afficher la liste des enseignants de la plate-forme"
    			<< "\n\t [11] - Afficher la liste des cours de la plate-forme"
				<< std::endl;
		std::cin >> choice ;

		switch (choice){
			case 0:{
				std::cout << "Au revoir." << std::endl;
				quit = true;
				break;
			}
			case 1:{
				Enseignant *entest;
				std::string login = "";
				std::string mdp = "";
                std::cout << "Compris !\nEntrez le login de l'Enseignant : ";
				std::cin >> login;
                std::cout << "Entrez le mot de passe de l'Enseignant : ";
				std::cin >> mdp;
				entest = new Enseignant(login, mdp);
				p.addEnseignant(*entest);
				std::cout << "Votre enseignant : \nLogin : " << entest->getLogin() <<"\nMDP : " << entest->getMDP() << "\nA été ajouté a la plate-forme." << std::endl;
				//delete entest;
				pause();
				break;
			}
			case 2:{
				Etudiant *etutest;
				std::string login = "";
				std::string mdp = "";
                std::cout << "Compris !\nEntrez le login de l'Etudiant : ";
				std::cin >> login;
                std::cout << "Entrez le mot de passe de l'Etudiant : ";
				std::cin >> mdp;
				etutest = new Etudiant(login, mdp);
				p.addEtudiant(*etutest);
				std::cout << "Votre etudiant : \nLogin : " << etutest->getLogin() <<"\nMDP : " << etutest->getMDP() << "\nA été ajouté a la plate-forme." << std::endl;
				//delete etutest;
				pause();
				break;
			}
			case 3:{
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
				p.addCours(*coutest);
				std::cout << "Votre Cours : \nNom : " << coutest->getNom() <<"\nEnseingant auteur : " << coutest->getLoginEnseignant() << "\nA été ajouté a la plate-forme." << std::endl;
				//delete coutest;
				pause();
				break;
			}
			case 4:{
                std::string nomCours = "";
				std::string nomEnseignant = "";
				std::cout << "Compris !\nEntrez le nom d'un Cours de la PA :\n" << p.afficherCours() <<std::endl;
				std::cin >> nomCours;
				Cours& coursrecup = p.getCoursParNom(nomCours);
				/*while(coursrecup){
                    std::cout << "Impossible de trouver le cours donné : " << p.afficherCours() <<std::endl;
                    pause();
                    std::cin >> nomCours;
				}*/
                std::cout << "Merci !\nEntrez le nom d'un Enseignant de la PA :\n" << p.afficherEnseignant() <<std::endl;
				std::cin >> nomEnseignant;
				Enseignant& ensrecup = p.getEnseignantparLogin(nomEnseignant);
				/*while(ensrecup == null){
                    std::cout << "Impossible de trouver l'enseignant donné : " << p.afficherEnseignant() <<std::endl;
                    pause();
                    std::cin >> nomEnseignant;
				}*/
				ensrecup.proposerUnCours(coursrecup);
				std::cout << "Resultat :\n" << ensrecup.getLogin()<< " à desormais les cours :\n" <<ensrecup.afficherCoursPropose() << std::endl;
				pause();
				break;
			}
			case 5:{
                std::string nomCours = "";
				std::string nomEtudiant = "";
				std::cout << "Compris !\nEntrez le nom d'un Cours de la PA :\n" << p.afficherCours() <<std::endl;
				std::cin >> nomCours;
				Cours& coursrecup = p.getCoursParNom(nomCours);
				/*while(coursrecup){
                    std::cout << "Impossible de trouver le cours donné : " << p.afficherCours() <<std::endl;
                    pause();
                    std::cin >> nomCours;
				}*/
                std::cout << "Merci !\nEntrez le nom d'un Etudiant de la PA :\n" << p.afficherEtudiant() <<std::endl;
				std::cin >> nomEtudiant;
				Etudiant& eturecup = p.getEtudiantParLogin(nomEtudiant);
				/*while(ensrecup == null){
                    std::cout << "Impossible de trouver l'enseignant donné : " << p.afficherEnseignant() <<std::endl;
                    pause();
                    std::cin >> nomEnseignant;
				}*/
				eturecup.inscrire(coursrecup);
				std::cout << "Resultat :\n" << eturecup.getLogin()<< " à desormais les cours :\n" <<eturecup.afficherCours() << std::endl;
				pause();
				break;
			}
			case 6:{
                std::string nomCours = "";
				std::string nomEtudiant = "";
				std::cout << "Compris !\nEntrez le nom d'un Cours de la PA :\n" << p.afficherCours() <<std::endl;
				std::cin >> nomCours;
				Cours& coursrecup = p.getCoursParNom(nomCours);
				/*while(coursrecup){
                    std::cout << "Impossible de trouver le cours donné : " << p.afficherCours() <<std::endl;
                    pause();
                    std::cin >> nomCours;
				}*/
                std::cout << "Merci !\nEntrez le nom d'un Etudiant de la PA :\n" << p.afficherEtudiant() <<std::endl;
				std::cin >> nomEtudiant;
				Etudiant& eturecup = p.getEtudiantParLogin(nomEtudiant);
				/*while(ensrecup == null){
                    std::cout << "Impossible de trouver l'enseignant donné : " << p.afficherEnseignant() <<std::endl;
                    pause();
                    std::cin >> nomEnseignant;
				}*/
				eturecup.desinscrire(coursrecup);
				std::cout << "Resultat :\n" << eturecup.getLogin()<< " à desormais les cours :\n" <<eturecup.afficherCours() << std::endl;
				pause();
				break;
			}
			case 7:{
				std::string nomEnseignant = "";
				std::cout << "Compris !\nEntrez le nom d'un Enseignant de la PA :\n" << p.afficherEnseignant() <<std::endl;
				std::cin >> nomEnseignant;
				Enseignant& ensrecup = p.getEnseignantparLogin(nomEnseignant);
				/*while(ensrecup == null){
                    std::cout << "Impossible de trouver l'enseignant donné : " << p.afficherEnseignant() <<std::endl;
                    pause();
                    std::cin >> nomEnseignant;
				}*/
				std::cout << "Cours proposé de l'enseignant " << ensrecup.getLogin() << " :\n" << ensrecup.afficherCoursPropose() << std::endl;
				pause();
				break;
			}
			case 8:{
                std::string nomEtudiant = "";
                std::cout << "Compris !\nEntrez le nom d'un Etudiant de la PA :\n" << p.afficherEtudiant() <<std::endl;
				std::cin >> nomEtudiant;
				Etudiant& eturecup = p.getEtudiantParLogin(nomEtudiant);
				/*while(ensrecup == null){
                    std::cout << "Impossible de trouver l'enseignant donné : " << p.afficherEnseignant() <<std::endl;
                    pause();
                    std::cin >> nomEnseignant;
				}*/
				std::cout << "Cours de l'etudiant :\n" << eturecup.getLogin()<< " à desormais les cours :\n" <<eturecup.afficherCours() << std::endl;
				pause();
				break;
			}
			case 9:{
				std::cout << "Liste des étudiants de la plate-forme :\n" << p.afficherEtudiant() << std::endl;
				pause();
				break;
			}
            case 10:{
				std::cout << "Liste des enseignants de la plate-forme :\n" << p.afficherEnseignant() << std::endl;
				pause();
				break;
			}
			case 11:{
				std::cout << "Liste des cours de la plate-forme :\n" << p.afficherCours() << std::endl;
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


