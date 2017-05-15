#include <cstdlib>
#include <iostream>
#include <string.h>

#define RUN 1

using namespace std;

int split_line(char ***dst_line, char *src_line);

int main(void) { 
    
    printf("Looool!");
    cout << "Lol";
    /*
    if (!RUN) {
        char *tmp_a = NULL, *tmp_b = NULL;
        int a = 0;
        // ВОТ ОНО!!! Если strcmp принял указатель со значаением NULL, будет Segmentation fault. 
        a = strcmp(tmp_a, "lol");
        return 0;
    }
    */
    char in_buff[256], **in_argvs = NULL;
    cout << "Lol";
    /////////////////////////////////////////////////////////////

    //char test_buf[10] = {'q', 'w', 'e', '\0'};
    char test_buf[10] = {'\0'};

    char *tmp_ptr; // = NULL;
    tmp_ptr = strtok(test_buf, " ");
    //cout << strcmp(test_buf, tmp_ptr);
    cout << tmp_ptr;


    return 0;


    /////////////////////////////////////////////////////////////

    cout << "Char** :" << sizeof (char**) << endl;
    cout << "Char*  :" << sizeof (char*) << endl;
    cout << "Char   :" << sizeof (char) << endl;
    cout << "Int    :" << sizeof (int) << endl;
    cout << "Unsigned Long Int :" << sizeof (unsigned long) << endl;

    //return 0;

    while (true) {
        cout << "> ";
        cin.getline(in_buff, 256);


        //int sret = split_line(&in_argvs, in_buff);

        // Разделяем предложение на отдельные слова. +!_Работает_!+.
        //        char *tmpc = strtok(in_buff, " ");
        //        cout << tmpc << endl;
        //        while (tmpc != NULL) {
        //            tmpc = strtok(NULL, " ");
        //            cout << tmpc << endl;
        //        }
        //        return 0;



        //        int mresult = split_line(&in_argvs, in_buff);
        //        cout << mresult << endl;
        //        unsigned long addr;
        //        for (int i = 0; i < mresult; i++) {
        //            addr = (unsigned long) (in_argvs + i);
        //            cout << addr << " : " << *(in_argvs + i) << endl;
        //        }
        //        return 0;

        int wcounts = split_line(&in_argvs, in_buff);
        cout << wcounts << endl;
        if (!strcmp((*in_argvs), "exit"))
            break;

        if (!strcmp((*in_argvs), "get-all")) {
            cout << "get-all\n";
        }
        free(in_argvs);
    }
    return 0;
}

/*
 * Функция разделяет предложение на отдельные слова. +!_Работает_!+.
 * Функция создает на выходе массив указателей на строки такой-же как
 * argv в функции main и возвращает количествое считанных слов, как argc.
 */
int split_line(char ***dst_line, char *src_line) {
    int words_num; // Количество слов.
    // Выделяем память под массив указателей. Пока на 1 элемент.
    *dst_line = (char**) calloc(1, sizeof (char*));
    // Достаем указатель на первое слово, а точнее адрес первого символа этого слова.
    **dst_line = strtok(src_line, " ");
    char *tmpp; // Переменная для временного хранения указателей на извлекаемые слова.
    // Достаем указатель на следующее слово. Если слов больше нет вернется NULL.
    for (words_num = 1; (tmpp = strtok(NULL, " ")) != NULL; words_num++) {
        // Добавим места для нового слова.
        *dst_line = (char**) realloc(*dst_line, sizeof (char*)*(words_num + 1));
        // Адрес нового слова присвоим соответствующем элементу массива.
        *((*dst_line) + words_num) = tmpp;
    }
    return words_num;
}

