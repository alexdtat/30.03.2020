#include <iostream>
#include <string>

using namespace std;

/*Написать программу для нахождения
расстояния Хэмминнга
Расстояния Левенштейна
Взвешенного расстояния Левенштейна
для двух строк
Считаем стоимость операции добавления буквы - 15, удаления - 20, замены буквы на другую - 12. Вычислить минимальную стоимость преобразования первого предложения 1 главы романа "Война и Мир" во второе и обратно.(можно и нужно делать с помощью реализованного алгоритма Вагнера-Фишера из задачи 1)
*/

int main()
{
    setlocale( LC_ALL, "Russian" );
    setlocale( LC_ALL, "French" );
    int size1, size2;
    int** alg_table;
    int ins_cost = 1;
    int del_cost = 1;
    int sub_cost = 1;
    int mincost = 0;
    int dHam = 0;
    int dLev = 0;

    string string1;
    cout << "Input the first string:\n";
    getline(cin, string1);
    string string2;
    cout << "Input the second string:\n";
    getline(cin, string2);

    size1 = string1.length();
    size2 = string2.length();

    if (size1 == size2){
        for (int l = 0; l < size1; l++){
            if (string1[l] != string2[l]) dHam++;
        }
        cout << "\nA Hamming distance is " << dHam;

    }
    else cout << "\nA Hamming distance can not be calculated\n";

    alg_table = new int*[size1+1];
    for (int k = 0; k < size1+1; k++) alg_table[k] = new int[size2+1];
    alg_table[0][0] = 0;
    for (int m = 1; m <= size2; m++) alg_table[0][m] = alg_table[0][m-1]+ins_cost;
    for (int n = 1; n <= size1; n++) alg_table[n][0] = alg_table[n-1][0]+del_cost;



    for (int i = 1; i < size1+1; i++){
        for (int j = 1; j < size2+1; j++){
            if (string1[i-1] != string2[j-1]) mincost = min(min(alg_table[i][j-1]+ins_cost, alg_table[i-1][j]+del_cost), alg_table[i-1][j-1]+sub_cost);
            if (string1[i-1] == string2[j-1]) mincost = min(min(alg_table[i][j-1]+ins_cost, alg_table[i-1][j]+del_cost), alg_table[i-1][j-1]);
            alg_table[i][j] = mincost;
        }
    }
    dLev = alg_table[size1][size2];


    cout << "\n\nA Levenshtein distance is " << dLev << "\n A cost of deletion is\t"<<del_cost<<"\n A cost of insertion is\t"<<ins_cost<<"\n A cost of substitution is\t"<<sub_cost;

    ins_cost = 15;
    del_cost = 20;
    sub_cost = 12;

    for (int m = 1; m <= size2; m++) alg_table[0][m] = alg_table[0][m-1]+ins_cost;
    for (int n = 1; n <= size1; n++) alg_table[n][0] = alg_table[n-1][0]+del_cost;

    for (int i = 1; i < size1+1; i++){
        for (int j = 1; j < size2+1; j++){
            if (string1[i-1] != string2[j-1]) mincost = min(min(alg_table[i][j-1]+ins_cost, alg_table[i-1][j]+del_cost), alg_table[i-1][j-1]+sub_cost);
            if (string1[i-1] == string2[j-1]) mincost = min(min(alg_table[i][j-1]+ins_cost, alg_table[i-1][j]+del_cost), alg_table[i-1][j-1]);
            alg_table[i][j] = mincost;
        }
    }
    dLev = alg_table[size1][size2];

    cout << "\n\nA Levenshtein distance is " << dLev << "\n A cost of deletion is\t"<<del_cost<<"\n A cost of insertion is\t"<<ins_cost<<"\n A cost of substitution is\t"<<sub_cost;

    return 0;
}
