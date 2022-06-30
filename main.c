#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int anioImp;//2020 a 2022
    int bimestre;//1 a 6
    char propiedad;//‘T’ Terreno, ‘D’ Departamento, ‘C’ Casa, ‘L’ Local y ‘Q’ Quinta
    float importe;
}sMontos;
typedef struct
{
    int nroContri;//1 a 15200
    char tipo;//‘T’ Terreno, ‘D’ Departamento, ‘C’ Casa, ‘L’ Local y ‘Q’ Quinta
    int aniodImp;//2020 a 2022
    int bimes;//1 a 6
}sContribu;

void cargarArch();
int buscarImp(sMontos [][6],sContribu [91200] ,int ); //Matriz de con 6 columnas por los bimestres y filas para el tipo, vector de nroContri*bimestres y entero de cantidad.
int validar(int,int);

int main()
{
    int anio,x=0,primero=1,maximoBim,pos;
    int antContri[91200];
    float antBim,importeTotal;
    FILE*fcontri;
    sContribu contri[91200];
    sMontos mon[x][6];

    printf("Ingrese anio a realizar: ");
    anio=validar(2020,2022);
    cargarArch();
    fcontri=fopen("CONTRIBUYENTES.dat","rb");
    if(fcontri==NULL)
    {
        printf("Error en CONTRIBUYENTES.dat");
        system("pause");
        exit(2);
    }
    fread(&contri[x],sizeof(sContribu),1,fcontri);
    printf("Contribuyentes                  Bimestres");
    while(!feof(fcontri))
    {
        antContri[x]=contri[91200].nroContri;
        antBim=mon[x][6].bimestre;
        while(antContri==contri[91200].nroContri||!feof(fcontri))
        {
            pos=buscarImp(mon,contri,91200);
            importeTotal+=mon[x][6].importe;
            x++;
            fread(&contri[x],sizeof(sContribu),1,fcontri);
        }
        printf("%d                      %.2f %.2f %.2f %.2f %.2f %.2f\n",contri[pos].nroContri,antBim);//Punto C
    }
    printf("Importe total: %.2f",importeTotal);//Punto A
    if(antBim>maximoBim || primero==0)
        {
            maximoBim=antBim;
            primero=1;
        }
    else
        primero=0;

    printf("El Maximo bimestre es: %d",maximoBim);

  return 0;
}
void cargarArch()
{
    int x;
    sMontos montos[x][6];
    FILE*fmontos;
    fmontos=fopen("montos.dat","rb");
    if(fmontos==NULL)
    {
        printf("Error en montos.dat");
        system("pause");
        exit(1);
    }
    fread(&montos[x][6],sizeof(sMontos),1,fmontos);
    while(!feof(fmontos))
    {
        x++;
        fread(&montos[x][6],sizeof(sMontos),1,fmontos);
    }
};
int buscarImp(sMontos moni[][6],sContribu contris[91200] ,int cant)
{
    int pos=-1,i=0;
    while(pos==-1&&i<cant)
    {
        if(moni[i][6].propiedad==contris[91200].tipo)
            pos=i;
        else
            i++;
    }

    return pos;
};
int validar(int min,int max)
{
    int dato;

    do{scanf("%d",&dato);
    }while(dato<min||dato>max);

    return dato;
};
