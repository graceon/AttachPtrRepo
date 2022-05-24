#include<AttachPtr.hpp>
#include"Cake.hpp"

#include<iostream>
#include<vector>

#define LINE_DEUBG std::cout << std::endl << __FILE__ << " " << __LINE__ << ":"

int func(attach_ptr<void, int> x) {
    return 0;
}

int main(void){
    {
        std::shared_ptr<int> s_int;
        std::shared_ptr<void> s_void;
        //s_int = s_void;
        //VS Error	C2440	'<function-style-cast>': cannot convert from 'const std::shared_ptr<TAttach>' to 'std::shared_ptr<int>'	AttachPtrTest	C : \Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.31.31103\include\memory	1624
        //accuratly:'const std::shared_ptr<void>' to 'std::shared_ptr<int>'
    }
    attach_ptr<Cake, int> cake_attach;
    attach_ptr<AppleCake, int> appleCake_attach;
    attach_ptr<void, int> void_attach;
    cake_attach = appleCake_attach;
    void_attach = cake_attach;
    func(cake_attach);

    attach_ptr<Cake, int> s1_x;
    attach_ptr<Cake, int> s2_x;

    {
        auto s1 = make_attach<Cake>();
        s1->x = 100;
        auto s2 = make_attach<Cake>(200);

        LINE_DEUBG << s1.use_count();
        LINE_DEUBG << s2.use_count();

        s1_x = make_attach_member(s1, x);
        s2_x = make_attach_member(s2, x);

        void_attach = s1_x;
        LINE_DEUBG << s1.use_count();
        LINE_DEUBG << s2.use_count();

    }
    *void_attach += 1;
    LINE_DEUBG << *s1_x;
    LINE_DEUBG << *s2_x;

    LINE_DEUBG << s1_x.use_count();
    LINE_DEUBG << s2_x.use_count();
    return 0;
}
