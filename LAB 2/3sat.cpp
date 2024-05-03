#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

bool is_3sat(const string& expression) {
    stringstream ss(expression);
    vector<string> clauses;

    // Split the expression into clauses
    string clause;
    while (getline(ss, clause, ')')) {
        if (!clause.empty()) {
            clauses.push_back(clause.substr(1)); // Exclude the opening parenthesis
        }
    }

    // Check if each clause has exactly three literals
    for (const string& clause : clauses) {
        stringstream clause_ss(clause);
        vector<string> literals;

        string literal;
        while (clause_ss >> literal) {
            literals.push_back(literal);
        }

        if (literals.size() != 3) {
            return false;
        }
    }

    return true;
}

int main() {
    string expression = "((~x3 OR ~x2 OR x3) AND (~x3 OR ~x2 OR x2) AND (~x1 OR ~x4 OR x1) AND (~x4 OR x1 OR x3) AND (x1 OR x2 OR ~x3))";

    if (is_3sat(expression)) {
        cout << "The expression is in 3-SAT form." << endl;
    } else {
        cout << "The expression is not in 3-SAT form." << endl;
    }

    return 0;
}
