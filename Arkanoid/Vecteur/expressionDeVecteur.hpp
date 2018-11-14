#pragma once
#include <vector>
#include <cstddef>
#include <iostream>
#include <ostream>
#include <cassert>

/*
 * représente l'expression d'un vecteur
 */
template <typename E>
class ExpressionDeVecteur
{
    public:
        //opérateur [] (accesseur)
		double operator[](size_t i) const 
		{ 
			return static_cast<E const&>(*this)[i];     
		}

		//la taille d'un vecteur
		size_t size() const 
		{ 
			return static_cast<E const&>(*this).size(); 
		}
};
