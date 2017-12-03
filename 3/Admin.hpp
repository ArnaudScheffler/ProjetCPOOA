/*
 * @file Admin.hpp
 *
 * @date 30 nov. 2017
 * @author EVA
 */

#ifndef ADMIN_HPP_
#define ADMIN_HPP_

#include "Etudiant.hpp"
#include "Cours.hpp"

/**
 * @class Admin
 */
class Admin : public Enseignant {

private:

public:

	/**
	 * @brief Constructeur de l'objet Admin
	 * @param login Login de l'admin
	 * @param motDePasse Mot de passe de l'admin
	 * @version 3
	 */
	Admin(std::string login,std::string motDePasse) : Enseignant(login,motDePasse) {}

	/**
	 * @brief Permet a l'admin de valider un cours
	 * @param c Cours a valider par l'admin
	 * @version 3
	 */
	void validerCours(Cours &c){
		c.setValidation(true);
	}

};
#endif /* COURS_HPP_ */
