#ifndef RESSOURCE_H
#define RESSOURCE_H


class Ressource {

private :
    std::string type;
    std::string path;
public:
    Ressource(std::string type, std::string path) : type(type), path(path){}

    std::string getType(){ return type; }

    std::string getPath(){ return path; }

};

#endif // RESSOURCE_H
