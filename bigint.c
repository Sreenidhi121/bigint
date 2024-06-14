#include <stdio.h>
#include <string.h>

#define SIZE 1025

typedef struct {
    char digits[SIZE];
    int length;
} BigInt;



// Initialize a BigInt with a string representation
void initializeBigint(BigInt *num) 
{
    char str[SIZE]="";

    scanf("%s", str);
    num->length = strlen(str);
    for (int i = 0; i < num->length; i++) {
        num->digits[i] = str[num->length - 1 - i] - '0'; // Convert character to digit
    }
}
//initailly setting bigints as 0
void ResetBigint(BigInt *num) 
{
    for (int i = 0; i < SIZE; i++) {
        num->digits[i] = 0;
    }
    num->length = 1;
}

// Adding two bigints
void addBigInt(const BigInt *a, const BigInt *b, BigInt *result) {
    int carry = 0;
    
    for (int i = 0; i < SIZE; i++) {
        int sum = a->digits[i] + b->digits[i] + carry;
        result->digits[i] = sum % 10;  // Store the least significant digit
        carry = sum / 10; 
    }

    // set the size of the result
    for (int i = SIZE - 1; i >= 0; i--) {
        if (result->digits[i] != 0) {
            result->length = i + 1;
            break;
        }
    }
}

// subracting two bigints
void subtractBigInt(BigInt *a, BigInt *b, BigInt *result) {
   
    int x=0,y=0;
    x=a->length;
    y=b->length;
    int borrow = 0;
    // comparing the two bigints
    
       if(x==y){
  for (int j = a->length ; j >= 0; j--) {
        if (a->digits[j] > b->digits[j]){
    for (int i = 0; i < SIZE; i++) {
        int diff = a->digits[i] - b->digits[i] - borrow;

        if (diff < 0) {
            diff =diff +10;  // Borrow from the next higher digit
            borrow = 1;
        } else {
            borrow = 0;
        }
    
        result->digits[i] = diff % 10;  // Store the least significant digit
    }
   }else{
    for (int i = 0; i < SIZE; i++) {
        int diff = b->digits[i] - a->digits[i] - borrow;

        if (diff < 0) {
            diff =diff +10;  // Borrow from the next higher digit
            borrow = 1;
        } else {
            borrow = 0;
        }

        result->digits[i] = diff % 10;  // Store the least significant digit
    }
   }
  }
  }
   if(x>y) {
    for (int i = 0; i < SIZE; i++) {
        int diff = a->digits[i] - b->digits[i] - borrow;

        if (diff < 0) {
            diff =diff +10;  // Borrow from the next higher digit
            borrow = 1;
        } else {
            borrow = 0;
        }
    
        result->digits[i] = diff % 10;  // Store the least significant digit
    }
   }
 
   else{
    for (int i = 0; i < SIZE; i++) {
        int diff = b->digits[i] - a->digits[i] - borrow;

        if (diff < 0) {
            diff =diff +10;  // Borrow from the next higher digit
            borrow = 1;
        } else {
            borrow = 0;
        }

        result->digits[i] = diff % 10;  // Store the least significant digit
    }
   }

    
    // set the size of the result
    for (int i = SIZE - 1; i >= 0; i--) {
        if (result->digits[i] != 0) {
            result->length = i + 1;
            break;
        }
    }
}


// Multiply two BigInts
void multiplyBigInt(const BigInt *a, const BigInt *b, BigInt *result) {
 
 for (int i = 0; i < SIZE; i++) {
        int carry = 0;

        for (int j = 0; j < SIZE - i; j++) {
            int product = a->digits[i] * b->digits[j] + result->digits[i + j] + carry;

            result->digits[i + j] = product % 10; // Store the least significant digit
            carry = product / 10; // Carry for the next iteration
        }
    }


    // set the size of the result
    for (int i = SIZE - 1; i >= 0; i--) {
        if (result->digits[i] != 0) {
            result->length = i + 1;
            break;
        }
    }
}

// Print a BigInt
void printBigInt(const BigInt *num) {
    for (int i = num->length - 1; i >= 0; i--) {
        printf("%d", num->digits[i]);
    }
    printf("\n");
}

int main() {
    BigInt a, b, result;
 ResetBigint(&a);
 ResetBigint(&b);

    printf("Enter the first number: ");
    initializeBigint(&a);
    printf("Enter the second number: ");
    initializeBigint(&b);

ResetBigint(&result);
    addBigInt(&a, &b, &result);
    printf("Sum: ");
    printBigInt(&result);
ResetBigint(&result);
    subtractBigInt(&a,&b,&result);
    printf("subtraction:");
    printBigInt(&result);
ResetBigint(&result);   
    multiplyBigInt(&a, &b, &result);
    printf("Product: ");
    printBigInt(&result);
ResetBigint(&result);

    return 0;
}

