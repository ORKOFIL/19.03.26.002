#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <algorithm>

using namespace std;

void sortAsc(vector<int>& v)
{
    int n = v.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (v[j] > v[j + 1])
            {
                swap(v[j], v[j + 1]);
            }
        }
    }
}

void sortDesc(vector<int>& v)
{
    int n = v.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (v[j] < v[j + 1])
            {
                swap(v[j], v[j + 1]);
            }
        }
    }
}

int sumOfElements(vector<int>& v)
{
    int sum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        sum += v[i];
    }
    return sum;
}

void removeDuplicates(vector<int>& v, vector<int>& unique)
{
    unique.clear();
    for (int i = 0; i < v.size(); i++)
    {
        bool found = false;
        for (int j = 0; j < unique.size(); j++)
        {
            if (v[i] == unique[j])
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            unique.push_back(v[i]);
        }
    }
}

void printDuplicates(vector<int>& v)
{
    cout << "Duplicates: ";
    bool hasDuplicates = false;

    for (int i = 0; i < v.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < v.size(); j++)
        {
            if (v[i] == v[j])
                count++;
        }

        if (count > 1)
        {
            bool alreadyPrinted = false;
            for (int j = 0; j < i; j++)
            {
                if (v[i] == v[j])
                {
                    alreadyPrinted = true;
                    break;
                }
            }
            if (!alreadyPrinted)
            {
                cout << v[i] << " ";
                hasDuplicates = true;
            }
        }
    }

    if (!hasDuplicates)
    {
        cout << "none";
    }
    cout << endl;
}

void outputJSON(ofstream& jout, int sum2, int sum3, int duplicatesCount, vector<int>& v1, vector<int>& v2)
{
    jout << "{\n";
    jout << "  \"S2\": " << sum2 << ",\n";
    jout << "  \"S3\": " << sum3 << ",\n";
    jout << "  \"S3 - S2\": " << sum3 - sum2 << ",\n";
    jout << "  \"duplicatesCount\": " << duplicatesCount << ",\n";
    jout << "  \"V1\": [";
    for (int i = 0; i < v1.size(); i++)
    {
        jout << v1[i];
        if (i < v1.size() - 1) {
            jout << ", ";
        }
    }
    jout << "],\n";
    jout << "  \"V2\": [";
    for (int i = 0; i < v2.size(); i++)
    {
        jout << v2[i];
        if (i < v2.size() - 1) {
            jout << ", ";
        }
    }
    jout << "]\n";
    jout << "}\n";
}