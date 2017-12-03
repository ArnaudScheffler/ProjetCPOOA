/*
 * @file Cours.hpp
 *
 * @date 1 nov. 2017
 * @author EVA
 */

#ifndef COURS_HPP_
#define COURS_HPP_

#include <iostream>
#include <list>

// Classes définies ici pour éviter l'inclusion circulaire
class Enseignant;
class Etudiant;

/**
 * @class Cours
 */
class Cours {

private:
	std::string nom;
	std::string dateDebut;
	std::string dateFin;
	std::string dateFinInscription;
	int nbPlace;
	Enseignant* enseignant;
	std::list<Etudiant*> listeEtudiant;

public:

	/**
	 * @brief Constructeur de l'objet Cours
	 * @param nom Le nom du cours
	 * @param dateDebut Date de commencement du cours
	 * @param dateFin Date de fin du cours
	 * @param dateFinInscription Date de fin d'inscription au cours
	 * @param nbPlace Nombre de place disponible pour le cours
	 * @version 1
	 *
	 */
	Cours(std::string nom, std::string dateDebut, std::string dateFin, std::string dateFinInscription, int nbPlace)
		: nom(nom), dateDebut(dateDebut), dateFin(dateFin), dateFinInscription(dateFinInscription), nbPlace(nbPlace), enseignant(NULL) {}

	/**
	 * @brief Renvoie le nom du cours
	 * @return std::string
	 * @version 1
	 *
	 */
	std::string getNom() { return nom; }

	/**
	 * @brief Defini l'enseignant responsable du cours
	 * @param e L'enseignant qui deviendra responsable
	 * @version 1
	 *
	 */
	void setEnseignant(Enseignant& e) { enseignant = &e; }

	/**
	 * @brief Renvoie l'enseigant responsable du cours
	 * @return Enseignant&
	 * @version 1
	 *
	 */
	Enseignant& getEnseignant() { return *enseignant ;}

	/**
	 * @brief Renvoie le login de l'enseigant responsable du cours
	 * @return const std::string
	 * @version 1
	 *
	 */
	const std::string getLoginEnseignant();

	/**
	 * @brief Renvoie la liste des etudiant sur la liste principale d'inscription au cours
	 * @return std::list<Etudiant*>
	 * @version 1
	 *
	 */
	std::list<Etudiant*> getListeEtudiantP() { return listeEtudiant; }

	/**
	 * @brief Ajoute un etudiant a la liste principale/attente
	 * @param etu Etudiant devant etre ajouter a la liste
	 * @version 1
	 *
	 */
	void addEtudiantP(Etudiant& etu){ listeEtudiant.push_back(&etu); }

	/**
	 * @brief Redefinition de l'operateur == pour pouvoir l'utiliser sur des cours, utile pour list.remove
	 * par exemple
	 * @return bool
	 * @version 1
	 */
	bool operator==( const Cours& test ) const {
		return this->nom == test.nom;
	}
};

#endif /* COURS_HPP_ */
