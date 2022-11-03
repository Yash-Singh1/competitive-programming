void countSwaps(vector<int> a) {
    int swaps{0};
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < a.size() - 1; ++j) {
            // Swap adjacent elements if they are in decreasing order
            if (a[j] > a[j + 1]) {
                int s{a[j]};
                a[j] = a[j + 1];
                a[j + 1] = s;
                ++swaps;
            }
        }
    }
    cout << "Array is sorted in " << swaps << " swaps.\n" << "First Element: " << a[0] << "\n" << "Last Element: " << a[a.size()-1] << "\n";
}
