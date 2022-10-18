
#include "CppUnitTest.h"
#include "..\nikita4\DialogFinder.h"
#include "..\nikita4\DialogFinder.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	private:
		
		std::string  test_text = "\n– A.\n– B!\n– C?\n F\n– E.";
		std::vector < std::string> test_answer_list = {"– A.\n– B!\n– C?\n"};
	public:
		
		TEST_METHOD(TestMethod1)
		{
			DialogFinder finder(test_text);
			finder.FindDialogs();

			Assert::IsTrue(test_answer_list == finder.GetVector());
		}
	};
}
