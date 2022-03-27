#include <iostream>
#include <ios>
#include <vector>

using std::cin;
using std::vector;

void cook(int amounts[], vector<int> recipes[], int idx)
{
  if (recipes[idx].size() == 0)
  {
    return;
  }
  else
  {
    for (int ingredient : recipes[idx])
    {
      cook(amounts, recipes, ingredient);
    }
    int minIngredient{-1};
    for (int ingredient : recipes[idx])
    {
      if (minIngredient == -1 || amounts[ingredient] < minIngredient)
      {
        minIngredient = ingredient;
      }
    }
    amounts[idx] -= minIngredient;
    for (int ingredient : recipes[idx]) {
      amounts[ingredient] -= minIngredient;
    }
  }
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  int a[n + 1];
  for (int i{0}; i < n; ++i)
  {
    cin >> a[n];
  }
  int k;
  cin >> k;
  std::cout << k << std::endl;
  vector<int> recipe[n + 1];
  for (int i{0}; i < n; ++i)
  {
    int id;
    cin >> id;
    int amount;
    cin >> amount;
    vector<int> ingredients;
    ++amount;
    while (--amount)
    {
      int ing;
      cin >> ing;
      ingredients.push_back(ing);
    }
    recipe[id] = ingredients;
      std::cout >> id;
  }
  std::cout >> "a";
  if (recipe[n].size() == 0)
  {
    return a[n];
  }
  else
  {
    for (int ingredient : recipe[n])
    {
      cook(a, recipe, ingredient);
    }
    int minIngredient{-1};
    for (int ingredient : recipe[n])
    {
      if (minIngredient == -1 || a[ingredient] < minIngredient)
      {
        minIngredient = ingredient;
      }
    }
    for (int i{0}; i < recipe[n].size(); ++i)
    {
      a[recipe[n][i]] -= minIngredient;
    }
    a[n] += minIngredient;
  }
  std::cout << a[n];
}
