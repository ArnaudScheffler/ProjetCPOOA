/*
 * \file main.cpp
 *
 * \date 1 nov. 2017
 * \author EVA
 */

#include <iostream>
#include <list>
#include <limits>
#include <stdlib.h>
#include "Cours.hpp"
#include "Enseignant.hpp"
#include "Etudiant.hpp"
#include "Plateforme.hpp"
#include "Admin.hpp"

/**
 *\fn void pause()
 *\brief Met l'interface en attente
 *
 */
void pause(){
    std::cout << "Appuyez sur une touche pour continuer..." << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

/**
 *\fn void remplir
 *\brief Remplis la PA de donénes
 *\return void
 */
void remplir(Plateforme &p){
    Enseignant* endef = new Enseignant("Gautier", "pass");
    p.addEnseignant(*endef);

    Etudiant* etudef = new Etudiant("Elliot", "pass");
    p.addEtudiant(*etudef);

    Cours* cdef = new Cours("CPOOA", "", "", "", 10);
    endef->proposerUnCours(*cdef);
    p.addCours(*cdef);

    Admin* adm = new Admin("admin","pass");
    p.addAdmin(*adm);
}

/**
 *\fn int main()
 *\brief Affiche la console
 *\return int
 */
int main() {
    bool quit = false;
    int choice = -1;

    Plateforme p = Plateforme();
    remplir(p);

    while (!quit){
        std::cout << "\nBienvenue dans notre menu ! Choisissez votre action :"
                  << "\n\t [0] - Quitter"
                  << "\n\t [1] - Créer un Enseignant (et l'ajouter à la plate-forme)"
                  << "\n\t [2] - Créer un Etudiant (et l'ajouter à la plate-forme)"
                  << "\n\t [3] - Créer un Cours (et l'ajouter à la plate-forme)"
                  << "\n\t [4] - Faire proposer un Cours à un enseignant"
                  << "\n\t [5] - Inscrire un étudiant à un cours"
                  << "\n\t [6] - Désinscrire un étudiant à un cours"
                  << "\n\t [7] - Afficher les cours propose par un enseignant"
                  << "\n\t [8] - Afficher les cours d'un étudiant"
                  << "\n\t [9] - Liste des étudiants de la plate-forme"
                  << "\n\t [10] - Liste des enseignants de la plate-forme"
                  << "\n\t [11] - Liste des cours de la plate-forme"
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
            delete etutest;
            pause();
            break;
        }
        case 3:{
            Cours *coutest;
            std::string nomEnseignant = "";
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
            std::cout << "Compris !\nListe des Enseignants :\n" << p.afficherEnseignant() << "Login : ";
            std::cin >> nomEnseignant;
            if (p.containsEnseignant(nomEnseignant)) {
                Enseignant& ensrecup = p.getEnseignantparLogin(nomEnseignant);
                ensrecup.proposerUnCours(*coutest);
            }
            p.addCours(*coutest);
            std::cout << "Votre Cours : \nNom : " << coutest->getNom() <<"\nEnseingant auteur : " << coutest->getLoginEnseignant() << "\nA été ajouté a la plate-forme." << std::endl;
            pause();
            break;
        }
        case 4:{
            std::string nomEnseignant = "";
            std::string nomCours = "";

            std::cout << "Compris !\nListe des Enseignants :\n" << p.afficherEnseignant() << "Login : ";
            std::cin >> nomEnseignant;
            if (p.containsEnseignant(nomCours)) {
                std::cout << "Merci !\nListe des cours :\n" << p.afficherCours() << "Nom du cours : ";
                std::cin >> nomCours;
                if (p.containsCours(nomCours)) {
                    Enseignant& ensrecup = p.getEnseignantparLogin(nomEnseignant);
                    Cours& coursrecup = p.getCoursParNom(nomCours);
                    ensrecup.proposerUnCours(coursrecup);
                    std::cout << "Resultat :\n" << ensrecup.getLogin()<< " à desormais les cours :\n" <<ensrecup.afficherCoursPropose() << std::endl;
                } else
                    std::cout << "Le cours n'éxiste pas !" << std::endl;
            } else
                std::cout << "L'enseignant n'éxiste pas !" << std::endl;

            pause();
            break;
        }
        case 5:{
            std::string nomEtudiant = "";
            std::string nomCours = "";

            std::cout << "Compris !\nListe des Etudiant :\n" << p.afficherEtudiant() << "Login : ";
            std::cin >> nomEtudiant;
            if (p.containsEtudiant(nomEtudiant)) {
                std::cout << "Merci !\nListe des cours :\n" << p.afficherCours() << "Nom du cours : ";
                std::cin >> nomCours;
                if (p.containsCours(nomCours)) {
                    Etudiant& eturecup = p.getEtudiantParLogin(nomEtudiant);
                    Cours& coursrecup = p.getCoursParNom(nomCours);
                    eturecup.inscrire(coursrecup);
                    std::cout << "Resultat :\n" << eturecup.getLogin()<< " à desormais les cours :\n" <<eturecup.afficherCours() << std::endl;
                } else
                    std::cout << "Le cours n'éxiste pas !" << std::endl;
            } else
                std::cout << "L'étudiant n'éxiste pas !" << std::endl;

            pause();
            break;
        }
        case 6:{
            std::string nomCours = "";
            std::string nomEtudiant = "";

            std::cout << "Compris !\nListe des Etudiant :\n" << p.afficherEtudiant() << "Login : ";
            std::cin >> nomEtudiant;
            if (p.containsEtudiant(nomEtudiant)) {
                std::cout << "Merci !\nListe des cours :\n" << p.afficherCours() << "Nom du cours : ";
                std::cin >> nomCours;
                if (p.containsCours(nomCours)) {
                    Etudiant& eturecup = p.getEtudiantParLogin(nomEtudiant);
                    Cours& coursrecup = p.getCoursParNom(nomCours);
                    eturecup.desinscrire(coursrecup);
                    std::cout << "Resultat :\n" << eturecup.getLogin()<< " à desormais les cours :\n" <<eturecup.afficherCours() << std::endl;
                } else
                    std::cout << "Le cours n'éxiste pas !" << std::endl;
            } else
                std::cout << "L'étudiant n'éxiste pas !" << std::endl;

            pause();
            break;
        }
        case 7:{
            std::string nomEnseignant = "";
            std::cout << "Compris !\nListe des enseignants :\n" << p.afficherEnseignant() << "Login : ";
            std::cin >> nomEnseignant;

            if (p.containsEnseignant(nomEnseignant)) {
                Enseignant& ensrecup = p.getEnseignantparLogin(nomEnseignant);
                std::cout << "Cours proposé par l'enseignant " << ensrecup.getLogin() << " :\n" << ensrecup.afficherCoursPropose() << std::endl;
            } else
                std::cout << "L'enseignant n'éxiste pas !" << std::endl;

            pause();
            break;
        }
        case 8:{
            std::string nomEtudiant = "";
            std::cout << "Compris !\nListe des étudiants :\n" << p.afficherEtudiant() << "Login : " ;
            std::cin >> nomEtudiant;
            if (!p.containsEtudiant(nomEtudiant))
                std::cout << "L'étudiant n'existe pas !" << std::endl;
            else {
                Etudiant& eturecup = p.getEtudiantParLogin(nomEtudiant);
                std::cout << "Cours de l'etudiant :\n" << eturecup.getLogin()<< " a les cours :\n" <<eturecup.afficherCours() << std::endl;
            }
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



