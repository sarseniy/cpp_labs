#include <iostream>

struct string {
    char *str;
    size_t size;
    size_t capacity;

    string() {
    	size = 1;
    	capacity = 2;
    	str = new char [capacity];
    	str[0] = '\0';
    }  // Конструктор пустой строки

    string(size_t cnt, char c) {
    	string();
    	while (capacity <= cnt) {
    		reallocate(capacity * 2);
    	}
    	for (int i = 0; i < cnt; ++i)
    	{
    		str[i] = c;
    	}
    	str[cnt] = '\0';
    }  // Заполняющий конструктор

    string(const string& s) {
    	size = s.size;
    	capacity = s.capacity;
    	str = new char [capacity];
    	str = s.str;
    }  // Копирующий конструктор

    string(char c) {
    	size = 2;
    	capacity = 2;
    	str = new char [2];
    	str[0] = c;
    	str[1] = '\0';
    }  // Конструктор строки из одного символа

    string(const char * c_str) {
    	string();
    	int count = 0;
    	char * my_c_str;
    	while (*my_c_str != '\0') {
    		count++;
    		my_c_str++;
    	}
    	while (capacity <= count) {
    		reallocate(capacity * 2);
    	}
    	for (int i = 0; i < count; ++i)
    	{
    		str[i] = c_str[i];
    	}
    	str[count] = '\0';
    }  // Конструктор строки из c-style строки (массива символов)

    ~string() {
    	delete [] str;
    }     //очистить всю используемую память

    string& operator= (const string& new_str) {  }

    bool operator== (const string& other) {  }

    bool operator!= (const string& other) {  }

    bool operator> (const string& other) {  }

    bool operator< (const string& other) {  }

    string& operator+= (const string& other) {  }

    char operator[] (unsigned int pos) {  }

    void append(const string other);  // дописать в конец данной строки другую

    void reallocate(unsigned int new_capacity) {
    	capacity = new_capacity;
    	char * new_data = new char [capacity];
    	for (int i = 0; i < size and i < capacity; ++i)
    	{
    		new_data[i] = str[i];
    	}
    	delete [] str;
    	str = new_data;
    }  // реаллокация

    void insert(unsigned int pos, string other);  // Вставка другой строки внутрь данной

    void shrink_to_fit();  //очистить неиспользуемую память

    void clear();   //очистить содержимое строки, занимаемое место при этом не меняется

    friend std::ostream& operator<< (std::ostream& ostr, const string& str) {
    	ostr << str.str;
    }

    friend std::istream& operator>> (std::istream& istr, string& str) {  }

};


string operator + (const string & str1, const string & str2)
{

}


int stoi(const string str, size_t pos = 0, int base = 10 );
// Преобразование числа, записанного символами в строке, в int
// base - основание системы счисления
// Числа могут быть отрицательными
// Обработка чисел в сс > 10. Большие и маленькие буквы.

int main()
{
	string a;
	string b(7, 'b');
	//string c(a);
	//string d('d');
	//string e("abcdef");

	//std::cout << e;
	return 0;
}