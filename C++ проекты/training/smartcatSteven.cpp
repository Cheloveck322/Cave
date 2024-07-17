#include <iostream>
#include <vector>

using namespace std;

int beauty_degree(vector<int>& arr) {
    int max_beauty = 0;
    int current_beauty = 1;
    int min_value = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] == arr[i - 1] + 1) {
            current_beauty++;
        } else {
            min_value = arr[i];
            if (current_beauty > max_beauty) {
                max_beauty = current_beauty;
            }
            current_beauty = 1;
        }
    }

    if (current_beauty > max_beauty) {
        max_beauty = current_beauty;
    }

    return (max_beauty > 1) ? max_beauty : 0;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (n == 1) {
        cout << 1 << endl; // Для массива из одного элемента степень красоты равна 1.
    } else {
        int result = beauty_degree(arr);
        cout << result << endl;
    }

    return 0;
}
