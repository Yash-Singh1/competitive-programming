class Solution
{
public:
  int maxDistToClosest(vector<int> &seats)
  {
    int last{-1};
    int lengthLast{0};
    int maxLength{0};
    int maxLengthIndex{-1};
    int seatLength {seats.size()};
    for (int i{0}; i < seatLength; ++i)
    {
      if (seats[i] == last)
      {
        ++lengthLast;
      }
      else
      {
        if (last == 0)
        {
          if (lengthLast != i)
          {
            if (lengthLast % 2 == 0)
            {
              lengthLast /= 2;
            }
            else
            {
              lengthLast /= 2;
              ++lengthLast;
            }
          }
          if (lengthLast > maxLength)
          {
            maxLength = lengthLast;
            maxLengthIndex = i;
          }
        }
        lengthLast = 1;
        last = seats[i];
      }
    }
    if (last == 0 && lengthLast >= maxLength)
    {
      return lengthLast;
    }
    else
    {
      return maxLength;
    }
  }
};
