#include<stdio.h>
#include"sm.h"
#include<string.h>

int searchFirstOccurrence(char *pattern, char *text){
    int patternLength = strlen(pattern);
    int textLength = strlen(text);
    int flag = 0;
    for(int i = 0;i<textLength - patternLength;i++){
        flag = 1;
        for(int j=0;j<patternLength && flag;j++){
            if(text[i+j] != pattern[j]){
                flag = 0;
            }
        }
        if(flag)
            return i;
    }
    return -1;
}

int searchLastOccurrence(char *pattern, char *text){
    int patternLength = strlen(pattern);
    int textLength = strlen(text);
    int flag = 1;
    for(int i = textLength - patternLength -1;i>=0;i--){
        flag = 1;
        for(int j=0;j<patternLength && flag;j++){
            if(text[i+j] != pattern[j]){
                flag =0;
            }
        }
        if(flag)
            return i;
    }
    return -1;
}

int numOccurrences(char* pattern,char* text){
    int patternLength = strlen(pattern);
    int textLength = strlen(text);
    int flag = 0;
    int  count = 0;
    for(int i = 0;i<=textLength - patternLength;i++){
        flag = 1;
        for(int j=0;j<patternLength && flag;j++){
            if(text[i+j] != pattern[j]){
                flag = 0;
            }
        }
        if(flag)
            count++;;
    }
    return count;
}

int longestPrefix(char *pattern, char *text){
    int patternLength = strlen(pattern);
    int textLength = strlen(text);
    int flag = 0;
    int max = 0;
    int temp = 0;
    for(int i = 0;i<=textLength - patternLength ;i++){
        flag = 1;
        temp =0;
        for(int j = 0;j<patternLength && flag;j++){
            if(text[i+j] != pattern[j]){
                flag = 0;
            }
            else
                temp++;
                    
        }
        if(temp>max)
            max = temp;
    }
    return max;
}


int charactersCompared(char *pattern, char *text){
    int patternLength = strlen(pattern);
    int textLength = strlen(text);
    int flag = 0;
    int  count = 0;
    for(int i = 0;i<=textLength - patternLength;i++){
        flag = 1;
        int j=0;
        for(;j<patternLength && flag;j++){
            if(text[i+j] != pattern[j]){
                flag = 0;
            }
        }
        count+=j;
    }
    return count;
}