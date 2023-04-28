# PC1: Practica Calificada #1  
**course:** Programación III  
**unit:** 1 y 2  
**cmake project:** prog3_PC1_teo3_v2023_1
## Indicaciones Específicas
- El tiempo límite para la evaluación es 100 minutos.
- Cada pregunta deberá ser respondida en un archivo fuente (`.cpp`) y un archivo cabecera (`.h`) con el número de la pregunta:
    - `P1.cpp, P1.h`
    - `P2.cpp, P2.h`
- Deberás subir estos archivos directamente a [www.gradescope.com](https://www.gradescope.com) o se puede crear un `.zip` que contenga todos ellos y subirlo.


## Question #1 - clases, punteros y sobrecarga de operadores y template de clases (14 points)

Crear un template de clase `Multiplies` que se pueda crear con un constructor que tenga dos parámetros, 
- el primer parámetro es una cadena de caracteres, que contendrá una lista aleatoria de números separados por espacios.
- el segundo parámetro es un número que filtre solo aquellos valores que sean múltiplos de ese número.

El primer parámetro sera una cadena de caracteres `const char*`
El segundo parámetro sera un número (enteros o decimales)

El template de clase `Multiplies` debera almacenar en un arreglo dinámico los valores seleccionados.

debera implementarse los siguientes métodos:
- `begin()` que retorne el puntero a la dirección del primer valor
- `end()` que retorne un puntero a la dirección posterior del segundo valor
- `size()` que retorne la cantidad de múltiplos.
- el operador `[]` que retorne el valor en el indice seleccionado

adicionalmente debe de implementarse el operador ^ que realice la intersección (valores en común) de 2 objetos `multiples<T>` o un objeto `multiples<T>`y un arreglo estático.

**Use Case #1:**
```cpp
Multiplies<int> m1("1 20 3 4 5 10 15", 5);
auto m2 = m1;
for (int i = 1; i < m2.size(); ++i)
    cout << m2[i] << " "; // 20 5 10 15
```

**Use Case #2:**
```cpp
Multiplies<int> m1("1 20 3 4 5 10 15", 5);
auto m2 = m1;
for (auto ptr = m2.begin(); ptr != m2.end(); ++ptr)
    cout << *ptr << " "; // 20 5 10 15
```
**Use Case #3:**

```cpp
Multiplies<double> m1("1 20 3 4 5 10 15", 5);
auto m2 = m1;
double arr[] = {10, 20, 3};
auto m2 = m2 ^ arr; 
for (auto ptr = m2.begin(); ptr != m2.end(); ++ptr)
    cout << *ptr << " "; // 10 20 
```

## Question #2 - template de función (6 points)

Crear un template de función `generate_matrix` que tenga adicionalmente 2 parámetros `no-tipo` que representen el número de filas (`r`) y columnas (`c`) y que cuente con un parámetro de función del tipo `vector`, `deque` con valores numéricos.
La función generará una matriz de tamaño `r x c` que sera un contenedor de contenedores del tipo similar al contenedor original, si el parámetro de función tiene una cantidad menor de valores que el tamaño de la matriz el resto debe ser llenado con ceros (`0`), si es mayor el resto de valores sera descartado.  

**Use Case #1:**
```cpp
vector v1 = {1, 2, 3, 4};
auto m1 = generate_matrix<3, 2>(v1);
for (auto row: m1) {
    for (auto item: row)
        cout << setw(3) << item;
    cout << endl;
    }
/* Resultado:
1  2  
3  4
0  0
 */
```

**Use Case #2:**
```cpp
deque d1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
deque m1 = generate_matrix<3, 3>(d1);
for (auto row: m1) {
    for (auto item: row)
        cout << setw(3) << item;
    cout << endl;
}
/* Resultado:
1  2  3
4  5  6
7  8  9
 */
```

