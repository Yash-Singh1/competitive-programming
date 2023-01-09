// Modified version of GeeksForGeeks code demonstrating how to use G++ ordered set as multiset.
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
#include <iostream>
using namespace __gnu_pbds;
using namespace std;

// a new data structure defined. Please refer below
// GNU link : https://goo.gl/WVDL6g
typedef tree<pair<int, int>, null_type,
             less<pair<int, int> >, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_multiset;

// Driver code
int main()
{
    ordered_multiset p;

    // During insertion, use {VAL, IDX}
    p.insert({ 5, 0 });
    p.insert({ 5, 1 });
    p.insert({ 5, 2 });
    p.insert({ 2, 3 });
    p.insert({ 2, 4 });
    p.insert({ 6, 5 });
    p.insert({ 4, 6 });

    for (int i = 0; i < (int)p.size(); i++) {

        cout << "The element present at the index " << i
             << " is ";

        // Print element present at the ith index
        // Use .first to get the actual value
        cout << p.find_by_order(i)->first << ' ';
        cout << '\n';
    }

    cout << "\nDeleting element of 2\n\n";

    // Whenever searching use {VAL, 0}       for lower_bound
    //                        {VAL, IDX}     for find
    //                        {VAL, INT_MAX} for upper_bound
    p.erase(p.lower_bound({ 2, 0 }));

    for (int i = 0; i < (int)p.size(); i++) {

        cout << "The element present at the index " << i
             << " is ";

        cout << p.find_by_order(i)->first << ' ';
        cout << '\n';
    }

    return 0;
}
