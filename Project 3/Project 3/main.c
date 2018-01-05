/*  main.c */
/*  Project 3 */
/*  Created by Nate McCain on 10/9/17. */
/*  Copyright © 2017 Nate McCain. All rights reserved. */

#include <stdio.h>
#include <stdlib.h>
#include "ProjectThreeFunctions.h"

int main()
{
    // This is the variable that holds all of the sentences.
    char **sentenceHolder;
    
    // Run the startup dialog.
    int numOfSentences = startupDialog();
    
    // If the person cannot follow instructions, exit the program.
    if (numOfSentences <= 0 || numOfSentences > 10)
    {
        printf("It appears that you cannot follow instructions. Goodbye. \n");
        return 1;
    }
    
    // Allocate space for the array of character arrays.
    sentenceHolder = (char **)malloc(numOfSentences * sizeof(char *));
    
    // Get the user's input
    getUserInputSentences(sentenceHolder, numOfSentences);
    
    // Convert the strings to all uppercase.
    convertAllToUpperCase(sentenceHolder, numOfSentences);
    
    // Print out the uppercase sentences.
    printOutConvertedSentences(sentenceHolder, numOfSentences);
    
    // Count the number of characters, including whitespace.
    countAllCharactersIncludingWhitespace(sentenceHolder, numOfSentences);
    
    // Count the number of characters, excluding whitespace.
    countAllCharactersExcludingWhitespace(sentenceHolder, numOfSentences);
    
    // Free up the memory that was allocated earlier.
    freeUpMemory(sentenceHolder, numOfSentences);
    
    // End of the program.
    return 0;
}
