#include <bits/stdc++.h>
using namespace std;
 
class BST {
    int dane;
    BST *lewe, *prawe;
 
public:
    ~BST(){
        delete lewe;
        delete prawe;
    }
    BST() : dane(0),lewe(NULL),prawe(NULL){};
    BST(int wartosc){
        dane = wartosc;
        lewe = prawe = NULL;
    }
    BST* wstaw(BST* korzen, int wartosc){

    //Jeśli drzewo jest puste dodaj korzeń    
    if (!korzen) 
    return new BST(wartosc);
    
    //Jesli wartosc jest wieksza wstaw do prawego poddrzewa
    if (wartosc > korzen->dane) 
        korzen->prawe = wstaw(korzen->prawe, wartosc);
    
    //Jesli wartosc jest mniejsza wstaw do lewgo poddrzewa
    else if (wartosc < korzen->dane) 
        korzen->lewe = wstaw(korzen->lewe, wartosc);
    
    return korzen;
    }
 
    // Wyświetlenie drzewa w porządku inorder
    void inorder(BST* korzen){
            if (!korzen) return;
    
    inorder(korzen->lewe);
    cout << korzen->dane << " ";
    inorder(korzen->prawe);
    }

    void preorder(BST* wezel){
            if (wezel == NULL)return;

    cout << wezel->dane << " ";
    preorder(wezel->lewe);// Przejdz lewe poddrzewo
    preorder(wezel->prawe);// Przejdz prawe poddrzewo
    }

    void postorder(BST* wezel)
{
    if (wezel == NULL)return;
 
    postorder(wezel->lewe);
    postorder(wezel->lewe);
    cout << wezel->dane << " ";
}

    BST* usunElement(BST* korzen, int wartosc){
        //Przypadek bazowy
         if (korzen == NULL)
        return korzen;
 


    //Rekurencyjne wywołanie usuwania funkcji
    if (korzen->dane > wartosc) {
        korzen->lewe = usunElement(korzen->lewe, wartosc);
        return korzen;
    }
    else if (korzen->dane < wartosc) {
        korzen->prawe = usunElement(korzen->prawe, wartosc);
        return korzen;
    }
 
    // Jeżeli jeden z synów jest pusty usun korzen i zwroc prawy badz lewy nastepnik
    if (korzen->lewe == NULL) {
        BST* temp = korzen->prawe;
        delete korzen;
        return temp;
    }
    else if (korzen->prawe == NULL) {
        BST* temp = korzen->lewe;
        delete korzen;
        return temp;
    }
 
    // Jezeli istnieja obaj synowie
    else {
 
        BST* nastepnikRodzic = korzen;
 
        // Znajdz nastepnik
        BST* nastepnik = korzen->prawe;
        while (nastepnik->lewe != NULL) {
            nastepnikRodzic = nastepnik;
            nastepnik = nastepnik->lewe;
        }
 
        //Usun nastepnik badz jesli go nie ma - przypisz prawego syna nastepnika do prawego syna rodzica
        if (nastepnikRodzic != korzen)
            nastepnikRodzic->lewe = nastepnik->prawe;
        else
            nastepnikRodzic->prawe = nastepnik->prawe;
 
        // Przypisz dane z nastepnika do korzenia
        korzen->dane = nastepnik->dane;
 
        delete nastepnik;
        return korzen;
    }
    
    }
};
 

