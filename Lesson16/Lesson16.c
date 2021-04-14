#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//  1.) Реализовать шифрование и расшифровку цезаря с передаваемым в функцию сообщением и ключом
//  char* caesar(char* in, int key, bool encrypt) bool encrypt - Если true, то происходит
//  шифрование строки char* in. Если false, то расшифровка
void printString(char* string){
    for(int i = 0; string[i] != '\0'; ++i){
        printf("%c", string[i]);
    }

    printf("\n");
}

char* caesar(char* in, int key, bool encrypt){
    int a;
    int size = (int)strlen(in);
    char *out =(char*) calloc(size + 1, sizeof (char));

    if(encrypt){
        for(int i = 0; in[i] != '\0'; ++i){
            a = (int)in[i];
            a += key;
            out[i] = (char)a;
        }

        return out;
    }
    else{
        for(int i = 0; in[i] != '\0'; ++i){
            a = (int)in[i];
            a -= key;
            out[i] = (char)a;
        }


        return out;
    }
}

void taskOne(){
    char string[] = "Hello world!";
    char *decrypted;
    char *encrypted;
    int key = 3;
    printString(string);

    bool encrypt = true;
    decrypted = caesar(string, key, encrypt);
    printString(decrypted);

    encrypt = false;
    encrypted = caesar(decrypted, key, encrypt);
    printString(encrypted);

    free(decrypted);
    free(encrypted);
}

//  2.) Реализовать шифрование и расшифровку перестановками с передаваемым в функцию сообщением и
//  количеством столбцов char* shuffle(char* in, int key, bool encrypt) bool encrypt - Если true,
//  то происходит шифрование строки char* in. Если false, то расшифровка
char* shuffle(char* in, int key, bool encrypt){
    int count = 0;
    int size = (int) strlen(in);
    char *out = (char*) calloc(size + 1, sizeof (char));

    if(encrypt){
        for(int i = 0; i < key; ++i){
            for(int j = 0; j + i < size; j += key){
                out[count] = in[j + i];
                count++;
            }
        }

        return out;
    }
    else{
        int step;
        if(size % key == 0){
           step = size / key;
        }
        else{
            step = size / key + 1;
        }

        for(int i = 0; i < step; ++i){
            for(int j = 0 ; j + i < size; j += step){
                out[count] = in[j + i];
                count++;
            }
        }

        return out;
    }
}

void taskTwo(){
    char string[] = "World say, little bit think:\"Hello!\"";
    char *decrypted;
    char *encrypted;
    int key = 4;
    printString(string);

    bool encrypt = true;
    decrypted = shuffle(string, key, encrypt);
    printString(decrypted);

    encrypt = false;
    encrypted = shuffle(decrypted, key, encrypt);
    printString(encrypted);
    free(decrypted);
    free(encrypted);
}

int main(const int argc, const char** argv){
    printf("TaskOne:\n");
    taskOne();
    printf("\n");
    printf("TaskTwo:\n");
    taskTwo();

    return 0;
}