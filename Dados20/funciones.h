#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

///DECLARACION DE FUNCIONES

void cargarAleatorio(int v[], int* tam, int* limite); ///asigna valores aleatorios a cada posicion del vector

void mostrarVector(int v[], int* tam); ///muestra lo que contiene cada una de las posiciones del vector

int valormaximoVector(int v[], int tam);///devuelve  el valor (primero) maximo en el vector

void ponerCero(int v[], int tam);/// pone en 0 todas las posiciones del vector

int sumarVector(int v[], int tam ); /// suma los valores contenidos en el vector

int posicionNumeroEnVector(int v[],int tam, int numero);/// devuelve la posición que ocupa un número que se //envía como parámetro. Devuelve la primera posición que encuentra el número. Si no lo encuentra devuelve -1

int contarNumerosRepetidos(int v[], int tam , int numero);///cuenta la cantidad de veces que se repite un //número en el vector

void mostrarVectorSin0(int v[], int tam); /// muestra lo que contiene cada una de las posiciones del vector que no contienen 0.

void cargarVector(int v[], int tam);///asigna valores a cada una de las posiciones del vector



///DEFINICIONES DE FUNCIONES

void cargarAleatorio(int v[], int tam, int limite){
  int i;
  srand(time(NULL));
  for( i=0; i<tam; i++ ){
        v[i]=(rand()%limite)+1;
  }
}

void mostrarVector(int v[], int tam){
    int i;
    for(i=0;i<tam;i++){
        cout<<v[i]<<"\t";
    }
}

int valormaximoVector(int v[], int tam){
    int i, posMax=0;
    for(i=1;i<tam;i++){
        if(v[i]>v[posMax]) {
                posMax=i;
        }
    }
    return v[posMax];
}

void ponerCero(int v[], int tam){
    int i;
    for(i=0;i<tam;i++){
        v[i]=0;
    }
}

int sumarVector(int v[], int tam ){
    int i, suma=0;
    for(i=0;i<tam;i++){
        suma+=v[i];
    }
    return suma;
}

int posicionNumeroEnVector(int v[],int tam, int numero){
    int i;
    for(i=0;i<=tam;i++){
        if(v[i]==numero) return i;
        }
    return -1;
}

int contarNumerosRepetidos(int v[], int tam, int numero){
    int i, cant=0;
    for(i=0;i<tam;i++){
        if(v[i]==numero) cant++;
        }
    return cant;
}

void mostrarVectorSin0(int v[], int tam){
    int i;
    for(i=0;i<tam;i++){
        if(v[i]!=0){
            cout << "\t" << v[i];
        }
    }
}

void cargarVector(int v[], int tam){
    int i;
    for(i=0;i<tam;i++){
        cout<<"DADO " << i + 1 << ":";
        cin>>v[i];
        system("cls");
    }
}




#endif // FUNCIONES_H_INCLUDED
