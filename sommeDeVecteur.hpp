#pragma once
#include <vector>
#include <cstddef>
#include <iostream>
#include <ostream>
#include <cassert>
#include "vecteurs.hpp"

/*
 * la somme de deux vecteurs
 */
template <typename E1, typename E2>
class SommeDeVecteurs : public ExpressionDeVecteur<SommeDeVecteurs<E1, E2> > 
{
    E1 const& _u;
    E2 const& _v;

    public:
        SommeDeVecteurs(E1 const& u, E2 const& v) : _u(u), _v(v) 
		{
			assert(u.size() == v.size());
		};
        
        //opérateur [] (accesseur)
        double operator[](size_t i) const
        { 
			return _u[i] + _v[i]; 
		}
        
        //la taille du vecteur
        size_t size() const
        { 
			return _v.size();
		}
};

/*
 * surcharge de l'operation +
 */
template <typename E1, typename E2>
SommeDeVecteurs<E1,E2>
operator+(E1 const& u, E2 const& v) 
{
   return SommeDeVecteurs<E1, E2>(u, v);
}
