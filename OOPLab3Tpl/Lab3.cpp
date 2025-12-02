#include <iostream>
#include <stdexcept>
#include <cassert>
using namespace std;


// _________________________________ Task 1 ______________________________

class Vector {
private:
    unsigned int *data;
    size_t size_;
    int state;

    static size_t object_count;

    void init(size_t n, unsigned int value) {
        if ((int)n < 0) {
            state = -1;
            data = nullptr;
            size_ = 0;
            return;
        }
        data = nullptr;
        try {
            data = new unsigned int[n];
        } catch (bad_alloc &) {
            state = -2;
            size_ = 0;
            return;
        }
        size_ = n;
        state = 0;

        for (size_t i = 0; i < n; i++) {
            data[i] = value;
        }
    }

public:
    Vector() {
        init(1, 0);
        object_count++;
    }

    Vector(size_t n) {
        init(n, 0);
        object_count++;
    }

    Vector(size_t n, unsigned int value) {
        init(n, value);
        object_count++;
    }

    Vector(const Vector &other) {
        init(other.size_, 0);
        if (data) {
            for (size_t i = 0; i < other.size_; i++) {
                data[i] = other.data[i];
            }
        }
        state = other.state;
        object_count++;
    }

    Vector& operator=(const Vector &other) {
        if (this == &other) {
            return *this;
        }
        delete[] data;

        init(other.size_, 0);
        if (data) {
            for (size_t i = 0; i < other.size_; i++) {
                data[i] = other.data[i];
            }
        }
        state = other.state;
        return *this;
    }

    ~Vector() {
        delete[] data;
        object_count--;
    }

    void set(size_t index, unsigned int value = 0) {
        if (index >= size_) {
            state = -3;
            return;
        }
        data[index] = value;
        state = 0;
    }

    unsigned int get(size_t index) const {
        if (index >= size_) {
            return 0;
        }
        return data[index];
    }

    void print() const {
        cout << "[";
        for (size_t i = 0; i < size_; i++) {
            cout << data[i];
            if (i + 1 < size_) cout << ", ";
        }
        cout << "]";
    }

    Vector add(const Vector &other) const {
        size_t n = (size_ < other.size_) ? size_ : other.size_;
        Vector result(n);
        for (size_t i = 0; i < n; i++) {
            result.data[i] = data[i] + other.data[i];
        }
        return result;
    }
    Vector subtract(const Vector &other) const {
        size_t n = (size_ < other.size_) ? size_ : other.size_;
        Vector result(n);
        for (size_t i = 0; i < n; i++) {
            result.data[i] = data[i] - other.data[i];
        }
        return result;
    }

    Vector multiply(unsigned short m) const {
        Vector result(size_);
        for (size_t i = 0; i < size_; i++) {
            result.data[i] = data[i] * m;
        }
        return result;
    }

    bool greater(const Vector &other) const {
        size_t n = (size_ < other.size_) ? size_ : other.size_;
        for (size_t i = 0; i < n; i++) {
            if (data[i] > other.data[i]) return true;
            if (data[i] < other.data[i]) return false;
        }
        return size_ > other.size_;
    }

    bool less(const Vector &other) const {
        size_t n = (size_ < other.size_) ? size_ : other.size_;
        for (size_t i = 0; i < n; i++) {
            if (data[i] < other.data[i]) return true;
            if (data[i] > other.data[i]) return false;
        }
        return size_ < other.size_;
    }

    bool equal(const Vector &other) const {
        if (size_ != other.size_) return false;
        for (size_t i = 0; i < size_; i++) {
            if (data[i] != other.data[i]) return false;
        }
        return true;
    }

    bool not_equal(const Vector &other) const {
        return !equal(other);
    }

    int get_state() const {
        return state;
    }

    size_t size() const {
        return size_;
    }

    static size_t get_object_count() {
        return object_count;
    }
};

size_t Vector::object_count = 0;

int main1() {
    Vector v1;
    Vector v2(3);
    Vector v3(4, 5);

    v2.set(1, 10);
    cout << "v2: "; v2.print(); cout << "\n";

    Vector v4 = v3;
    cout << "v4 (копія v3): "; v4.print(); cout << "\n";

    Vector v5;
    v5 = v2;
    cout << "v5 після присвоєння v2: "; v5.print(); cout << "\n";

    Vector sum = v2.add(v3);
    cout << "sum v2+v3: "; sum.print(); cout << "\n";

    Vector diff = v3.subtract(v2);
    cout << "diff v3-v2: "; diff.print(); cout << "\n";

    Vector mul = v2.multiply(2);
    cout << "mul v2*2: "; mul.print(); cout << "\n";

    cout << "v3 > v2 ? " << v3.greater(v2) << "\n";
    cout << "v3 < v2 ? " << v3.less(v2) << "\n";
    cout << "v3 == v4 ? " << v3.equal(v4) << "\n";
    cout << "v2 != v3 ? " << v2.not_equal(v3) << "\n";

    cout << "Кількість об’єктів Vector: " << Vector::get_object_count() << "\n";

    return 0;
}

// _________________________________ Task 2 ______________________________

int main2() {}

// _________________________________ Task 3 ______________________________

int main3() {}