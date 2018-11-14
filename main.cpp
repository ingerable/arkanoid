#include "expressionDeVecteur.hpp"
#include "vecteurs.hpp"
#include "sommeDeVecteur.hpp"
#include "multiplicationDeVecteur.hpp"
#include "soustractionDeVecteur.hpp"
#include "negatifDeVecteur.hpp"
#include <iostream>
#include <memory>
//design pattern "factory" pour les briques (brique + ou - dure, bonus ou pas)
int main() //chapitre template
{
    //Vecteur v0 = {23.4,12.5,144.56,90.56};
    Vecteur v1 = {
		67.12,
		34.8,
		90.34,
		89.30
	};
    Vecteur v2 = {
		34.90,
		111.9,
		45.12,
		90.5
	};
    
    std::unique_ptr<Vecteur> v0 (new Vecteur{
		23.4,
		12.5,
		144.56,
		90.56
	}); //chapitre mémoire

    Vecteur somme = *v0+v1+v2;
    Vecteur mult = *v0*v1*v2;
    Vecteur sous = *v0-v1-v2;
    Vecteur neg = -*v0-v1-v2;

    for(int i=0;i<somme.size();++i)
    {
        std::cout << somme[i] << std::endl;
    }
    std::cout << std::endl;
    for(int i=0;i<mult.size();++i)
    {
        std::cout << mult[i] << std::endl;
    }
    std::cout << std::endl;
    for(int i=0;i<sous.size();++i)
    {
        std::cout << sous[i] << std::endl;
    }
    std::cout << std::endl;
    for(int i=0;i<neg.size();++i)
    {
        std::cout << neg[i] << std::endl;
    }
}
