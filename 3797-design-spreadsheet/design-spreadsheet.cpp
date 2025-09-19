class Spreadsheet {
public:
    vector<vector<int>> sheet;
    int rows;
    Spreadsheet(int rows) {
        this -> rows = rows;
        sheet = vector<vector<int>>(rows, vector<int>(26, 0));
    }
    
    void setCell(string cell, int value) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;
        sheet[row][col] = value;
    }
    
    void resetCell(string cell) {
        setCell(cell, 0);
    }
    
    int getValue(string formula) {
        int idx = formula.find('+');
        string l = formula.substr(1, idx);
        string r = formula.substr(idx + 1);

        int lval = (l[0] >= 'A' && l[0] <= 'Z') ? sheet[stoi(l.substr(1)) - 1][l[0] - 'A'] : stoi(l);
        int rval = (r[0] >= 'A' && r[0] <= 'Z') ? sheet[stoi(r.substr(1)) - 1][r[0] - 'A'] : stoi(r);

        return lval + rval;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */