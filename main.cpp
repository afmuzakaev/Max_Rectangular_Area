#include <iostream>
#include <stack>
using namespace std;

long long largestRectangleArea(int arr[], int N) {
    stack<int> s;
    long long maxArea = 0;
    
    for (int i = 0; i < N; i++) {
        while (!s.empty() && arr[i] <= arr[s.top()]) {
            int height = arr[s.top()];
            s.pop();
            
            int width = (s.empty() ? i : i - s.top() - 1);
            maxArea = max(maxArea, static_cast<long long>(height) * width);
        }
        s.push(i);
    }
    
    while (!s.empty()) {
        int height = arr[s.top()];
        s.pop();
        
        int width = (s.empty() ? N : N - s.top() - 1);
        maxArea = max(maxArea, static_cast<long long>(height) * width);
    }
    
    return maxArea;
}

int main() {
    int N;
    cin >> N;
    
    int arr[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    long long result = largestRectangleArea(arr, N);
    cout << "Largest rectangular area: " << result << endl;
    
    return 0;
}
