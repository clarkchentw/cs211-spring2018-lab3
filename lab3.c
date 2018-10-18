#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

/* use of typedef simplifies variable declaration code 
 * Without typedef code would be:
 *    struct arrElemStruct e1;
 * With typedef (as written below) code can be:
 *    arrElem e1;
 */
typedef struct arrElemStruct
{
 double value1;
 int value2;
 int value3;
} arrElem;


void init1(arrElem el)
{
  el.value1 = (double)(rand()) * rand() / rand();
  el.value2 = rand() % 100;
  el.value3 = rand() % 1000;
  printf ("In init1(): value1: %14.5f, value2: %6d, value3: %6d\n",
           el.value1, el.value2, el.value3);
}

void init2(arrElem* el)
{
  el->value1 = (double)(rand()) * rand() / rand();
  el->value2 = rand() % 100;
  el->value3 = rand() % 1000;
  printf ("In init2(): value1: %14.5f, value2: %6d, value3: %6d\n",
           el->value1, el->value2, el->value3);
}

arrElem init3()
{
  arrElem el;

  el.value1 = (double)(rand()) * rand() / rand();
  el.value2 = rand() % 100;
  el.value3 = rand() % 1000;
  printf ("In init3(): value1: %14.5f, value2: %6d, value3: %6d\n",
           el.value1, el.value2, el.value3);
  return el;
}



int main (int argc, char**argv)
{
 
 /* */
  arrElem  var1, var2, var3;

  init1(var1);     /* FIRST CALL */
  printf ("In main() with var1: value1: %14.5f, value2: %6d, value3: %6d\n",
             var1.value1, var1.value2, var1.value3);

  init2(&var2);    /* SECOND CALL */
  printf ("In main() with var2: value1: %14.5f, value2: %6d, value3: %6d\n",
             var2.value1, var2.value2, var2.value3);

  var3 = init3();   /* THIRD CALL */
  printf ("In main() with var3: value1: %14.5f, value2: %6d, value3: %6d\n",
             var3.value1, var3.value2, var3.value3);

  printf ("\n\n");

//  return 1;   /* remove this line after answering question 2 */

  arrElem* ptr1;
  ptr1 = (arrElem*) malloc(sizeof(arrElem));
  init2(ptr1);

  printf ("In main() with ptr1: value1: %14.5f, value2: %6d, value3: %6d\n",
             ptr1->value1, ptr1->value2, ptr1->value3);

//    return 1;

  /* All three variables a1, a2, and a3 are intended to be used as *
   * some form of array of the struct type declared above.         */
  arrElem a1[SIZE]; 
  arrElem* a2[SIZE];
  arrElem* a3;
  int i;

  printf ("Calling init1()\n");
  for (i = 0 ; i < SIZE; ++i)
    {
     printf ("For position %d\n", i);
     init1 (a1[i]);                     /* FOURTH CALL */
     printf ("In main(): value1: %14.5f, value2: %6d, value3: %6d\n",
             a1[i].value1, a1[i].value2, a1[i].value3);
    }

  printf ("\nRepeating with init2()\n");
  for (i = 0 ; i < SIZE; ++i)
    {
     printf ("For position %d\n", i);
//     a1[i] = (arrElem) malloc(sizeof(arrElem));
     init2 (&(a1[i]));                 /* FIFTH CALL */
     printf ("In main(): value1: %14.5f, value2: %6d, value3: %6d\n",
             a1[i].value1, a1[i].value2, a1[i].value3);
    }

  printf ("\nRepeating call to init2() with a2\n");

  for (i = 0 ; i < SIZE; ++i)
    {
     printf ("For position %d\n", i);
     a2[i] = (arrElem*) malloc(sizeof(arrElem));
     init2 (a2[i]);                  /* SIXTH CALL */
     printf ("In main(): value1: %14.5f, value2: %6d, value3: %6d\n",
             a2[i]->value1, a2[i]->value2, a2[i]->value3);
    }

  printf ("\nRepeating call to init2() with a3\n");

  a3 = (arrElem*) malloc(sizeof(arrElem[10]));
  for (i = 0 ; i < SIZE; ++i)
    {
     printf ("For position %d\n", i);
     init2 (&(a3[i]));                  /* SEVENTH CALL */
     printf ("In main(): value1: %14.5f, value2: %6d, value3: %6d\n",
             a3[i].value1, a3[i].value2, a3[i].value3);
    }


}
