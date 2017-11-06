/*
 * Cours.hpp
 *
 *  Created on: 1 nov. 2017
 *      Author: Arnaud
 */

#ifndef COURS_HPP_
#define COURS_HPP_

#include <iostream>

class Cours {

	std::string titre;

public:
	Cours() {}
	Cours(std::string t) : titre(t) {}

	std::string getTitre() { return titre; }


};

#endif /* COURS_HPP_ */
