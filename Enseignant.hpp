/*
 * Enseignant.hpp
 *
 *  Created on: 6 nov. 2017
 *      Author: Arnaud
 */

#ifndef ENSEIGNANT_HPP_
#define ENSEIGNANT_HPP_

#include "Etudiant.hpp"

class Enseignant : public Etudiant {

public:
	Enseignant(std::string login, std::string motDePasse) : Etudiant(login, motDePasse) {};
	void proposerUnCours(std::string titre) {

	};

};



#endif /* ENSEIGNANT_HPP_ */
