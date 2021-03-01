#include <iostream>

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

int main() {
    Stack a;
    int num;
    cin >> num;
    while (num != 0)
    {
        if (num > 0)
        {
            a.push(num);
        }
        if (num < 0)
        {
            if (a.depth() != 0) {
                if (-num < a.top())
                {
                    int temp = a.pop();
                    a.push(temp + num);
                }
                else {
                    a.pop();
                }
            }
        }
        cin >> num;
    }
    cout << a.depth() << ' ' << a.top();
	return 0;
}