#include<iostream>
#include<conio.h>
using namespace std;

int main(){
	
int numeros[] = {1,2,3,4,5};
int sum = 0;

for(int i=0;i<5;i++){
	sum += numeros[i];
}
	cout<<"La suma acumulada de los elementos del 1-5 es: "<<sum<<endl;
	
	getch();
	return 0;
}