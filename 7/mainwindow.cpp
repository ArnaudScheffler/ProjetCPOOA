#include <QtDebug>
#include <QStringListModel>

#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, Plateforme &p) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    adapter(p)
{
    ui->setupUi(this);
    //évite de nous retrouver sur le mauvais widget a cause de l'uidesigner
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::seConnecter()
{
    // Récupère les données des champs
    std::string login = ui->lineLogin->text().toStdString();
    std::string mdp = ui->lineMdp->text().toStdString();

    // Affiche la vue
    connexion(login, mdp);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_buttonDeconnexion_clicked()
{
    etudiantConnecte = nullptr;
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_actionexit_triggered()
{
    close();
}

void MainWindow::on_pushButtonAccueil_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButtonAccueil_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_listCoursSuivis_doubleClicked(const QModelIndex &index)
{
    // On récupère le nom du cours en fonction de l'index
    QString nomCours = listeModelCoursSuivis.data(index,0).toString();
    afficherCours(nomCours);
}


void MainWindow::on_listCours_doubleClicked(const QModelIndex &index)
{
    //Recupere le nom du cours
    QString nomCours = listeModelCours.data(index,0).toString();
    afficherCours(nomCours);
}

void MainWindow::on_SeDesinscrire_clicked()
{
    //Desinscrit l'étudiant
    etudiantConnecte->desinscrire(*coursSelectionne);

    //Met a jour ses logins
    listeModelCoursSuivis.setStringList(adapter.ListeCoursSuivis(*etudiantConnecte));
    ui->listCoursSuivis->setModel(&listeModelCoursSuivis);

    //remet sur la bonne page
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_inscrirecours_clicked()
{
    //Inscrit l'étudiant
    if(!etudiantConnecte->isInscrit(*coursSelectionne)){
        etudiantConnecte->inscrire(*coursSelectionne);
        listeModelCoursSuivis.setStringList(adapter.ListeCoursSuivis(*etudiantConnecte));
        ui->listCoursSuivis->setModel(&listeModelCoursSuivis);
    }

    //remet sur la bonne page
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButtonInscription_clicked()
{
    std::string login = ui->lineLoginInscription->text().toStdString();
    std::string mdp = ui->lineMdpInscription->text().toStdString();
    int role = ui->comboBoxTypeCompte->currentIndex();

    // Créer un utilisateur avec les données renseignées
    adapter.getPF().sInscrire(login, mdp, role);

    // Affiche la vue
    connexion(login, mdp);
}

void MainWindow::on_validationCours_stateChanged()
{
    if(ui->validationCours->isChecked())
        coursSelectionne->setValidation(true);

    majListes();
}

void MainWindow::afficherCours(QString nomCours){

    // On enlève le " (à valider)" pour retrouver le cours dans la plateforme
    if (nomCours.contains(" (à valider)"))
        nomCours.chop(12);

    coursSelectionne = &(adapter.getPF().getCoursParNom(nomCours.toStdString()));

    //propre aux Admins
    if(adapter.getPF().isGranted(etudiantConnecte->getLogin(),ROLE_ADMIN)){
        ui->validationCours->show();
        if(coursSelectionne->getStatus()){
            ui->validationCours->setChecked(true);
            ui->validationCours->setEnabled(false);
        }else{
            ui->validationCours->setChecked(false);
            ui->validationCours->setEnabled(true);
        }
    }else{
        ui->validationCours->hide();
    }
    // Donne le nom du cours au label
    QString labelText = "Cours : " + nomCours;
    ui->labelNomCours->setText(labelText);

    // Affiche le nom de l'enseignant
    QString labelNomEnseignant = "Enseignant : " + QString::fromStdString(coursSelectionne->getLoginEnseignant());
    ui->label_NomEnseigant->setText(labelNomEnseignant);

    // Affiche la liste des ressources
    if (etudiantConnecte->isInscrit(*coursSelectionne)){
        listeModelRessources.setStringList(adapter.mapRessourceToQStringList(coursSelectionne->getRessources()));
        ui->listRessources->setModel(&listeModelRessources);
        ui->labelpasinscrit->hide();
        ui->inscrirecours->hide();
        ui->listRessources->show();
        ui->label_6->show();
        ui->SeDesinscrire->show();
    }else{
        ui->listRessources->hide();
        ui->label_6->hide();
        ui->labelpasinscrit->show();
        ui->inscrirecours->show();
        ui->SeDesinscrire->hide();
    }

    // Affiche la liste principale des étudiants
    listeModelEtudiantsPrincipal.setStringList(adapter.ListeEtudiantToQStringList(coursSelectionne->getListeEtudiantP()));
    ui->listPrincipaleEtudiant->setModel(&listeModelEtudiantsPrincipal);

    // Affiche la liste d'attente des étudiants
    listeModelEtudiantsSecondaire.setStringList(adapter.ListeEtudiantToQStringList(coursSelectionne->getListeEtudiantA()));
    ui->listAttenteEtudiant->setModel(&listeModelEtudiantsSecondaire);

    // Affiche le nombre de place
    labelText = QString("Nombre de places : %1").arg(coursSelectionne->getNbPlace());
    ui->labelNombrePlace->setText(labelText);

    // Affiche la bonne page
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::connexion(std::string login, std::string mdp)
{
    if (adapter.getPF().seConnecter(login,mdp)) {

        // Récupère l'user
        etudiantConnecte = &(adapter.getPF().getEtudiantParLogin(login));

        // Vide les champs de la première page
        ui->lineLogin->setText("");
        ui->lineLoginInscription->setText("");
        ui->lineMdp->setText("");
        ui->lineMdpInscription->setText("");

        // Affiche un message de bienvenue
        QString home = QString::fromStdString("Bienvenue " + login + " !");
        ui->label_3->setText(home);

        // Actualise les listes de cours
        majListes();

        // Passe à la page suivante
        ui->stackedWidget->setCurrentIndex(1);
    } else {
        QMessageBox::critical(this, tr("Erreur"), tr("Login ou mot de passe incorrect"));
    }
}

void MainWindow::majListes()
{
    // Afficher les cours suivis
    listeModelCoursSuivis.setStringList(adapter.ListeCoursSuivis(*etudiantConnecte));
    ui->listCoursSuivis->setModel(&listeModelCoursSuivis);

    // Affiche la liste des cours validés si non admin et tous sinon
    if (adapter.getPF().isGranted(etudiantConnecte->getLogin(), ROLE_ADMIN)) {
        listeModelCours.setStringList(adapter.ListeCoursPourAdmin());
    }
    else
        listeModelCours.setStringList(adapter.ListeCoursValide());
    ui->listCours->setModel(&listeModelCours);

    // Affiche la liste des cours proposés si l'utilisateur est enseignant
    if (adapter.getPF().isGranted(etudiantConnecte->getLogin(), ROLE_ENSEIGN)) {
        // Cast l'étudiant en enseigant (car on a vérifé son role)
        listeModelCoursPropose.setStringList(adapter.ListeCoursPropose( *(Enseignant*)etudiantConnecte ));
        ui->listViewCoursPropose->setModel(&listeModelCoursPropose);
        // Affiche le widget liste et le label
        ui->listViewCoursPropose->setVisible(true);
        ui->label_CoursPropose->setVisible(true);
        ui->buttonProposerCoursAccueil->setVisible(true);
    } else {
        // Cache le widget liste, label et bouton pour les cours proposés
        ui->listViewCoursPropose->setVisible(false);
        ui->label_CoursPropose->setVisible(false);
        ui->buttonProposerCoursAccueil->setVisible(false);
    }
}

void MainWindow::on_buttonProposerCoursAccueil_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButtonProposerCours_clicked()
{
    // Récupération des données du formulaire
    std::string nomCours = ui->lineEditNomCoursPropose->text().toStdString();
    std::string date_debut = ui->dateEdit_debut->date().toString().toStdString();
    std::string date_fin = ui->dateEdit_fin->date().toString().toStdString();
    std::string date_fin_i = ui->dateEdit_fin_i->date().toString().toStdString();
    int nbPlace = ui->spinBox_nbEtu->value();
    Enseignant *e = (Enseignant*)etudiantConnecte;

    // Création du cours
    adapter.getPF().proposerUnCours(*e, nomCours, date_debut, date_fin, date_fin_i, nbPlace);

    // Affichage de la page
    majListes();
    ui->stackedWidget->setCurrentIndex(1);
}
