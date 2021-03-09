#include <iostream>
#include <string>

using namespace std;

int main() {
	char array[1000000];
	fgets(array, 1000000, stdin);

	char * p_array = array;
	char tmp [100];
	int i = 0;

	while (*p_array != '\0') {
		if (*p_array != ' ')
		{
			cout << *p_array;
		} 
		else if (*p_array == ' ' or *p_array == '\0')
		{
			cout << endl;
		}
		p_array++;
	}
	return 0;
}