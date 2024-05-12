#include <iostream>


class Singleton {
public:
    static Singleton &GetInstance()
    {
        static Singleton instance;
        return instance;
    }

    void Print() const
    {
        std::cout << "singleton print patten1."  << std::endl;
    }
    ~Singleton() = default;

private:
    Singleton() = default;
    // Singleton(const Singleton &other) = delete;
    // Singleton(const Singleton &&other) = delete;
    // Singleton &operator=(const Singleton &other) = delete;
};


int main(int atgc, char **argv)
{
    auto target = Singleton::GetInstance();
    target.Print();

    return 0;
}