// Still WIP, some WA

class Solution
{

public:
    int xmod11(string x)
    {
        if (x[0] == '-') {
            x.erase(0,1);
        }
        int n {x[0] - '0'};
        while (x.size() > 2 || std::stoi(x) > 11) {
         for (int i{1}; i < x.size(); ++i) {
          if (i % 2 == 0) {
              n += x[i] - '0';
          } else {
              n -= x[i] - '0';
          }
         }
         n = std::abs(n);
         x = std::to_string(n);
         n = x[0] - '0';
        }
       return std::stoi(x);
    }
};
