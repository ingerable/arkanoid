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

/*
 * l'évaluation d'un vecteur (ses coordonnées)
 */
class Vecteur : public ExpressionDeVecteur<Vecteur> 
{
    std::vector<double> elems;

    public:
        //opérateur [] (accesseur)
        double operator[](size_t i) const 
        { 
            return elems[i]; 
        }
        double &operator[](size_t i) 
        { 
            return elems[i]; 
        }
        
        //la taille du vecteur
        size_t size() const               
        { 
            return elems.size(); 
        }
        
        //constructeurs
        Vecteur(size_t n) : elems(n) 
        {}
        Vecteur(std::initializer_list<double>init)
        {
            for(auto i:init)
            {
                elems.push_back(i);
            }
        }
        template <typename E>
        Vecteur(ExpressionDeVecteur<E> const& vecteur) : elems(vecteur.size()) 
        {
            for (size_t i = 0; i != vecteur.size(); ++i) 
            {
                elems[i] = vecteur[i];
            }
        }
};

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
        }
        
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

/*
 * la multiplication de deux vecteurs
 */
template <typename E1, typename E2>
class MultiplicationDeVecteurs : public ExpressionDeVecteur<MultiplicationDeVecteurs<E1, E2> > 
{
    E1 const& _u;
    E2 const& _v;

    public:
        MultiplicationDeVecteurs(E1 const& u, E2 const& v) : _u(u), _v(v) 
        {
            assert(u.size() == v.size());
        }
        
        //opérateur [] (accesseur)
        double operator[](size_t i) const 
        { 
            return _u[i] * _v[i]; 
        }
        
        //la taille du vecteur
        size_t size() const 
        { 
            return _v.size();
        }
};

/*
 * surcharge de l'operation *
 */
template <typename E1, typename E2>
MultiplicationDeVecteurs<E1,E2>
operator*(E1 const& u, E2 const& v) 
{
   return MultiplicationDeVecteurs<E1, E2>(u, v);
}

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

int main()
{
    Vecteur v0 = {23.4,12.5,144.56,90.56};
    Vecteur v1 = {67.12,34.8,90.34,89.30};
    Vecteur v2 = {34.90,111.9,45.12,90.5};

    Vecteur somme = v0+v1+v2; 
    Vecteur mult = v0*v1*v2; 
    Vecteur sous = v0-v1-v2;
    Vecteur neg = -v0-v1-v2;

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
