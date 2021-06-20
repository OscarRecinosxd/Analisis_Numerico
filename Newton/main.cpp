#include <cstdio> //printf
#include <cmath> //sin, cos

double f(double x) { return pow(x,4)-16*pow(x,3)+78*pow(x,2)-412*x+624; }
double df(double x) { return 

	((pow(x+pow(1,-4),4)-16*pow(x+pow(1,-4),3)+78*pow(x+pow(1,-4),2)-412*(x+pow(1,-4))+624) - (pow(x,4)-16*pow(x,3)+78*pow(x,2)-412*x+624)) / (pow(1,-4))

; }

void Newton(double p0, double TOL, int Nmax){
    double p = 0; //p will hold the current approximation
    for(int i=0; i<Nmax; i++){
        p = p0 - f(p0)/df(p0);
        printf("%d\t%.10f\t%.10f\t%.10f\n", i, p0, p, std::abs(p - p0));
        if(std::abs(p - p0) < TOL) break;
        p0 = p;
    }
}

int main() {
		

	
    Newton(-6, 1e-6, 100);
    return 0;
}
