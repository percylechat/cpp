#include <iostream>
#include <string>
#include "map.hpp"
#include "vector.hpp"
#include "stack.hpp"
#include <cstring>

void go_stack_100(void){
    ft::stack<int> mystack;
    int i = 0;
    while (i < 100){
        mystack.push(i);
        i++;
    }
    while (mystack.empty() != 0)
        mystack.pop();
}

void go_stack_1000(void){
    ft::stack<int> mystack;
    int i = 0;
    while (i < 1000){
        mystack.push(i);
        i++;
    }
    while (mystack.empty() != 0)
        mystack.pop();
}

void go_stack_10000(void){
    ft::stack<int> mystack;
    int i = 0;
    while (i < 10000){
        mystack.push(i);
        i++;
    }
    while (mystack.empty() != 0)
        mystack.pop();
}

void go_vector_100(void){
    ft::vector<int> myvec;
    int i = 0;
    while (i < 100){
        myvec.push_back(i);
        i++;
    }
    while (myvec.empty() != 0)
        myvec.pop_back();
}

void go_vector_1000(void){
    ft::vector<int> myvec;
    int i = 0;
    while (i < 1000){
        myvec.push_back(i);
        i++;
    }
    while (myvec.empty() != 0)
        myvec.pop_back();
}

void go_vector_10000(void){
    ft::vector<int> myvec;
    int i = 0;
    while (i < 10000){
        myvec.push_back(i);
        i++;
    }
    while (myvec.empty() != 0)
        myvec.pop_back();
}

void go_map_100(void){
    ft::map<int, int> mymap;
    int i = 0;
    while (i < 100){
        mymap.insert(ft::pair<int, int>(i, i));
        i++;
    }
    i = 0;
    while (mymap.empty() != 0){
        mymap.erase(i);
        i++;
    }
}

void go_map_1000(void){
    ft::map<int, int> mymap;
    int i = 0;
    while (i < 1000){
        mymap.insert(ft::pair<int, int>(i, i));
        i++;
    }
    i = 0;
    while (mymap.empty() != 0){
        mymap.erase(i);
        i++;
    }
}

void go_map_10000(void){
    ft::map<int, int> mymap;
    int i = 0;
    while (i < 10000){
        mymap.insert(ft::pair<int, int>(i, i));
        i++;
    }
    i = 0;
    while (mymap.empty() != 0){
        mymap.erase(i);
        i++;
    }
}

int main(int argc, char *argv[]){
	if (argc != 3){
		std::cout << "USE: ./perf container_to_test size_to_test(100/1000/10000)" << std::endl;
		return 0;
	}
	if (!strcmp(argv[1], "stack")){
        if (!strcmp(argv[2], "100"))
		    go_stack_100();
        else if (!strcmp(argv[2], "1000"))
		    go_stack_1000();
        else if (!strcmp(argv[2], "10000"))
		    go_stack_10000();
        else
            std::cout << "USE: ./container container_to_test" << std::endl;
    }
	else if (!strcmp(argv[1], "map")){
        if (!strcmp(argv[2], "100"))
		    go_map_100();
        else if (!strcmp(argv[2], "1000"))
		    go_map_1000();
        else if (!strcmp(argv[2], "10000"))
		    go_map_10000();
        else
            std::cout << "USE: ./container container_to_test" << std::endl;
    }
	else if (!strcmp(argv[1], "vector")){
        if (!strcmp(argv[2], "100"))
		    go_vector_100();
        else if (!strcmp(argv[2], "1000"))
		    go_vector_1000();
        else if (!strcmp(argv[2], "10000"))
		    go_vector_10000();
        else
            std::cout << "USE: ./container container_to_test" << std::endl;
    }
	else
		std::cout << "USE: ./container container_to_test" << std::endl;
	return 1;
}