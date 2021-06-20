#include <iostream>

using namespace std;

int main(void)
{
    char caracter;
    cout << "Ingrese la letra: "; cin >> caracter;

    if (caracter=='a', caracter=='e', caracter=='i',caracter=='o',caracter=='u'){
        cout << "La letra es una vocal" << endl;
    } else {
        cout << "No es una vocal" << endl;
    }
    return 0;
}
