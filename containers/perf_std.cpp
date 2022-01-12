#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <stack>
#include <cstring>

void go_stack_10(void){
    std::stack<int> mystack;
    int i = 0;
    while (i < 10){
        mystack.push(i);
        i++;
    }
    while (mystack.empty() != 0)
        mystack.pop();
}

void go_stack_100(void){
    std::stack<int> mystack;
    int i = 0;
    while (i < 100){
        mystack.push(i);
        i++;
    }
    while (mystack.empty() != 0)
        mystack.pop();
}

void go_stack_1000(void){
    std::stack<int> mystack;
    int i = 0;
    while (i < 1000){
        mystack.push(i);
        i++;
    }
    while (mystack.empty() != 0)
        mystack.pop();
}

void go_vector_10(void){
    std::vector<int> myvec;
    int i = 0;
    while (i < 10){
        myvec.push_back(i);
        i++;
    }
    while (myvec.empty() != 0)
        myvec.pop_back();
}

void go_vector_100(void){
    std::vector<int> myvec;
    int i = 0;
    while (i < 100){
        myvec.push_back(i);
        i++;
    }
    while (myvec.empty() != 0)
        myvec.pop_back();
}

void go_vector_1000(void){
    std::vector<int> myvec;
    int i = 0;
    while (i < 1000){
        myvec.push_back(i);
        i++;
    }
    while (myvec.empty() != 0)
        myvec.pop_back();
}

void go_map_10(void){
    std::map<int, int> mymap;
    int i = 0;
    while (i < 10){
        mymap.insert(std::pair<int, int>(i, i));
        i++;
    }
    i = 0;
    while (mymap.empty() != 0){
        mymap.erase(i);
        i++;
    }
}

void go_map_100(void){
    std::map<int, int> mymap;
    int i = 0;
    while (i < 100){
        mymap.insert(std::pair<int, int>(i, i));
        i++;
    }
    i = 0;
    while (mymap.empty() != 0){
        mymap.erase(i);
        i++;
    }
}

void go_map_1000(void){
    std::map<int, int> mymap;
    int i = 0;
    while (i < 1000){
        mymap.insert(std::pair<int, int>(i, i));
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
		std::cout << "USE: ./perf container_to_test size_to_test(10/100/1000)" << std::endl;
		return 0;
	}
	if (!strcmp(argv[1], "stack")){
        if (!strcmp(argv[2], "10"))
		    go_stack_10();
        else if (!strcmp(argv[2], "100"))
		    go_stack_100();
        else if (!strcmp(argv[2], "1000"))
		    go_stack_1000();
        else
            std::cout << "USE: ./perf container_to_test size_to_test(10/100/1000)" << std::endl;
    }
	else if (!strcmp(argv[1], "map")){
        if (!strcmp(argv[2], "10"))
		    go_map_10();
        else if (!strcmp(argv[2], "100"))
		    go_map_100();
        else if (!strcmp(argv[2], "1000"))
		    go_map_1000();
        else
            std::cout << "USE: ./perf container_to_test size_to_test(10/100/1000)" << std::endl;
    }
	else if (!strcmp(argv[1], "vector")){
        if (!strcmp(argv[2], "10"))
		    go_vector_10();
        else if (!strcmp(argv[2], "100"))
		    go_vector_100();
        else if (!strcmp(argv[2], "1000"))
		    go_vector_1000();
        else
            std::cout << "USE: ./perf container_to_test size_to_test(10/100/1000)" << std::endl;
    }
	else
		std::cout << "USE: ./perf container_to_test size_to_test(10/100/1000)" << std::endl;
	return 1;
}