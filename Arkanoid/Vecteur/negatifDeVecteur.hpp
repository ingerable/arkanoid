#pragma once
#include <vector>
#include <cstddef>
#include <iostream>
#include <ostream>
#include <cassert>
#include "vecteurs.hpp"

/*
 * le négatif d'un vecteur
 */
template <typename E1>
class NegatifDeVecteur : public ExpressionDeVecteur<NegatifDeVecteur<E1> > 
{
    E1 const& _v;

    public:
        NegatifDeVecteur(E1 const& v) : _v(v)
        {}
        
        //opérateur [] (accesseur)
        double operator[](size_t i) const 
        { 
            return - _v[i]; 
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
template <typename E1>
NegatifDeVecteur<E1>
operator-(E1 const& v) 
{
   return NegatifDeVecteur<E1>(v);
}
