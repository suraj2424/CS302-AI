#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Utility function to join elements of a vector with a delimiter
template <typename T>
string join(const vector<T>& vec, const string& delimiter) {
    string result;
    for (size_t i = 0; i < vec.size(); ++i) {
        result += vec[i];
        if (i < vec.size() - 1) {
            result += delimiter;
        }
    }
    return result;
}

vector<string> generate_k_sat(int k, int m, int n) {
    vector<string> variables;
    for (int i = 1; i <= n; ++i) {
        variables.push_back("x" + to_string(i));
    }

    vector<string> formula;

    for (int i = 0; i < m; ++i) {
        vector<string> clause(variables.begin(), variables.end());
        random_shuffle(clause.begin(), clause.end());
        clause.resize(k); // Keep only the first k elements

        // Append "~" to each variable in the clause to represent negation
        for (string& var : clause) {
            var = "~" + var;
        }

        formula.push_back("(" + join(clause, " OR ") + ")");
    }

    return formula;
}

void print_formula(const vector<string>& formula) {
    cout << "(" << join(formula, " AND ") << ")" << endl;
}

int main() {
    int k_value = 3;
    int m_value = 5;
    int n_value = 4;

    vector<string> random_k_sat_formula = generate_k_sat(k_value, m_value, n_value);

    cout << "Generated k-SAT formula:" << endl;
    print_formula(random_k_sat_formula);

    return 0;
}
