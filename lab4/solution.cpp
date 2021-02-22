#include <iostream>

using namespace std;

struct Node {
    int value;
    struct Node* next;
};

void push_back(Node** head, int value)
{
    if (*head == NULL) {
        *head = new Node;
        (*head)->value = value;
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
    new_node->next = NULL;
}

void print_list(Node* head) {
    Node* p_node = head;
    while (p_node != NULL) {
        std::cout << p_node->value << ' ';
        p_node = p_node->next;
    }
    std::cout << '\n';
}

// 1 задание

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

// 2 задание

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

// 3 задание

int pop(Node** head, int index) {
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

// 4 задание

void remove(Node** head, int value) {
    Node* p_node = *head;
    Node* tmp = *head;

    while (p_node->value != value)
    {
        if (p_node->next == NULL) return;
        tmp = p_node;
        p_node = p_node->next;
    }
    if (p_node == *head) {
        tmp = p_node;
        delete p_node;
        *head = tmp->next;
        return;
    }

    tmp->next = p_node->next;
    delete p_node;
}

// 5 задание

void remove_all(Node** head, int value) {
    Node* p_node = *head;
    Node* tmp = *head;

    while (p_node->next != NULL) {
        if (p_node->value == value) {
            if (p_node == *head) {
                tmp = p_node;
                *head = tmp->next;
                delete p_node;
                p_node = *head;
                tmp = p_node;
            }
            else {
                tmp->next = p_node->next;
                delete p_node;
                p_node = tmp->next;
            }
        }
        else
        {
            tmp = p_node;
            p_node = p_node->next;
        }
    }
    if (p_node->value == value)
    {
        tmp->next = NULL;
        delete p_node;
    }
}

// 6 задание

void replace_all(Node* head, int old_value, int new_value) {
    Node* p_node = head;
    while (p_node != NULL)
    {
        if (p_node->value == old_value)
        {
            p_node->value = new_value;
        }
        p_node = p_node->next;
    }
}

// 7 задание

bool contains_in(Node* head, int value) {
    Node* p_node = head;
    while (p_node != NULL)
    {
        if (p_node->value == value) return true;
        p_node = p_node->next;
    }
    return false;
}

int count_length(Node* head) {
    int count = 0;
    Node* p_node = head;
    while (p_node != NULL)
    {
        count++;
        p_node = p_node->next;
    }
    return count;
}

int unique(Node* head) {
    Node* list_of_unique = NULL;
    Node* p_node = head;
    while (p_node != NULL)
    {
        if (not contains_in(list_of_unique, p_node->value)) {
            push_back(&list_of_unique, p_node->value);
        }
        p_node = p_node->next;
    }
    return count_length(list_of_unique);
}

// 8 задание

void reverse(Node** head) {
    Node* new_head = NULL;
    Node* p_node = *head;
    while (p_node != NULL)
    {
        push_left(&new_head, p_node->value);
        p_node = p_node->next;
    }
    Node* tmp = *head;
    *head = new_head;
    clear_list(&tmp);
}

// 9* задание

// Склеивание двух отсортированных списков
void merge(Node* first, Node* second, Node** result) {
    Node tmp;
    *result = NULL;

    if (first == NULL) {
        *result = second;
        return;
    }
    if (second == NULL) {
        *result = first;
        return;
    }

    if (first->value < second->value) {
        *result = first;
        first = first->next;
    }
    else {
        *result = second;
        second = second->next;
    }

    tmp.next = *result;

    while (first && second) {
        if (first->value < second->value) {
            (*result)->next = first;
            first = first->next;
        }
        else {
            (*result)->next = second;
            second = second->next;
        }
        (*result) = (*result)->next;
    }

    if (first) {
        while (first) {
            (*result)->next = first;
            (*result) = (*result)->next;
            first = first->next;
        }
    }
    if (second) {
        while (second) {
            (*result)->next = second;
            (*result) = (*result)->next;
            second = second->next;
        }
    }

    *result = tmp.next;
}

// Разделение списка пополам
void split(Node* head, Node** lower, Node** upper) {
    Node* fast = NULL;
    Node* slow = NULL;

    if (head == NULL || head->next == NULL) {
        (*lower) = head;
        (*upper) = NULL;
        return;
    }

    slow = head;
    fast = head->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
    }

    *lower = head;
    *upper = slow->next;
    slow->next = NULL;
}

// Основная сортировка
void merge_sort(Node** head) {

    Node* lower = NULL;
    Node* upper = NULL;

    if ((*head == NULL) || ((*head)->next == NULL)) {
        return;
    }

    split(*head, &lower, &upper);

    merge_sort(&lower);
    merge_sort(&upper);

    merge(lower, upper, head);
}

int main() {
    Node* list = NULL;
    for (int i = 1; i <= 10; ++i) {
        push_back(&list, i);
        push_back(&list, i % 2);
    }

    // 1 задание

    push_left(&list, 70);
    print_list(list);

    // 3 задание

    std::cout << pop(&list, 0) << '\n';
    print_list(list);

    // 4 задание

    remove(&list, 7);
    print_list(list);

    // 5 задание

    remove_all(&list, 1);
    print_list(list);

    // 6 задание

    replace_all(list, 0, 33);
    print_list(list);

    // 7 задание

    std::cout << unique(list) << '\n';

    // 8 задание

    reverse(&list);
    print_list(list);

    // 9* задание (сортировка слиянием через указатели)

    merge_sort(&list);
    print_list(list);

    // 2 задание

    clear_list(&list);
    return 0;
}