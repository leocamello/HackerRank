template <class T>
class AddElements {
    private:
        T element;
    public:
        AddElements(T element) {
            this->element = element;
        }

        T add(T element) {
            return this->element + element;
        }
};

template <>
class AddElements<string> {
    private:
        string element;
    public:
        AddElements(string element) {
            this->element = element;
        }

        string concatenate(string element) {
            return this->element + element;
        }
};
