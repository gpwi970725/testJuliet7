/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Memory_Not_on_Heap__delete_class_static_66a.cpp
Label Definition File: CWE590_Free_Memory_Not_on_Heap__delete.nonpointer.label.xml
Template File: sources-sink-66a.tmpl.cpp
*/
/*
 * @description
 * CWE: 590 Free Memory Not on Heap
 * BadSource: static Data buffer is declared static on the stack
 * GoodSource: Allocate memory on the heap
 * Sinks:
 *    BadSink : Print then free data
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE590_Free_Memory_Not_on_Heap__delete_class_static_66
{

#ifndef OMITBAD

/* bad function declaration */
void badSink(TwoIntsClass * dataArray[]);

void bad()
{
    TwoIntsClass * data;
    TwoIntsClass * dataArray[5];
    data = NULL; /* Initialize data */
    {
        /* FLAW: data is allocated on the stack and deallocated in the BadSink */
        static TwoIntsClass dataBuffer;
        dataBuffer.intOne = 1;
        dataBuffer.intTwo = 1;
        data = &dataBuffer;
    }
    /* put data in array */
    dataArray[2] = data;
    badSink(dataArray);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declarations */

/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink(TwoIntsClass * dataArray[]);

static void goodG2B()
{
    TwoIntsClass * data;
    TwoIntsClass * dataArray[5];
    data = NULL; /* Initialize data */
    {
        /* FIX: data is allocated on the heap and deallocated in the BadSink */
        TwoIntsClass * dataBuffer = new TwoIntsClass;
        dataBuffer->intOne = 2;
        dataBuffer->intTwo = 2;
        data = dataBuffer;
    }
    dataArray[2] = data;
    goodG2BSink(dataArray);
}

void good()
{
    goodG2B();
}

#endif /* OMITGOOD */

} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE590_Free_Memory_Not_on_Heap__delete_class_static_66; /* so that we can use good and bad easily */

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
