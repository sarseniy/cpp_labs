#include <iostream>
#include <random>
#include <chrono>
#include <fstream>

using namespace std;

struct Node {
    int value;
    int key;
    struct Node* next;
};

void push_back(Node** head, int value, int key)
{
    if (*head == NULL) {
        *head = new Node;
        (*head)->value = value;
        (*head)->key = key;
        (*head)->next = NULL;
        return;
    }

    Node* p_node = *head;
    while (p_node->next != NULL) {
        p_node = p_node->next;
    }

    Node* new_node = new Node;
    p_node->next = new_node;
    new_node->value = value;
    new_node->key = key;
    new_node->next = NULL;
}

int list_pop(Node** head, int key) {
    Node* p_node = *head;
    Node* tmp = *head;
    if (!*head)
    {
        return INT_MIN;
    }

    while (p_node->key != key)
    {
        if (p_node->next == NULL) return INT_MIN;
        tmp = p_node;
        p_node = p_node->next;
    }
    int val;
    if (p_node == *head) {
        val = p_node->value;
        tmp = p_node;
        *head = tmp->next;
        delete p_node;
        return val;
    }

    tmp->next = p_node->next;
    val = p_node->value;
    delete p_node;
    return val;
}

int list_get(Node* head, int key) {
    Node* p_node = head;
    Node* tmp = head;

    if (head == NULL) return INT_MIN;

    while (p_node->key != key)
    {
        if (p_node->next == NULL) return INT_MIN;
        tmp = p_node;
        p_node = p_node->next;
    }
    return p_node->value;
}

void clear_list(Node** head) {
    if (*head == NULL) return;

    Node* old_node = *head;
    Node* new_node = (*head)->next;

    while (new_node != NULL)
    {
        delete old_node;
        old_node = new_node;
        new_node = old_node->next;
    }

    delete old_node;
    *head = NULL;
}

int h(int size, int key, int index) {
    return index % size * key % size;
}

struct HashTable
{
    HashTable(int size) : size(size)
    {
        table = new Node* [size];
        for (size_t i = 0; i < size; i++)
        {
            table[i] = NULL;
        }
        key = size - 1;
        num = 0;
    }

    ~HashTable() 
    {
        for (size_t i = 0; i < size; i++)
        {
            clear_list(&table[i]);
        }
        delete[] table;
    }

    void add(int key, int value) {
        int hash;
        hash = h(size, this->key, key);
        push_back(&table[hash], value, key);
        num++;
        check_reallocate();
    }

    int pop(int key) {
        int hash;
        int res;
        hash = h(size, this->key, key);
        res = list_pop(&table[hash], key);
        if (res != INT_MIN)
        {
            num--;
        }
        return res;
    }

    int get(int key) {
        int hash;
        hash = h(size, this->key, key);
        return list_get(table[hash], key);
    }

    void check_reallocate() {
        if ((double)num / (double)size < 0.5) return;

        int new_size = 2 * size;
        Node ** new_table = new Node* [new_size];
        for (size_t i = 0; i < new_size; i++)
        {
            new_table[i] = NULL;
        }
        int new_h_key = new_size - 1;
        int new_num = 0;
        
        for (size_t i = 0; i < size; i++)
        {
            while (table[i] != NULL)
            {
                int new_value;
                int new_key;
                new_key = table[i]->key;
                new_value = this->pop(new_key);

                int hash;
                hash = h(new_size, new_h_key, new_key);
                push_back(&new_table[hash], new_value, new_key);
                new_num++;
            }
        }

        for (size_t i = 0; i < size; i++)
        {
            clear_list(&table[i]);
        }
        delete[] table;

        key = new_h_key;
        size = new_size;
        num = new_num;
        table = new_table;
    }
    
    int key;
    int size;
    int num;
    Node** table;

};

int main() {
    mt19937 engine(23);
    uniform_int_distribution<int> int_dist(0, 100000);
    ofstream f;

    HashTable h(100);
    Node* head = NULL;

    f.open("hash.txt");
    f.close();
    f.open("list.txt");
    f.close();
    f.open("hash_pop.txt");
    f.close();
    f.open("list_pop.txt");
    f.close();

    int num_list = 0;

    
    for (size_t i = 0; i < 10000; i++)
    {
        int tmp = int_dist(engine);
        {
            cout << i << ' ';
            f.open("hash.txt", ios::app);
            auto start = chrono::high_resolution_clock::now();
            h.add(tmp, i);
            auto end = chrono::high_resolution_clock::now();
            auto nsec = end - start;
            f << i << '\t' << nsec.count() << '\n';
            f.close();
        }
        {
            cout << i << '\n';
            f.open("list.txt", ios::app);
            auto start = chrono::high_resolution_clock::now();
            push_back(&head, i, tmp);
            auto end = chrono::high_resolution_clock::now();
            auto nsec = end - start;
            num_list++;
            f << i << '\t' << nsec.count() << '\n';
            f.close();
        }
    }

    for (size_t i = 0; i < 100000000; i++)
    {
        int tmp = int_dist(engine);
        {
            int res;
            cout << i << ' ';
            f.open("hash_pop.txt", ios::app);
            auto start = chrono::high_resolution_clock::now();
            res = h.pop(tmp);
            auto end = chrono::high_resolution_clock::now();
            auto nsec = end - start;
            f << h.num << '\t' << nsec.count() << '\n';
            f.close();
        }
        {
            int res;
            cout << i << '\n';
            f.open("list_pop.txt", ios::app);
            auto start = chrono::high_resolution_clock::now();
            res = list_pop(&head, tmp);
            auto end = chrono::high_resolution_clock::now();
            auto nsec = end - start;
            if (res != INT_MIN)
            {
                num_list--;
            }
            f << num_list << '\t' << nsec.count() << '\n';
            f.close();
        }
        break;
    }
    
    return 0;
}