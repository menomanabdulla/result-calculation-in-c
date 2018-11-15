#include <stdio.h>
#include <stdlib.h>

void multiPleFileRead(char *fp_in,char *fp_out){
    int num,i=0;
    char line[80];

    while(fgets(line,80,fp_in) != NULL ){
        line[strlen(line)-1] = '\0';
        sscanf(line,"%*d %d",&num);
        //sum = num1+num2;
        //printf("%d + %d = %d \n",num1,num2,sum);
        printf("%d \n",num);
        fprintf(fp_out,"%d -l\n",num);
    }

}
int main()
{
    FILE *fp_math,*fp_bangle,*fp_english,*fp_avg,*fp_result;
    char *math_file = "./file/math.txt";
    char *bangla_file = "./file/bangla.txt";
    char *english_file = "./file/english.txt";
    char *avg_file = "./file/avg.txt";
    char *result_file = "./file/result.txt";

    fp_math = fopen(math_file,"r");
    //fp_bangle = fopen(bangla_file,"r");
    //fp_english = fopen(english_file,"r");

    fp_avg = fopen(avg_file,"a");
    fp_result = fopen(fp_result,"a");

    //printf("Hello world!\n");
    multiPleFileRead(fp_math,fp_avg);


    return 0;
}
