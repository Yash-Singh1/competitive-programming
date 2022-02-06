class Bitset {
private:
  string val;
  int size2;
  int ones {0};
public:
    Bitset(int size) {
        val = string(size, '0');
        size2 = size;
    }
    
    void fix(int idx) {
        val[idx] = '1';
      if (val[idx] == '0') {
        ++ones;
      }
    }
    
    void unfix(int idx) {
      val[idx] = '0';
      if (val[idx] == '1') {
        --ones;
      }
    }
    
    void flip() {
        for (unsigned long i{0}; i < size2; ++i) {
          if (val[i] == '0') {
            val[i] = '1';
            ++ones;
          } else {
            val[i] = '0';
            --ones;
          }
        }
      // ones = size2 - ones;
    }

    bool all() {
      cout << ones << " " << val << endl;
      return ones == size2;
    }

    bool one() {
      return ones > 0;
    }

    int count() {
      return std::count(val.begin(), val.end(), '1');
    }

    string toString() {
      return val;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */