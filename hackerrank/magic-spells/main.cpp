#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Spell { 
    private:
        string scrollName;
    public:
        Spell(): scrollName("") { }
        Spell(string name): scrollName(name) { }
        virtual ~Spell() { }
        string revealScrollName() {
            return scrollName;
        }
};

class Fireball : public Spell { 
    private: int power;
    public:
        Fireball(int power): power(power) { }
        void revealFirepower(){
            cout << "Fireball: " << power << endl;
        }
};

class Frostbite : public Spell {
    private: int power;
    public:
        Frostbite(int power): power(power) { }
        void revealFrostpower(){
            cout << "Frostbite: " << power << endl;
        }
};

class Thunderstorm : public Spell { 
    private: int power;
    public:
        Thunderstorm(int power): power(power) { }
        void revealThunderpower(){
            cout << "Thunderstorm: " << power << endl;
        }
};

class Waterbolt : public Spell { 
    private: int power;
    public:
        Waterbolt(int power): power(power) { }
        void revealWaterpower(){
            cout << "Waterbolt: " << power << endl;
        }
};

class SpellJournal {
    public:
        static string journal;
        static string read() {
            return journal;
        }
}; 
string SpellJournal::journal = "";

void counterspell(Spell *spell) {
    string state {"generic"};
    Fireball my_fireball(0);
    Frostbite my_frost(0);
    Waterbolt my_water(0);
    Thunderstorm my_thunder(0);
    try {
        my_fireball = dynamic_cast<Fireball&>(*spell);
        state = "fire";
    } catch (const std::bad_cast& e) {}
    try {
        my_frost = dynamic_cast<Frostbite&>(*spell);
        state = "frost";
    } catch (const std::bad_cast& e) {}
    try {
        my_water = dynamic_cast<Waterbolt&>(*spell);
        state = "water";
    } catch (const std::bad_cast& e) {}
    try {
        my_thunder = dynamic_cast<Thunderstorm&>(*spell);
        state = "thunder";
    } catch (const std::bad_cast& e) {}
    if (state == "generic") {
        int tab[spell->revealScrollName().size() + 1][SpellJournal::read().size() + 1];
        for (int i{0}; i <= spell->revealScrollName().size(); ++i) {
            for (int j{0}; j <= SpellJournal::read().size(); ++j) {
                if (i == 0 || j == 0) tab[i][j] = 0;
                else if (spell->revealScrollName()[i - 1] == SpellJournal::read()[j - 1]) tab[i][j] = tab[i - 1][j - 1] + 1;
                else tab[i][j] = tab[i - 1][j] > tab[i][j - 1] ? tab[i - 1][j] : tab[i][j - 1];
            }
        }
        std::cout << tab[spell->revealScrollName().size()][SpellJournal::read().size()] << endl;
    }
    else {
        if (state == "fire") {
            my_fireball.revealFirepower();
        } else if (state == "frost") {
            my_frost.revealFrostpower();
        } else if (state == "water") {
            my_water.revealWaterpower();
        } else if (state == "thunder") {
            my_thunder.revealThunderpower();
        }
    }
}

class Wizard {
    public:
        Spell *cast() {
            Spell *spell;
            string s; cin >> s;
            int power; cin >> power;
            if(s == "fire") {
                spell = new Fireball(power);
            }
            else if(s == "frost") {
                spell = new Frostbite(power);
            }
            else if(s == "water") {
                spell = new Waterbolt(power);
            }
            else if(s == "thunder") {
                spell = new Thunderstorm(power);
            } 
            else {
                spell = new Spell(s);
                cin >> SpellJournal::journal;
            }
            return spell;
        }
};

int main() {
    int T;
    cin >> T;
    Wizard Arawn;
    while(T--) {
        Spell *spell = Arawn.cast();
        counterspell(spell);
    }
    return 0;
}