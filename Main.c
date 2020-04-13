// Main.c : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include "recursion.h"
#include "tree.h"

int main()
{
    //Factorial
    printf("Factorial of 5: %d \n\n", factorial(5));
    
    //Sum of Digits
    printf("Digit sum of 1239875: %d \n\n", digitSum(1239875));
    
    //String reversal
    printf("String abcdefghi in reverse: "); 
        reversePrint("abcdefghi");
        printf("\n\n");
    
    //Check palindrome
    printf("Is string abhgfrtrfghba a palindrome? %s", checkPalindrome("abhgfrtrfghba"));
    printf("\n\n");
    
    //Print BST in Sorted order
    printf("Putting the numbers 1,0,5,3,785,-552,9547,2001,6465,-9899,-5,-665 in a BST and printing them in sorted order:\n\t");
        int insBst[]={ 1,0,5,3,785,-552,9547,2001,6465,-9899,-5,-665 };
        TreeNode* BST = insertBST(NULL, insBst[0]);
        //If the tree was created, insert the rest of the elements and traverse them
        if (BST != NULL) {
            for (int i = 1; i < 12; ++i) {
                //If the system runs out of memory, don't nsert more elements
                if (insertBST(BST, insBst[i]) == NULL) {
                    break;
                }
            }
            //Traverse the tree
            traverseInorder(BST);
        }
        printf("\n\n");

    //Check if String 1 is a subsequence of the 2nd
    printf("Is haavavas a subsequence of werhaweradsaaasvdaasdvdfagsrgwerfgw? %s", checkSubsequence("haavavas", "werhaweradsaaasvdaasdvdfagsrgwerfgw"));
        printf("\n\n");
    

}
