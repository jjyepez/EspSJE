//------------------------------------------------------------
//------------- basado en el código de "C codechamp" ---------
//---------- adaptación y UI por: JJYépez - nov 2012 ---------
//------------------------------------------------------------
// fuente: http://www.ccodechamp.com/c-program-of-n-queens-problem-solution-using-backtracking/

#include<conio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>
#include<stdio.h>

int delay=50; //fijar valores bajos e ir subiendo - depende del procesador
void nreinas(int n); // declaracion de la funcion que se define más adelante

/* Main Function */
int main(){
    // se define el número de reinas a 8 fijo, pero funciona con cualquier número  n | n > 4
  int n=8;
	nreinas(n);

}
void mostrarReinas(int n,int x[]){
    char arr[20][20];
    int i,j,f,c,z=1;
    
    printf("\t ");
    for(c=1;c<=n;c++){ printf(" %c ",96+c); }
    printf("\n\t%c",218);
    for(c=1;c<=n;c++){ printf("%c%c",196,196); if(c<n)printf("%c",194);}
	printf("%c\n",191);
	
	for(f=1;f<=n;f++){
		printf("\t%c",179);
		for(c=1;c<=n;c++){
			if(f==x[c]) printf("%c ",15); else printf("  ");
			printf("%c",179);
		}
		int cierrei=195, conector=197,cierred=180;
		
		if(f==n){ cierrei=192;conector=193;cierred=217; }
		
		printf(" %d\n\t%c",f,cierrei);
		for(c=1;c<=n;c++){ printf("%c%c",196,196); if(c<n)printf("%c",conector);}
		printf("%c\n",cierred);
	}
	z++;
	//for(int d=0;d<=delay*1000000;d++);
}
int posicionsegura(int x[],int k){       
	for(int i=1;i<k;i++){ // se evalua fila, columna y diagonales
        if(x[i]==x[k]||i-x[i]==k-x[k]||i+x[i]==k+x[k]){ return 0;  /* False*/  }
    } return 1; /*true*/
}
void nreinas(int n){
    int x[20],count=0,k=1,c=0;
    char cursor[4]; cursor[0]='/',cursor[1]='-',cursor[2]='\\',cursor[3]=124;
	char cursorx;
    x[k]=0;
    while(k!=0){
        x[k]=x[k]+1;
        while((x[k]<=n)&&(!posicionsegura(x,k))){
             x[k]=x[k]+1;
        }
        if(x[k]<=n){
			printf("\n\n\tPROBLEMA DE LAS %d REINAS\n",n);
            if(k==n){
                count++;
                printf("\n\tLa soluci%cn %d es:\n\n",162,count);
                mostrarReinas(n,x);
                printf ("\n\t[ENTER] para ver la siguiente soluci%cn",162);
                printf ("\n\t[ESC]   para finalizar",162);
                int r=getch();
                if(r==27) exit(0);
                system("cls");
            } else {
                k++; x[k]=0;
                printf("\n\tVerificando posiciones para soluci%cn %d ... \n\n",162,count+1);
                mostrarReinas(n,x);
                if(c<4)c++;else c=0;
                cursorx=cursor[c];
                printf("\n\tProcesando %c", cursorx);
                for(int d=0;d<=delay*1000000;d++);
                system("cls");
        	}
        }else{
            k--;
        }
    }
    return;
}
