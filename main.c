#include <stdio.h>
#include <stdlib.h>

void multiPleFileRead(char *fp_in,int *numbers){
    int num,i=0,count = 0;
    char line[80];
    while(fgets(line,80,fp_in) != NULL ){
        line [ strcspn(line, "\r\n") ] = 0;
        sscanf(line,"%*d %d",&numbers[count]);
        count++;
    }
}
int main()
{
    FILE *fp_math,*fp_bangle,*fp_english,*fp_result;
    char *math_file = "./file/math.txt",
    *english_file = "./file/english.txt",
    *result_file = "./file/result.txt",
    *bangla_file = "./file/bangla.txt";
    int mathNumber[9],banglaNumber[9],englishNumber[9],i = 0;
    float avg=0;
    fp_math = fopen(math_file,"r");
    fp_bangle = fopen(bangla_file,"r");
    fp_english = fopen(english_file,"r");
    fp_result = fopen(result_file,"w");

    multiPleFileRead(fp_math,mathNumber);
    multiPleFileRead(fp_bangle,banglaNumber);
    multiPleFileRead(fp_english,englishNumber);

    for(i = 0; i<9;i++){
        avg = (mathNumber[i]+banglaNumber[i]+englishNumber[i])/3;
        fprintf(fp_result,"%d %.1lf\n",i+1,avg);
        printf("%d %.1lf\n",i+1,avg);
    }

     printf("\nAlso check result.txt file it's updated.!taadaaa\n");
    fclose(fp_math);
    fclose(fp_result);
    return 0;
}



