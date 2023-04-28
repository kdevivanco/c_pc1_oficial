//
// Este trabajo pertence a: KAYLA DE VIVANCO BRICENO
//

#ifndef PROG3_PC1_TEO3_V2023_1_P1_H
#define PROG3_PC1_TEO3_V2023_1_P1_H
#include<iostream>
#include <vector>
#include <cstring> // strlen, strcpy
#include <cctype> // isspace, isdigit
#include <cmath> //fmod
#include<string>
#include <array>
#include <cstdlib>
#include <memory>


using namespace std;

template <class T>
class Multiplies{
private:
    vector<T> results; //arreglo dinamico de los valores seleccionados

public:

    Multiplies() = default;

    ~Multiplies(){}

    Multiplies(const char* cad_char, int x_val):results(){
        vector<int> valores;
        int siz = strlen(cad_char);
        const char* value = cad_char; //Este valor se va a sobreescribir con cada loop, cada vez que se encuentra con un espacio " "
        for(int i= 0; i < siz; i++){
            if(isspace(static_cast<unsigned char>(cad_char[i]))){
                //Inserto el valor COMO INT al vector valores usando funcion atoi (https://en.cppreference.com/w/cpp/string/byte/atoi)
                valores.push_back(atoi(value));
                value = &cad_char[i+1];
            }
        }
        //Inserta el ultimo valor
        valores.push_back(atoi(value));

        for(const auto& entero : valores){
            if (fmod(entero, x_val) == 0){
                results.push_back(entero);
            }
        }
    }

    Multiplies(const Multiplies& other){
        //Solo es necesario copiar results
        results = other.results;
    }

    Multiplies& operator=(const Multiplies& other){
        if(&other == this){
            return *this;
        }
        results = other.results;
        return *this;
    }

    Multiplies operator^(const Multiplies& other) const{
        Multiplies<T> res; //Crea un nuevo objeto Multiplies para almacenar la respuesta
        //Filtra los duplicados e inserta a res
        for (const auto& i : results) {
            if (std::find(other.results.begin(), other.results.end(), i) != other.results.end()) {
                res.results.push_back(i);
            }
        }
        return res;
    }

    //Como no sabemos el tipo de arr, no se puede hacer (const arr[])
    //Por eso creo otro template para la sobrecarga de ^
    //Esto permite copiar los valores de arr a un vector, y hacer los calculos sobre eso
    template<size_t N>
    Multiplies operator^(const T(&arr)[N]) const {
        Multiplies<T> res; //objeto de retorno
        //Crea el vector arr_vec con el contenido de arr
        vector<T> arr_vec(arr, arr + N);
        for (const auto &i: arr_vec) {
            for (const auto &j: results) {
                if (i == j) { //Evita que itere de mas
                    res.results.push_back(i);
                    break;
                }
            }
        }
        return res;
    }


    T& operator[](int position){
        return results[position]; //indice del vector results
    }

    int size() const {
        return results.size();
    }


    // Deduje que se devuelve un typename vector<T>::iterator cuando me encontre con el siguiente error:
    // error: no viable conversion from returned value of type 'std::__1::vector<int>::iterator'
    // antes lo estaba haciendo con T* como return type y no funciono
    // luego de implementarlo con int (como salia en el error), cambie a T para que funcione para cualquier tipo de vector
    typename vector<T>::iterator begin(){
        return results.begin();
    }

    typename vector<T>::iterator end(){
        return results.end();
    }



};

void question_1();

#endif //PROG3_PC1_TEO3_V2023_1_P1_H
