#include <iostream>
template <typename K, typename V>
class Map {
private:
    struct Element {
        K key;
        V value;
    };

    Element* data;
    int count;
    int capacity;

    void resize() { //pt cand ramanem fara loc 
        capacity = (capacity == 0) ? 2 : capacity * 2;
        Element* newData = new Element[capacity];
        for (int i = 0; i < count; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }

public:
    Map() {
        count = 0;
        capacity = 0;
        data = nullptr;
    }

    ~Map() {
        delete[] data;
    }

    V& operator[](const K& key) { //cauta o cheie, daca nu o gaseste, o creeaza
        for (int i = 0; i < count; i++) { //verifica daca e deja cheia 
            if (data[i].key == key) {
                return data[i].value;
            }
        }
        if (count == capacity) { //daca nu mai e loc, mai face
            resize();
        }
        data[count].key = key; //adauga cheia la final
        return data[count++].value;
    }

    void Set(const K& key, const V& value) {
        (*this)[key] = value; 
    }

    bool Get(const K& key, V& value) const {
        for (int i = 0; i < count; i++) {
            if (data[i].key == key) {
                value = data[i].value;
                return true;
            }
        }
        return false;
    }

    int Count() const {
        return count;
    }

    void Clear() {
        count = 0; //se comporta de parca vectorul e gol, desi nu e; suprascrie datele
    }

    bool Delete(const K& key) {
        for (int i = 0; i < count; i++) {
            if (data[i].key == key) {
                for (int j = i; j < count - 1; j++) {
                    data[j] = data[j + 1];
                }
                count--;
                return true;
            }
        }
        return false;
    }

    bool Includes(const Map<K, V>& other) const {
        for (int i = 0; i < other.count; i++) {
            bool found = false;
            for (int j = 0; j < this->count; j++) {
                if (this->data[j].key == other.data[i].key) { //daca gaseste o cheie din other care nu e in this se opreste
                    found = true;
                    break;
                }
            }
            if (!found) {
                return false; 
            }
        }
        return true;
    }

    struct ElementView {
        K key;
        V value;
        int index;
    };

    class Iterator {
    private:
        Element* ptr;
        int index;
    public:
        Iterator(Element* p, int idx) : ptr(p), index(idx) {}

        bool operator!=(const Iterator& other) const { //ca sa stie cand sa se opreasca
            return ptr != other.ptr;
        }

        Iterator& operator++() { //urm element
            ptr++;
            index++;
            return *this;
        }

        ElementView operator*() const { //sa citeasca datele
            return { ptr->key, ptr->value, index };
        }
    };

    Iterator begin() {
        return Iterator(data, 0);
    }

    Iterator end() {
        return Iterator(data + count, count);
    }
};

int main() {
    Map<int, const char*> m; //se apeleaza constructorul
    m[10] = "C++"; 
    m[20] = "test";
    m[30] = "Poo";

    for (auto [key, value, index] : m) { //structured binding
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    m[20] = "result";

    for (auto [key, value, index] : m) {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    return 0;
}