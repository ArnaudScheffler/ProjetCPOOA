/*
 * \file Admin.hpp
 *
 * \date 30 nov. 2017
 * \author EVA
 */

#ifndef ADMIN_HPP_
#define ADMIN_HPP_

#include "Etudiant.hpp"
#include "Cours.hpp"

/**
 *\class Admin
 */
class Admin : public Enseignant {

private:

public:
  /**
   *\fn Admin
   *\brief Constructeur de l'objet Admin
   *\param login Login de l'admin
   *\param motDePasse Mot de passe de l'admin
   */
  Admin(std::string login,std::string motDePasse) : Enseignant(login,motDePasse) {}
  /**
   *\fn void validerCours(Cours &c)
   *\brief Permet a l'admin de valider un cours
   *\param c Cours a valider par l'admin
   */
  void validerCours(Cours &c){
    c.setValidation(true);
  }
