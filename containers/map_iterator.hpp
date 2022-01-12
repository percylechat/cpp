#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP

namespace ft {

template<typename T, typename n>
class map_iterator{
	public:
		typedef T value_type;
		typedef std::ptrdiff_t difference_type;
		typedef T* pointer;
		typedef T& reference;
	protected:
		n _ite;
	public:
		map_iterator(){
			this->_ite = NULL;
		}
		map_iterator(n p){
			this->_ite = p;
		}
		map_iterator(map_iterator const & one){
			this->_ite = one._ite;
		}
		map_iterator& operator=(map_iterator const & one) {
			this->_ite = one._ite;
			return *this;
		}
		~map_iterator() {}
		operator map_iterator<value_type const, n>() const {
			return map_iterator<value_type const, n>(this->_ite);
		}
		reference operator*() const{
			return this->_ite->_content;
		}
		pointer operator->() const{
			return &(operator*());
		}
		map_iterator &operator++(){
			n current = this->_ite;
			if (current->r_child != NULL){
				current = current->r_child;
				while (current->l_child != NULL)
					current = current->l_child;
				this->_ite = current;
			}
			else{
				n temp = current;
				current = current->mom;
				while (current->l_child != temp){
					temp = current;
					current = current->mom;
				}
				this->_ite = current;
			}
			return *this;
		}
		map_iterator operator++(int){
			n temp = this->_ite;
			n current = this->_ite;
			if (current->r_child != NULL){
				current = current->r_child;
				while (current->l_child != NULL)
					current = current->l_child;
				this->_ite = current;
			}
			else{
				n temp1 = current;
				current = current->mom;
				while (current->l_child != temp1){
					temp1 = current;
					current = current->mom;
				}
				this->_ite = current;
			}
			return temp;
		}
		map_iterator &operator--(){
			n current = this->_ite;
			if (current->l_child != NULL){
				current = current->l_child;
				while (current->r_child != NULL)
					current = current->r_child;
				this->_ite = current;
			}
			else{
				current = current->mom;
				this->_ite = current;
			}
			return *this;
		}
		map_iterator operator--(int){
			n temp = this->_ite;
			n current = this->_ite;
			if (current->l_child != NULL){
				current = current->l_child;
				while (current->r_child != NULL)
					current = current->r_child;
				this->_ite = current;
			}
			else{
				current = current->mom;
				this->_ite = current;
			}
			return temp;
		}
		bool operator!=(const map_iterator bis) const{
			if (this->_ite != bis._ite)
				return true;
			return false;
		}
		bool operator==(const map_iterator bis) const{
			if (this->_ite == bis._ite)
				return true;
			return false;
		}
};

template<typename it1, typename it2>
bool operator==(const map_iterator<it1, it2>& one, const map_iterator<it1, it2>& two) {
	return one->_content == two->_content();
}
template<typename it1, typename it2>
bool operator!=(const map_iterator<it1, it2>& one, const map_iterator<it1, it2>& two) {
	return one->_content() != two->_content();
}

};
#endif