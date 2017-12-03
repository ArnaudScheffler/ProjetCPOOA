/*
 * @file Enseignant.hpp
 *
 * @date 6 nov. 2017
 * @author EVA
 */

#ifndef ENSEIGNANT_HPP_
#define ENSEIGNANT_HPP_

#include "Etudiant.hpp"
#include "Cours.hpp"

/**
 * @class Enseignant
 */
class Enseignant : public Etudiant {

private:
		std::list<Cours*> listeCoursPropose;

public:

	/**
	 * @fn Enseignant(std::string login, std::string motDePasse)
	 * @brief Constructeur de l'objet enseignant
	 * @param login Login de l'enseigant 
	 * @param motDePasse Mot de passe de l'enseignant
	 *
	 */
	Enseignant(std::string login, std::string motDePasse) : Etudiant(login, motDePasse) {}

	/**
	 * @fn void proposerUnCours(Cours& c)
	 * @brief Fonction qui permet a un enseignant de proposer un cours 
	 * @param c Le cours proposé par l'enseignant
	 *
	 */
	void proposerUnCours(Cours& c) { c.setEnseignant(*this); listeCoursPropose.push_back(&c); }

	/**
	 * @fn std::list<Cours*>::iterator getPremierCoursPropose()
	 * @brief Renvoie un iterateur sur les cours proposés depuis le premier element de la liste
	 * @return std::list<Cours*>::iterator
	 *
	 */
	std::list<Cours*>::iterator getPremierCoursPropose() { return listeCoursPropose.begin(); }
	
	/**
	 * @fn std::list<Cours*>::iterator getDernierCoursPropose()
	 * @brief Renvoie un iterateur sur les cours proposés depuis le dernier element de la liste
	 * @return std::list<Cours*>::iterator
	 *
	 */
	std::list<Cours*>::iterator getDernierCoursPropose() { return listeCoursPropose.end(); }

	/**
	 * @fn std::string afficherCoursPropose
	 * @brief Renvoie un string contenant tous les cours proposé par l'enseignant
	 * @return std::string
	 *
	 */
	std::string afficherCoursPropose(){
		std::stringstream stringstream;
		for(std::list<Cours*>::iterator it = getPremierCoursPropose(); it != getDernierCoursPropose(); it++) {
			stringstream << "Nom : " << (*it)->getNom() << std::endl;
		}
		return stringstream.str();
	}

};


#endif /* ENSEIGNANT_HPP_ */
