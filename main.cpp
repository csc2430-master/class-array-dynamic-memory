#include <iostream>
#include <cassert>

using std::cout;
using std::endl;
using std::ostream;

class Data{
private:
    size_t _size;
    double* _data;
public:
    Data(size_t size);
    Data(const Data& data);
    ~Data();
    const Data& operator=(const Data& rhs);
    void SetValue(size_t index, double value);
    double GetValue(size_t index)const;
    ostream& Write(ostream& output)const;
};

Data::Data(size_t size): _size(size){
    _data = new double[size];
}
Data::Data(const Data& data): _size(data._size){
    _data = new double[_size];
    for (int i = 0; i < _size; ++i) {
        _data[i] = data._data[i];
    }
}
Data::~Data(){
    delete[] _data;
}
const Data& Data::operator=(const Data& rhs){
    delete[] _data;
    _size = rhs._size;
    _data = new double[_size];
    for (int i = 0; i < _size; ++i) {
        _data[i] = rhs._data[i];
    }
    return *this;
}
void Data::SetValue(size_t index, double value){
    assert(index < _size);
    _data[index] = value;
}
double Data::GetValue(size_t index)const{
    assert(index < _size);
    return _data[index];
}
ostream& Data::Write(ostream& output)const{
    for (int i = 0; i < _size; ++i) {
        output << _data[i] << "\t";
    }
    output << endl;
    return output;
}

int main() {
    cout << "First Step: Local Variable" << endl;
    Data step1(4);
    step1.SetValue(0, 3.1);
    step1.SetValue(1, 1.3);
    step1.SetValue(2, 4.8);
    step1.SetValue(3, 0.01);
    step1.Write(cout);

    Data* step2 = new Data(3);
    step2->SetValue(0, 9.9);
    step2->SetValue(1, 1.9);
    step2->SetValue(2, 0.9);
    step2->Write(cout);
    delete step2;

    Data* array[2]; // The array is NOT dynamically array, the elements of the array are
    array[0] = new Data(2);
    array[1] = new Data(3);

    array[0]->SetValue(0, 0);
    array[0]->SetValue(1, 2);

    array[1]->SetValue(0, 3);
    array[1]->SetValue(1, 2);
    array[1]->SetValue(2, 1);

    for (int i = 0; i < 2; ++i) {
        array[i]->Write(cout);
    }

    for (int i = 0; i < 2; ++i) {
        delete array[i];
    }

    Data** array2 = nullptr;

    array2 = new Data*[3];
    array2[0] = new Data(1);
    array2[1] = new Data(3);
    array2[2] = new Data(2);

    array2[0]->SetValue(0, 0);

    array2[1]->SetValue(0, 10);
    array2[1]->SetValue(1, 20);
    array2[1]->SetValue(2, 30);

    array2[2]->SetValue(0, 4);
    array2[2]->SetValue(1, -4);

    for (int i = 0; i < 3; ++i) {
        array2[i]->Write(cout);
    }

    for (int i = 0; i < 3; ++i) {
        delete array2[i];
    }
    delete[] array2;

    Data* step3 = &step1;

    return 0;
}
