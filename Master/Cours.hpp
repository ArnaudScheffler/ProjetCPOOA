
/*
 * Cours.hpp
 *
 *  Created on: 1 nov. 2017
 *      Author: EVA
 */

#ifndef COURS_HPP_
#define COURS_HPP_

#include <iostream>
#include <list>

class Enseignant;
class Etudiant;

class Cours {

private:
	std::string nom;
	std::string dateDebut;
	std::string dateFin;
	std::string dateFinInscription;
	int nbPlace;
	Enseignant* enseignant;
    std::list<Etudiant*> listeEtudiantP;
    std::list<Etudiant*> listeEtudiantA;

public:
	// Vérifier la passage par référence
	Cours(std::string nom, std::string dateDebut, std::string dateFin, std::string dateFinInscription, int nbPlace)
: nom(nom), dateDebut(dateDebut), dateFin(dateFin), dateFinInscription(dateFinInscription), nbPlace(nbPlace), enseignant(NULL) {}

	std::string getNom() { return nom; }
	void setEnseignant(Enseignant& e) { enseignant = &e; }
	Enseignant& getEnseignant() { return *enseignant ;}

	const std::string getLoginEnseignant();
    std::list<Etudiant*> getListeEtudiantP() { return listeEtudiantP; }
    void addEtudiant(Etudiant& etu){
        if (listeEtudiantP.size() >= (size_t)nbPlace){
            listeEtudiantA.push_back(&etu);
        }else{
            listeEtudiantP.push_back(&etu);
        }
    }
    void removeEtudiant(Etudiant& etu){
        listeEtudiantA.remove(&etu);
        listeEtudiantP.remove(&etu);
        if (listeEtudiantP.size() < (size_t)nbPlace){
            listeEtudiantP.push_back(*listeEtudiantA.begin());
        }
    }

    //Pour utiliser liste.remove on doit définir un opérateur d'égalité pour nos classes
    bool operator==( const Cours& test ) const {
        return this->nom == test.nom;
	}
};

#endif /* COURS_HPP_ */
