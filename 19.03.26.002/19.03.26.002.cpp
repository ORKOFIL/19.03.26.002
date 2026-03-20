//Умова завдання
//1.  Користувач вводить розмір масиву size.
//2.  Створити масив V1 з size елементів та заповнити його випадковими
//цілими числами.
//3.  Вивести масив на екран.
//4.  Користувач вводить число n.
//5.  Поділити масив V1 на групи по n елементів.
//6.  Для кожної групи обчислити суму елементів : S1 = x1 + x2 + … + xn S2
//= …
//7.  Записати всі отримані суми у текстовий файл e.txt.
//8.  Відсортувати масив V1 за зростанням(ASC) та знайти суму всіх
//елементів.
//9.  Відсортувати масив V1 за спаданням(DESC) та знайти суму всіх
//елементів.
//10. Видалити повторювані елементи з масиву V1 та створити новий масив
//V2.
//11. Обчислити суму елементів нового масиву V2(S3).
//12. Знайти різницю сум : S3 - S2.
//13. Порахувати кількість елементів, які повторювалися у початковому
//масиві.
//14. Зберегти результати у JSON файл :
//-S2
//- S3
//- S3 - S2
//- кількість повторюваних елементів
//- масив V1
//- масив V2
//15. Вивести на екран різницю масивів | V1 - V2 | (елементи, які були
//    видалені).



#include "func.h"

int main()
{
    srand(time(0));

    ofstream out("data.txt");
    ofstream jout("data.json");

    if (!out.is_open() || !jout.is_open())
    {
        cerr << "cannot open files!" << endl;
        return 1;
    }

    int size;
    int n;

    cout << "Enter array size: ";
    cin >> size;

    if (size <= 0)
    {
        cerr << "size must be greater than 0!" << endl;
        return 1;
    }

    vector<int> v1(size);
    vector<int> v2;

    for (int i = 0; i < size; i++)
    {
        v1[i] = rand() % 99 + 1;
    }

    cout << "\nArray V1: ";
    for (int i = 0; i < size; i++)
    {
        cout << v1[i] << " ";
    }
    cout << endl;

    cout << "\nEnter n: ";
    cin >> n;

    if (n <= 0)
    {
        cerr << "n must be greater than 0!" << endl;
        return 1;
    }

    out << "=== Sums of sequences by " << n << " elements ===" << endl;
    for (int i = 0; i < v1.size(); i += n)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (i + j < v1.size()) {
                sum += v1[i + j];
            }
        }
        out << "Sum of block " << (i / n + 1) << ": " << sum << endl;
    }
    out << endl;

    sortAsc(v1);
    cout << "Array V1 (ASC): ";
    for (int i = 0; i < size; i++)
    {
        cout << v1[i] << " ";
    }
    int sum2 = sumOfElements(v1);
    cout << "\nSum of elements (S2): " << sum2 << endl;

    sortDesc(v1);
    cout << "Array V1 (DESC): ";
    for (int i = 0; i < size; i++)
    {
        cout << v1[i] << " ";
    }
    cout << "\nSum of elements: " << sumOfElements(v1) << endl;

    vector<int> copyV1 = v1;
    removeDuplicates(v1, v2);
    int sum3 = sumOfElements(v2);

    cout << "Unique elements V2: ";
    for (int i = 0; i < v2.size(); i++)
    {
        cout << v2[i] << " ";
    }
    cout << "\nSum of unique elements (S3): " << sum3 << endl;

    int sizeV2 = v2.size();
    int duplicatesCount = size - sizeV2;

    cout << "\nNumber of duplicates: " << duplicatesCount << endl;
    cout << "Difference of sums (S3 - S2): " << sum3 - sum2 << endl;

    printDuplicates(copyV1);

    outputJSON(jout, sum2, sum3, duplicatesCount, v1, v2);
    
    out.close();
    jout.close();

    cout << "\nData saved to data.txt and data.json" << endl;

    return 0;
    //test
}