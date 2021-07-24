//
//  main.cpp
//  280Project1
//
//  Created by Zhoujiaxi on 5/31/18.
//  Copyright  2018 Zhoujiaxi. All rights reserved.
//


#include <iostream>
#include <string>

#include "p1.h"
#include "rand.h"

using namespace std;

int main() {
    
    /*PART1: random a word*/
    
    int seed;
    cout << "Please input seed: ";
    cin >> seed;
    p1_srand(seed);
    int a = p1_rand()%49;
    string word = words[a];
    
    
    /*VARIABLES*/
    
    int wordlen = 0;  //length of the word generated
    wordlen = word.length();
    
    int score = 0;              //score
    char propchar[10] = {0};    //store already proposed characters
    int prop_num = 0;           //number of those already proposed characters
    
    int flag[20] = {0};         //record whether a character in the word has been guessed: 0 - no; 1 - right
    
    int p = 1;                  //signal for existing the while loop
    char x = 0;                 //the current character entered
    
    
    /*PART2: HANGMAN loop starts*/
    
    while (score < 10 && p==1) {
        
        p = 0;                      //signal!
        
        //1# display the score
        cout << "Score: " << score << endl;
        
        //2# display the word
        for (int i=0; i< wordlen; i++){
            if (flag[i]==0) {
                cout << "_ ";
            }else {
                cout << word[i] << " ";
            }
        }
        cout << endl;
        
        //3# display already proposed characters
        cout << "Already proposed characters: " << endl;
        for (int i=0; i<prop_num-1; i++){
            for(int j=0; j<prop_num-1-i; j++){
                if (propchar[j]>propchar[j+1]) {
                    char temp = propchar[j];
                    propchar[j] = propchar[j+1];
                    propchar[j+1]=temp;
                }
            }
        }
        for (int i=0; i<prop_num; i++){
            cout << propchar[i] << " ";
        }
        cout << endl;
        
        //4# make a guess round
        int s = 0;                  //signal to judge whether a x need to be stored in propchar!
        
        cout << "Please enter a letter (a-z): " ;
        cin >> x;
        
        for (int k=0; k< wordlen; k++){
            if (word[k]==x) {
                flag[k]=1;
                s = 1;
            }
        }                           //in the word, so no need to be recorded
        
        for (int i=0; i<prop_num; i++) {
            if (propchar[i]==x) {
                s = 1;
            }
        }                           //has been guessed previously, so no need to be recorded
        
        if (s==0) {
            score ++;
            *(propchar + prop_num) = x;
            prop_num ++;
        }                           //need to be recorded
        
        for (int i=0; i< wordlen; i++){
            if (flag[i]==0) {
                p = 1;          //signal!
            }
        }
        
    }
    
    
    /*PART3: game ends*/
    if (p==1) {
        cout << "The word was: " << word << endl;
        cout << "You lost! "<< endl;
    } else {
        cout << "The word was: " << word << endl;
        cout << "You won! "<< endl;
    }
    
    
    return 0;
}
