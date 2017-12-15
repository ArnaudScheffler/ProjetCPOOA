/*
 * @file Etudiant.hpp
 *
 * @date 6 nov. 2017
 * @author EVA
 */

#ifndef ETUDIANT_HPP_
#define ETUDIANT_HPP_

#include <iostream>
#include <list>
#include <sstream>
#include <string>

#include "Cours.hpp"

/**
 * @class Etudiant
 */
class Etudiant {

protected:
	std::string login;
	std::string motDePasse;
	std::list<Cours*> listeCours;

public:

	/**
	 * @brief Constructeur de l'objet Etudiant
	 * @param login 
	 * @param motDePasse
	 * @version 1
	 *
	 */
	Etudiant(std::string login, std::string motDePasse) : login(login), motDePasse(motDePasse) {}

	/**
	 * @brief Renvoie le login de l'etudiant
	 * @return const std::string
	 * @version 1
	 *
	 */
	const std::string getLogin() { return login; }

	/**
	 * @brief Renvoie le mot de passe de l'etudiant
	 * @return const std::string
	 * @version 1
	 *
	 */
	const std::string getMDP() { return motDePasse; }

	/**
	 * @brief Comparaison du mot de passe de l'etudiant et celui donné en parametre
	 * @param mdp Le mot de passe a verifier
	 * @return bool
	 * @version 1
	 *
	 */
	bool verifMDP(const std::string mdp) { return mdp.compare(motDePasse) == 0 ? true : false; }

	/**
	 * @brief Renvoie un iterateur sur les cours depuis le premier element de la liste
	 * @return std::list<Cours*>::iterator
	 * @version 1
	 *
	 */
	std::list<Cours*>::iterator getPremierCours() { return listeCours.begin(); }

	/**
	 * @brief Renvoie un iterateur sur les cours depuis le dernier element de la liste
	 * @return std::list<Cours*>::iterator
	 * @version 1
	 *
	 */
	std::list<Cours*>::iterator getDernierCours() { return listeCours.end(); }

    /**
     * @brief verifie si l'étudiant est inscrit.
     * @param c Le cours auquel l'etudiant veut s'inscrire
     * @version 7
     * @return return true si l'étudiant est déjà inscrit
     */
    bool isInscrit(Cours& c) {
        bool inscrit = false;
        for(std::list<Cours*>::iterator it = getPremierCours(); it != getDernierCours(); it++) {
            if( ((*it)->getNom()) == c.getNom() ){
                inscrit = true;
            }
        }
        return inscrit;
    }

	/**
	 * @brief Permet a un etudiant de s'inscrire a un cours
	 * @param c Le cours auquel l'etudiant veut s'inscrire
	 * @version 1
	 */
    void inscrire(Cours& c) {
        if(!isInscrit(c)){
			c.addEtudiant(*this);
			listeCours.push_back(&c);
		}
	}

	/**
	 * @brief Permet a un etudiant de se desinscrire d'un cours
	 * @param c Le cours auquel l'etudiant veut se desinscire
	 * @version 2a
	 *
	 */
    void desinscrire(Cours& c) { c.removeEtudiant(*this); listeCours.remove(&c); }

	/**
	 * @brief Renvoie un string qui contient tous les cours auquel l'etudiant est inscrit
	 * @return std::string
	 * @version 1
	 *
	 */
	std::string afficherCours(){
		std::stringstream stringstream;
		for(std::list<Cours*>::iterator it = getPremierCours(); it != getDernierCours(); it++) {
			stringstream << (*it)->getNom() <<" Auteur : " << (*it)->getLoginEnseignant() << std::endl;
		}
		return stringstream.str();
	}

    /**
     * @brief getListeCours Retourne la liste des étudiants
     * @return La liste des cours de l'étudiants
     * @version 6
     */
    std::list<Cours*> getListeCours() { return listeCours; }

	/**
	 * @brief Redefinition de l'operateur == pour pouvoir l'utiliser sur des etudiants (dans liste.remove par exemple)
	 * @return bool
	 * @version 1
	 *
	 */
	bool operator==( const Etudiant& test ) const  {
		bool res = false;
		if(this->login == test.login){
			res = true;
		}
		return res;
	}
};

#endif /* ETUDIANT_HPP_ */
