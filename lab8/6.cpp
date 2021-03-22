#include <iostream>
#include <string>

using namespace std;

struct Node {
	int value;
	struct Node* next;
};

int node_pop(Node** head, int index) {
    Node* tmp = *head;
    int result;

    if (index == 0) {
        *head = (*head)->next;
        result = tmp->value;
        delete tmp;
        return result;
    }

    int count = 0;
    Node* p_node = *head;
    while (count != index and p_node != NULL)
    {
        if (count == index - 1) {
            tmp = p_node->next;
            result = tmp->value;
            p_node->next = (p_node->next)->next;
            delete tmp;
            return result;
        }
        p_node = p_node->next;
        count++;
    }
}

void push_left(Node** head, int value) {
    if (*head == NULL) {
        *head = new Node;
        (*head)->value = value;
        (*head)->next = NULL;
        return;
    }

    Node* new_node = new Node;
    new_node->next = *head;
    new_node->value = value;
    *head = new_node;
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

void print_list(Node* head) {
    Node* p_node = head;
    while (p_node != NULL) {
        std::cout << p_node->value << ' ';
        p_node = p_node->next;
    }
    std::cout << '\n';
}

void insert(Node** head, int index, int value) {
    Node* p_node = *head;
    Node* tmp = new Node;

    if (*head == NULL or index == 0) {
        tmp->value = value;
        tmp->next = *head;
        *head = tmp;
        return;
    }

    for (int i = 0; i < index - 1; i++)
    {
        p_node = p_node->next;
    }

    tmp->value = value;
    tmp->next = p_node->next;
    p_node->next = tmp;
}

class Queue
{
public:
    Queue() : Size(0), Items(NULL)
    {}

    ~Queue() {
        clear_list(&Items);
    }

    int get() {
        Size--;
        return node_pop(&Items, Size);
    }

    void push_back(int elem) {
        push_left(&Items, elem);
        Size++;
    }

    void push_mid(int elem) {
        insert(&Items, (Size % 2 == 1) ? (Size - 1) / 2 : Size / 2, elem);
        Size++;
    }
    void print() {
        print_list(Items);
    }
private:
    Node* Items;
    int Size;
};

int main() {
    Queue a;
    int N;
    cin >> N;
    string input;
    for (int i = 0; i < N; i++) {
        cin >> input;
        if (input == "+") 
        {
            cin >> input;
            a.push_back(stoi(input));
        }
        else if (input == "*")
        {
            cin >> input;
            a.push_mid(stoi(input));
        }
        else if (input == "-")
        {
            cout << a.get() << '\n';
        }
    }
	return 0;
}