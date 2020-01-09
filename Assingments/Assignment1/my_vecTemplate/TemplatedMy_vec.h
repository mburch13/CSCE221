/*My_vec.h
McKenzie Burch
Header file for a vector data structure.
*/

#include <ostream>

using namespace std;

template<class T>
class TemplatedMy_vec{

	//member variables
    int size, capacity;
	T* ptr;
	
public:	
	//member functions
    TemplatedMy_vec(){size = 0; capacity = 10; ptr = new T[capacity];}   //constructor
    ~TemplatedMy_vec(){delete [] ptr;}  //destructor
	TemplatedMy_vec(const TemplatedMy_vec& vec);  //copy constructor
	TemplatedMy_vec& operator=(const TemplatedMy_vec& vec);
	int get_size() const;
	int get_capacity() const;
	T& operator[](int i) const;
	T& operator[](int i);
	bool is_empty() const;
	T& elem_at_rank(int r) const;
	void insert_at_rank(int r, const T& elem);
	void replace_at_rank(int r, const T& elem);
	void remove_at_rank(int r);
	
};

//    ostream& operator<<(ostream& out, const TemplatedMy_vec<T>& vec);
//    int find_max_index(const TemplatedMy_vec<T>& v,int size);
//    void sort_max(TemplatedMy_vec<T>& vec);


//copy constructor
template<class T>
TemplatedMy_vec<T>::TemplatedMy_vec(const TemplatedMy_vec<T>& vec){
    size = vec.size;
    capacity = vec.capacity;
    ptr = new T[capacity];
    for (int i = 0; i < size; i++)
    {
        ptr[i] = vec.ptr[i];
    }
}

template<class T>
TemplatedMy_vec<T>& TemplatedMy_vec<T>::operator=(const TemplatedMy_vec<T>& vec){
    if (this != &vec){
        delete [] ptr;
        size = vec.size;
        capacity = vec.capacity;
        ptr = new T[capacity];
        for(int i = 0; i < size; i++){
            ptr[i] = vec.ptr[i];
        }
    }
    return *this;
}

template<class T>
int TemplatedMy_vec<T>::get_size() const{
    return size;
}

template<class T>
int TemplatedMy_vec<T>::get_capacity() const{
    return capacity;
}

template<class T>
T& TemplatedMy_vec<T>::operator[](int i) const{
    return ptr[i];
}

template<class T>
T& TemplatedMy_vec<T>::operator[](int i){
    return ptr[i];
}

template<class T>
bool TemplatedMy_vec<T>::is_empty() const{
    if(ptr == nullptr && size == 0 && capacity == 0){
        return true;
    }
    else{
        return false;
    }
}

template<class T>
T& TemplatedMy_vec<T>::elem_at_rank(int r) const{
    return ptr[r];
}

template<class T>
void TemplatedMy_vec<T>::insert_at_rank(int r, const T& elem){
    T temp;
    if(size == capacity){
        TemplatedMy_vec vec;
        size = vec.size+1;
        capacity = vec.capacity * 2;
        ptr = new T[capacity];
        for (int i = 0; i < size; i++){
            ptr[i] = vec.ptr[i];
            if(ptr[i] == ptr[r]){
                temp = ptr[i];
                ptr[i] = elem;
                ptr[i+1] = temp;
            }
        }
    }
    else{
        size += 1;
        for (int i = 0; i < size; i++){
            if(ptr[i] == NULL){
                ptr[i] = elem;
            }
            if(ptr[i] == ptr[r]){
                temp = ptr[i];
                ptr[i] = elem;
                ptr[i+1] = temp;
            }
        }
    }
}

template<class T>
void TemplatedMy_vec<T>::replace_at_rank(int r, const T& elem){
    for(int i = 0; i < size; i++){
        if(ptr[i] == ptr[r]){
            ptr[i] = elem;
        }
    }
}

template<class T>
void TemplatedMy_vec<T>::remove_at_rank(int r){
    for(int i = 0; i < size; i++){
        if(ptr[i] == ptr[r]){
            ptr[i] = ptr[i+1];
        }
    }
}

template<typename T>
ostream& operator<<(ostream& out, const TemplatedMy_vec<T>& vec){
    for(int i = 0; i<vec.get_size(); i++){
        out << vec.elem_at_rank(i) << " ";
    }
    return out;
}

template<typename T>
int find_max_index(const TemplatedMy_vec<T>& v,int size){
    int max = 0;
    size = v.get_size();
    for(int i = 0; i < size; i++){
        if(v.elem_at_rank(i+1)<v.elem_at_rank(i)){
            max = i;
        }
    }
    return max;
}

template<typename T>
void sort_max(TemplatedMy_vec<T>& vec)
{
    int size = vec.get_size();
    int indexTemp = find_max_index(vec, size);
    T temp;
    
    if(size%2 == 0){
        while(indexTemp > indexTemp%2){
            for(int i = 0; i < indexTemp; i++){
                temp = vec[indexTemp];
                vec[indexTemp] = vec[i];
                vec[i] = temp;
                --indexTemp;
            }
        }
    }
    else{
        while(indexTemp > indexTemp%3){
            for(int i = 0; i < indexTemp; i++){
                temp = vec[indexTemp];
                vec[indexTemp] = vec[i];
                vec[i] = temp;
                --indexTemp;
            }
        }
    }
}

