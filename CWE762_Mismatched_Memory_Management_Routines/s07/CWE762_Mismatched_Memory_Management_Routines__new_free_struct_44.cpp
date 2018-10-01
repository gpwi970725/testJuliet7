/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__new_free_struct_44.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__new_free.label.xml
Template File: sources-sinks-44.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * BadSource:  Allocate data using new
 * GoodSource: Allocate data using malloc()
 * Sinks:
 *    GoodSink: Deallocate data using delete
 *    BadSink : Deallocate data using free()
 * Flow Variant: 44 Data/control flow: data passed as an argument from one function to a function in the same source file called via a function pointer
 *
 * */

#include "std_testcase.h"

namespace CWE762_Mismatched_Memory_Management_Routines__new_free_struct_44
{

#ifndef OMITBAD

static void badSink(twoIntsStruct * data)
{
    /* POTENTIAL FLAW: Deallocate memory using free() - the source memory allocation function may
     * require a call to delete to deallocate the memory */
    free(data);
}

void bad()
{
    twoIntsStruct * data;
    /* define a function pointer */
    void (*funcPtr) (twoIntsStruct *) = badSink;
    /* Initialize data*/
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory with a function that requires delete to free the memory */
    data = new twoIntsStruct;
    /* use the function pointer */
    funcPtr(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2BSink(twoIntsStruct * data)
{
    /* POTENTIAL FLAW: Deallocate memory using free() - the source memory allocation function may
     * require a call to delete to deallocate the memory */
    free(data);
}

static void goodG2B()
{
    twoIntsStruct * data;
    void (*funcPtr) (twoIntsStruct *) = goodG2BSink;
    /* Initialize data*/
    data = NULL;
    /* FIX: Allocate memory from the heap using malloc() */
    data = (twoIntsStruct *)malloc(100*sizeof(twoIntsStruct));
    if (data == NULL) {exit(-1);}
    funcPtr(data);
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2GSink(twoIntsStruct * data)
{
    /* FIX: Deallocate the memory using delete */
    delete data;
}

static void goodB2G()
{
    twoIntsStruct * data;
    void (*funcPtr) (twoIntsStruct *) = goodB2GSink;
    /* Initialize data*/
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory with a function that requires delete to free the memory */
    data = new twoIntsStruct;
    funcPtr(data);
}

void good()
{
    goodG2B();
    goodB2G();
}

#endif /* OMITGOOD */

} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE762_Mismatched_Memory_Management_Routines__new_free_struct_44; /* so that we can use good and bad easily */

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
