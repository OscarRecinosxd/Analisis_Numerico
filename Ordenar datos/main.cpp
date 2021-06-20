#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

int main(int argc, char** argv) {
	int n = 0;
	float aux;
	cout<<"Ingrese el numero de datos a ordenar"<<endl;
	cin>>n;
	
	float Datos[n];
	
	for(int i = 0 ; i < n ; i++){
		cout << "Ingrese el dato "<< i + 1 << endl;
		cin >> Datos[i];
		cout<<endl;
	}
	
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){		
			if(Datos[j]>Datos[j+1]){
				aux = Datos[j];
				Datos[j] = Datos[j+1];
				Datos[j+1] = aux;
			}
		}
	}
	
	cout<<"Los datos ordenados son: "<<endl;
	
	for(int i = 1 ; i <= n ; i++  ){
		cout<< "Dato " << i <<": " <<Datos[i]<<endl;
	}
	
	cout<<endl;
	
	return 0;
}
