// PF Project
// Noman ALi
// L1F20BSCS0554
#include <iostream>
#include <fstream>
using namespace std;
int DataInsertion(int **table, int field, int colSize, int value);
int totalResult(int **table, int rowSize, int colSize);
bool deleteTestResult(int **table, int field, int position);
void averageOFRow(int **table, int rowSize, int colSize, float * &Average);
int MaximumNum(int **table,int colSize,int rowSize,int *Maximum);
void Most_accurance(int **table, int rowSize, int colSize);
int main()
{
	int rowSize = 4;
	int colSize = 6;
	int **table = new int*[rowSize];
	ifstream read;
	int Numbers = 0;
	read.open("inputFile.txt");
	for (int i = 0; i < rowSize; i++)
	{
		table[i] = new int[colSize];
	}

	for (int i = 0; i < rowSize; i++)
	{
		for (int k = 0; k < colSize; k++)
		{
			read >> Numbers;
			table[i][k] = Numbers;
		}
	}

	cout << "*******************************************************************************************" << endl << endl;
	cout << "*             Pestcouts is an emerging pesticide (insect killer) research lab             *" << endl << endl;
	cout << "*******************************************************************************************" << endl << endl;
	while (true)
	{

		int PerformFunction = 0;
		cout << "\n\nPress 1 to insert new test result\n";
		cout << "Press 2 to display total number of results in table\n";
		cout << "Press 3 to delete any test value from table\n";
		cout << "Press 4 to display the 2 most frequent values in table.\n";
		cout << "Press 5 to display average scores of each field.\n";
		cout << "Press 6 to display field having maximum success score.\n";
		cout << "Press 7 to Exit the Programe\n";
		cin >> PerformFunction;

		if (PerformFunction == 1)
		{
			int field = 0;
			cout << "\nEnter the field in which you want to enter a value: \n";
			cin >> field;

			while (field != 1 && field != 2 && field != 3 && field != 4)
			{
				cout << "Alert! Wrong Input Again Enter Field : ";
				cin >> field;
			}
			int value = 0;
			cout << "Enter Value :";
			cin >> value;
			int position = 0;
			position = DataInsertion(table, field, colSize, value);
			cout << endl << value << " is entered in field " << field << " at location : " << position + 1;
			cout << endl;

			cout << "\n\nYou entered Data : \n\n";

			for (int i = 0; i < rowSize; i++)
			{
				cout << "Field " << i + 1 << "   ";
				for (int k = 0; k < colSize; k++)
				{
					cout << table[i][k] << "\t";
				}
				cout << endl;
			}
		}
		else if (PerformFunction == 2)
		{
			int total_result = totalResult(table, rowSize, colSize);
			cout << "\nThere are " << total_result << " test score values entered in table.\n";
		}
		else if (PerformFunction == 3)
		{
			int fieldNo = 0;
			int position = 0;
			cout << "\nEnter Field No : \n";
			cin >> fieldNo;
			while (fieldNo != 1 && fieldNo != 2 && fieldNo != 3 && fieldNo != 4)
			{
				cout << "Alert! Wrong Input Again Enter Field : ";
				cin >> fieldNo;
			}
			cout << "\nEnter Position No : \n";
			cin >> position;

			while (position != 1 && position != 2 && position != 3 && position != 4 && position != 5 && position != 6)
			{
				cout << "Alert! Wrong Input Again Enter Position : ";
				cin >> position;
			}

			bool status = 0;
			status = deleteTestResult(table, fieldNo, position);
			if (status == true)
			{
				cout << "\nYour Desire Data is Deleted:\n";
			}
			else
			{
				cout << "\nYour Desire Data is not Deleted:\n";
			}

			cout << "\nCheck Table After Delet a Value : \n\n";
			for (int i = 0; i < rowSize; i++)
			{
				cout << "Field " << i + 1 << "   ";
				for (int k = 0; k < colSize; k++)
				{
					cout << table[i][k] << "\t";
				}
				cout << endl;
			}
		}
		else if (PerformFunction == 4)
		{
			Most_accurance(table, rowSize, colSize);
		}
		else if (PerformFunction == 5)
		{
			float *Average;
			Average = new float[rowSize];

			averageOFRow(table, rowSize, rowSize, Average);

			for (int i = 0; i < rowSize; i++)
			{
				if (Average[i] > 0)
				{
					cout << "Field " << i + 1 << " Average " << Average[i] << endl;
				}
				else
				{
					cout << "Field " << i + 1 << " Empty Field!" << endl;
				}
			}
		}
		else if (PerformFunction == 6)
		{
			int *Maximum = new int[rowSize];
			int maximum_Score = 0;
			maximum_Score = MaximumNum(table, colSize, rowSize, Maximum);
			cout << "\n\nField " << maximum_Score + 1 << " has the maximum success score\n\n";
		}
		else if (PerformFunction == 7)
		{
			return 0;
		}
	}
	cout << endl;
	return 0;
}
void Most_accurance(int **table, int rowSize, int colSize)
{
	int count = 0;
	int value = table[0][0];

	for (int i = 0; i < rowSize; i++)
	{
		for (int k = 0; k < colSize; k++)
		{
			if (value == table[i][k])
			{
				value = table[i][k];
				count++;
			}
		}
	}
	cout << endl << value << " has maximum occurrence of " << count << " times\n" << endl;
}
int MaximumNum(int **table, int colSize, int rowSize, int *Maximum)
{
	int largest = 0;
	for (int i = 0; i < rowSize; i++)
	{
		for (int k = 0; k < colSize; k++)
		{
			if (k == 0)
			{
				largest = table[i][k];
			}
			if (largest < table[i][k])
			{
				largest = table[i][k];
			}
		}
		Maximum[i] = largest;
	}
	int larger = 0;
	int Filed_Row = 0;
	for (int l = 0; l < rowSize; l++)
	{
		if (l == 0)
		{
			larger = Maximum[l];
		}
		if (larger < Maximum[l])
		{
			larger = Maximum[l];
			Filed_Row = l;
		}
	}
	delete[]Maximum;
	Maximum = 0;
	return Filed_Row;
}
void averageOFRow(int **table, int rowSize, int colSize, float * &Average)
{
	int count = 0;
	float sumOfRow = 0;
	
	int index = 0;
	for (int i = 0; i < rowSize; i++)
	{
		count = 0;
		sumOfRow = 0;
		for (int k = 0; k < colSize; k++)
		{
			if (table[i][k] != -1)
			{
				sumOfRow = sumOfRow + table[i][k];
				count++;
			}
		}
		Average[index] = sumOfRow / count;
		index++;
	}
}
bool deleteTestResult(int **table, int field, int position)
{

			table[field - 1][position - 1] = -1;	
			
			return true;
}
int totalResult(int **table, int rowSize, int colSize)
{
	int test_Score = 0;
	for (int i = 0; i < rowSize; i++)
	{
		for (int k = 0; k < colSize; k++)
		{
			if (table[i][k] == -1 || table[i][k] == 0)
			{
				continue;
			}
			else
			{
				test_Score++;
			}
		}
	}
	return test_Score;
}
int DataInsertion(int **table, int field, int colSize, int value)
{
	int i;
	for (i = 0; i < colSize; i++)
	{
		if (table[field-1][i] == -1)
		{
			table[field-1][i] = value;
			break;
		}
	}
	return i;
}