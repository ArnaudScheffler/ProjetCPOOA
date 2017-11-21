/*
 * Enseignant.hpp
 *
 *  Created on: 6 nov. 2017
 *      Author: EVA
 */

#ifndef ENSEIGNANT_HPP_
#define ENSEIGNANT_HPP_

#include "Etudiant.hpp"
#include "Cours.hpp"


class Enseignant : public Etudiant {

private:
	std::list<Cours*> listeCoursPropose;

public:

	Enseignant(std::string login, std::string motDePasse) : Etudiant(login, motDePasse) {};
	void proposerUnCours(Cours& c) { c.setEnseignant(*this); listeCoursPropose.push_back(&c); };
	std::list<Cours*>::iterator getPremierCoursPropose() { return listeCoursPropose.begin(); };
	std::list<Cours*>::iterator getDernierCoursPropose() { return listeCoursPropose.end(); };
	std::string afficherCoursPropose(){
		std::stringstream stringstream;
		for(std::list<Cours*>::iterator it = getPremierCoursPropose(); it != getDernierCoursPropose(); it++) {
			stringstream << "Nom : " << (*it)->getNom() << std::endl;
		}
		return stringstream.str();
	}

};



#endif /* ENSEIGNANT_HPP_ */
