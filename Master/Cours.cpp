/*
 * \file Cours.cpp
 *
 * \date 11 nov. 2017
 * \author EVA
 */

#include "Cours.hpp"
#include "Enseignant.hpp"

const std::string Cours::getLoginEnseignant() {
	return enseignant->getLogin();
}
