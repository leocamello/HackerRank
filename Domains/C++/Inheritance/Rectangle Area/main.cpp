class Rectangle {
    protected:
        int width, height;

    public:
        void Display() {
            cout << width << " " << height << endl;
        }
};

class RectangleArea : public Rectangle {
    public:
        void Input() {
            cin >> width >> height;
        }

        void Display() {
            cout << width * height << endl;
        }
};
