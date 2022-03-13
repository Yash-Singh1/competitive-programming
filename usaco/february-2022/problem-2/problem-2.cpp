// #include <iostream>
// #include <ios>
// #include <map>

// using std::cin;

// bool identical(int a[], int b[], int n)
// {
//   for (int i{0}; i < n; ++i)
//   {
//     if (a[i] != b[i])
//     {
//       return false;
//     }
//   }
//   return true;
// }

// int main()
// {
//   std::ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   int n{0};
//   cin >> n;
//   int a[n];
//   int b[n];
//   for (int i{0}; i < n; ++i)
//   {
//     cin >> a[i];
//   }
//   for (int i{0}; i < n; ++i)
//   {
//     cin >> b[i];
//   }
//   int swps{0};
//   while (!identical(a, b, n)) {
//     for (int i{n - 1}; i >= 0; --i) {
//       if (a[i] != b[i]) {
//         for (int j{n - 1}; j >= 0; --j) {
//           if (i != j && b[j] == a[i]) {
//             int swp{a[j]};
//             a[j] = a[i];
//             a[i] = swp;
//             for (int k{j + 1}; k < i; ++k) {
//               swp = a[k];
//               a[k] = a[i];
//               a[i] = swp;
//             }
//             ++swps;
//             break;
//           }
//         }
//         break;
//       }
//     }
//   }
//   std::cout << swps;
// }
