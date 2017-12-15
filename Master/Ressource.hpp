#ifndef RESSOURCE_H
#define RESSOURCE_H


class Ressource {

private :
    std::string type;
    std::string path;

public:

    /**
     * @brief Ressource
     * @param type Type de la ressource
     * @param path Chemin d'acces vers la ressource
     */
    Ressource(std::string type, std::string path) : type(type), path(path){}

    /**
     * @brief getType
     * @return Le type de la ressource
     */
    std::string getType(){ return type; }

    /**
     * @brief getPath
     * @return Le chemin d'acces de la ressource
     */
    std::string getPath(){ return path; }

    /**
     * @brief Redefinition de l'operateur == pour pouvoir l'utiliser sur des ressources,
     * par exemple
     * @return bool
     * @version 5
     */
    bool operator==( const Ressource& test ) const {
        return this->path == test.path;
    }

};

#endif // RESSOURCE_H
