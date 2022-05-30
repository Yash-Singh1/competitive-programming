map<int, int> facts;

int fact(int n) {
    int storen {n};
    if (facts.find(n) != facts.end()) {
        return facts[n];
    }
    int res = 1;
    while (n > 1) {
        if (facts.find(n) != facts.end()) {
            res *= facts[n];
            res %= MOD;
            break;
        }
        res *= n;
        res %= MOD;
        --n;
    }
    facts[storen] = res;
    return res;
}
