#include <memory>

template <typename TAttach, typename TValue, class... _Types>
class attach_ptr;

template <typename TAttach, class... _Types>
attach_ptr<TAttach, TAttach> make_attach(_Types&&... _Args);


template <typename TAttach, typename TValue,class... _Types>
class attach_ptr {
	//friend attach_ptr make_attach<TAttach>();
	template <typename TAttach, class... _Types>
	friend attach_ptr make_attach<TAttach>(_Types&&... _Args);
private:
	TValue* value;
public:
	std::shared_ptr<TAttach> attach;
	//TValue* value;
	attach_ptr() {}

	attach_ptr(std::shared_ptr<TAttach> _attach, TValue* _value) {
		attach = _attach;
		value = _value;
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
	attach_ptr<TAttach, TAttach> r;
	auto t = std::make_shared<TAttach>(_STD forward<_Types>(_Args)...);
	r.attach = t;
	r.value = t.get();
	return r;
}

//template <typename TAttach>
//attach_ptr<TAttach, TAttach> make_attach() {
//	attach_ptr<TAttach, TAttach> r;
//	auto t = std::make_shared<TAttach>();
//	r.attach = t;
//	r.value = t.get();
//	return r;
//}