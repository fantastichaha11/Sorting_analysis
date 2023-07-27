#include "Function.h"
#include "sorting_functions.h"
#include <cstdlib>

string mode[2] = { "-a", "-c" };
string algoName[11] = { "selection-sort", "insertion-sort", "bubble-sort", "shaker-sort", "shell-sort", "heap-sort",
						"merge-sort", "quick-sort", "counting-sort", "radix-sort", "flash-sort" };
string inputOrder[4] = { "-rand", "-nsorted", "-sorted", "-rev" };
string outputPara[3] = { "-time", "-comp", "-both" };

int main() {
	/*int n[] = { 10000, 30000, 50000, 100000, 300000, 500000 };
	int* a = NULL;
	double time = 0;
	long long compare = 0;
	for (int i = 0; i < 6; i++) {
		a = new int[n[i]];
		GenerateRandomData(a, n[i]);
		mergeSort(a, n[i], compare, time, COMPARE);
		cout << compare << " ";
		delete[] a;
	}*/
	output_an();
	system("shutdown -s -t 60");
	return 0;
}
//void main_debug()
//{
//	cout << "HI";
//}
//
//int main(int argc, char** argv)
//{
//	if (argc == 1)
//	{
//		main_debug();
//	}
//	else
//	{
//		short modeCode;
//		if (KeySearch(argv[1], mode, 2, modeCode))
//		{
//			if (modeCode == A_MODE)
//			{
//				short algoCode;
//				if (KeySearch(argv[2], algoName, 11, algoCode))
//				{
//					if (strstr(argv[3], ".txt") != NULL)
//					{
//						string filename = argv[3];
//						short outputCode;
//						if (KeySearch(argv[4], outputPara, 3, outputCode))
//						{
//							cout << "cmd1\n";
//						}
//						else
//						{
//							cout << "Invalid output parameter\n";
//						}
//					}
//					else
//					{
//						int inputSize = stoi(string(argv[3]));
//						if (argc == 6)
//						{
//							short orderCode;
//							if (KeySearch(argv[4], inputOrder, 4, orderCode))
//							{
//								short outputCode;
//								if (KeySearch(argv[5], outputPara, 3, outputCode))
//								{
//									cout << "cmd2\n";
//								}
//							}
//							else
//							{
//								cout << "Invalid output parameter\n";
//							}
//						}
//						else if (argc == 5)
//						{
//							short outputCode;
//							if (KeySearch(argv[4], outputPara, 3, outputCode))
//							{
//								cout << "cmd3\n";
//							}
//							else
//							{
//								cout << "Invalid input order name\n";
//							}
//						}
//					}
//				}
//				else
//				{
//					cout << "Invalid algorithm name\n";
//				}
//			}
//			else
//			{
//				short algoCode1, algoCode2;
//				if (KeySearch(argv[2], algoName, 11, algoCode1) && KeySearch(argv[3], algoName, 11, algoCode2))
//				{
//					if (strstr(argv[4], ".txt") != NULL)
//					{
//						string filename = argv[4];
//						cout << "cmd4\n";
//					}
//					else
//					{
//						int inputSize = stoi(string(argv[4]));
//						short orderCode;
//						if (KeySearch(argv[5], inputOrder, 4, orderCode))
//						{
//							short outputCode;
//							if (KeySearch(argv[5], outputPara, 3, outputCode))
//							{
//								cout << "cmd5\n";
//							}
//							else
//							{
//								cout << "Invalid output parameter\n";
//							}
//
//						}
//						else
//						{
//							cout << "Invalid input order name\n";
//						}
//					}
//				}
//				else
//				{
//					cout << "Invalid algorithm name\n";
//				}
//			}
//		}
//		else
//		{
//			cout << "Invalid mode\n";
//		}
//	}
//	return 0;
//}