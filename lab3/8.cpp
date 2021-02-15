#include <iostream>
using std::cin;
using std::cout;
using std::endl;

struct Cat {
    char* name;
    unsigned int id;
    double weight, length;
    unsigned int mice_caught;
};

Cat* get_home_for_a_cats_pride(unsigned int n) {
    Cat* p_cat;
    p_cat = new struct Cat[n];
    for (int i = 0; i < n; i++) {
        p_cat[i].name = new char[10];
    }
    return p_cat;
}

void clear_home_of_a_cats_pride(Cat* cats, unsigned int n) {
    for (int i = 0; i < n; i++) {
        delete [] cats[i].name;
    }
    delete [] cats;
}

int main() {
    unsigned int n;
    cin >> n;
    Cat* a = get_home_for_a_cats_pride(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].name >> a[i].weight >> a[i].length >> a[i].mice_caught;
        a[i].id = i;
    }
    for (int i = 0; i < n; i++)
        cout << a[i].name << " ";
    cout << endl;
    clear_home_of_a_cats_pride(a, n);
    return 0;
}
