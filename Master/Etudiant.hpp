/*
 * \file Etudiant.hpp
 *
 * \date 6 nov. 2017
 * \author EVA
 */

#ifndef ETUDIANT_HPP_
#define ETUDIANT_HPP_

#include <iostream>
#include <list>
#include <sstream>
#include <string>

#include "Cours.hpp"

/**
 *\class Etudiant
 */
class Etudiant {

protected:
	std::string login;
	std::string motDePasse;
	std::list<Cours*> listeCours;

public:

  /**
   *\fn Etudiant(std::string login, std::string motDePasse)
   *\brief Constructeur de l'objet Etudiant
   *\param login 
   *\param motDePasse
   *
   */
    Etudiant(std::string login, std::string motDePasse) : login(login), motDePasse(motDePasse) {}

  /**
   *\fn const std::string getLogin()
   *\brief Renvoie le login de l'etudiant
   *\return const std::string
   *
   */
	const std::string getLogin() { return login; }

  /**
   *\fn const std::string getMDP()
   *\brief Renvoie le mot de passe de l'etudiant
   *\return const std::string
   *
   */
	const std::string getMDP() { return motDePasse; }

  /**
   *\fn	bool verifMDP(const std::string mdp)
   *\brief Comparaison du mot de passe de l'etudiant et celui donné en parametre
   *\param mdp Le mot de passe a verifier
   *\return bool
   *
   */
	bool verifMDP(const std::string mdp) { return mdp.compare(motDePasse) == 0 ? true : false; }

  /**
   *\fn std::list<Cours*>::iterator getPremierCours()
   *\brief Renvoie un iterateur sur les cours depuis le premier element de la liste
   *\return std::list<Cours*>::iterator
   *
   */
    std::list<Cours*>::iterator getPremierCours() { return listeCours.begin(); }

  /**
   *\fn std::list<Cours*>::iterator getDernierCours()
   *\brief Renvoie un iterateur sur les cours depuis le dernier element de la liste
   *\return std::list<Cours*>::iterator
   *
   */
    std::list<Cours*>::iterator getDernierCours() { return listeCours.end(); }

  /**
   *\fn void inscrire(Cours& c)
   *\brief Permet a un etudiant de s'inscrire a un cours
   *\param c Le cours auquel l'etudiant veut s'inscrire
   *
   */
    void inscrire(Cours& c) { c.addEtudiant(*this); listeCours.push_back(&c); }

  /**
   *\fn void desinscrire(Cours& c) 
   *\brief Permet a un etudiant de se desinscrire d'un cours
   *\param c Le cours auquel l'etudiant veut se desinscire 
   *
   */
    void desinscrire(Cours& c) { c.removeEtudiant(*this);listeCours.remove(&c); }

  /**
   *\fn	std::string afficherCours()
   *\brief Renvoie un string qui contient tous les cours auquel l'etudiant est inscrit
   *\return std::string
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
   *\fn bool operator==( const Etudiant& test ) const
   *\brief Redefinition de l'operateur == pour pouvoir l'utiliser sur des etudiants
   *\return bool
   *
   */
	//Pour utiliser liste.remove on doit déini un op?ateur d'éaglité pour nos classes
	bool operator==( const Etudiant& test ) const  {
		bool res = false;
		if(this->login == test.login){
			res = true;
		}
		return res;
	}
};


#endif /* ETUDIANT_HPP_ */
