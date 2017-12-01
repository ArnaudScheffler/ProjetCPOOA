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
#include <stdio.h>
#include "rang.hpp"
#include "Cours.hpp"
#include "Enseignant.hpp"
#include "Etudiant.hpp"
#include "Plateforme.hpp"
#include "Admin.hpp"


//#define EFFACER "\ec"
//define EFFACER "\033c"
#define EFFACER ""
#define GREEN <<rang::fg::green
#define RED <<rang::fg::red
#define BLUE <<rang::fg::cyan
#define RESET rang::style::reset<<

/**
 *\fn void pause()
 *\brief Met l'interface en attente
 */
void pause(){
    std::cout << "Appuyez sur une touche pour continuer..." << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    std::cout << EFFACER;
}

/**
 *\fn void remplir
 *\brief Remplis la PA de donénes
 *\return void
 */
void remplir(Plateforme& p){
    Cours* cdef = new Cours("c", "", "", "", 2);
    p.addCours(*cdef);

    Enseignant* endef = new Enseignant("ga", "pass");
    endef->proposerUnCours(*cdef);
    p.addEnseignant(*endef);

    Etudiant* etudef = new Etudiant("el", "pass");
    p.addEtudiant(*etudef);
    etudef = new Etudiant("a", "pass");
    p.addEtudiant(*etudef);
    etudef = new Etudiant("b", "pass");
    p.addEtudiant(*etudef);
    etudef = new Etudiant("this4u", "pass");
    p.addEtudiant(*etudef);
    etudef = new Etudiant("jo", "pass");
    p.addEtudiant(*etudef);

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

    /* Affiche le menu de sélection */
    std::cout << EFFACER GREEN << "Bienvenue dans notre menu !" << std::endl << std::endl;
    while (!quit) {
        std::cout << "Choisissez une action :" << RESET std::endl
                  BLUE << "[0]" << RESET "- Quitter" << std::endl
                  BLUE << "[1]" << RESET "- Créer un Enseignant" << std::endl
                  BLUE << "[2]" << RESET "- Créer un Etudiant" << std::endl
                  BLUE << "[3]" << RESET "- Créer un Cours" << std::endl
                  BLUE << "[4]" << RESET "- Faire proposer un Cours à un enseignant" << std::endl
                  BLUE << "[5]" << RESET "- Inscrire un étudiant à un cours" << std::endl
                  BLUE << "[6]" << RESET "- Désinscrire un étudiant à un cours" << std::endl
                  BLUE << "[7]" << RESET "- Afficher les cours propose par un enseignant" << std::endl
                  BLUE << "[8]" << RESET "- Afficher les cours d'un étudiant" << std::endl
                  BLUE << "[9]" << RESET "- Liste des étudiants" << std::endl
                  BLUE << "[10]" << RESET "- Liste des enseignants" << std::endl
                  BLUE << "[11]" << RESET "- Liste des cours" << std::endl
                  BLUE << "[12]" << RESET "- Liste des etudiants d'un cours" << std::endl
                  BLUE << "[13]" << RESET "- Liste des admins de la plate-forme" << std::endl
                  BLUE << "[14]" << RESET "- Créer un Admin" << std::endl
                  BLUE << "[15]" << RESET "- Valider un cours" << std::endl;

        /* Demande une valeur et la vérifie */
        std::cin >> choice ;
        if (!std::cin.good()) choice = -1;

        /* Choix de l'action à effectuer */
        switch (choice){
        case 0 :
            std::cout << "Au revoir." << std::endl;
            quit = true;
            break;

        case 1:{
            Enseignant *entest;
            std::string login = "";
            std::string mdp = "";
            std::cout << "Entrez le login de l'Enseignant : ";
            std::cin >> login;
            std::cout << "Entrez le mot de passe de l'Enseignant : ";
            std::cin >> mdp;
            entest = new Enseignant(login, mdp);
            p.addEnseignant(*entest);
            std::cout GREEN << "Votre enseignant : \nLogin : " << entest->getLogin() <<"\nMDP : " << entest->getMDP() << "\nA été ajouté a la plate-forme." << RESET std::endl;

            break;
        }
        case 2:{
            Etudiant *etutest;
            std::string login = "";
            std::string mdp = "";
            std::cout << "Entrez le login de l'Etudiant : ";
            std::cin >> login;
            std::cout << "Entrez le mot de passe de l'Etudiant : ";
            std::cin >> mdp;
            etutest = new Etudiant(login, mdp);
            p.addEtudiant(*etutest);
            std::cout GREEN << "Votre etudiant : \nLogin : " << etutest->getLogin() <<"\nMDP : " << etutest->getMDP() << "\nA été ajouté a la plate-forme." << RESET std::endl;

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
            std::cout << "Entrez le nom du Cours." << std::endl;
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
            std::cout << "Liste des Enseignants :" << std::endl << p.afficherEnseignant() << "Login : ";
            std::cin >> nomEnseignant;
            if (p.containsEnseignant(nomEnseignant)) {
                Enseignant& ensrecup = p.getEnseignantparLogin(nomEnseignant);
                ensrecup.proposerUnCours(*coutest);
                p.addCours(*coutest);
                std::cout GREEN << "Votre Cours : \nNom : " << coutest->getNom() <<"\nEnseingant auteur : " << coutest->getLoginEnseignant() << "\nA été ajouté a la plate-forme." << RESET std::endl;
            } else
                std::cout RED << "L'enseignant n'existe pas !" << RESET std::endl;

            break;
        }
        case 4:{
            std::string nomEnseignant = "";
            std::string nomCours = "";

            std::cout << "Liste des Enseignants :" << std::endl << p.afficherEnseignant() << "Login : ";
            std::cin >> nomEnseignant;
            if (p.containsEnseignant(nomCours)) {
                std::cout << "Liste des cours :" << std::endl << p.afficherCours() << "Nom du cours : ";
                std::cin >> nomCours;
                if (p.containsCours(nomCours)) {
                    Enseignant& ensrecup = p.getEnseignantparLogin(nomEnseignant);
                    Cours& coursrecup = p.getCoursParNom(nomCours);
                    ensrecup.proposerUnCours(coursrecup);
                    std::cout << "Resultat :" << std::endl << ensrecup.getLogin()<< " à desormais les cours :" << std::endl << ensrecup.afficherCoursPropose() << std::endl;
                } else
                    std::cout RED << "Le cours n'existe pas !" << RESET std::endl;
            } else
                std::cout RED << "L'enseignant n'existe pas !" << RESET std::endl;


            break;
        }
        case 5:{
            std::string nomEtudiant = "";
            std::string nomCours = "";

            std::cout << "Liste des Etudiant :" << std::endl << p.afficherEtudiant() << "Login : ";
            std::cin >> nomEtudiant;
            if (p.containsEtudiant(nomEtudiant)) {
                std::cout << "Liste des cours :" << std::endl << p.afficherCours() << "Nom du cours : ";
                std::cin >> nomCours;
                if (p.containsCours(nomCours)) {
                    Etudiant& eturecup = p.getEtudiantParLogin(nomEtudiant);
                    Cours& coursrecup = p.getCoursParNom(nomCours);
                    if (coursrecup.getStatus()){
                        eturecup.inscrire(coursrecup);
                        std::cout << "Resultat :" << std::endl << eturecup.getLogin()<< " à desormais les cours :" << std::endl << eturecup.afficherCours() << std::endl;
                    } else
                        std::cout << "Le cours n'est pas encore validé !" << std::endl;
                } else
                    std::cout RED << "Le cours n'existe pas !" << RESET std::endl;
            } else
                std::cout RED << "L'étudiant n'existe pas !" << RESET std::endl;


            break;
        }
        case 6:{
            std::string nomCours = "";
            std::string nomEtudiant = "";

            std::cout << "Liste des Etudiant :" << std::endl << p.afficherEtudiant() << "Login : ";
            std::cin >> nomEtudiant;
            if (p.containsEtudiant(nomEtudiant)) {
                Etudiant& eturecup = p.getEtudiantParLogin(nomEtudiant);
                std::cout << "Liste des cours de l'étudiant :" << std::endl << eturecup.afficherCours() << "Nom du cours : ";
                std::cin >> nomCours;
                if (p.containsCours(nomCours)) {
                    Etudiant& eturecup = p.getEtudiantParLogin(nomEtudiant);
                    Cours& coursrecup = p.getCoursParNom(nomCours);
                    eturecup.desinscrire(coursrecup);
                    std::cout << "Resultat :" << std::endl << eturecup.getLogin()<< " à desormais les cours :" << std::endl <<eturecup.afficherCours() << std::endl;
                } else
                    std::cout RED << "Le cours n'existe pas !" << RESET std::endl;
            } else
                std::cout RED << "L'étudiant n'existe pas !" << RESET std::endl;


            break;
        }
        case 7:{
            std::string nomEnseignant = "";
            std::cout << "Liste des enseignants :" << std::endl << p.afficherEnseignant() << "Login : ";
            std::cin >> nomEnseignant;

            if (p.containsEnseignant(nomEnseignant)) {
                Enseignant& ensrecup = p.getEnseignantparLogin(nomEnseignant);
                std::cout << "Cours proposé par l'enseignant " << ensrecup.getLogin() << " :" << std::endl << ensrecup.afficherCoursPropose() << std::endl;
            } else
                std::cout RED << "L'enseignant n'existe pas !" << RESET std::endl;


            break;
        }
        case 8:{
            std::string nomEtudiant = "";
            std::cout << "Liste des étudiants :" << std::endl << p.afficherEtudiant() << "Login : " ;
            std::cin >> nomEtudiant;
            if (!p.containsEtudiant(nomEtudiant))
                std::cout RED << "L'étudiant n'existe pas !" << RESET std::endl;
            else {
                Etudiant& eturecup = p.getEtudiantParLogin(nomEtudiant);
                std::cout << "Cours de l'etudiant :" << std::endl << eturecup.getLogin()<< " a les cours :" << std::endl <<eturecup.afficherCours() << std::endl;
            }

            break;
        }

        case 9:
            std::cout << "Liste des étudiants :" << std::endl << p.afficherEtudiant() << std::endl;
            break;

        case 10:
            std::cout << "Liste des enseignants :" << std::endl << p.afficherEnseignant() << std::endl;
            break;

        case 11:
            std::cout << "Liste des cours :" << std::endl << p.afficherCours() << std::endl;
            break;

        case 12: {
            std::string nomCours = "";
            std::cout << "Liste des cours :" << std::endl << p.afficherCours() << "Nom du cours : ";
            std::cin >> nomCours;
            if (p.containsCours(nomCours)) {
                std::cout << p.getCoursParNom(nomCours).afficherListesEtudiants() << std::endl;
            } else
                std::cout RED << "Le cours n'existe pas !" << RESET std::endl;
            break;
        }

        case 13:{
            std::cout << "Liste des admins de la plate-forme :\n" << p.afficherAdmin() << std::endl;
            pause();
            break;
        }

        case 14:{
            Admin *adtest;
            std::string login = "";
            std::string mdp = "";
            std::cout << "Entrez le login de l'Admin: ";
            std::cin >> login;
            std::cout << "Entrez le mot de passe de l'Admin : ";
            std::cin >> mdp;
            adtest = new Admin(login, mdp);
            p.addAdmin(*adtest);
            std::cout << "Votre admin : \nLogin : " << adtest->getLogin() <<"\nMDP : " << adtest->getMDP() << "\nA été ajouté a la plate-forme." << std::endl;
            //delete adtest;
            break;
        }
        case 15:{
            std::string nomAdmin = "";
            std::string nomCours = "";
            std::cout << "Liste des admins :\n" << p.afficherAdmin() << "Login : ";
            std::cin >> nomAdmin;
            if (p.containsAdmin(nomAdmin)) {
                Admin& adrecup = p.getAdminparLogin(nomAdmin);
                std::cout << "Liste des cours invalides :" << std::endl << p.afficherCoursInvalide() << "Nom du cours : ";
                std::cin >> nomCours;
                if (p.containsCours(nomCours)) {
                    Cours& coursrecup = p.getCoursParNom(nomCours);
                    adrecup.validerCours(coursrecup);
                    std::cout << "L'etat de validation du cours " << coursrecup.getNom() << " est desomrais " << coursrecup.getStatus() << std::endl;
                } else
                    std::cout RED << "Le cours n'existe pas !" << RESET std::endl;
            } else
                std::cout << "L'admin n'existe pas !" << std::endl;
            break;
        }

        default:
            std::cout << "Entrée non reconnue, veuillez réessayer." << std::endl;
            break;
        }
        if (!quit) pause();
    }
    return 0;
}



