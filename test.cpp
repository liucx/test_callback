#include <stdio.h>
#include <vector>


class A{
public:
    A(){};
    ~A(){};

    void push_element(int n) {
        _odd_num.push_back(n);
    };
    
    int get_size() {
        return static_cast<int>(_odd_num.size());
    };

    int at(int index) {
        return _odd_num[index];
    }

    void clear() {
        _odd_num.clear();
    };

private:
	std::vector<int> _odd_num;
};

typedef void (*call_back)(int n, void* args);

void get_odd_number(int n, void* args)
{
    A* inst = static_cast<A*>(args);
    if (n % 2 == 1) {
        inst->push_element(n);
    }
}

void get_even_number(int n, void* args)
{
    A* inst = static_cast<A*>(args);
    if (n % 2 == 0) {
        inst->push_element(n);
    }
}

void select_num(int range, call_back fun, void* args)
{
	for (int i = 0; i < range; ++i) {
        fun(i, args);
	}
}


int main(int argc, char* argv[]) {
    A inst_a;
    select_num(10, get_odd_number, &inst_a);

    for(int i = 0; i < inst_a.get_size(); ++i) {
        printf("%d \t", inst_a.at(i));
    }
    printf("Get odd number done \n");

    inst_a.clear();
    select_num(10, get_even_number, &inst_a);
    for(int i = 0; i < inst_a.get_size(); ++i) {
        printf("%d \t", inst_a.at(i));
    }
    printf("Get even number done \n");

}