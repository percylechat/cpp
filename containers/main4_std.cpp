#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <stack>
#include <cstring>

void go_size(std::vector<int> a){
	// test size, empty, cap et max_size
	std::cout << "\tSIZE" << std::endl;
	std::cout << "size: " << a.size() << std::endl;
	std::cout << "is empty: " << a.empty() << std::endl;
	std::cout << "capacity: " << a.capacity() << std::endl;
	std::cout << "max_size: " << a.max_size() << std::endl;
}

void go_vector(void){
	std::cout << "\t\tINSERT" << std::endl;
	// push_back et crea vecteur vide
	std::vector<int> vector_int;
	go_size(vector_int);
	vector_int.push_back(42);
	vector_int.push_back(2);
	vector_int.push_back(4);
	vector_int.push_back(99);
	// insert avec pos + valeur
	vector_int.insert((vector_int.begin() + 2), 150);
	// insert avec pos + count + valeur
	vector_int.insert(vector_int.begin(), 3, 193);
	// crea vecteur plein
	std::vector<int> vector_int_bis(4, 177);
	// insert de vecteur a pos
	vector_int.insert(vector_int.begin(), vector_int_bis.begin(), vector_int_bis.end());
	// test crea iterateurs + circulation
	std::vector<int>::iterator a = vector_int.begin();
	std::vector<int>::iterator b = vector_int.end();
	while (a != b){
		std::cout << *a << std::endl;
		a++;
	}
	go_size(vector_int);

	std::cout << "\t\tRESERVE & RESIZE" << std::endl;
	// test reserve
	// normal que plus grand, choix poir optimiser gestion de memoire.
	vector_int.reserve(50);
	go_size(vector_int);
	// test resize
	// plus grand que size actuel
	vector_int.resize(15, 999);
	go_size(vector_int);
	a = vector_int.begin();
	b = vector_int.end();
	while (a != b){
		std::cout << *a << std::endl;
		a++;
	}
	// plus petit que size actuel
	vector_int.resize(10);
	go_size(vector_int);
	a = vector_int.begin();
	b = vector_int.end();
	while (a != b){
		std::cout << *a << std::endl;
		a++;
	}

	std::cout << "\t\tACCESS" << std::endl;
	// test front
	std::cout << vector_int.front() << std::endl;
	// test back
	std::cout << vector_int.back() << std::endl;
	// test []
	std::cout << vector_int[8] << std::endl;
	// test at
	std::cout << vector_int.at(7) << std::endl;

	std::cout << "\t\tSWAP & ASSIGN" << std::endl;
	// test swap
	vector_int.swap(vector_int_bis);
	a = vector_int.begin();
	b = vector_int.end();
	while (a != b){
		std::cout << *a << std::endl;
		a++;
	}
	go_size(vector_int);
	a = vector_int_bis.begin();
	b = vector_int_bis.end();
	while (a != b){
		std::cout << *a << std::endl;
		a++;
	}
	go_size(vector_int_bis);
	// test assign par vecteur
	vector_int.assign(vector_int_bis.begin(), vector_int_bis.end());
	a = vector_int.begin();
	b = vector_int.end();
	while (a != b){
		std::cout << *a << std::endl;
		a++;
	}
	std::cout << std::endl;
	// test assign avec size et content
	vector_int_bis.assign(7, 300);
	a = vector_int_bis.begin();
	b = vector_int_bis.end();
	while (a != b){
		std::cout << *a << std::endl;
		a++;
	}

	std::cout << "\t\tERASE & POP BACK" << std::endl;
	// test pop_back
	vector_int.pop_back();
	a = vector_int.begin();
	b = vector_int.end();
	while (a != b){
		std::cout << *a << std::endl;
		a++;
	}
	std::cout << std::endl;
	// test erase avec un iterateur de pos
	vector_int.erase(vector_int.begin());
	a = vector_int.begin();
	b = vector_int.end();
	while (a != b){
		std::cout << *a << std::endl;
		a++;
	}
	std::cout << std::endl;
	// test avec un range d iterateurs
	vector_int.erase(vector_int.begin() + 2, vector_int.begin() + 5);
	a = vector_int.begin();
	b = vector_int.end();
	while (a != b){
		std::cout << *a << std::endl;
		a++;
	}

	std::cout << "\t\tCLEAR" << std::endl;
	go_size(vector_int_bis);
	vector_int_bis.clear();
	go_size(vector_int_bis);

	std::cout << "\t\tCONSTR" << std::endl;
	// test constr copie
	std::vector<int> vector_int_tre(vector_int);
	a = vector_int_tre.begin();
	b = vector_int_tre.end();
	while (a != b){
		std::cout << *a << std::endl;
		a++;
	}
	std::cout << std::endl;
	// test const iterateurs
	std::vector<int>vector_int_quat(vector_int.begin(), vector_int.end());
	a = vector_int_quat.begin();
	b = vector_int_quat.end();
	while (a != b){
		std::cout << *a << std::endl;
		a++;
	}

	std::cout << "\t\tCOMP" << std::endl;
	vector_int_tre.push_back(66);
	vector_int_quat.pop_back();
	std::cout << (vector_int > vector_int_quat) << std::endl;
	std::cout << (vector_int < vector_int_tre) << std::endl;
	std::cout << (vector_int == vector_int_quat) << std::endl;
	std::cout << (vector_int >= vector_int_quat) << std::endl;
	std::cout << (vector_int <= vector_int_tre) << std::endl;
	std::cout << (vector_int != vector_int_quat) << std::endl;

	std::cout << "\t\tREVERSE ITERATOR" << std::endl;
	std::vector<int>::reverse_iterator it = vector_int.rbegin();
	std::vector<int>::reverse_iterator itt = vector_int.rend();
	while (it != itt){
		std::cout << *it << std::endl;
		it++;
	}
}

void go_stack(void){
std::cout << "\t\tSTACK" << std::endl;
// pop, top et push
	std::stack<int> mystack;
	for (int i=0; i<5; ++i) mystack.push(i);
	std::cout << "Popping out elements...";
	while (!mystack.empty()){
		std::cout << ' ' << mystack.top() << mystack.size() << std::endl;
		mystack.pop();
	}
	std::cout << '\n';
}

void go_map(void){
	std::cout << "\t\tINSERT" << std::endl;
	//crea map vide
	std::map<int, std::string> map1;
	std::map<int, std::string> map2;
	// test size, empty, max_size
	std::cout << "\tSIZE" << std::endl;
	std::cout << "size: " << map1.size() << std::endl;
	std::cout << "is empty: " << map1.empty() << std::endl;
	std::cout << "max_size: " << map1.max_size() << std::endl;
	// insert valeur
	map1.insert(std::pair<int, std::string>(43, "hello"));
	map1.insert(std::pair<int, std::string>(12, "bebe"));
	map1.insert(std::pair<int, std::string>(25, "chat"));
	// insert valeur + iterateur suggere
	map1.insert(map1.begin(), std::pair<int, std::string>(55, "Percy"));
	map1.insert(std::pair<int, std::string>(43, "lol"));
	// insert avec ope
	map1[58]="kikou";

	map2.insert(std::pair<int, std::string>(44, "new"));
	map2.insert(std::pair<int, std::string>(99, "map"));
	// insert avec iterateurs
	std::map<int, std::string>::iterator a = map1.begin();
	std::map<int, std::string>::iterator b = map1.end();
	while (a != b){
		std::cout << a->first << " " << a->second << std::endl;
		a++;
	}
	std::cout << "\tSIZE" << std::endl;
	std::cout << "size: " << map1.size() << std::endl;
	std::cout << "is empty: " << map1.empty() << std::endl;
	std::cout << "max_size: " << map1.max_size() << std::endl;
	map1.insert(map2.begin(), map2.end());
	std::cout << std::endl;
	a = map1.begin();
	b = map1.end();
	while (a != b){
		std::cout << a->first << " " << a->second << std::endl;
		a++;
	}
	std::cout << "\tSIZE" << std::endl;
	std::cout << "size: " << map1.size() << std::endl;
	std::cout << "is empty: " << map1.empty() << std::endl;
	std::cout << "max_size: " << map1.max_size() << std::endl;

	//k;,jjjjjjjjjjjjjj << un message de mon chat

	std::cout << "\t\tFIND & COUNT" << std::endl;
	// test value in map
	std::map<int, std::string>::iterator ret = map1.find(55);
	std::cout << ret->first << " " << ret->second << std::endl;
	// test value not in map
	ret = map1.find(150);
	// CHANGE with ft version because printing end iterator returns random stuff
	if (ret == map1.end())
		std::cout << "Returned end iterator" << std::endl;
	else
		std::cout << ret->first << " " << ret->second << std::endl;
	// test count with value in map
	std::cout << map1.count(55) << std::endl;
	// test count with value not in map
	std::cout << map1.count(150) << std::endl;

	std::cout << "\t\tBOUNDS" << std::endl;
	// check http://www.cplusplus.com/reference/map/map/upper_bound/
	std::map<char,int> mymap;
	std::map<char,int>::iterator itlow,itup;
	mymap['a']=20;
	mymap['b']=40;
	mymap['c']=60;
	mymap['d']=80;
	mymap['e']=100;
	itlow=mymap.lower_bound ('b');  // itlow points to b
	itup=mymap.upper_bound ('d');   // itup points to e (not d!)
	mymap.erase(itlow,itup);        // erases [itlow,itup)
	for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
	std::cout << it->first << " => " << it->second << '\n';

	std::cout << "\t\tCLEAR\n" << std::endl;
	std::cout << "\tSIZE" << std::endl;
	std::cout << "size: " << mymap.size() << std::endl;
	std::cout << "is empty: " << mymap.empty() << std::endl;
	std::cout << "max_size: " << mymap.max_size() << std::endl;
	mymap.clear();
	std::cout << "\tSIZE" << std::endl;
	std::cout << "size: " << mymap.size() << std::endl;
	std::cout << "is empty: " << mymap.empty() << std::endl;
	std::cout << "max_size: " << mymap.max_size() << std::endl;

	std::cout << "\t\tERASE" << std::endl;
	std::cout << "\tSIZE" << std::endl;
	std::cout << "size: " << map1.size() << std::endl;
	std::cout << "is empty: " << map1.empty() << std::endl;
	std::cout << "max_size: " << map1.max_size() << std::endl;
	std::cout << std::endl;
	a = map1.begin();
	b = map1.end();
	while (a != b){
		std::cout << a->first << " " << a->second << std::endl;
		a++;
	}
	// test erase value
	map1.erase(44);
	std::cout << "\tSIZE" << std::endl;
	std::cout << "size: " << map1.size() << std::endl;
	std::cout << "is empty: " << map1.empty() << std::endl;
	std::cout << "max_size: " << map1.max_size() << std::endl;
	std::cout << std::endl;
	a = map1.begin();
	b = map1.end();
	while (a != b){
		std::cout << a->first << " " << a->second << std::endl;
		a++;
	}
	a = map1.begin();
	a++;
	// test erase position
	map1.erase(a);
	std::cout << "\tSIZE" << std::endl;
	std::cout << "size: " << map1.size() << std::endl;
	std::cout << "is empty: " << map1.empty() << std::endl;
	std::cout << "max_size: " << map1.max_size() << std::endl;
	std::cout << std::endl;
	a = map1.begin();
	b = map1.end();
	while (a != b){
		std::cout << a->first << " " << a->second << std::endl;
		a++;
	}
	std::cout << std::endl;
	// test erase range
	a = map1.begin();
	a++;
	b = a;
	b++;
	b++;
	map1.erase(a, b);
	a = map1.begin();
	b = map1.end();
	while (a != b){
		std::cout << a->first << " " << a->second << std::endl;
		a++;
	}
	std::cout << "\tSIZE" << std::endl;
	std::cout << "size: " << map1.size() << std::endl;
	std::cout << "is empty: " << map1.empty() << std::endl;
	std::cout << "max_size: " << map1.max_size() << std::endl;
	std::cout << std::endl;

	std::cout << "\t\tSWAP" << std::endl;
	// test swap
	map1.swap(map2);
	a = map1.begin();
	b = map1.end();
	while (a != b){
		std::cout << a->first << " " << a->second << std::endl;
		a++;
	}
	std::cout << "\tSIZE" << std::endl;
	std::cout << "size: " << map1.size() << std::endl;
	std::cout << "is empty: " << map1.empty() << std::endl;
	std::cout << "max_size: " << map1.max_size() << std::endl;
	std::cout << std::endl;
	a = map2.begin();
	b = map2.end();
	while (a != b){
		std::cout << a->first << " " << a->second << std::endl;
		a++;
	}
	std::cout << "\tSIZE" << std::endl;
	std::cout << "size: " << map2.size() << std::endl;
	std::cout << "is empty: " << map2.empty() << std::endl;
	std::cout << "max_size: " << map2.max_size() << std::endl;
	std::cout << std::endl;

	std::cout << "\t\tREVERSE ITERATOR" << std::endl;
	std::map<int, std::string>::reverse_iterator it(map2.rbegin());
	std::map<int, std::string>::reverse_iterator itt(map2.rend());
	while (it != itt){
		std::cout << it->first << std::endl;
		it++;
	}
}

int main(int argc, char *argv[]){
	if (argc != 2){
		std::cout << "USE: ./container container_to_test" << std::endl;
		return 0;
	}
	if (!strcmp(argv[1], "stack"))
		go_stack();
	else if (!strcmp(argv[1], "map"))
		go_map();
	else if (!strcmp(argv[1], "vector"))
		go_vector();
	else
		std::cout << "USE: ./container container_to_test" << std::endl;
	return 1;
}