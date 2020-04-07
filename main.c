#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int check (int,int,int);

int main(int argc, char* argv[])
{


    int i;

    FILE * fp;
    fp = fopen("input.txt", "r");
    if (fp == NULL){
        printf("Problem with the input file!");
        exit(1);
    }



    char needIndex[5];

    fscanf(fp, "%[^\n]", needIndex);
    int index = atoi(needIndex);

    char line[256];
    int num[3];
    int j;
    int k = -1;
    int z;
    int num2;
    int numFinal[index][3];


    while(fgets(line, sizeof(line), fp)) {
        if (strlen(line)>2 && k<index){
            j = 0;
            for(i=0; i<strlen(line); i++){
                if(i==0 || i%2==0){
                    char* tmp = &line[i];
                    num2 = atoi(tmp);
                    numFinal[k][j] = num2;
                    j++;
                }
            }
        }

        k++;
    }





    char resString1[10];
    char resString2[10];
    char nope = '-';

    char finishString[index][5][10];

    int a,b,c;



    for(i=0; i<index; i++){

        double resr1,resr2 = 0;

        a = numFinal[i][0];
        b = numFinal[i][1];
        c = numFinal[i][2];

        if(check(a,b,c)== 0){
            resString1[0] = nope;
            resString1[1] = '\0';
            resString2[0] = nope;
            resString2[1] = '\0';
            strcpy(finishString[index][3], resString2);
            strcpy(finishString[index][4], resString1);
        }
        else{
            resr1 = sqrt((pow(b,2)-(4*a*c)));
            resr2 = ((-1)*b) - resr1;
            resr1 += (-1)*b;
            resr1 /= 2.0*a;
            resr2 /= 2.0*a;

            double* egy = &resr1;
            double* ketto = &resr2;


            sprintf(finishString[index][3], "%f", resr1);
            sprintf(finishString[index][4], "%f", resr2);
        }


        sprintf(finishString[index][0], "%d", numFinal[index][0]);
        sprintf(finishString[index][1], "%d", numFinal[index][1]);
        sprintf(finishString[index][2], "%d", numFinal[index][2]);



        printf("%s %s %s       %s %s\n", finishString[index][0],finishString[index][1],finishString[index][2],finishString[index][3],finishString[index][4]);

    }


    fclose(fp);
}


int check (int a,int b, int c){

    int pos = 0;

    int result = (pow(b,2)-(4*a*c));

    if(result>=0){
        pos = 1;
    }else{
        pos = 0;
    }

    return pos;

}