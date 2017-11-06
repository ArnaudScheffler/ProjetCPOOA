/*
 * main.cpp
 *
 *  Created on: 1 nov. 2017
 *      Author: Arnaud
 */

#include <iostream>

#include "Cours.hpp"
#include "Enseignant.hpp"

int main(int argc, char **argv) {
	Cours c1 = Cours("Anglais");
	Cours c2 = Cours("CPOOA");

	std::cout << c1.getTitre() << std::endl << c2.getTitre() << std::endl;

	Enseignant en1 = Enseignant("Gautier", "pass");

	std::cout << en1.getLogin() << std::endl;
}
