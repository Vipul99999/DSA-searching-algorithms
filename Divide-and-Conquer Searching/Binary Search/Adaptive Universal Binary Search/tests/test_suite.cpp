#include <iostream>

void testExactSearch();
void testExactSearchNotFound();

void testLowerBound();
void testUpperBound();

void testFirstOccurrence();
void testLastOccurrence();

void testInsertPosition();

void testPeakSearch();

void testRotatedSearch();

void testExponentialSearch();

void testBinarySearchAnswer();

int main()
{
    testExactSearch();
    testExactSearchNotFound();

    testLowerBound();
    testUpperBound();

    testFirstOccurrence();
    testLastOccurrence();

    testInsertPosition();

    testPeakSearch();

    testRotatedSearch();

    testExponentialSearch();

    testBinarySearchAnswer();

    std::cout
        << "================================\n";

    std::cout
        << "ALL AUBS TESTS PASSED\n";

    std::cout
        << "================================\n";

    return 0;
}