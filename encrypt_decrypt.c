#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char encrypt(char p){ //Encryption Function
    int ran;
    char c;
    char p1;
    char c1;
    ran = random() %97;
    if (p =='\t'){
        p1 = 0;
    }else if(p =='\n'){
        p1 = 1;
    }else{
        p1 = p-30;
    }
    c1 = (p1 + ran) %97;
    if (c1 == 0){
        c = '\t';
    }else if (c1 == 1){
        c = '\n';
    }else{
        c = c1 + 30;
    }
    return c; //return of encrypted charchter
}
char decrypt(char p){ //Decryption Function
    int ran;
    char c;
    char p1;
    char c1;
    ran = random() %97;
    if (p =='\t'){
        p1 = 0;
    }else if(p =='\n'){
        p1 = 1;
    }else{
        p1 = p-30;
    }
    c1 = (p1 + 97 - ran) %97;
    if (c1 == 0){
        c = '\t';
    }else if (c1 == 1){
        c = '\n';
    }else{
        c = c1 + 30;
    }
    return c;//return of decrypted charchter
}
int main(int argc, char *argv[]){ //Main Function
    if (argc != 5){ //Takes 5 Arguments
        printf("ERROR: Incorrect Number of Arguments!"); // Error message
        exit(0); //Exit Program
    }
    FILE *input;
    FILE *output;
    char mode[1000];
    char in[1000];
    char out[1000]; //Intialization of variables
    int key = *argv[1]; // intialization and setting of variable key to first argument
    strcpy(mode, argv[2]); //Copying String of argument 2 into mode
    strcpy(in, argv[3]); //Copying String of argument 3 into in
    strcpy(out, argv[4]); //Copying String of argument 4 into out
    int c;
	  srandom(key); //Seeding random with key
    if (strcmp(mode,"ENCRYPT")==0){ //If mode = encryption
        printf("Encryption of %s has intiated!\n", in); //prints message
        input = fopen(in, "r"); //opens input file
        output = fopen(out, "w"); //opens output file
        if (input == NULL){ // checks if input file exists
            printf("Error: %s Not Found!", in); //prints error message
            exit(0); // exits program
        }
        while ((c = fgetc(input)) != EOF){ // checks if end of file and takes next charchter
           fputc(encrypt(c),output); // sends charchter to encryption function then saves in in output file
        }
        fclose(input); // closes input file
        fclose(output); // closes output file
        printf("Encrypted file has been written to %s!\n", out); // prints message
    }else if (strcmp(mode,"DECRYPT")==0){ //If mode = Decryption
        printf("Decryption of %s has intiated!\n", in); //prints message
        input = fopen(in, "r"); // opens input file
        output = fopen(out, "w"); //opens output file
        if (input == NULL){ //checks input file exists
            printf("Error: %s Not Found!", in); //Prints error message
            exit(0); //exits program
        }
        while ((c = fgetc(input)) != EOF){ // checks if end of file and takes next charchter
           fputc(decrypt(c),output); // sends charchter to decryption function then saves in in output file
        }
        fclose(input); //closes input file
        fclose(output); //closes output file
        printf("Decrypted file is being written to %s!\n", out); // prints message
    }
    return 0;
}