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

struct Stack
{
public:
    Stack() : NumEl(0), Items(NULL)
    {}

    ~Stack() {
        clear_list(&Items);
    }

    void push(int elem) {
        push_left(&Items, elem);
        NumEl++;
    }

    int pop() {
        NumEl--;
        return node_pop(&Items, 0);
    }

	bool Stack_Is_Empty() {
		return NumEl == 0;
	}

    int top() {
        return Items == NULL ? -1 : Items->value;
    }

    int depth() {
        return NumEl;
    }

private:
    int NumEl;
    Node* Items;
};

int get_int(string num) {
    return stoi(num);
}

int main() {
    Stack a;
    string m;
    int first;
    int second;
    int result;
    while (cin >> m)
    {
        if (m == "+")
        {
            second = a.pop();
            first = a.pop();
            result = first + second;
            a.push(result);
        }
        else if (m == "-")
        {
            second = a.pop();
            first = a.pop();
            result = first - second;
            a.push(result);
        }
        else if (m == "*")
        {
            second = a.pop();
            first = a.pop();
            result = first * second;
            a.push(result);
        }
        else if (m == "/") 
        {
            second = a.pop();
            first = a.pop();
            result = first / second;
            a.push(result);
        }
        else
        {
            a.push(get_int(m));
        }
    }
    cout << a.top();
	return 0;
}