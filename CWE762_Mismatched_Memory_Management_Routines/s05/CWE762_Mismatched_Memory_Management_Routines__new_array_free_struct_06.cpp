/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__new_array_free_struct_06.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__new_array_free.label.xml
Template File: sources-sinks-06.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * BadSource:  Allocate data using new []
 * GoodSource: Allocate data using malloc()
 * Sinks:
 *    GoodSink: Deallocate data using delete []
 *    BadSink : Deallocate data using free()
 * Flow Variant: 06 Control flow: if(STATIC_CONST_FIVE==5) and if(STATIC_CONST_FIVE!=5)
 *
 * */

#include "std_testcase.h"

/* The variable below is declared "const", so a tool should be able
   to identify that reads of this will always give its initialized
   value. */
static const int STATIC_CONST_FIVE = 5;

namespace CWE762_Mismatched_Memory_Management_Routines__new_array_free_struct_06
{

#ifndef OMITBAD

void bad()
{
    twoIntsStruct * data;
    /* Initialize data*/
    data = NULL;
    if(STATIC_CONST_FIVE==5)
    {
        /* POTENTIAL FLAW: Allocate memory with a function that requires delete [] to free the memory */
        data = new twoIntsStruct[100];
    }
    if(STATIC_CONST_FIVE==5)
    {
        /* POTENTIAL FLAW: Deallocate memory using free() - the source memory allocation function may
         * require a call to delete [] to deallocate the memory */
        free(data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G1() - use badsource and goodsink by changing the second STATIC_CONST_FIVE==5 to STATIC_CONST_FIVE!=5 */
static void goodB2G1()
{
    twoIntsStruct * data;
    /* Initialize data*/
    data = NULL;
    if(STATIC_CONST_FIVE==5)
    {
        /* POTENTIAL FLAW: Allocate memory with a function that requires delete [] to free the memory */
        data = new twoIntsStruct[100];
    }
    if(STATIC_CONST_FIVE!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Deallocate the memory using delete [] */
        delete [] data;
    }
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second if */
static void goodB2G2()
{
    twoIntsStruct * data;
    /* Initialize data*/
    data = NULL;
    if(STATIC_CONST_FIVE==5)
    {
        /* POTENTIAL FLAW: Allocate memory with a function that requires delete [] to free the memory */
        data = new twoIntsStruct[100];
    }
    if(STATIC_CONST_FIVE==5)
    {
        /* FIX: Deallocate the memory using delete [] */
        delete [] data;
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first STATIC_CONST_FIVE==5 to STATIC_CONST_FIVE!=5 */
static void goodG2B1()
{
    twoIntsStruct * data;
    /* Initialize data*/
    data = NULL;
    if(STATIC_CONST_FIVE!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Allocate memory from the heap using malloc() */
        data = (twoIntsStruct *)malloc(100*sizeof(twoIntsStruct));
        if (data == NULL) {exit(-1);}
    }
    if(STATIC_CONST_FIVE==5)
    {
        /* POTENTIAL FLAW: Deallocate memory using free() - the source memory allocation function may
         * require a call to delete [] to deallocate the memory */
        free(data);
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first if */
static void goodG2B2()
{
    twoIntsStruct * data;
    /* Initialize data*/
    data = NULL;
    if(STATIC_CONST_FIVE==5)
    {
        /* FIX: Allocate memory from the heap using malloc() */
        data = (twoIntsStruct *)malloc(100*sizeof(twoIntsStruct));
        if (data == NULL) {exit(-1);}
    }
    if(STATIC_CONST_FIVE==5)
    {
        /* POTENTIAL FLAW: Deallocate memory using free() - the source memory allocation function may
         * require a call to delete [] to deallocate the memory */
        free(data);
    }
}

void good()
{
    goodB2G1();
    goodB2G2();
    goodG2B1();
    goodG2B2();
}

#endif /* OMITGOOD */

} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE762_Mismatched_Memory_Management_Routines__new_array_free_struct_06; /* so that we can use good and bad easily */

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
