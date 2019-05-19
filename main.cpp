#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

using namespace std;

class Sequence {
protected:
    int Length;
public:
    int GetLength() {
        return Length;
    }

    bool GetIsEmpty(){
        bool Empty;
        if (Length == 0) Empty = true;
            else Empty == false;
        return Empty;
    }

};

template <typename TElement> class ArraySequence: public Sequence{
    TElement *ArrayHead;
public:
    void CreateSequence(int inputLength, ArraySequence *inputHead){
        inputHead->Length = inputLength;
        ArrayHead = new TElement[Length];
        if (inputHead->Length != 0){
            cout << "Введите значения Array Sequence " << endl;
            for (int i = 0; i < Length; i++)
                cin >> ArrayHead[i];
        }
    }

    void Print(ArraySequence *inputHead){
        for(int i = 0; i < inputHead->Length; i++)
            cout << inputHead->ArrayHead[i] << " ";
        cout << endl;
    }

    TElement Get(int index){
        return ArrayHead[index];
    }

    TElement GetFirst(){
        return ArrayHead[0];
    }

    TElement GetLast(){
        return ArrayHead[Length - 1];
    }

    ArraySequence *GetSubsequence(int StartIndex, int EndIndex){
        ArraySequence *Subsequence = new ArraySequence;
        Subsequence->Length = EndIndex - StartIndex + 1;
        Subsequence->ArrayHead = new TElement[Subsequence->Length];
        int j = 0;
        for (int i = StartIndex; i <= EndIndex; i++){
            Subsequence->ArrayHead[j] = ArrayHead[i];
            j++;
        }
        return Subsequence;
    }

    ArraySequence *Append(TElement item){
        ArraySequence *Appendsequence = new ArraySequence;
        Appendsequence->Length = Length + 1;
        Appendsequence->ArrayHead = new TElement[Appendsequence->Length];
        for (int i = 0; i < Length; i++)
            Appendsequence->ArrayHead[i] = ArrayHead[i];
        Appendsequence->ArrayHead[Appendsequence->Length - 1] = item;
        return Appendsequence;
    }

    ArraySequence *Prepend(TElement item){
        ArraySequence *Prependsequence = new ArraySequence;
        Prependsequence->Length = Length + 1;
        Prependsequence->ArrayHead = new TElement[Prependsequence->Length];
        for (int i = 0; i < Length; i++)
            Prependsequence->ArrayHead[i + 1] = ArrayHead[i];
        Prependsequence->ArrayHead[0] = item;
        return Prependsequence;
    }

    ArraySequence *InsertAt(int index, TElement item){
        ArraySequence *Insertsequence = new ArraySequence;
        Insertsequence->Length = Length + 1;
        Insertsequence->ArrayHead = new TElement[Insertsequence->Length];
        for (int i = 0; i < index; i++)
            Insertsequence->ArrayHead[i] = ArrayHead[i];
        Insertsequence->ArrayHead[index] = item;
        for (int i = index + 1; i < Insertsequence->Length; i++)
            Insertsequence->ArrayHead[i] = ArrayHead[i - 1];
        return Insertsequence;
    }

    ArraySequence *Remove(TElement item){
        int size = Length;
        for (int i = 0 ; i < size; i++){
            if (ArrayHead[i] == item)
              Length = Length - 1;
        }
        ArraySequence *newSequence = new ArraySequence;
        newSequence->ArrayHead = new TElement[Length];
        newSequence->Length = Length;
        for (int i = 0, j = 0; i < size; i++){
            if (ArrayHead[i] != item){
                newSequence->ArrayHead[j] = ArrayHead[i];
                j++;
            }
        }
        return newSequence;
    }
};

template <typename TElement> class ListSequence: public Sequence{
    TElement Value;
    ListSequence *Head, *next;
public:
    void CreateSequence(int inputLength, ListSequence *inputHead)  {
        Head = inputHead;
        Head->Length = inputLength;
        ListSequence *temp = Head;
        if (Length != 0){
            cout << "Введите значения List Sequence " << endl;
            cin >> temp->Value;
            for (int i = 0; i < Head->Length - 1; i++){
                temp->next = new ListSequence;
                temp = temp->next;
                cin >> temp->Value;
            }
        }
    }

    void Print(ListSequence *example){
        int size = example->Length;
        for (int i = 0; i < size; i++){
            cout << example->Value << " ";
            example = example->next;
        }
        cout << endl;
    }

    TElement Get(int index){
        ListSequence *temp = Head;
        for (int i = 0; i < index; i++){
            temp = temp->next;
        }
        return temp->Value;
    }

    TElement GetFirst(){
        return Head->Value;
    }

    TElement GetLast(){
        ListSequence *temp = Head;
        for (int i = 0; i < Head->Length - 1; i++){
            temp = temp->next;
        }
        return temp->Value;
    }

    ListSequence *GetSubsequence(int StartIndex, int EndIndex){
        ListSequence *temp = Head;
        for (int i = 0; i < StartIndex; i++)
            temp = temp->next;
        temp->Length = EndIndex - StartIndex + 1;
        return temp;
    }

    ListSequence *Append(TElement item){
        ListSequence *temp = Head;
        if (Length == 0){
            Head->Value = item;
            Head->Length = 1;
        }
            else{
                for (int i = 0; i < Head->Length - 1; i++)
                    temp = temp->next;
                temp->next = new ListSequence;
                temp = temp->next;
                temp->Value = item;
                Head->Length = Head->Length + 1;
            }
        return Head;
    }

    ListSequence *Prepend(TElement item){
        ListSequence *temp = new ListSequence;
        temp->next = Head->next;
        temp->Value = Head->Value;
        Head->next = temp;
        Head->Value = item;
        Head->Length = Head->Length + 1;
        return Head;
    }

    ListSequence *InsertAt(int index, TElement item){
        ListSequence *tempitem = new ListSequence;
        ListSequence *ctemp = new ListSequence;
        if (index == 0){
            tempitem->Value = Head->Value;
            Head->Value = item;
            ctemp = Head->next;
            Head->next = tempitem;
            tempitem->next = ctemp;

        }
        if (index != 0){
            ListSequence *temp = Head;
            for (int i = 0; i < index-1; i++)
                temp = temp->next;
            ctemp = temp->next;
            temp->next = tempitem;
            tempitem->next = ctemp;
            tempitem->Value = item;
        }
        Head->Length = Head->Length + 1;
        return Head;
    }

    ListSequence *Remove(TElement item){
        ListSequence *temp = Head;
        ListSequence *NLsequence = new ListSequence;
        ListSequence *cNLsequence = NLsequence;
        int size = Length;
        for (int i = 0; i < size; i++){
            if (temp->Value != item){
                NLsequence->Value = temp->Value;
                NLsequence->next = new ListSequence;
                NLsequence = NLsequence->next;
            }
            if (temp->Value == item){
                Length = Length - 1;
            }
            temp = temp->next;
        }
        Head->Value = cNLsequence->Value;
        Head->next = cNLsequence->next;
        return Head;
    }
};

template <class Var, typename TElement> void choice(int Length, int flag){
        Var example;
        example.CreateSequence(Length, &example);
        cout << "Выберите необходимый метод:" << endl;
        cout << "1. Length" << endl;
        cout << "2. IsEmpty" << endl;
        cout << "3. Get" << endl;
        cout << "4. GetFirst" << endl;
        cout << "5. GetLast" << endl;
        cout << "6. GetSubsequence" << endl;
        cout << "7. Append" << endl;
        cout << "8. Prepend" << endl;
        cout << "9. InsertAt" << endl;
        cout << "10. Remove" << endl;
        int choice;
        for (int i = 0, k = 1; i < k; i++){
            cin >> choice;
            if (choice == 1){
                cout << "Длина последовательности: ";
                cout << example.GetLength() << endl;
            }
            if (choice == 2){
                cout << "Последовательность пустая: ";
                if (example.GetIsEmpty() == 1)
                    cout << "Да" << endl;
                if (example.GetIsEmpty() == 0)
                    cout << "Нет" << endl;
            }
            if (choice == 3){
                cout << "Введите индекс элемента" << endl;
                int index;
                cin >> index;
                while (index < 0 || index >= example.GetLength()){
                    cout << "Введите корректное значение!" << endl;
                    cin >> index;
                }
                cout << "Элемент последовательности: ";
                cout << example.Get(index) << endl;
            }
            if (choice == 4){
                cout << "Первый элемент последовательности:" << endl;
                cout << example.GetFirst();
            }
            if (choice == 5){
                cout << "Последний элемент последовательности:" << endl;
                cout << example.GetLast();
            }
            if (choice == 6){
                cout << "Введите начальный и конечный индекс подпоследовательности:" << endl;
                int StartIndex, EndIndex;
                cin >> StartIndex >> EndIndex;
                while (StartIndex < 0 || StartIndex > EndIndex || EndIndex >= example.GetLength()){
                    cout << "Введите корректные значения!" << endl;
                    cin >> StartIndex >> EndIndex;
                }
                cout << "Выделенная подпоследовательность: ";
                example = *example.GetSubsequence(StartIndex, EndIndex);
                example.Print(&example);
            }
            if (choice == 7){
                cout << "Введите дополнительный элемент последовательности:" << endl;
                TElement item;
                cin >> item;
                cout << "Новая последовательность: ";
                example = *example.Append(item);
                example.Print(&example);
            }
            if (choice == 8){
                cout << "Введите дополнительный элемент последовательности:" << endl;
                TElement item;
                cin >> item;
                cout << "Новая последовательность: ";
                example = *example.Prepend(item);
                example.Print(&example);
            }
            if (choice == 9){
                cout << "Введите индекс элемента:" << endl;
                int index;
                cin >> index;
                while (index < 0 || index >= example.GetLength()){
                    cout << "Введите корректное значение!" << endl;
                    cin >> index;
                }
                cout << "Введите дополнительный элемент последовательности:" << endl;
                TElement item;
                cin >> item;
                cout << "Новая последовательность: ";
                example = *example.InsertAt(index, item);
                example.Print(&example);
            }
            if (choice == 10){
                cout << "Введите элемент последовательности:" << endl;
                TElement item;
                cin >> item;
                cout << "Полученная последовательность: ";
                example = *example.Remove(item);
                if (example.GetLength() != 0 )
                    example.Print(&example);
                if (example.GetLength() == 0 )
                    cout << "Пустая последовательность" << endl;
            }
            if (flag == 1){
            cout << endl << "Для того, чтобы продолжить нажмите пробел " << endl;
            char button = getch();
            if (button == 32)
                k = k + 1;
            }
            if (flag == 0)
                k = k + 1;
            cout << "Выберите необходимый метод:" << endl;

        }
}

void user(int flag){
    system("cls");
    cout << "Выберите тип данных:" << endl;
    cout << "1. int" << endl;
    cout << "2. float" << endl;
    cout << "3. char" << endl;
    char Tchoice;
    cin >> Tchoice;
    while (Tchoice != '1' && Tchoice != '2' && Tchoice != '3'){
        cout << "Выполните корректный выбор!" << endl;
        cin >> Tchoice;
    }
    cout << "Выберите реализацию:" << endl;
    cout << "1. Array Sequence" << endl;
    cout << "2. List Sequence" << endl;
    char Mchoice;
    cin >> Mchoice;
    while (Mchoice != '1' && Mchoice != '2'){
        cout << "Выполните корректный выбор!" << endl;
        cin >> Mchoice;
    }
    cout << "Введите длину последовательности" << endl;
    int Length;
    cin >> Length;
    while (Length < 0){
        cout << "Введите корректную длину!" << endl;
        cin >> Length;
    }
    if (Tchoice == '1'){
        if (Mchoice == '1')
            choice <ArraySequence<int>, int>(Length, flag);
        if (Mchoice == '2')
            choice <ListSequence<int>, int>(Length, flag);
    }
    if (Tchoice == '2'){
        if (Mchoice == '1')
            choice <ArraySequence<float>, float>(Length, flag);
        if (Mchoice == '2')
            choice <ListSequence<float>, float>(Length, flag);
    }
    if (Tchoice == '3'){
        if (Mchoice == '1')
            choice <ArraySequence<char>, char>(Length, flag);
        if (Mchoice == '2')
            choice <ListSequence<char>, char>(Length, flag);
    }
}

void test(){
    freopen("test/test.txt", "r", stdin);
    user(1);
    freopen("CONIN$", "r", stdin);
}

int main(){
    setlocale(0,"Russian");
    cout << "Выберите режим:" << endl;
    cout << "1. Пользователь" << endl;
    cout << "2. Тестировщик" << endl;
    int choice;
    cin >> choice;
    while (choice != 1 && choice != 2){
        cout << "Выполните корректный выбор!" << endl;
        cin >> choice;
    }
    if (choice == 1)
        user(0);
    if (choice == 2)
        test();
    return 0;
}

