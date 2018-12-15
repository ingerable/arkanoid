#pragma once
#include <vector>
#include <cstddef>
#include <iostream>
#include <ostream>
#include <cassert>
#include <memory>
#include "expressionDeVecteur.hpp"
/*#include "sommeDeVecteur.hpp"
#include "multiplicationDeVecteur.hpp"
#include "soustractionDeVecteur.hpp"
#include "negatifDeVecteur.hpp"*/


/*
 * l'évaluation d'un vecteur (ses coordonnées)
 */
class Vecteur : public ExpressionDeVecteur<Vecteur>
{
	std::vector<double> elems;

	public:
        //opérateur [] (accesseur)
        double operator[](size_t i) const;
        double &operator[](size_t i);

        //la taille du vecteur
        size_t size() const;

        //constructeurs
        Vecteur(size_t n);
        Vecteur(std::initializer_list<double>init);
        template <typename E> Vecteur(ExpressionDeVecteur<E> const& vecteur) : elems(vecteur.size())
		{
			for (size_t i = 0; i != vecteur.size(); ++i)
			{
				elems[i] = vecteur[i];
			}
		}
};
