#include <stdio.h>
#include <stdlib.h>



double ChooseOperator(double num1, double num2, char op)
{
    switch(op)
    {
        case '+':
            return (float)num1+num2;
            break;
        case '-':
            return (float)num1-num2;
            break;
        case '*':   
            return (float)num1*num2;
            break;
        case '/':
            return (float)num1/num2;
            break;
        default:
            printf("Lütfen geçerli bir işlem yazınız! \n");
            return 0.0f;
            break;
    }
    return 1;
}

double CLI_Calculator(char *str)
{
    float num1 = 0.0;
    float num2 = 0.0;
    char operator;
    if(str == NULL)
    {
        printf("str NULL");
        return 0.0;
    }

    sscanf(str, "%f %c %f", &num1, &operator, &num2);

    if(num1 == 0.0)
    {
        //printf("num1 0.0 \n");
        return 0.0;
    }

    return ChooseOperator(num1,num2,operator);
}

char *FindSize(char *str)
{
    int character;
    size_t strSize = 0;
    while((character = getchar()) != '\n'&& character != EOF)
    {
        strSize++;
        char *temp = realloc(str, strSize * sizeof(char));
        if(temp == NULL)
        {
            printf("Yer ayarlanamadı\n");
            free(str);
            return NULL;
        }
        str = temp;

        str[strSize-1] = (char)character;
    }

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
        float temp = CLI_Calculator(str);
        if(temp == 0.0)
        {
            printf("Numara okunamadı! \n");
        }
        else
        {
            printf("Calculation is: %.2f \n", temp);
        }
        free(str);
    }
    
    
    return 0;
}




