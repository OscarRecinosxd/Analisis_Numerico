#include <iostream> // std::cout, std::endl
#include <cmath> //std::abs
#include <iomanip> //std::setprecision

using std::cout;	using std::endl;
using std::abs;		using std::setprecision;

// Función para IPF
inline long double g(long double x){ return 2.18902*(pow((pow(x,1.41844)-32.6757),0.585062));  }


// Inline para calcular cada término de la sucesión de Aitken
inline long double p_hat(long double p0,long double p1,long double p2){ return p0 - pow( p1-p0 , 2.0)/(p2 - 2.0*p1 + p0);}

/*
p0: aproximacion inicial
Nmax: numero maximo de iteraciones
T: tolerancia
Si no se usa long double, algún dato se puede aproximar a 0
*/
void steffensen(long double p0, int Nmax, long double T){

	long double p, p1, p2;

	for(int i = 0; i <= Nmax; i++){
		
		p1 = g(p0);
		p2 = g(p1);
		p = p_hat(p0, p1, p2);

		if(i == 0) cout <<i << setprecision(11) << "\t" << p0 << "\t" << p1 << "\t" << p2 << "\t"  << p << endl;
		else cout <<  i<<setprecision(11) << "\t" << p0 << "\t" << p1 << "\t" << p2 << "\t"  << p << "\t"  << abs(p0 - p) << endl;


		if(abs(p0-p) < T){
			cout << "Objetivo logrado con " << i+1 << " iteraciones"<< endl;
			break;
		}

		p0 = p;
	}
}

int main(){
	

	//STEFENSEN
	steffensen(70,100 , 1e-5);
	
}
