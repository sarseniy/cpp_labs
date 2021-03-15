#include <iostream>

struct string {
    char* str;
    size_t size;
    size_t capacity;

    string() {
        size = 0;
        capacity = 2;
        str = new char[capacity];
        str[0] = '\0';
    }  // Конструктор пустой строки

    string(size_t cnt, char c) {
        size = 0;
        capacity = 2;
        str = new char[capacity];
        str[0] = '\0';

        while (capacity <= cnt) {
            reallocate(capacity * 2);
        }

        size = cnt;

        for (size_t i = 0; i < cnt; ++i)
        {
            str[i] = c;
        }

        str[cnt] = '\0';
    }  // Заполняющий конструктор

    string(const string& s) {
        size = s.size;
        capacity = s.capacity;
        str = new char[capacity];
        str = s.str;
    }  // Копирующий конструктор

    string(char c) {
        size = 1;
        capacity = 2;
        str = new char[2];
        str[0] = c;
        str[1] = '\0';
    }  // Конструктор строки из одного символа

    string(const char* c_str) {
        size = 0;
        capacity = 2;
        str = new char[capacity];
        str[0] = '\0';

        size_t count = 0;
        while (c_str[count] != '\0') {
            count++;
        }

        while (capacity <= count) {
            reallocate(capacity * 2);
        }

        size = count;

        for (size_t i = 0; i < count; ++i)
        {
            str[i] = c_str[i];
        }

        str[count] = '\0';
    }  // Конструктор строки из c-style строки (массива символов)

    ~string() {
        delete[] str;
    }     //очистить всю используемую память

    string& operator= (const string& new_str) {
        if (this->capacity > new_str.size)
        {
            size = new_str.size;
            delete[] str;
            str = new_str.str;
        }
        else
        {
            while (capacity <= new_str.size)
            {
                reallocate(capacity * 2);
            }

            size = new_str.size;

            for (size_t i = 0; i < size; i++)
            {
                str[i] = new_str.str[i];
            }
            str[size] = '\0';
        }
        return *this;
    }

    bool operator== (const string& other) {

    }

    bool operator!= (const string& other) {  }

    bool operator> (const string& other) {  }

    bool operator< (const string& other) {  }

    string& operator+= (const string& other) {  }

    char operator[] (unsigned int pos) {  }

    void append(const string other);  // дописать в конец данной строки другую

    void reallocate(unsigned int new_capacity) {
        capacity = new_capacity;
        char* new_data = new char[capacity];
        for (size_t i = 0; i < size + 1 and i < capacity; ++i)
        {
            new_data[i] = str[i];
        }
        delete[] str;
        str = new_data;
    }  // реаллокация

    void insert(unsigned int pos, string other);  // Вставка другой строки внутрь данной

    void shrink_to_fit();  //очистить неиспользуемую память

    void clear();   //очистить содержимое строки, занимаемое место при этом не меняется

    friend std::ostream& operator<< (std::ostream& ostr, const string& str) {
        return ostr << str.str;
    }

    friend std::istream& operator>> (std::istream& istr, string& str) {  }

};


string operator + (const string& str1, const string& str2);


int stoi(const string str, size_t pos = 0, int base = 10);
// Преобразование числа, записанного символами в строке, в int
// base - основание системы счисления
// Числа могут быть отрицательными
// Обработка чисел в сс > 10. Большие и маленькие буквы.

int main()
{
    string a;
    string b(7, 'b');
    string c(b);
    string d('d');
    string e("abcdef");

    a = e;

    return 0;
}