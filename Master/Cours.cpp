/*
 * \file Cours.cpp
 *
 * \date 11 nov. 2017
 * \author EVA
 */

#include "Cours.hpp"
#include "Enseignant.hpp"
#include "Etudiant.hpp"

const std::string Cours::getLoginEnseignant() {
	return enseignant->getLogin();
}

std::string Cours::afficherListeP() {
    std::stringstream stringstream;
    for (auto it = listeEtudiantP.cbegin(); it != listeEtudiantP.cend(); it++) {
        stringstream << (*it)->getLogin() << std::endl;
    }
    return stringstream.str();
}

std::string Cours::afficherListeA() {
    std::stringstream stringstream;
    for (auto it = listeEtudiantA.cbegin(); it != listeEtudiantA.cend(); it++) {
        stringstream << (*it)->getLogin() << std::endl;
    }
    return stringstream.str();
}

std::string Cours::afficherListesEtudiants() {
    std::stringstream stringstream;
    bool resteP = true;
    bool resteA = true;
    auto itP = listeEtudiantP.cbegin();
    auto itA = listeEtudiantA.cbegin();
    while (resteP || resteA) {
        // Parcours et affichage de la liste principale
        if (itP != listeEtudiantP.cend()) {
            stringstream << "p : "<< (*itP)->getLogin();
            itP++;
        } else
            resteP = false;
        stringstream << "\t" << std::endl;

        // Parcours et affichage de la liste d'attente
        if (itA != listeEtudiantA.cend()) {
            stringstream << "a : " << (*itA)->getLogin();
            itA++;
        } else
            resteA = false;
        stringstream << std::endl;
    }
    return stringstream.str();
}
