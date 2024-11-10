#include "pch.h"
#include "CppUnitTest.h"
#include "../pds_13/pds_13.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestGraphColoring)
        {
            int graph[MAX_VERTICES][MAX_VERTICES] = { 0 };
            graph[0][1] = 1;
            graph[1][0] = 1;
            graph[1][2] = 1;
            graph[2][1] = 1;
            graph[2][0] = 1;
            graph[0][2] = 1;
            int n = 3;
            graphColoring(n);
            int numColors = *max_element(color, color + n) + 1;
            Assert::AreEqual(1, numColors);
            Assert::AreEqual(0, color[0]); 
            Assert::AreEqual(0, color[1]);  
            Assert::AreEqual(0, color[2]); 

            for (int i = 0; i < MAX_VERTICES; i++) {
                for (int j = 0; j < MAX_VERTICES; j++) {
                    graph[i][j] = 0; 
                }
            }
            graph[0][1] = 1;
            graph[1][0] = 1;
            graph[1][2] = 1;
            graph[2][1] = 1;
            graph[2][3] = 1;
            graph[3][2] = 1;
            graph[3][4] = 1;
            graph[4][3] = 1;
            n = 5;
            graphColoring(n);
            numColors = *max_element(color, color + n) + 1;
            Assert::AreEqual(1, numColors);
            Assert::AreEqual(0, color[0]); 
            Assert::AreEqual(0, color[1]); 
            Assert::AreEqual(0, color[2]);  
            Assert::AreEqual(0, color[3]);  
            Assert::AreEqual(0, color[4]);
        }
	};
}
