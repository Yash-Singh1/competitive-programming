#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

vector<size_t> filterZero(vector<size_t> vec)
{
  vector<size_t> newVector;
  for (auto number : vec)
  {
    if (number != 0)
    {
      newVector.push_back(number);
    }
  }
  return newVector;
}

bool includes(vector<size_t> vec, size_t search)
{
  for (auto num : vec)
  {
    if (num == search)
    {
      return true;
    }
  }
  return false;
}

vector<vector<size_t>> transpose(vector<vector<size_t>> state)
{
  vector<vector<size_t>> newVec(4, vector<size_t>());
  for (auto row : state)
  {
    for (size_t i{0}; i < 4; ++i)
    {
      newVec[i].insert(newVec[i].begin(), row[i]);
    }
  }
  return newVec;
}

vector<vector<size_t>> untranspose(vector<vector<size_t>> state)
{
  vector<vector<size_t>> newVec;
  for (size_t i{0}; i < 4; ++i) {
    newVec.push_back(vector<size_t>());
  }
  for (auto row : state)
  {
    for (size_t i{0}; i < 4; ++i)
    {
      newVec[3 - i].push_back(row[i]);
    }
  }
  return newVec;
}

int main()
{
  vector<vector<size_t>> state;
  for (size_t i{0}; i < 4; ++i)
  {
    vector<size_t> row;
    for (size_t j{0}; j < 4; ++j)
    {
      size_t cell;
      cin >> cell;
      row.push_back(cell);
    }
    state.push_back(row);
  }

  unsigned short dir;
  cin >> dir;

  if (dir == 1 || dir == 3)
  {
    state = transpose(state);
  }

  for (size_t i{0}; i < 4; ++i)
  {
    state[i] = filterZero(state[i]);

    for (size_t k{0}; k < state[i].size() - 4; ++k)
    {
      if (dir == 0)
      {
        state[i].push_back(0);
      }
      else
      {
        state[i].insert(state[i].begin(), 0);
      }
    }
  }

  for (size_t i{0}; i < 4; ++i)
  {
    vector<size_t> upgraded;
    for (size_t j{(dir == 0 || dir == 3 ? static_cast<size_t>(1) : 2)}; (dir == 0 || dir == 3 ? j < 4 : j >= 0); j += (dir == 0 || dir == 3 ? 1 : -1))
    {
      if (state[i][j] != 0 && state[i][j + (dir == 0 || dir == 3 ? -1 : 1)] == state[i][j] && !includes(upgraded, j))
      {
        state[i][j + (dir == 0 || dir == 3 ? -1 : 1)] *= 2;
        state[i][j] = 0;
        upgraded.push_back(j + (dir == 0 || dir == 3 ? -1 : 1));
      }
      if (j == 0)
      {
        break;
      }
    }
  }

  for (size_t i{0}; i < 4; ++i)
  {
    state[i] = filterZero(state[i]);

    for (size_t k{0}; k < state[i].size() - 4; ++k)
    {
      if (dir == 0 || dir == 3)
      {
        state[i].push_back(0);
      }
      else
      {
        state[i].insert(state[i].begin(), 0);
      }
    }
  }

  if (dir == 1 || dir == 3)
  {
    state = untranspose(state);
  }

  for (size_t i{0}; i < 4; ++i)
  {
    for (size_t j{0}; j < 4; ++j)
    {
      cout << state[i][j];
      if (j != 3)
      {
        cout << ' ';
      }
    }
    cout << std::endl;
  }
}
