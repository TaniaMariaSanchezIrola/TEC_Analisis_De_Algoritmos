#include <iostream>
#include <map> 

//Constant declarations

#define SIZE_OF_INT 4
#define SIZE_OF_BOOL 1

/* Encontrar el número mayor en un arreglo y su posición, el arreglo se recibe por parámetro.
 * Input: Integer Array Pointer and integer with array Size.
 * Output: Index Biggest integer.
 * If empty, returns -1.
 */
int findOne(int pArray[], int pArraySize){
    if(pArraySize > 0){
        int biggest = 0;
        int resultIndex;
        for(int index = 0; index < pArraySize; index++){
            if(pArray[index] > biggest){
                biggest = pArray[index];
                resultIndex = index;
            }
        }
        return resultIndex;
    }
    return -1;
}

/* Determinar si un arreglo de booleans es palíndrome o no, el arreglo se recibe por parámetro
 * Input: Integer Array Pointer
 * Output: Boolean, true if palindrome, false otherwise
 * If empty, returns -1.
 */
int binaryPalindrome(bool pArray[], int pArraySize){
    if(pArraySize > 0){
        int low = 0;
        int high = pArraySize - 1;
        for(int index = 0; index < pArraySize; index++){       
            if(pArray[low] == pArray[high]){
                low++;
                high--;
            }
            else{
                return false;
            }
        }
        return true;
    }
    return false;
}

/* Encontrar cuál número no tiene pareja en un arreglo, asuma que solo 1 número no tiene pareja, arreglo por parámetro
 * Inputs: Integer Array Pointer.
 * Output: an integer.
 * Restrictions: Empty Array.
 * */
void matches(int pMatches[], int pMatchesSize){
    std::map <int, bool> matchHash = std::map <int, bool>();
    if(pMatchesSize > 0){
        for(int number = 0; number < pMatchesSize; number++){
            if(matchHash[pMatches[number]] == false){
                matchHash[pMatches[number]] = true;
            }
            else{
                std::cout << "Numero: " << pMatches[number] << " tiene pareja!" << std::endl;
                matchHash[pMatches[number]] = false;
            }
        }
    }
    else{
        std::cout << "ERROR: Empty array." << std::endl;
    }
}

/* Encontrar cuál número no tiene pareja en un arreglo, asuma que solo 1 número no tiene pareja, arreglo por parámetro
 * Inputs: Integer Array Pointer.
 * Output: an integer.
 * Restrictions: Empty Array. Error result is -9999999
 * */
int getLonelyOne(int pArray[], int pArraySize){
    int result = -9999999;
    if(pArraySize > 0){
        result = pArray[0];
        for(int index = 1; index < pArraySize; index++){
            result = result ^ pArray[index];
        }
    }
    return result;
}

/* dado un número entero por parámetro determinar cuantos 1’s tiene en binario
 * Inputs: an integer.
 * Output: an integer.
 * Restrictions: None.
 * */
int getBinaryOnes(int pNumber){
    int result = 0;
    while(pNumber > 0){
        /*
        16-8-4-2-1
         1 0 0 0 1 = 17
         0 1 0 0 0 = 8
         0 0 1 0 0 = 4
         0 0 0 1 0 = 2
         0 0 0 0 1 = 1
         0 0 0 0 0 = 0
        */
        std::cout << "Before shift: " << pNumber << std::endl;
        pNumber = pNumber >> 1;
        std::cout << "After shift: " << pNumber << std::endl;
        result++;
    }
    return result;
}

int main() {
    std::cout << "Caso 1" << std::endl;
    //Ejercicio 1: Test
    std::cout << "FindOne test con array [5, 1, 4, 7, 0]" << std::endl;
    int array[] = {5, 1, 4, 7, 0};
    int arraySize = (sizeof(array)/SIZE_OF_INT);
    int resultFindOne = findOne(array, arraySize);
    std::cout << "En array, el numero mas grande es: " << array[resultFindOne] << " en la posicion: " << resultFindOne << std::endl;
    //Ejercicio 2: Test
    bool palindrome[] = {1, 0, 1, 0, 1};
    int palindromeSize = (sizeof(palindrome)/SIZE_OF_BOOL);
    int resultPalindrome = binaryPalindrome(palindrome, palindromeSize);
    std::cout << "Palindrome es palindromo? R/ " << resultPalindrome << std::endl;
    //Ejercicio 3: Test
    int matchesArray[] = {8, 13, 45, 8, 5, 13, 9, 8};
    int matchesSize = (sizeof(matchesArray)/SIZE_OF_INT);
    matches(matchesArray, matchesSize);
    //Ejercicio 4: Test
    int xorArray[] = {8, 13, 45, 5, 13, 45, 8};
    int xorSize = (sizeof(xorArray)/SIZE_OF_INT);
    int xorResult = getLonelyOne(xorArray, xorSize);
    std::cout << "El numero sin pareja es:" << xorResult << std::endl;
    //Ejercicio 5: Test
    int resultBinaryOnes = getBinaryOnes(17);
    std::cout << "El numero 19 en binario tiene: " << resultBinaryOnes << " 1's" << std::endl;
}