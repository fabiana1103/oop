#include <iostream>
#include <exception>

using namespace std;

class IndexOutOfBoundsException : public exception {
public:
    virtual const char* what() const throw() { //throw apeleaza catch
        return "exceptie: indexul este in afara domeniului valid";
    }
};

class Compare {
public:
    virtual int CompareElements(void* e1, void* e2) = 0;
};

template<class T>
class ArrayIterator {
private:
    int Current;
    T** List; //pointerii adreselor; list[0]=new T[14]

public:
    ArrayIterator() : Current(0), List(nullptr) {}

    ArrayIterator(T** list, int start) : List(list), Current(start) {}

    ArrayIterator& operator++() {
        Current++;
        return *this;
    }

    ArrayIterator& operator--() {
        Current--;
        return *this;
    }

    bool operator=(ArrayIterator<T>& other) {
        this->List = other.List;
        this->Current = other.Current;
        return true;
    }

    bool operator!=(ArrayIterator<T>& other) {
        return this->Current != other.Current;
    }

    T* GetElement() {
        return List[Current];
    }
};

template<class T>
class Array {
private:
    T** List;
    int Capacity;
    int Size;

    void resize(int newCapacity) {
        if (newCapacity <= Capacity) return;
        T** newList = new T * [newCapacity];
        for (int i = 0; i < Size; i++) {
            newList[i] = List[i];
        }
        delete[] List;
        List = newList;
        Capacity = newCapacity;
    }

public:

    Array() : Capacity(0), Size(0), List(nullptr) {}

    Array(int capacity) : Capacity(capacity), Size(0) {
        List = new T * [Capacity];
    }

    Array(const Array<T>& otherArray) {
        Capacity = otherArray.Capacity;
        Size = otherArray.Size;
        List = new T * [Capacity];
        for (int i = 0; i < Size; i++) {
            List[i] = new T(*(otherArray.List[i]));
        }
    }

    ~Array() {
        for (int i = 0; i < Size; i++) {
            delete List[i]; //stergem fiecare element
        }
        delete[] List; //stergem lista in sine
    }

    bool operator=(const Array<T>& otherArray) {
        if (this == &otherArray) return true;

        for (int i = 0; i < Size; i++) delete List[i];
        delete[] List;

        Capacity = otherArray.Capacity;
        Size = otherArray.Size;
        List = new T * [Capacity];
        for (int i = 0; i < Size; i++) {
            List[i] = new T(*(otherArray.List[i]));
        }
        return true;
    }

    T& operator[](int index) {
        if (index < 0 || index >= Size) {
            throw IndexOutOfBoundsException();
        }
        return *(List[index]);
    }

    const Array<T>& operator+=(const T& newElem) {
        if (Size == Capacity) {
            resize((Capacity == 0) ? 2 : Capacity * 2);
        }
        List[Size++] = new T(newElem);
        return *this;
    }

    const Array<T>& Insert(int index, const T& newElem) {
        if (index < 0 || index > Size) {
            throw IndexOutOfBoundsException();
        }
        if (Size == Capacity) {
            resize((Capacity == 0) ? 2 : Capacity * 2);
        }
        for (int i = Size; i > index; i--) {
            List[i] = List[i - 1];
        }
        List[index] = new T(newElem);
        Size++;
        return *this;
    }

    const Array<T>& Insert(int index, const Array<T> otherArray) {
        if (index < 0 || index > Size) {
            throw IndexOutOfBoundsException();
        }
        if (Size + otherArray.Size > Capacity) {
            resize(Size + otherArray.Size + 5);
        }
        for (int i = Size - 1; i >= index; i--) {
            List[i + otherArray.Size] = List[i];
        }
        for (int i = 0; i < otherArray.Size; i++) {
            List[index + i] = new T(*(otherArray.List[i]));
        }
        Size += otherArray.Size;
        return *this;
    }

    const Array<T>& Delete(int index) {
        if (index < 0 || index >= Size) {
            throw IndexOutOfBoundsException();
        }
        delete List[index]; 
        for (int i = index; i < Size - 1; i++) {
            List[i] = List[i + 1];
        }
        Size--;
        return *this;
    }

    void Sort() {
        for (int i = 0; i < Size - 1; i++) {
            for (int j = i + 1; j < Size; j++) {
                if (*(List[j]) < *(List[i])) {
                    T* temp = List[i];
                    List[i] = List[j];
                    List[j] = temp;
                }
            }
        }
    }

    void Sort(int(*compare)(const T&, const T&)) {
        for (int i = 0; i < Size - 1; i++) {
            for (int j = i + 1; j < Size; j++) {
                if (compare(*(List[i]), *(List[j])) > 0) {
                    T* temp = List[i];
                    List[i] = List[j];
                    List[j] = temp;
                }
            }
        }
    }

    void Sort(Compare* comparator) {
        for (int i = 0; i < Size - 1; i++) {
            for (int j = i + 1; j < Size; j++) {
                if (comparator->CompareElements(List[i], List[j]) > 0) {
                    T* temp = List[i];
                    List[i] = List[j];
                    List[j] = temp;
                }
            }
        }
    }

    int BinarySearch(const T& elem) {
        int left = 0, right = Size - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (*(List[mid]) == elem) return mid;
            if (*(List[mid]) < elem) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }

    int BinarySearch(const T& elem, int(*compare)(const T&, const T&)) {
        int left = 0, right = Size - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int res = compare(*(List[mid]), elem);
            if (res == 0) return mid;
            if (res < 0) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }

    int BinarySearch(const T& elem, Compare* comparator) {
        T tempElem = elem;
        int left = 0, right = Size - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int res = comparator->CompareElements(List[mid], &tempElem);
            if (res == 0) return mid;
            if (res < 0) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }

    int Find(const T& elem) {
        for (int i = 0; i < Size; i++) {
            if (*(List[i]) == elem) return i;
        }
        return -1;
    }

    int Find(const T& elem, int(*compare)(const T&, const T&)) {
        for (int i = 0; i < Size; i++) {
            if (compare(*(List[i]), elem) == 0) return i;
        }
        return -1;
    }

    int Find(const T& elem, Compare* comparator) {
        T tempElem = elem;
        for (int i = 0; i < Size; i++) {
            if (comparator->CompareElements(List[i], &tempElem) == 0) return i;
        }
        return -1;
    }

    int GetSize() { return Size; }
    int GetCapacity() { return Capacity; }

    ArrayIterator<T> GetBeginIterator() {
        return ArrayIterator<T>(List, 0);
    }

    ArrayIterator<T> GetEndIterator() {
        return ArrayIterator<T>(List, Size);
    }
};

int main() {
    Array<int> arr;

    arr += 10;
    arr += 20;
    arr += 30;

    for (int i = 0; i < arr.GetSize(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "\ntestare exceptii" << endl;
    try {
        cout << "arr[100]" << endl;
        int val = arr[100]; 
    }
    catch (exception& e) { 
        cout << e.what() << endl;
    }

    try {
        cout << "sterg de la -1" << endl;
        arr.Delete(-1); 
    }
    catch (exception& e) {
        cout << e.what() << endl;
    }

    cout << "\ntest iterator" << endl;
    ArrayIterator<int> it = arr.GetBeginIterator();
    ArrayIterator<int> endIt = arr.GetEndIterator();

    while (it != endIt) {
        cout << *(it.GetElement()) << " ";
        ++it;
    }
    cout << endl;

    return 0;
}