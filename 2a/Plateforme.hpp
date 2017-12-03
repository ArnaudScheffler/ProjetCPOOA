/*
 * @file Plateforme.hpp
 *
 * @date 17 nov. 2017
 * @author EVA
 */

#ifndef PLATEFORME_HPP_
#define PLATEFORME_HPP_

#include <iostream>
#include <list>
#include <utility>
#include <map>


#include "Cours.hpp"
#include "Enseignant.hpp"

/**
 * @class Plateforme
 *
 */
class Plateforme {

private:
	std::map<std::string, Cours*> mapCours;
	std::map<std::string, Etudiant*> mapEtudiant;
	std::map<std::string, Enseignant*> mapEnseignant;

public:

	/**
	 * @brief Constructeur de plateforme (qui ne fait rien)
	 * @version 1
	 *
	 */
	Plateforme() {}

	/**
	 * @brief Fonction d'ajout d'un cours à la liste de cours de la plateforme
	 * @param c Le cours a ajouter a la liste
	 * @version 1
	 *
	 */
	void addCours(Cours& c) { mapCours.insert(std::make_pair(c.getNom(), &c)); }

	/**
	 * @brief Retourne l'objet cours depuis son nom
	 * @param nom Le nom du cours recherché
	 * @return Cours&
	 * @version 1
	 *
	 */
	Cours& getCoursParNom(const std::string nom) { return *mapCours[nom]; }

	/**
	 * @brief Renvoie un iterateur sur le permier élément de la liste de cours
	 * @return std::map<std::string, Cours*>::iterator
	 * @version 1
	 *
	 */
	std::map<std::string, Cours*>::iterator getPremierCours() { return mapCours.begin(); }

	/**
	 * @brief Renvoie un iterateur sur la liste de cours depuis le dernier element
	 * @return std::map<std::string, Cours*>::iterator
	 * @version 1
	 */
	std::map<std::string, Cours*>::iterator getDernierCours() { return mapCours.end(); }


	/**
	 * @brief Renvoie un string contenant tous les cours de la plateforme
	 * @return std::string
	 * @version 1
	 *
	 */
	std::string afficherCours() {
		std::stringstream stringstream;
		for(std::map<std::string, Cours*>::iterator it = mapCours.begin(); it != mapCours.end(); it++) {
			stringstream << (*it).second->getNom() <<" Auteur : " << (*it).second->getLoginEnseignant() << std::endl;
		}
		return stringstream.str();
	}

	/**
	 * @brief Ajoute un etudiant la plateforme
	 * @param e L'etudiant à ajouter à la plateforme
	 * @version 1
	 *
	 */
	void addEtudiant(Etudiant& e) { mapEtudiant.insert(std::make_pair(e.getLogin(), &e)); }

	/**
	 * @brief Renvoie l'etudiant à partir de son login
	 * @param login Login de l'etudiant recherche
	 * @return Etudiant&
	 * @version 1
	 *
	 */
	Etudiant& getEtudiantParLogin(const std::string login) { return *mapEtudiant[login]; }

	/**
	 * @brief Renvoie un string contenant tous les étudiants de la plateforme
	 * @return std::string
	 * @version 1
	 *
	 */
	std::string afficherEtudiant() {
		std::stringstream stringstream;
		for(std::map<std::string, Etudiant*>::iterator it = mapEtudiant.begin(); it != mapEtudiant.end(); it++) {
			stringstream << (*it).second->getLogin() << std::endl;
		}
		return stringstream.str();
	}

	/**
	 * @brief Permet d'ajouter un enseignant a la liste de la plateforme
	 * @param e Enseignant a ajouter a la plateforme
	 * @version 1
	 *
	 */
	void addEnseignant(Enseignant& e) { mapEnseignant.insert(std::make_pair(e.getLogin(), &e)); }

	/**
	 * @brief Renvoie un enseignant a partir de son login
	 * @param login Login de l'enseignant recherche
	 * @return Enseignant&
	 * @version 1
	 *
	 */
	Enseignant& getEnseignantparLogin(const std::string login) { return *mapEnseignant[login]; }

	/**
	 * @brief Renvoie un string contenant tous les enseignant de la plateforme
	 * @return std::string
	 * @version 1
	 *
	 */
	std::string afficherEnseignant() {
		std::stringstream stringstream;
		for(std::map<std::string, Enseignant*>::iterator it = mapEnseignant.begin(); it != mapEnseignant.end(); it++) {
			stringstream << (*it).second->getLogin() << std::endl;
		}
		return stringstream.str();
	}
};



#endif /* PLATEFORME_HPP_ */
