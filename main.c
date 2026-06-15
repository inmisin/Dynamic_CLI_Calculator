#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


double ChooseOperator(double num1, double num2, char op)
{
    switch(op)
    {
        case '+':
            return num1+num2;
            
        case '-':
            return num1-num2;
            
        case '*':   
            return num1*num2;
            
        case '/':
            if(num2 == 0)
            {
                printf("Sıfıra bölemezsin! \n");
                return 0.0;
                break;
            }
            return num1/num2;
            
        default:
            printf("Lütfen geçerli bir işlem yazınız! \n");
            return 0.0;
            
    }
    return 1;
}

double CLI_Calculator(char *str)
{
    double num1 = 0.0;
    double num2 = 0.0;
    char operator;
    if(str == NULL)
    {
        printf("str NULL");
        return 0.0;
    }

    if(isalpha(str[0]))
    {
        printf("Geçersiz hesaplama! \n");
        return 0.0;
    }
    

    sscanf(str, "%lf %c %lf", &num1, &operator, &num2);

    return ChooseOperator(num1,num2,operator);
}

char *FindSize(char *str)
{
    int character;
    size_t strSize = 0;
    while((character = getchar()) != '\n'&& character != EOF)
    {
        if(character == 'q')
        {
            exit(EXIT_SUCCESS);
        }
        strSize++;
        char *temp = realloc(str, strSize * sizeof(char));
        // char *temp = (char *)malloc(strSize);
        if(temp == NULL)
        {
            printf("Yer ayarlanamadı\n");
            free(str);
            return NULL;
        }
        str = temp;
        str[strSize-1] = (char)character;
    }
    
    //printf("uzunluk %d", length); 

    strSize++;
    char *temp = realloc(str, strSize * sizeof(char));
    if(temp != NULL)
    {
        str = temp;
        str[strSize-1] = '\0';
    }
    else
    {
        printf("son düzlük");
    }
    return str;
    //printf("%s\n", str);
    //free(str);
}



int main()
{
    while (1)
    {
        char *str = NULL;
        printf("Bir hesaplama yazınız: \n");
        str = FindSize(str);
        //printf("Girdiğiniz hesaplama: %s \n", str);
        double temp = CLI_Calculator(str);
        printf("Calculation is: %.2f \n", temp);
        free(str);
    }
    
    
    return 0;
}




