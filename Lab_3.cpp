#include <iostream>
#include "vector.hpp"

void ptr_print(vector_2d* p)
{
    p->print();
}
void ref_print(const vector_2d& r)
{
    r.print();
}

int main()
{

    //1
    {
        vector_2d v1(1, 2);
        //vector_2d v1 = vector_2d(1, 2);
        vector_3d v2(1, 2, 3);
        //length
        std::cout << "\nlength()\n";
        double v1_len2_a = v1.length();
        double v1_len2_b = v1.vector_2d::length();

        double v2_len2 = v2.vector_2d::length();

        double v2_len3_a = v2.vector_3d::length();
        double v2_len3_b = v2.length();

        vector_2d& ref_v1 = v1;
        vector_2d& ref_v2_a = v2;
        vector_3d& ref_v2_b = v2;

        std::cout << "\nref 2d:\n";
        ref_v1.print();
        ref_v2_a.print();
        ref_v2_a.vector_2d::print();
        //ref_v2_a.vector_3d::print();

        std::cout << "\nref 3d:\n";
        ref_v2_b.print();
        ref_v2_b.vector_2d::print();
        ref_v2_b.vector_3d::print();

        std::cout << "\nptr print:\n";
        ptr_print(&v1);
        ptr_print(&v2);

        std::cout << "\nref print:\n";

        ref_print(ref_v1);
        ref_print(ref_v2_a);
        ref_print(ref_v2_b);
    }
    //2
    {
        std::cout << "\nptr to obj\n";
        vector_2d* dyn_v1 = new vector_2d(3, 4);
        vector_2d* dyn_v2_a = new vector_3d(3, 4, 5);
        vector_3d* dyn_v2_b = new vector_3d(3, 4, 5);

        //length
        std::cout << "\nlength()\n";
        double v1_len2_a = dyn_v1->length();
        double v1_len2_b = dyn_v1->vector_2d::length();

        double v2_len2 = dyn_v2_a->vector_2d::length();
        //double v2_len2 = dyn_v2_a->vector_3d::length();


        double v2_len3_a = dyn_v2_b->vector_3d::length();
        double v2_len3_b = dyn_v2_b->length();

        std::cout << "\nptr print:\n";
        ptr_print(dyn_v1);
        ptr_print(dyn_v2_a);
        ptr_print(dyn_v2_b);

        std::cout << "\nenter obj count: ";
        int n;
        std::cin >> n;
        if (n <= 0)
        {
            n = 2;
        }
        vector_2d** array = new vector_2d * [n];
        for (int i = 0; i < n; i++)
        {
            std::cout << "enter 1-vector_2d or 2-vector_3d\n";
            int a;
            std::cin >> a;
            if (a == 1) {
                array[i] = new vector_2d(i + 1, i + 3);
            }
            else
            {
                array[i] = new vector_3d(i + 1, i + 3, i + 5);
            }
        }
        std::cout << "\npolymorphism\n";
        for (int i = 0; i < n; i++)
        {
            ptr_print(array[i]);
        }
        delete dyn_v1;
        delete dyn_v2_a;
        delete dyn_v2_b;

        for (int i = 0; i < n; ++i)
        {
            if (array[i] != nullptr)
            {
                delete array[i];
            }
        }
        delete[] array;
    }
}