#include "pch.h"
#include "CppUnitTest.h"
#include "../lab2/Header1.h"
#include "../lab2/Header1.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestSort
{
	TEST_CLASS(TestSort)
	{
	public:
		TEST_METHOD(correct_BinarySearch)
		{
			int array[5] = { 0,1,2,3,4 };
			Assert::AreEqual(BinarySearch(5, array, 3), 3);
		}
		TEST_METHOD(incorrect_BinarySearch)
		{
			int array[5] = { 0,1,2,3,4 };
			Assert::AreEqual(BinarySearch(5, array, 5), -1);
		}
		TEST_METHOD(correct_QuickSort)
		{
			int array[5] = { 5,3,4,0,6 };
			QuickSort(array, 0, 4);
			Assert::AreEqual(array[2], 4);
		}
		TEST_METHOD(correct_BubbleSort)
		{
			int array[5] = { 5,3,4,0,6 };
			BubbleSort(array, 5);
			Assert::AreEqual(array[2], 4);
		}
		TEST_METHOD(correct_BogoSort)
		{
			int array[5] = { 5,3,4,0,6 };
			BogoSort(array, 5);
			Assert::AreEqual(array[2], 4);
		}
		TEST_METHOD(correct_CountingSort)
		{
			char array[5] = { 'B','A','G','C','V' };
			CountingSort(array, 5);
			Assert::AreEqual(array[2], 'C');
		}
	};
}
