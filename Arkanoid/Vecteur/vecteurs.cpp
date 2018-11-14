#include "vecteurs.hpp"

double Vecteur::operator[](size_t i) const 
{ 
	return elems[i]; 
}
double & Vecteur::operator[](size_t i) 
{ 
	return elems[i]; 
}

//la taille du vecteur
size_t Vecteur::size() const               
{ 
	return elems.size(); 
}

//constructeurs
Vecteur::Vecteur(size_t n) : elems(n) 
{}
Vecteur::Vecteur(std::initializer_list<double>init)
{
	for(auto i:init)
	{
		elems.push_back(i);
	}
}

