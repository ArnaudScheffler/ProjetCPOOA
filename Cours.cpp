/*
 * Cours.cpp
 *
 *  Created on: 11 nov. 2017
 *      Author: EVA
 */

#include "Cours.hpp"
#include "Enseignant.hpp"

const std::string Cours::getLoginEnseignant() {
	return enseignant->getLogin();
}
