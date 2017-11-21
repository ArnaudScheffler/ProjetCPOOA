/*
 * Etudiant.hpp
 *
 *  Created on: 6 nov. 2017
 *      Author: EVA
 */

#ifndef ETUDIANT_HPP_
#define ETUDIANT_HPP_

#include <iostream>
#include <list>
#include <sstream>
#include <string>

#include "Cours.hpp"

class Etudiant {

protected:
	std::string login;
	std::string motDePasse;
	std::list<Cours*> listeCours;

public:
	Etudiant(std::string login, std::string motDePasse) : login(login), motDePasse(motDePasse) {};

	const std::string getLogin() { return login; }
	bool verifMDP(const std::string mdp) { return mdp.compare(motDePasse) == 0 ? true : false; }
	std::list<Cours*>::iterator getPremierCours() { return listeCours.begin(); };
	std::list<Cours*>::iterator getDernierCours() { return listeCours.end(); };
	void inscrire(Cours& c) { c.addEtudiantP(*this); listeCours.push_back(&c); };
	void desinscrire(Cours& c) { listeCours.remove(&c); };
	std::string afficherCours(){
		std::stringstream stringstream;
		for(std::list<Cours*>::iterator it = getPremierCours(); it != getDernierCours(); it++) {
			stringstream << "Nom : " << (*it)->getNom() <<" Auteur : " << (*it)->getLoginEnseignant() << std::endl;
		}
		return stringstream.str();
	}
	//Pour utiliser liste.remove on doit définir un opérateur d'égalitée pour nos classes
	bool operator==( const Etudiant& test ) const  {
		bool res = false;
		if(this->login == test.login){
			res = true;
		}
		return res;
	}
};


#endif /* ETUDIANT_HPP_ */
