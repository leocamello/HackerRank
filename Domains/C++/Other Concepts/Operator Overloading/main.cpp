class Matrix {
    public:
    vector<vector<int>> a;
    Matrix operator + (const Matrix& other) {
        Matrix result;
        int rows = a.size(), columns = a[0].size();

        for (int i = 0; i < rows; i++) {
            vector<int> row;
            for (int j = 0; j < columns; j++) {
                row.push_back(a[i][j] + other.a[i][j]);
            }
            result.a.push_back(row);
        }

        return result;
    }
};
