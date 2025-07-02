#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORDS_COUNT 200 // Items of dataset

// Struct to organize dataset items by field
struct wordsDict {
    char enWord[100]; // English words column
    char itWord[100]; // Italian words column
};

// Functions declaration
void readData(struct wordsDict arrDict[]);
int wordToIndex(char wordKey[], struct wordsDict arrDict[]);

// Main function
int main (void) {

    struct wordsDict arrDict[WORDS_COUNT]; // Array dictionary
    char wordKey[46]; // Longest english word has 45 characters (plus terminator \0)

    printf("Start execution...\n");

    readData(arrDict); // Read dataset

    printf("Insert the word to search: ");
    scanf("%s", wordKey);

    // Search word and print translation
    int index = wordToIndex(wordKey, arrDict);
    if(index != -1){
        printf("The translated word is: %s\n", arrDict[index].itWord);
    } else {
        printf("Word not found!\n");
    }
    

    printf("Execution stopped.\n");

    return 0;
}

// Function to read data and store data from dataset
void readData(struct wordsDict arrDict[]) {
    
    FILE *fptr = fopen("dataset/en_it_words.csv", "r");
    if(fptr == NULL){
        printf("File opening failed!");
        return; // Exit from function without code because is void function
    }

    // Skip first row (column headers)
    char buffer[256];
    fgets(buffer, sizeof(buffer), fptr);

    int i = 0;
    while(fgets(buffer, sizeof(buffer), fptr) && i < WORDS_COUNT) {
        strcpy(arrDict[i].enWord, strtok(buffer, ",")); // Copy english word into the array
        char *token = strtok(NULL, ",");
        if(token != NULL){
            token[strcspn(token, "\n")] = '\0'; // Delete newline
            strcpy(arrDict[i].itWord, token); // Copy the italian word into the array
        }
        i++;
    }

    fclose(fptr); // Close file

}

// Function to convert word to index
int wordToIndex(char wordKey[], struct wordsDict arrDict[]) {
    for(int i = 0; i < WORDS_COUNT; i++){
        if (strcmp(wordKey, arrDict[i].enWord) == 0){
            return i;
        }
    }
    return -1; // Not found code
}