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
#include "Admin.hpp"

/**
 * @class Plateforme
 *
 */
class Plateforme {

private:
	std::map<std::string, Cours*> mapCours;
	std::map<std::string, Etudiant*> mapEtudiant;
	std::map<std::string, Enseignant*> mapEnseignant;
	std::map<std::string, Admin*> mapAdmin;

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
	 * @brief Fonction test existence d'un cours
	 * @param nom le nom du cours
	 * @return true si le cours existe, false sinon
	 * @version 3
	 *
	 */
	bool containsCours(std::string nom) { return !(mapCours.find(nom) == mapCours.end()); }

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
			stringstream <<"Nom : " << (*it).second->getNom() <<" Auteur : " << (*it).second->getLoginEnseignant() << " Valide : " << (*it).second->getStatus()  << std::endl;
		}
		return stringstream.str();
	}

	/**
	 * @brief afficherCoursInvalide
	 * @return std::string avec les cours non validés
	 * @version 3
	 */
	std::string afficherCoursInvalide() {
		std::stringstream stringstream;
		for(std::map<std::string, Cours*>::iterator it = mapCours.begin(); it != mapCours.end(); it++) {
			if( !((*it).second->getStatus()) ){
				stringstream << (*it).second->getNom() <<" Auteur : " << (*it).second->getLoginEnseignant() << std::endl;
			}
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
	 * @brief Fonction test existence d'un étudiant
	 * @param login le login de l'étudiant
	 * @return true si l'étudiant existe, false sinon
	 * @version 3
	 *
	 */
	bool containsEtudiant(std::string login) { return !(mapEtudiant.find(login) == mapEtudiant.end()); }

	/**
	 * @brief Renvoie l'etudiant à partir de son login
	 * @param login Login de l'etudiant recherche
	 * @return Etudiant&
	 * @version 1
	 *
	 */
	Etudiant& getEtudiantParLogin(const std::string login) { return *mapEtudiant[login]; }

	/**
	 * @brief Renvoie un string contenant tous les etudiants de la plateforme
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
	 * @brief Fonction test existence d'un enseigant
	 * @param login le login de l'enseigant
	 * @return true si l'enseigant existe, false sinon
	 * @version 3
	 *
	 */
	bool containsEnseignant(std::string login) { return !(mapEnseignant.find(login) == mapEnseignant.end()); }

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


	/**
	 * @brief Permet d'ajouter un administrateur à la liste de la plateforme
	 * @param a administrateur à ajouter à la plateforme
	 * @version 1
	 *
	 */
	void addAdmin(Admin& a){ mapAdmin.insert(std::make_pair(a.getLogin(), &a)); }

	/**
	 * @brief containsAdmin
	 * @param login
	 * @return true si l'admin existe
	 * @version 3
	 */
	bool containsAdmin(std::string login) { return !(mapAdmin.find(login) == mapAdmin.end()); }

	/**
	 * @brief Renvoie un Admin a partir de son login
	 * @param login Login de l'admin recherche
	 * @return Admin&
	 * @version 3
	 *
	 */
	Admin& getAdminparLogin(const std::string login) { return *mapAdmin[login]; }

	/**
	 * @brief Renvoie un string contenant tous les Admin de la plateforme
	 * @return std::string
	 * @version 3
	 *
	 */
	std::string afficherAdmin() {
		std::stringstream stringstream;
		for(std::map<std::string, Admin*>::iterator it = mapAdmin.begin(); it != mapAdmin.end(); it++) {
			stringstream << (*it).second->getLogin() << std::endl;
		}
		return stringstream.str();
	}

	/**
	 * @brief Vide les listes en supprimant correctement tous les éléments
	 * @version 3
	 */
	void vider() {
		for(std::map<std::string, Admin*>::iterator it = mapAdmin.begin(); it != mapAdmin.end(); it++) {
			delete it->second;
		}
		for(std::map<std::string, Enseignant*>::iterator it = mapEnseignant.begin(); it != mapEnseignant.end(); it++) {
			delete it->second;
		}
		for(std::map<std::string, Cours*>::iterator it = mapCours.begin(); it != mapCours.end(); it++) {
			delete it->second;
		}
		for(std::map<std::string, Etudiant*>::iterator it = mapEtudiant.begin(); it != mapEtudiant.end(); it++) {
			delete it->second;
		}
	}

    /**
     * @brief Destructeur de Plateforme, appelle la fonction vider()
     *
     */
	~Plateforme() {
		vider();
	}
};



#endif /* PLATEFORME_HPP_ */
