
/*
 * \file Cours.hpp
 *
 * \date1 nov. 2017
 * \author EVA
 */

#ifndef COURS_HPP_
#define COURS_HPP_

#include <iostream>
#include <list>

class Enseignant; // Classe définies ici pour éviter l'inclusion circulaire
class Etudiant;

/**
 *\class Cours
 */
class Cours {

private:

  std::string nom; // Nom du cours
  std::string dateDebut;// Date de debut du cours
  std::string dateFin;// Date de fin du cours
  std::string dateFinInscription;// Date de fin des inscriptions
  int nbPlace;// Nombre de place disponible
  Enseignant* enseignant;//Enseignant responsable du cours
  std::list<Etudiant*> listeEtudiantP;
  std::list<Etudiant*> listeEtudiantA;
  bool validation;


public:
  /**
   *\fn Cours(std::string nom, std::string dateDebut, std::string dateFin, std::string dateFinInscription, int nbPlace)
   *\brief Constructeur de l'objet Cours
   *\param nom Le nom du cours
   *\param dateDebut Date de commencement du cours
   *\param dateFin Date de fin du cours
   *\param dateFinInscription Date de fin d'inscription au cours
   *\param nbPlace Nombre de place disponible pour le cours
   *
   */
	Cours(std::string nom, std::string dateDebut, std::string dateFin, std::string dateFinInscription, int nbPlace)
: nom(nom), dateDebut(dateDebut), dateFin(dateFin), dateFinInscription(dateFinInscription), nbPlace(nbPlace), enseignant(NULL) {
	  validation=false;
	}

  /**
   *\fn std::string getNom()
   *\brief Renvoie le nom du cours
   *\return std::string
   *
   */
	std::string getNom() { return nom; }
  /**
   *\fn void setEnseignant(Enseignant& e) 
   *\brief Defini l'enseignant responsable du cours
   *\param e L'enseignant qui deviendra responsable
   *
   *
   */

	void setEnseignant(Enseignant& e) { enseignant = &e; }
  /**
   *\fn Enseignant& getEnseignant()
   *\brief Renvoie l'enseigant responsable du cours
   *\return Enseignant&
   *
   */
	Enseignant& getEnseignant() { return *enseignant ;}

  /**
   *\fn const std::string getLoginEnseignant()
   *\brief Renvoie le login de l'enseigant responsable du cours
   *\return const std::string
   *
   */
  const std::string getLoginEnseignant();


  /**
   *\fn void removeEtudiant(Etudiant& etu)
   *\brief Supprime un etudiant a la liste principale/attente
   *\param etu Etudiant devant etre ajouter a la liste
   * \warning le remove ne fonctione pas mais le passage de principal à attente ok
   */
    void removeEtudiant(Etudiant& etu){
        listeEtudiantA.remove(&etu);
        listeEtudiantP.remove(&etu);
        if (listeEtudiantP.size() < (size_t)nbPlace){
            listeEtudiantP.push_back(*listeEtudiantA.begin());
        }
    }


    /**
     *\fn std::list<Etudiant*> getListeEtudiantP()
     *\brief Renvoie la liste des etudiant sur la liste principale d'inscription au cours
     *\return std::list<Etudiant*>
     *
     */
    std::list<Etudiant*> getListeEtudiantP() { return listeEtudiantP; }


    /**
     *\fn void addEtudiant(Etudiant& etu)
     *\brief Ajoute un etudiant a la liste principale/attente
     *\param etu Etudiant devant etre ajouter a la liste
     *
     */
    void addEtudiant(Etudiant& etu){
        if (listeEtudiantP.size() >= (size_t)nbPlace){
            listeEtudiantA.push_back(&etu);
        }else{
            listeEtudiantP.push_back(&etu);
        }
    }

  /**
   *\fn void setValidation(bool b)
   *\brief Setter pour l'attribut validation
   *\param b Valeur du boolean
   *
   */
  void setValidation(bool b){ validation=b; }
  
  /**
   *\fn bool operator==( const Cours& test ) const
   *\brief Redefinition de l'operateur == pour pouvoir l'utiliser sur des cours, utile pour list.remove
   * par exemple
   *\return bool
   */
    bool operator==( const Cours& test ) const {
        return this->nom == test.nom;
	}

    /**
     * \brief Affiche les étudiants des deux listes (principale et attente)
     * \return std::string
     */
    std::string afficherListesEtudiants();

    /**
     * @brief Permet d'afficher tous les étudiants de la liste principale
     * @return La liste des étudiants en liste principale
     */
    std::string afficherListeP();

    /**
     * @brief Permet d'afficher tous les étudiants de la liste d'attente
     * @return La liste des étudiants en liste d'attente
     */
    std::string afficherListeA();
};

#endif /* COURS_HPP_ */
