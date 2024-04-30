#include "pch.h"
#include "CppUnitTest.h"
#include "../ap_12.4.rek/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
			Elem* L = nullptr;
			for (int i = 1; i <= 10; i++) {
				insert(L, i);
			}

			Elem* tmp = L;
			for (int i = 1; i <= 10; i++) {
				Assert::AreEqual(i, tmp->info);
				tmp = tmp->link;
			}

        };
    };
}
