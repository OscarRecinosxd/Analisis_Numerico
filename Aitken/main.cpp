#include <iostream> // std::cout, std::endl
#include <cmath> //std::abs
#include <iomanip> //std::setprecision

using std::cout;	using std::endl;
using std::abs;		using std::setprecision;

// Funcion para IPF
inline long double g(long double x){ return  0.389045*(pow(((pow(x,1.70922))+124.667),0.705));  }

// Inline para calcular cada termino de la sucesion de Aitken
inline double p_hat(double p0, double p1, double p2){ return p0 - pow( p1-p0 , 2.0)/(p2 - 2.0*p1 + p0);}

/*
p0: aproximacion inicial
Nmax: numero maximo de iteraciones
T: tolerancia
*/
void aitken(double p0, int Nmax, double T){	

	double p0_hat; //utimo valor en la sucesion de Aitken
	double p1_hat; //valor actual en la sucesion de Aitken
		
	double p1, p2; //valores en la iteracion de punto fijo 

	for(int i = 0; i <= Nmax; i++){
		p1 = g(p0);	
		p2 = g(p1);
		
		p1_hat = p_hat(p0, p1, p2);		

		if(i == 0) cout << i <<setprecision(11) << "\t" << p0 << "\t" << p1 << "\t" << p2 << "\t" << p1_hat << endl;
		else cout <<i << setprecision(11) << "\t" << p0 << "\t" << p1 << "\t" << p2 << "\t" << p1_hat << "\t" << abs(p1_hat - p0_hat) <<endl;

		
		if(abs(p0_hat - p1_hat) < T){
			cout << "Objetivo logrado con " << i+1 << " iteraciones"<< endl;			
			break;						
		} 

		p0 = p1;
		p0_hat = p1_hat; 
	
	}		
}


int main(){
	//AITKENN
	

	aitken(20, 100, 1e-6);		
	
	return 0;
}
