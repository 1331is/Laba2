#include <iostream>
#include <ctime>
#include <chrono>
#include <cmath>
#include <iomanip>
#include <string>
#include <array>
using namespace std;
void pain_massive(array<int, 100> arr, int n) {
    for (int arr, int i = 0; i < n; i++, arr++) {
        cout << arr << " ";
    }
}



int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    int count;
    int yka;
    const int N = 100;
    int a[N] = {};
    int* pa = a;
    int randomdomdom = rand() % 199 - 99;
    bool is_true = 1;
    bool is_del;
    int maxnesort;
    int minnesort;
    auto start = chrono::high_resolution_clock::now();
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<float> duration = end - start;
    int syma;
    int maxnesort1;
    int minnesort1;
    int polz;
    int minpred;
    int maxpred;
    int k;
    int pervi_index;
    int vtoriu_index;
    int dop_chislo;
    cout << "==================ТИПО МЕНЮ==================\nВведите 1 чтобы создать массив \nВведите 2 чтобы отсортировать массив и УзнАтЬ СкОльКо на эТо УйдЁт времени \n";
    cout << "Введите 3 чтобы найти максиальный и минимальный элемент в отсортированном и не отсортированном массиве (и даже узнать время затраченное на это) \n";
    cout << "Введите 4 чтобы вывести среднее значение максимального и минимального, а также индексы элементов в массиве равные им (И конечено же время поиска/вывода) \n";
    cout << "Введите 5/6 для поиска количества элементов в массиве меньше/больше выбранного многоуважаемым пользователем (ВАМИ) \n";
    cout << "Введите 7 для Поиск элемента бинарным и обычным перебором, чтобы сравнить затраченное время \n";
    cout << "Введите 8 и два числа (Или даже цифры), чтобы поменять местами значения равные этим числам (Или даже цифрам) \n";
    do {
        cin >> yka;
        if (yka == 0) is_true = 0;
        switch (yka)
        {
        case (1):
            for (int i = 0; i < N; i++) {
                a[i] = rand() % 199 - 99;
                cout << a[i] << " ";
            }
            cout << " <- Массив \n";
            break;
            //--------------------------------------------------------------------------    
        case (2):
            start = chrono::high_resolution_clock::now();
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N - 1; j++) {
                    if (a[j] > a[j + 1]) {
                        int b = a[j];
                        a[j] = a[j + 1];
                        a[j + 1] = b;
                    }
                }
            }
            end = chrono::high_resolution_clock::now();
            duration = end - start;
            for (int i = 0; i < N; i++) {
                cout << a[i] << " ";
            }
            cout << "\n";
            cout << "Время сортировки массива -> " << duration.count() << "\n";
            break;
            //--------------------------------------------------------------------------
        case(3):
            maxnesort = a[0];
            minnesort = a[0];
            start = chrono::high_resolution_clock::now();
            for (int i = 1; i < N; i++) {
                if (a[i] > maxnesort) {
                    maxnesort = a[i];
                }
                if (a[i] < minnesort) {
                    minnesort = a[i];
                }
            }
            end = chrono::high_resolution_clock::now();
            duration = end - start;
            cout << "Минимальное не сортированное -> " << minnesort << " Максмальное не сортированное -> " << maxnesort << " время поиска -> " << duration.count() << "\n";
            for (int i = 0; i < N; i++) {
                cout << a[i] << " ";
            }

            cout << "\n" << "\n";
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N - 1; j++) {
                    if (a[j] > a[j + 1]) {
                        int b = a[j];
                        a[j] = a[j + 1];
                        a[j + 1] = b;
                    }
                }
            }
            start = chrono::high_resolution_clock::now();
            maxnesort1 = a[99];
            minnesort1 = a[0];
            end = chrono::high_resolution_clock::now();
            duration = end - start;
            cout << "Минимальное не сортированное -> " << minnesort << " Максимальное не сортированное -> " << maxnesort << " время поиска -> " << duration.count() << "\n";
            for (int i = 0; i < N; i++) {
                cout << a[i] << " ";
            }
            break;
            //--------------------------------------------------------------------------
        case(4):
            count = 0;
            maxnesort = a[0];
            minnesort = a[0];
            syma = 0;
            for (int i = 0; i < N; ++i) {
                if (a[i] > maxnesort) {
                    maxnesort = a[i];
                }
                if (a[i] < minnesort) {
                    minnesort = a[i];
                }
            }
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N - 1; j++) {
                    if (a[j] > a[j + 1]) {
                        int b = a[j];
                        a[j] = a[j + 1];
                        a[j + 1] = b;
                    }
                }
            }
            cout << "Максимальное и минимальное значение перебором " << maxnesort << " " << minnesort << "\n" << "Максимальное и минимальное в отсортированом массиве a[99], a[0] " << a[99] << " " << a[0] << "\n";
            syma = (maxnesort + minnesort) / 2;
            cout << "Среднее максимального и минимального -> " << syma << "\n";
            start = chrono::high_resolution_clock::now();
            for (int i = 0; i < N; i++) {
                if (a[i] == syma) {
                    cout << i << " ";
                    count++;
                }
            }
            end = chrono::high_resolution_clock::now();
            duration = end - start;
            if (count != 0) {
                cout << "<- Индекс(ы) элементов равные среднему максимального и минимального \n";
                cout << "Время вывода поиска индексов элементов равные среднему максимальному и минимального -> " << duration.count() << "\n";
            }
            else {
                cout << "Время поиска индексов но ничего не найдено -> " << duration.count() << "\n";
            }
            break;
            //--------------------------------------------------------------------------
        case (5):
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N - 1; j++) {
                    if (a[j] > a[j + 1]) {
                        int b = a[j];
                        a[j] = a[j + 1];
                        a[j + 1] = b;
                    }
                }
            }
            cin >> polz;
            k = 0;
            while (a[k] < polz) {
                k += 1;
            }

            cout << k << " <- Элементов меньше значения ведённого пользователем" << "\n";
            //   for (int i = 0; i < N; i++){
            //        cout << a[i] << " ";
            //    }
            break;
            //--------------------------------------------------------------------------    
        case (6):
            k = N-1;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N - 1; j++) {
                    if (a[j] > a[j + 1]) {
                        int b = a[j];
                        a[j] = a[j + 1];
                        a[j + 1] = b;
                    }
                }
            } 
            cin >> polz;

            while (a[k] > polz) {
                k -= 1;
            }

            cout << 99 - k << " <- Элементов больше ведённого пользователем\n";
            break;
            //--------------------------------------------------------------------------
        case(7):
            minpred = 0;
            maxpred = N - 1;
            k;
            cin >> polz;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N - 1; j++) {
                    if (a[j] > a[j + 1]) {
                        int b = a[j];
                        a[j] = a[j + 1];
                        a[j + 1] = b;
                    }
                }
            }
            start = chrono::high_resolution_clock::now();
            while (minpred <= maxpred) {
                k = (minpred + maxpred) / 2;
                if (polz == a[k]) {
                    end = chrono::high_resolution_clock::now();
                    break;
                }
                else if (polz > a[k]) {
                    minpred = k + 1;
                }
                else {
                    maxpred = k - 1;
                }
            }
            duration = end - start;
            if (a[k] == polz) {
                cout << "Число успешно найдено бинарным поиском, затраченное на это время = " << duration.count() << " ";
            }
            else {
                cout << "Число отсутсвует в списке, затраченное на это время = " << duration.count() << " ";
            }
            cout << "\n";

            start = chrono::high_resolution_clock::now();
            for (int i = 0; i < N; i++) {
                if (a[i] == polz) {
                    end = chrono::high_resolution_clock::now();
                    break;
                }
            }
            duration = end - start;
            if (a[k] == polz) {
                cout << "Число найдено переборот, время на это затраченное = " << duration.count() << " ";
            }
            else {
                cout << "Число не найдено, время затраченное = " << duration.count() << " ";
            }
            break;
            //--------------------------------------------------------------------------


        case(8):
            int pervi_index, vtoriu_index;
            cout << "Введите индекс первого числа \n";
            cin >> pervi_index;
            cout << "Введите индекс второго числа \n";
            cin >> vtoriu_index;
            dop_chislo = pervi_index;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N - 1; j++) {
                    if (a[j] > a[j + 1]) {
                        int b = a[j];
                        a[j] = a[j + 1];
                        a[j + 1] = b;
                    }
                }
            }
            start = chrono::high_resolution_clock::now();
            swap(a[pervi_index], a[vtoriu_index]);
            end = chrono::high_resolution_clock::now();
            duration = end - start;
            cout << duration.count() << "\n";
            //for (int i = min(pervi_index, vtoriu_index); i != max(pervi_index, vtoriu_index); i++) {                
            //}
            //--------------------------------------------------------------------------

            for (int i = 0; i < N; i++) {

                cout << a[i] << " ";

            }
            break;
        }
    } while (is_true);
    return 7 - 8;
}