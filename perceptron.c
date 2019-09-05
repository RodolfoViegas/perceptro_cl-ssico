#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Pequeno projeto de implementação do Perceptron clássico baseado 
 no pseudocódigo da fornecido canal do YouTube Deep Learning Brasil.*/

/*Este Perceptron tem a finalidade de resolver o problema lógico do AND.*/

int soma(int vetor[]){
    int i, s=0;
    for(i=0;i< 8;i++){
        s = s + vetor[i];
    }
    
}


int main(){
    
    
    float n=0.1; //taxa de aprendizado
    float w[]={0.5,0.5}; //pesos para as entradas 1 e 2
    int epoca =1000; //quantidade de ciclos, chamdas de épocas, para treinamento
    
    int entrada1[]={0,0,1,1,0,1,0,1}; // vetor de entradas 1
    int entrada2[]={0,0,1,1,1,1,0,0}; // vetor de entradas 2
    float vies = 0.5;
    
    int saida_atual[8];
    int saida_desejada[]={0,0,1,1,0,1,0,0};
    int t = 1,i,num=8, e[8], E=1;

    
    while(t< epoca && E>0){
        for(i=0;i<num;i++){
            if(vies + (w[0] * entrada1[i]) + (w[1] * entrada2[i]) >= 0){
            saida_atual[i] = 1; 
            }
            else{
                saida_atual[i] = 0; 
            }
            e[i] = saida_desejada[i] - saida_atual[i];
            w[0] = w[0] + n * e[i] * entrada1[i];
            w[1] = w[1] + n * e[i] * entrada2[i];//ajustar os pesos.
            vies = vies + n*e[i]; //ajustar o viés.
            e[i] = pow(e[i],2);
        }
        
        
        E = soma(e);
        t++;
    }
    
    
    printf("entrada1*%.2f + entrada2*%.2f + %f = y\t%i\n",w[0],w[1],vies,E);
    return 0;
}
