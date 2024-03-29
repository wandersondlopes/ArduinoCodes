/*
Cria um vetor com valores determinados
organiza esses valores
imprime na serial


criado   Set 2022
por Wanderson D. Lopes
modificado Out 2022
por Wanderson D. Lopes
*/

  int n=25;
  int Vetor[] = {3,6,5,1,2,8,7,9,4,10,13,12,11,17,18,19,20,14,15,16,25,24,23,22,21};


void setup(){
    Serial.begin(9600);
 
    Serial.println("Apresentação de valores do vetor: ");
    for(int i=0;i<n;i++){
        Serial.print(Vetor[i]);
        Serial.print(" - ");
    }

    Serial.println("");

    selecao(Vetor,n);

    Serial.print("\n\n");
    Serial.println("Valores organizados (ordenados): ");
    for(int i=0;i<n;i++){
        Serial.print(Vetor[i]);
        Serial.print(" - ");
    }


    Serial.print("\n\n\n");

}


void loop(){}

void selecao(int Vet[],int n){

    int Menor, aux;

    for(int i=0;i<n-1;i++){
        Menor=i;
        for(int j=i+1 ; j<n ; j++){
            if(Vet[Menor] > Vet[j])
                Menor=j;
        }
        if(i!=Menor){
            aux=Vet[i];
            Vet[i]=Vet[Menor];
            Vet[Menor]=aux;
        }
    }
}
