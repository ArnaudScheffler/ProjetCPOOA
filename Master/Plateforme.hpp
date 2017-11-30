/*
 * \file Plateforme.hpp
 *
 * \date 17 nov. 2017
 * \author EVA
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
 *\class Plateform
 *
 */
class Plateforme {

private:
	std::map<std::string, Cours*> mapCours;
	std::map<std::string, Etudiant*> mapEtudiant;
	std::map<std::string, Enseignant*> mapEnseignant;

public:

    /**
     *\fn Plateform()
     *\brief Constructeur de plateforme
     *
     */
	Plateforme() {}

    /**
     *\fn void addCours(Cours& c)
     *\brief Fonction d'ajout d'un cours a la liste de cours de la plateforme
     *\param c Le cours a ajouter a la liste
     *
     */
	void addCours(Cours& c) { mapCours.insert(std::make_pair(c.getNom(), &c)); }

    bool containsCours(std::string login) { return !(mapCours.find(login) == mapCours.end()); }

    /**
     *\fn Cours& getCoursParNom(const std::string nom)
     *\brief Retourne l'objet cours depuis son nom
     *\param nom Le nom du cours recherché
     *\return Cours&
     *
     */
    Cours& getCoursParNom(const std::string nom) { return *mapCours[nom]; }

    /**
     *\fn std::map<std::string, Cours*>::iterator getPremierCours()
     *\brief Renvoie un iterateur sur la liste de cours depuis le premier element
     *\return std::map<std::string, Cours*>::iterator
     *
     */
    std::map<std::string, Cours*>::iterator getPremierCours() { return mapCours.begin(); }

    /**
     *\fn std::map<std::string, Cours*>::iterator getDernierCours()
     *\brief Renvoie un iterateur sur la liste de cours depuis le dernier element
     *\return std::map<std::string, Cours*>::iterator
     *
     */
    std::map<std::string, Cours*>::iterator getDernierCours() { return mapCours.end(); }

    /**
     *\fn std::string afficherCours()
     *\brief Renvoie un string contenant tous les cours de la plateforme
     *\return std::string
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
     *\fn void addEtudiant(Etudiant& e)
     *\brief Ajoute un etudiant la plateforme
     *\param e L'etudiant a ajouter a la plateforme
     *
     */
	void addEtudiant(Etudiant& e) { mapEtudiant.insert(std::make_pair(e.getLogin(), &e)); }

    bool containsEtudiant(std::string login) { return !(mapEtudiant.find(login) == mapEtudiant.end()); }

    /**
     *\fn Etudiant& getEtudiantParLogin(const std::string login)
     *\brief Renvoie l'etudiant a partir de son login
     *\param login Login de l'etudiant recherche
     *\return Etudiant&
     *
     */
	Etudiant& getEtudiantParLogin(const std::string login) { return *mapEtudiant[login]; }

    /**
     *\fn std::string afficherEtudiant()
     *\brief Renvoie un string contenant tous les etudiants de la plateforme
     *\return std::string
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
     *\fn void addEnseignant(Enseignant& e)
     *\brief Permet d'ajouter un enseignant a la liste de la plateforme
     *\param e Enseignant a ajouter a la plateforme
     *
     */
	void addEnseignant(Enseignant& e) { mapEnseignant.insert(std::make_pair(e.getLogin(), &e)); }

    bool containsEnseignant(std::string login) { return !(mapEnseignant.find(login) == mapEnseignant.end()); }

    /**
     *\fn Enseignant& getEnseignantparLogin(const std::string login)
     *\brief Renvoie un enseignant a partir de son login
     *\param login Login de l'enseignant recherche
     *\return Enseignant&
     *
     */
	Enseignant& getEnseignantparLogin(const std::string login) { return *mapEnseignant[login]; }

    /**
     *\fn std::string afficherEnseignant()
     *\brief Renvoie un string contenant tous les enseignant de la plateforme
     *\return std::string
     *
     */
	std::string afficherEnseignant() {
		std::stringstream stringstream;
		for(std::map<std::string, Enseignant*>::iterator it = mapEnseignant.begin(); it != mapEnseignant.end(); it++) {
            stringstream << (*it).second->getLogin() << std::endl;
		}
		return stringstream.str();
	}

    void vider(){
//        for(std::map<std::string, Enseignant*>::iterator it = mapEnseignant.begin(); it != mapEnseignant.end(); it++) {
//            delete &it;
//        }
//        for(std::map<std::string, Cours*>::iterator it = mapCours.begin(); it != mapCours.end(); it++) {
//            delete &it;
//        }
        for(std::map<std::string, Etudiant*>::iterator it = mapEtudiant.begin(); it != mapEtudiant.end(); it++) {
            std::cout << "Suppression : " << (*it).second->getLogin() << std::endl;
            delete (*it).second;
        }
    }

    ~Plateforme() {
        vider();
    }
};



#endif /* PLATEFORME_HPP_ */
