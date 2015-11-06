class Student {
    private:
        int grades[5];
    public:
        void Input() {
            cin >> grades[0] >> grades[1] >> grades[2] >> grades[3] >> grades[4];
        }

        int CalculateTotalScore() {
            int sum = 0;
            for (int i = 0; i < 5; i++) {
                sum += grades[i];
            }
            return sum;
        }
};
