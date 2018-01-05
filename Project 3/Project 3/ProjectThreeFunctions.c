/*  ProjectThreeFunctions.c */
/*  Project 3 */
/*  Created by Nate McCain on 10/10/17. */
/*  Copyright © 2017 Nate McCain. All rights reserved. */

#include "ProjectThreeFunctions.h"

// Welcome the user and find out how many sentences they wish to enter.
// Return the user's response.
int startupDialog(void)
{
    int numOfSentences;
    
    printf("Welcome. \n");
    printf("Please tell me how many sentences you wish to enter (no more than 10): ");
    scanf("%d", &numOfSentences);
    
    return numOfSentences;
}

// Get the sentences from the user.
// Each sentence is added to the sentence list.
void getUserInputSentences(char **sentenceList, int numOfSentences)
{
    int i, j; // Variables required by the for loops.
    
    printf("You entered %d. Please enter your sentences one at a time. A sentence can only store 100 characters. \n", numOfSentences);
    int needToClearInputStream; // Acts as a boolean value.
    
    // Clear the standard input stream. Prevents the first
    // fgets() from storing '\n' as the user's first input.
    while (getchar() != '\n');
    
    // Repeatedly get the user's input.
    for (i = 0; i < numOfSentences; i += 1)
    {
        // Allocate the required memory in the character array for the user's next input.
        sentenceList[i] = (char *)malloc(102 * sizeof(char));
        
        // Ask for the user's sentence.
        printf("Enter Sentence #%d: ", i+1);
        
        // Get the user's sentence.
        fgets(sentenceList[i], 102, stdin);
        
        // Scan the imported sentence for the newline character. If it does not have a newline character,
        // then we need to clear the input stream.
        needToClearInputStream = 1;
        for (j = 0; j < 102; j += 1)
        {
            // If the newline character is found, exit the for loop.
            if (sentenceList[i][j] == '\n')
            {
                needToClearInputStream = 0;
                j = 200;
            }
        }
        
        // Clear the input stream, and replace the character before the null character in the latest
        // sentence with the newline character.
        if (needToClearInputStream == 1)
        {
            sentenceList[i][100] = '\n';
            while (getchar() != '\n');
        }
    }
}

// Convert the given character array to all uppercase.
void convertSentence(char *sentence)
{
    int i; // Variable required by the for loop.
    
    // Conversion takes place one character at a time.
    for (i = 0; i < 100; i += 1)
    {
        sentence[i] = toupper(sentence[i]);
    }
}

// Function that sends each character array in the list to the
// convertSentence function.
void convertAllToUpperCase(char **sentenceList, int numOfSentences)
{
    int i; // Variable required by the for loop.
    
    for (i = 0; i < numOfSentences; i += 1)
    {
        convertSentence(sentenceList[i]);
    }
}

// Counts the number of characters in a sentence, including
// whitespace, and return the count.
int countCharactersInSentenceIncludingWhitespace(char *sentence)
{
    int i; // Variable required by the for loop.
    
    // Variable that keeps track of the size of the sentence, including whitespace.
    int sizeOfString = 0;
    
    for (i = 0; i < 100; i += 1)
    {
        // If we reach a newline or null terminator,
        // exit the for loop.
        if (sentence[i] == '\n' || sentence[i] == '\0')
        {
            i = 100;
        }
        
        // Otherwise, increment the size of the string.
        else
        {
            sizeOfString += 1;
        }
    }
    
    // Return the size of the sentence, including whitespace.
    return sizeOfString;
}

// Get the total character count, including whitespaces, from the sentence list.
void countAllCharactersIncludingWhitespace(char **sentenceList, int numOfSentences)
{
    int i; // Variable required by the for loop.
    
    // Variable that keeps track of the size of all the sentences, including whitespace.
    int countIncludingWhitespace = 0;
    
    for (i = 0; i < numOfSentences; i += 1)
    {
        countIncludingWhitespace += countCharactersInSentenceIncludingWhitespace(sentenceList[i]);
    }
    
    // Print out the number of characters entered by the user, including whitespace.
    printf("There are %d Characters when including the whitespace. \n", countIncludingWhitespace);
}

// Counts the number of characters in a sentence, excluding
// whitespace, and return the count.
int countCharactersInSentenceExcludingWhitespace(char *sentence)
{
    int i; // Variable required by the for loop.
    
    // Variable that keeps track of the size of the sentence, excluding whitespace.
    int sizeOfString = 0;
    
    for (i = 0; i < 100; i += 1)
    {
        // If a newline or null character is reached,
        // exit the for loop.
        if (sentence[i] == '\n' || sentence[i] == '\0')
        {
            i = 100;
        }
        
        // Don't increment if a whitespace character is read.
        else if (sentence[i] == ' ')
        {
            // Do nothing.
        }
        
        // Otherwise, increment the count.
        else
        {
            sizeOfString += 1;
        }
    }
    
    // Return the size of the sentence, excluding whitespace.
    return sizeOfString;
}

// Get the total character count, excluding whitespaces, from the sentence list.
void countAllCharactersExcludingWhitespace(char **sentenceList, int numOfSentences)
{
    int i; // Variable required by the for loop.
    
    // Variable that keeps track of the size of all sentences, excluding whitespace.
    int countExcludingWhitespace = 0;
    
    for (i = 0; i < numOfSentences; i += 1)
    {
        countExcludingWhitespace += countCharactersInSentenceExcludingWhitespace(sentenceList[i]);
    }
    
    // Print out the number of characters entered, excluding whitespace.
    printf("There are %d Characters when excluding the whitespace. \n", countExcludingWhitespace);
}

// Print to the console the given character array.
void printOutConvertedSentence(char *sentence)
{
    // Print out the sentence that is passed in.
    printf("%s", sentence);
}

// Pass every character array in the sentence list to the print function.
void printOutConvertedSentences(char **sentenceList, int numOfSentences)
{
    int i; // Variable required by the for loop.
    
    // Let the user know what we are doing.
    printf("Your converted sentences are: \n");
    
    // Print out each sentence in the list.
    for (i = 0; i < numOfSentences; i += 1)
    {
        printOutConvertedSentence(sentenceList[i]);
    }
}

// Deallocate all of the memory used by the sentence list.
void freeUpMemory(char **sentenceList, int numOfSentences)
{
    int i; // Variable required by the for loop.
    
    // Start by deallocating each character array.
    for (i = 0; i < numOfSentences; i += 1)
    {
        free(sentenceList[i]);
    }
    
    // Finish by deallocating the memory for the array of character arrays.
    free(sentenceList);
}
