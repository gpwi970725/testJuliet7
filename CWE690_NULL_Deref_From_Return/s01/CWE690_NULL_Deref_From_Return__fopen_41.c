/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__fopen_41.c
Label Definition File: CWE690_NULL_Deref_From_Return.fclose.label.xml
Template File: source-sinks-41.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * BadSource: fopen Open data with fopen()
 * Sinks: 0
 *    GoodSink: Check data for NULL
 *    BadSink : Do not check data for NULL
 * Flow Variant: 41 Data flow: data passed as an argument from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

static void badSink(FILE * data)
{
    /* FLAW: if the fopen failed, data will be NULL here */
    fclose(data);
}

void CWE690_NULL_Deref_From_Return__fopen_41_bad()
{
    FILE * data;
    /* Initialize data */
    data = NULL;
    /* POTENTIAL FLAW: Open a file without checking the return value for NULL */
    data = fopen("file.txt", "w+");
    badSink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

static void goodB2GSink(FILE * data)
{
    /* FIX: check the return value */
    if (data != NULL)
    {
        fclose(data);
    }
}

/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G()
{
    FILE * data;
    /* Initialize data */
    data = NULL;
    /* POTENTIAL FLAW: Open a file without checking the return value for NULL */
    data = fopen("file.txt", "w+");
    goodB2GSink(data);
}

void CWE690_NULL_Deref_From_Return__fopen_41_good()
{
    goodB2G();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE690_NULL_Deref_From_Return__fopen_41_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE690_NULL_Deref_From_Return__fopen_41_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
