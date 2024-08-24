#include <stdio.h>
#include <stdlib.h>


struct Term {
    int coefficient;
    int exponent;
    struct Term *next;
};

struct Term *createTerm(int coef, int exp) {
    struct Term *newTerm = (struct Term *)malloc(sizeof(struct Term));
    if (newTerm == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newTerm->coefficient = coef;
    newTerm->exponent = exp;
    newTerm->next = NULL;
    return newTerm;
}


void addToPolynomial(struct Term **poly, int coef, int exp) {
    struct Term *newTerm = createTerm(coef, exp);
    if (*poly == NULL) {
        *poly = newTerm;
    } else {
        struct Term *current = *poly;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newTerm;
    }
}


struct Term *addPolynomials(struct Term *poly1, struct Term *poly2) {
    struct Term *result = NULL;
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exponent > poly2->exponent) {
            addToPolynomial(&result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        } else if (poly1->exponent < poly2->exponent) {
            addToPolynomial(&result, poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        } else {
            int sum = poly1->coefficient + poly2->coefficient;
            if (sum != 0) {
                addToPolynomial(&result, sum, poly1->exponent);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    while (poly1 != NULL) {
        addToPolynomial(&result, poly1->coefficient, poly1->exponent);
        poly1 = poly1->next;
    }
    while (poly2 != NULL) {
        addToPolynomial(&result, poly2->coefficient, poly2->exponent);
        poly2 = poly2->next;
    }
    return result;
}

void displayPolynomial(struct Term *poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }
    while (poly != NULL) {
        printf("%dx^%d ", poly->coefficient, poly->exponent);
        if (poly->next != NULL) {
            printf("+ ");
        }
        poly = poly->next;
    }
    printf("\n");
}


void freePolynomial(struct Term *poly) {
    while (poly != NULL) {
        struct Term *temp = poly;
        poly = poly->next;
        free(temp);
    }
}

int main() {
    struct Term *poly1 = NULL;
    struct Term *poly2 = NULL;
    struct Term *result = NULL;

    int numTerms1, numTerms2;
    int coef, exp;

    printf("Enter the number of terms in Polynomial 1: ");
    scanf("%d", &numTerms1);

    printf("Enter the terms of Polynomial 1 (coefficient exponent):\n");
    int i;
    for (i = 0; i < numTerms1; i++) {
        scanf("%d %d", &coef, &exp);
        addToPolynomial(&poly1, coef, exp);
    }

    printf("Enter the number of terms in Polynomial 2: ");
    scanf("%d", &numTerms2);

    printf("Enter the terms of Polynomial 2 (coefficient exponent):\n");
    for (i = 0; i < numTerms2; i++) {
        scanf("%d %d", &coef, &exp);
        addToPolynomial(&poly2, coef, exp);
    }

    printf("Polynomial 1: ");
    displayPolynomial(poly1);

    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    result = addPolynomials(poly1, poly2);

    printf("Result of addition: ");
    displayPolynomial(result);

    
    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(result);

    return 0;
}
