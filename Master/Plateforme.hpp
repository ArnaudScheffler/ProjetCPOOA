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

#define ROLE_ADMIN 2
#define ROLE_ENSEIGN 1
#define ROLE_ETUD 0

/**
 * @class Plateforme
 *
 */
class Plateforme {

private:
	std::map<std::string, Cours*> mapCours;
    std::map<std::string, std::pair<int, Etudiant*>> mapUser;

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
     * @brief Inscrit un étudiant à un cours
     * @param nometud le nom de l'étudiant
     * @param nomCours nom du cours
     * @return int -1 si cours/etud absents -2 si cours invalide 0 si succes
     * @version 6
     */
    int inscrireEtudiantCours(std::string nometud, std::string nomCours){
        bool res = false;
        if (this->containsUser(nometud) && this->containsCours(nomCours)){
            Etudiant& etud = this->getEtudiantParLogin(nometud);
            Cours& cours = this->getCoursParNom(nomCours);
            if (cours.getStatus()){
                res = etud.inscrire(cours);
            }else res = -2;
        }else res = -1;

        return res;
    }

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
     * @brief Ajoute un user la plateforme
     * @param role Le type de compte (0: Etudiant, 1: Enseignant, 2: Admin)
	 * @param e L'etudiant à ajouter à la plateforme
     * @version 6
	 *
	 */
    void addUser(int role,Etudiant& e) {mapUser.insert(std::make_pair(e.getLogin(),std::make_pair(role,&e))); }

	/**
     * @brief Fonction test existence d'un user avec le bon role
     * @param login le login de l'user
     * @param role le role de l'user
	 * @return true si l'étudiant existe, false sinon
     * @version 6
	 *
	 */
    bool containsUser(std::string login) {
        return (mapUser.find(login) != mapUser.end()) ;
    }

    /**
     * @brief Fonction test du role d'un user
     * @param login le login de l'user
     * @param role le role de l'user
     * @return true si l'user a le bon role, false sinon
     * @version 6
     *
     */
    bool isGranted(std::string login,int role) {
        return (mapUser.find(login) != mapUser.end() && mapUser.find(login)->second.first >= role) ;
    }

    /**
     * @brief Renvoie l'Admin à partir de son login
     * @param login Login de l'user recherche
     * @return Admin&
     * @version 6
     *
     */
    Admin& getAdminParLogin(const std::string login) {
        return *(Admin*)mapUser[login].second;
    }

    /**
     * @brief Renvoie l'Enseignant à partir de son login
     * @param login Login de l'user recherche
     * @return Enseignant&
     * @version 6
     *
     */
    Enseignant& getEnseignantParLogin(const std::string login) {
        return *(Enseignant*)mapUser[login].second;
    }

	/**
     * @brief Renvoie l'User à partir de son login
     * @param login Login de l'user recherche
	 * @return Etudiant&
     * @version 6
	 *
	 */
    Etudiant& getEtudiantParLogin(const std::string login) {
        return *mapUser[login].second;
    }

	/**
     * @brief Renvoie un string contenant tous les user de la plateforme qui ont le bon role
	 * @return std::string
     * @version 6
	 *
	 */
    std::string afficherUser(int role) {
		std::stringstream stringstream;
        for(std::map<std::string, std::pair<int,Etudiant*>>::iterator it = mapUser.begin(); it != mapUser.end(); it++) {
           if ((*it).second.first == role){
                stringstream << (*it).second.second->getLogin() << std::endl;
           }
        }
		return stringstream.str();
	}

	/**
	 * @brief Vide les listes en supprimant correctement tous les éléments
     * @version 6
	 */
	void vider() {
        for(std::map<std::string, std::pair<int,Etudiant*>>::iterator it = mapUser.begin(); it != mapUser.end(); it++) {
            delete it->second.second;
		}
		for(std::map<std::string, Cours*>::iterator it = mapCours.begin(); it != mapCours.end(); it++) {
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
