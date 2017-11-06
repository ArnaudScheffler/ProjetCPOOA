/*
 * Etudiant.hpp
 *
 *  Created on: 6 nov. 2017
 *      Author: Arnaud
 */

#ifndef ETUDIANT_HPP_
#define ETUDIANT_HPP_

#include <iostream>

class Etudiant {

private:
	std::string login;
	std::string motDePasse;

public:

	Etudiant(std::string login, std::string motDePasse) : login(login), motDePasse(motDePasse) {};
	std::string getLogin() {
		return login;
	}

	bool verifierMotDePasse(const std::string mdp) {
		return mdp.compare(motDePasse) == 0 ? true : false;
	}

};


#endif /* ETUDIANT_HPP_ */
