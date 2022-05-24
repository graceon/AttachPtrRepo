#include <memory>

template <typename TAttach, typename TValue>
class attach_ptr;

template <typename TAttach, class... _Types>
attach_ptr<TAttach, TAttach> make_attach(_Types&&... _Args);

template <typename TAttach, typename TValue>
class attach_ptr {
private:
	std::shared_ptr<TAttach> attach;
	TValue* value;
	template <typename TAttach, class... _Types>
	friend attach_ptr<TAttach, TAttach> make_attach<TAttach>(_Types&&... _Args);
public:

	attach_ptr() {
		attach = nullptr;
		value = nullptr;
	}
	attach_ptr(std::shared_ptr<TAttach> _attach, TValue* _value) {
		attach = _attach;
		value = _value;
	}
	inline std::shared_ptr<TAttach> get_attach() const {
		return attach;
	}
	inline TValue* get_value() const {
		return value;
	}
	inline long use_count() const {
		return attach.use_count();
	}

	//attach_ptr<Cake, int> cake_attach;
	//attach_ptr<void, int> void_attach;
	//void_attach = cake_attach;
	template <class Eliminate, class TValue_Right>
	attach_ptr& operator=(const attach_ptr<Eliminate, TValue_Right>& _Right) noexcept {
		attach = _Right.get_attach();
		value = _Right.get_value();
		return *this;
	}
	//int func(attach_ptr<void, int> x);
	//attach_ptr<Cake, int> cake_attach;
	//func(cake_attach);
	template <class Eliminate, class TValue_Right>
	attach_ptr(const attach_ptr<Eliminate, TValue_Right>& _Right) noexcept {
		attach = _Right.get_attach();
		value = _Right.get_value();
	}
	//only for decltype
	inline TAttach __get_attach_type() {
		return *attach;
	}
	inline TValue& operator*() {
		return *get();
	}
	inline TValue* operator->() {
		return get();
	}
	inline TValue* get() {
		return value;
	}

};

template <typename TAttach, class... _Types>
attach_ptr<TAttach, TAttach> make_attach(_Types&&... _Args) {
	auto t = std::make_shared<TAttach>(_STD forward<_Types>(_Args)...);
	attach_ptr<TAttach, TAttach> r(t, t.get());
	return r;
}

#define make_attach_member(__attach_ptr,_member) attach_ptr<decltype(__attach_ptr.__get_attach_type()), decltype(__attach_ptr->_member)>(__attach_ptr.get_attach(), &(__attach_ptr->_member));





//template <typename TValue>
//class value_ptr {
//protected:
//	std::shared_ptr<void> attach;
//	TValue* value;
//public:
//
//	value_ptr(std::shared_ptr<void> _attach,TValue* _value){
//		attach = _attach;
//		value = _value;
//	}
//
//	
//};
//template <typename TValue>
//class value_ptr;
