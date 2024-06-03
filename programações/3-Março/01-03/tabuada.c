#include<stdio.h> 
#include<locale.h>

int main(){
	
	setlocale(LC_ALL,"");
    int multiplicador;
    
    printf ("A tabuada de 1 à 10 é:\n");
    printf ("\n");

    for (multiplicador = 1; multiplicador <=10; multiplicador++) {

        int resultado = 1 * multiplicador;
    printf ("1 x %d = %d\n", multiplicador, resultado);
   }
   
    printf ("\n");
    
    for (multiplicador = 1; multiplicador <=10; multiplicador++) {

        int resultado = 2 * multiplicador;
    printf ("2 x %d = %d\n", multiplicador, resultado);
    }
    
    printf ("\n");
    
     for (multiplicador = 1; multiplicador <=10; multiplicador++) {

        int resultado = 3 * multiplicador;
    printf ("3 x %d = %d\n", multiplicador, resultado);

    }
     for (multiplicador = 1; multiplicador <=10; multiplicador++) {

        int resultado = 4 * multiplicador;
    printf ("4 x %d = %d\n", multiplicador, resultado);
    }
    
    printf ("\n");
    
     for (multiplicador = 1; multiplicador <=10; multiplicador++) {

        int resultado = 5 * multiplicador;
    printf ("5 x %d = %d\n", multiplicador, resultado);
    }
    
    printf ("\n");
    
     for (multiplicador = 1; multiplicador <=10; multiplicador++) {

        int resultado = 6 * multiplicador;
    printf ("6 x %d = %d\n", multiplicador, resultado);
    }
    
    printf ("\n");
    
     for (multiplicador = 1; multiplicador <=10; multiplicador++) {

        int resultado = 7 * multiplicador;
    printf ("7 x %d = %d\n", multiplicador, resultado);
    }
    
    printf ("\n");
    
     for (multiplicador = 1; multiplicador <=10; multiplicador++) {

        int resultado = 8 * multiplicador;
    printf ("8 x %d = %d\n", multiplicador, resultado);
    }
    
    printf ("\n");
    
     for (multiplicador = 1; multiplicador <=10; multiplicador++) {

        int resultado = 9 * multiplicador;
    printf ("9 x %d = %d\n", multiplicador, resultado);
    }
    
    printf ("\n");
    
     for (multiplicador = 1; multiplicador <=10; multiplicador++) {

        int resultado = 10 * multiplicador;
    printf ("10 x %d = %d\n", multiplicador, resultado);
    }
    
    printf ("\n");

    printf("\nAgora você já aprendeu a tabuada de 1 à 10!");


    return 0;
}


