#include<stdio.h>
double M4();
double data[3][5]={{34.5,56.7,12.6,98.4,54.21},{89.55,54.2,98.4,73.2,21.45},{34.5,98.4,21.45,98.4,9.3}};
int main(){
	printf("%.3f",M4());
	return 0;
}
double M1(){
	double tot=0.0;
	int x,y;
	for(x=0;x<3;x++){
		for(y=0;y<5;y++){
			tot=tot+data[x][y];
		}
	}
	return tot;
}
double M2(){
	return M1()/15;
}
double M3_max(){
	double max=0.0;
	int x,y;
	for(x=0;x<3;x++){
		for(y=0;y<5;y++){
			if(max<data[x][y]);
				max=data[x][y];
		}
	}
}
double M3_min(){
	double min=data[0][0];
	int x,y;
	for(x=0;x<3;x++){
		for(y=0;y<5;y++){
			if(min>data[x][y]);
				min=data[x][y];
		}
	}
}
double M4(){
	double max=0.0;
	double c[2][15];
	int x,y,sup=0;
	
	for(x=0;x<3;x++){
		for(y=0;y<5;y++){
			int z;
			for(z=0;z<15;z++){
				if(c[0][z]==data[x][y]){
					c[1][z]=c[1][z]+1;
					break;
				}else{
					c[0][sup]=data[x][y];
					sup=sup+1;
					break;
				}			
			}
		}
	}
	
	int a,b,nmax=0;
	for(a=0;a<15;a++){
		if(c[1][a]>nmax)
			nmax=c[1][a];
	}
	
	for(b=0;b<15;b++){
		if(c[1][b]==nmax)
			return c[0][b];
	}
}
