/*  ProjectThreeFunctions.h */
/*  Project 3 */
/*  Created by Nate McCain on 10/10/17. */
/*  Copyright © 2017 Nate McCain. All rights reserved. */


#ifndef ProjectThreeFunctions_h
#define ProjectThreeFunctions_h

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int startupDialog(void);

void getUserInputSentences(char **sentenceList, int numOfSentences);

void convertSentence(char *sentence);

void convertAllToUpperCase(char **sentenceList, int numOfSentences);

int countCharactersInSentenceIncludingWhitespace(char *sentence);

void countAllCharactersIncludingWhitespace(char **sentenceList, int numOfSentences);

int countCharactersInSentenceExcludingWhitespace(char *sentence);

void countAllCharactersExcludingWhitespace(char **sentenceList, int numOfSentences);

void printOutConvertedSentence(char *sentence);

void printOutConvertedSentences(char **sentenceList, int numOfSentences);

void freeUpMemory(char **sentenceList, int numOfSentences);

#endif /* ProjectThreeFunctions_h */
