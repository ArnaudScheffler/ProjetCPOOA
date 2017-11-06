/*
 * main.cpp
 *
 *  Created on: 1 nov. 2017
 *      Author: Arnaud
 */

#include "Cours.hpp"

int main(int argc, char **argv) {
	Cours c1 = Cours("Anglais");
	Cours c2 = Cours("CPOOA");

	std::cout << c1.getTitre() << c2.getTitre() << std::endl;
}
