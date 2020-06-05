#include <iostream>
#include<list>
#include<ctime>
#include<iterator>
#include<vector>

using namespace std;
/*
2. Создать линейный однонаправленый список из вещественных чисел. Вставить в список
число 1.5 после каждого элемента с отрицательным значением.
3. Создать циклический двунаправленый список из целых чисел. Удалить из списка
последний элемент со значением меньше 15.
*/
void Middle_level()
{
    srand(time(NULL));
    list <float> mylist;
    list <float> ::iterator myiter;
    int K;
    cout << "Enter size list" << endl;
    cin >> K;

    for (int i(0); i != K; i++)
    {
        int var = rand() % 10 - 5;

        if (var > 0)
            mylist.push_back(var);
        else {
            mylist.push_back(var);
            mylist.push_back(1.5);
        }
    }

    while (!mylist.empty()) {
        cout << "Number: " << mylist.front() << endl;
        mylist.pop_front();
    }
}

void High_Level()
{
    srand(time(NULL));
    list<int> mylist;
    int n, k = 0;
    cout << "Enter size list" << endl;
    cin >> n;
    vector<int> vector(n);

    for (size_t i = 0; i < n; i++)
    {
        mylist.push_back(rand() % 40);
    }

    cout << "First list:" << endl;
    copy(mylist.begin(), mylist.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    for (list<int>::iterator i = mylist.begin(); i != mylist.end(); i++)
    {
        vector[k] = *i;
        k++;
    }

    for (size_t i = n - 1; i >= 0; i--)
    {
        if (vector[i] < 15)
        {
            vector.erase(vector.begin() + i);
            break;
        }
    }

    mylist.clear();

    for (size_t i = 0; i < n - 1; i++)
    {
        mylist.push_back(vector[i]);
    }

    cout << endl << "List after deletion: " << endl;

    copy(mylist.begin(), mylist.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter task number: (2 - middle level| 3 - high level)" << endl;
    cin >> n;

    if (n == 2)
    {
        Middle_level();
    }
    else if (n == 3)
    {
        High_Level();
    }
    else
    {
        cout << "There is no such task!" << endl;
    }

    system("pause");
}


