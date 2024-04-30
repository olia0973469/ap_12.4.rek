#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

typedef int Info;

struct Elem
{
    Elem* link;
    Info info;
};

void insert(Elem*& L, Info value)
{
    Elem* tmp = new Elem;
    tmp->info = value;
    if (L != NULL)
    {
        Elem* T = L;
        while (T->link != L)
            T = T->link;
        T->link = tmp;
    }
    else
    {
        L = tmp;
    }
    tmp->link = L;
}

void swapAdjacent(Elem* current, Elem* prev)
{
    if (current == NULL || current->link == prev)
        return;

    Elem* next = current->link;
    Elem* nextNext = next->link;

    next->link = current;
    current->link = nextNext;
    if (prev != NULL)
        prev->link = next;

    swapAdjacent(nextNext, current);
}

void swapAdjacentElements(Elem*& L, Elem* current = nullptr)
{
    if (L == nullptr || L->link == L)
        return;

    if (current == nullptr)
        current = L;

    Info temp = current->info;
    current->info = current->link->info;
    current->link->info = temp;

    if (current->link->link != L)
        swapAdjacentElements(L, current->link->link);
}

void displayRecursive(Elem* L, Elem* current)
{
    if (current == nullptr || current->link == L)
    {
        cout << endl;
        return;
    }
    cout << current->info << " ";
    displayRecursive(L, current->link);
}

void display(Elem* L)
{
    if (L == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    displayRecursive(L, L);
}

int main()
{
    srand(time(NULL));
    Elem* L = NULL;

    for (int i = 1; i <= 10; i++) {
        insert(L, rand() % 10);
    }
    cout << "List:" << endl;
    display(L);

    swapAdjacentElements(L);

    cout << "After swap:" << endl;
    display(L);

    return 0;
}
