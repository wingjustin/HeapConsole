// HeapConsole.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <random>
#include "HeapSort.h"
#include "Heap.h"

#define INSERT_COUNT 810
#define REMOVE_COUNT 678

#define ROUND 42

using namespace std;
using namespace Sort;
using namespace BinaryTree;

int main()
{
	const int insertCount = INSERT_COUNT;
	const int removeCount = REMOVE_COUNT;

	const int round = ROUND;

	bool showEachHealthStatus = true;

	bool showInsertDetails = true;
	bool showRemoveDetails = true;

	bool healthHeavyCheck = true;

	random_device dev;
	mt19937 rng(dev());
	uniform_int_distribution<std::mt19937::result_type> insertRandom(0, 9999); // distribution in range [1, 6]

	MinHeap heap;

	bool totHealth = true;

	for (int r = 0; r < round; r++) {
		cout << "ROUND : " << r + 1 << "\n";

		int insertArr[insertCount];
		bool isHealth = false;

		//random insert array
		for (int i = 0; i < insertCount; i++)
			insertArr[i] = insertRandom(rng);

		isHealth = heap.HealthCheck();

		//insert into tree
		if (insertCount > 0) {
			if (showInsertDetails) cout << "Inserted : { ";
			string* data = new string("DATA" + to_string(insertArr[0]));
			heap.Push(insertArr[0], *data);
			if (healthHeavyCheck) isHealth = isHealth && heap.HealthCheck();
			if (showInsertDetails) cout << to_string(insertArr[0]);
			for (int i = 1; i < insertCount; i++) {
				data = new string("DATA" + to_string(insertArr[i]));
				heap.Push(insertArr[i], *data);
				if (healthHeavyCheck) isHealth = isHealth && heap.HealthCheck();
				if (showInsertDetails) cout << ", " << to_string(insertArr[i]);
			}
			if (showInsertDetails) cout << " }";
		}
		if (showInsertDetails) cout << " \n";

		isHealth = isHealth && heap.HealthCheck();

		//Check bugs
		if (showEachHealthStatus) cout << "Inserted Tree Health : " << (isHealth ? "OK, no BUG!" : "Warning! Error occured!") << "\n";
		if (showEachHealthStatus) cout << " \n";

		//Sort and Check heap order
		HeapSort::Sort(insertArr, insertCount);

		//remove from tree
		if (removeCount > 0) {
			HeapNode* remove = NULL;
			if (showRemoveDetails) cout << "Removed : { ";
			remove = heap.Pop();
			isHealth = isHealth && remove && remove->GetKey() == insertArr[0];
			if (healthHeavyCheck) isHealth = isHealth && heap.HealthCheck();
			delete remove->GetData();
			delete remove;
			if (showRemoveDetails) cout << to_string(insertArr[0]);
			for (int i = 1; i < removeCount; i++) {
				remove = heap.Pop();
				isHealth = isHealth && remove && remove->GetKey() == insertArr[i];
				if (healthHeavyCheck) isHealth = isHealth && heap.HealthCheck();
				delete remove->GetData();
				delete remove;
				if (showRemoveDetails) cout << ", " << to_string(insertArr[i]);
			}
			if (showRemoveDetails) cout << " }";
		}
		if (showRemoveDetails) cout << " \n";

		isHealth = isHealth && heap.HealthCheck();

		//Check bugs
		if (showEachHealthStatus) cout << "Removed Tree Health : " << (isHealth ? "OK, no BUG!" : "Warning! Error occured!") << "\n";
		if (showEachHealthStatus) cout << " \n";

		//Recheck
		if (removeCount > 0) {
			insertArr[0] = insertRandom(rng);
			string* data = new string("DATA" + to_string(insertArr[0]));
			heap.Push(insertArr[0], *data);
			if (healthHeavyCheck) isHealth = isHealth && heap.HealthCheck();
			for (int i = 1; i < removeCount; i++) {
				insertArr[i] = insertRandom(rng);
				data = new string("DATA" + to_string(insertArr[i]));
				heap.Push(insertArr[i], *data);
				if (healthHeavyCheck) isHealth = isHealth && heap.HealthCheck();
			}

			isHealth = isHealth && heap.HealthCheck();

			//Sort and Check heap order
			HeapSort::Sort(insertArr, insertCount);
		}

		//Check All
		HeapNode* remove = NULL;
		remove = heap.Pop();
		isHealth = isHealth && remove && remove->GetKey() == insertArr[0];
		if (healthHeavyCheck) isHealth = isHealth && heap.HealthCheck();
		delete remove->GetData();
		delete remove;
		for (int i = 1; i < insertCount; i++) {
			remove = heap.Pop();
			isHealth = isHealth && remove && remove->GetKey() == insertArr[i];
			if (healthHeavyCheck) isHealth = isHealth && heap.HealthCheck();
			delete remove->GetData();
			delete remove;
		}
		remove = NULL;

		isHealth = isHealth && !heap.GetRoot() && heap.GetLength() == 0 && heap.HealthCheck();

		totHealth = totHealth && isHealth;

		//Check bugs
		if (showEachHealthStatus) cout << "Recheck Tree Health : " << (isHealth ? "OK, no BUG!" : "Warning! Error occured!") << "\n";
		if (showEachHealthStatus) cout << " \n";
	}

	heap.Clear();

	cout << " \n";
	cout << "All Tree Health : " << (totHealth ? "OK, no BUG!" : "Warning! Error occured!") << "\n";
	cout << " \n";

	system("pause");
}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
