#pragma once
#include <vector>
#include <cstddef>
#include <iostream>
#include <ostream>
#include <cassert>
#include "vecteurs.hpp"

/*
 * la soustraction de deux vecteurs
 */
template <typename E1, typename E2>
class SoustractionDeVecteur : public ExpressionDeVecteur<SoustractionDeVecteur<E1, E2> > 
{
    E1 const& _u;
    E2 const& _v;

    public:
        SoustractionDeVecteur(E1 const& u, E2 const& v) : _u(u), _v(v) 
        {
            assert(u.size() == v.size());
        }
        
        //opérateur [] (accesseur)
        double operator[](size_t i) const 
        { 
            return _u[i] - _v[i]; 
        }
        
        //la taille du vecteur
        size_t size() const 
        { 
            return _v.size();
        }
};

/*
 * surcharge de l'operation -
 */
template <typename E1, typename E2>
SoustractionDeVecteur<E1,E2>
operator-(E1 const& u, E2 const& v) 
{
   return SoustractionDeVecteur<E1, E2>(u, v);
}
