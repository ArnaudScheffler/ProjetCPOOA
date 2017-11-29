/*
 * Plateforme.hpp
 *
 *  Created on: 17 nov. 2017
 *      Author: EVA
 */

#ifndef PLATEFORME_HPP_
#define PLATEFORME_HPP_

#include <iostream>
#include <list>
#include <utility>
#include <map>


#include "Cours.hpp"
#include "Enseignant.hpp"

class Plateforme {

private:
	std::map<std::string, Cours*> mapCours;
	std::map<std::string, Etudiant*> mapEtudiant;
	std::map<std::string, Enseignant*> mapEnseignant;

public:
	Plateforme() {}

	void addCours(Cours& c) { mapCours.insert(std::make_pair(c.getNom(), &c)); }
	Cours& getCoursParNom(const std::string nom) { return *mapCours[nom]; }
    std::map<std::string, Cours*>::iterator getPremierCours() { return mapCours.begin(); }
    std::map<std::string, Cours*>::iterator getDernierCours() { return mapCours.end(); }
	std::string afficherCours() {
		std::stringstream stringstream;
		for(std::map<std::string, Cours*>::iterator it = mapCours.begin(); it != mapCours.end(); it++) {
            stringstream << (*it).second->getNom() <<" Auteur : " << (*it).second->getLoginEnseignant() << std::endl;
		}
		return stringstream.str();
	}

	void addEtudiant(Etudiant& e) { mapEtudiant.insert(std::make_pair(e.getLogin(), &e)); }
	Etudiant& getEtudiantParLogin(const std::string login) { return *mapEtudiant[login]; }
	std::string afficherEtudiant() {
		std::stringstream stringstream;
		for(std::map<std::string, Etudiant*>::iterator it = mapEtudiant.begin(); it != mapEtudiant.end(); it++) {
            stringstream << (*it).second->getLogin() << std::endl;
		}
		return stringstream.str();
	}

	void addEnseignant(Enseignant& e) { mapEnseignant.insert(std::make_pair(e.getLogin(), &e)); }
	Enseignant& getEnseignantparLogin(const std::string login) { return *mapEnseignant[login]; }
	std::string afficherEnseignant() {
		std::stringstream stringstream;
		for(std::map<std::string, Enseignant*>::iterator it = mapEnseignant.begin(); it != mapEnseignant.end(); it++) {
            stringstream << (*it).second->getLogin() << std::endl;
		}
		return stringstream.str();
	}
};



#endif /* PLATEFORME_HPP_ */
