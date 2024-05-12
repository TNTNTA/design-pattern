#include <iostream>

//工厂模式提供了一种创建对象的方式，而无需指定要创建的具体类

class Computer
{
public:
    Computer(const std::string &product, const std::string &cpu)
         : product_(product), cpu_(cpu) {}
    virtual ~Computer() {};

    virtual void PrintInfo() = 0;
protected:
    std::string product_;
    std::string cpu_;
};

class MiComputer : public Computer
{
public:
    MiComputer() : Computer("xiaomi", "i7") {}
    void PrintInfo() override {
        std::cout << "product name: " << product_ << " cpu: " << cpu_ << std::endl;
    }
};

class MacComputer : public Computer
{
public:
    MacComputer() : Computer("apple", "M1") {}
    void PrintInfo() override {
        std::cout << "product name: " << product_ << " cpu: " << cpu_ << std::endl;
    }
};

enum class ComputeType
{
    XIAOMI,
    APPLE,
    INVALID
};

/* 
    1.简单工厂模式：工厂类封装了创建具体产品对象的函数
        缺点：扩展性差，新增产品的时候，需要去修改工厂类。
*/
class SimpleComputeFactory
{
public:
    Computer* GetComputer(ComputeType type){
        Computer *cpt = nullptr;
        switch(type){
            case ComputeType::XIAOMI:
                cpt = new MiComputer();
                break;
            case ComputeType::APPLE:
                cpt = new MacComputer();
                break;
            default: 
                break;
        }
        return cpt;
    }
};

/* 
    2.工厂方法：
    定义一个Factory基类，基类中定义了一个纯虚函数（创建产品），之后定义派生类（具体产品的工厂）负责创建对应的产品。
        优点：可以做到不同的产品在不同的工厂里面创建，能够对现有工厂以及产品的修改关闭。
        缺点：想要添加产品的话，就需要增加新的类。但是这些产品其实都应该在一个BmwFac工厂里面。另外，工厂类太多，不好维护。
*/
class Factory{
public:
    virtual Computer *GetComputer() = 0;
};

class MiFactory : public Factory{
public:
    Computer *GetComputer() override
    {
        return new MiComputer();
    }
};

class AppleFactory : public Factory {
public:
    Computer *GetComputer() override
    {
        return new MacComputer();
    }
};

/* 
    3.抽象工厂方法：
    属于一个产品簇的所有产品创建的接口函数，放在一个抽象工厂里面AbstractFactory，派生类（具体产品的工厂）应该负责创建该产品簇里面所有的产品。
        优点：可以做到不同的产品在不同的工厂里面创建，能够对现有工厂以及产品的修改关闭。
        缺点：想要添加产品的话，就需要增加新的类。但是这些产品其实都应该在一个BmwFac工厂里面。另外，工厂类太多，不好维护。
*/

class Phone
{
public:
    Phone(const std::string &product, const std::string &cpu)
         : product_(product), cpu_(cpu) {}
    virtual ~Phone() {};

    virtual void PrintInfo() = 0;
protected:
    std::string product_;
    std::string cpu_;
};

class MiPhone : public Phone
{
public:
    MiPhone() : Phone("xiaomi", "Qcom 8Gen3") {}
    void PrintInfo() override {
        std::cout << "product name: " << product_ << " cpu: " << cpu_ << std::endl;
    }
};

class IPhone : public Phone
{
public:
    IPhone() : Phone("apple", "A16") {}
    void PrintInfo() override {
        std::cout << "product name: " << product_ << " cpu: " << cpu_ << std::endl;
    }
};

class AbstractFactory{
public:
    virtual Computer *GetComputer() = 0;
    virtual Phone *GetPhone() = 0;
};

class AbsMiFactory : public AbstractFactory{
public:
    Computer *GetComputer() override
    {
        return new MiComputer();
    }
    Phone *GetPhone() override
    {
        return new MiPhone();
    }
};

class AbsAppleFactory : public AbstractFactory {
public:
    Computer *GetComputer() override
    {
        return new MacComputer();
    }
    Phone *GetPhone() override
    {
        return new IPhone();
    }
};

int main(int argc, char **argv)
{
    // 1. simple factory test
    std::cout << "Simple factory test" << std::endl;
    SimpleComputeFactory simplefactory = SimpleComputeFactory();
    auto cpt = simplefactory.GetComputer(ComputeType::APPLE);
    cpt->PrintInfo();

    // 2. factory test
    std::cout << "Factory test" << std::endl;
    MiFactory mifactory = MiFactory();
    auto micpt = mifactory.GetComputer();
    micpt->PrintInfo();

    // 3. Abstract factory test
    std::cout << "Abstract Factory test" << std::endl;
    AbsAppleFactory applefactory = AbsAppleFactory();
    auto iphone = applefactory.GetPhone();
    auto mac = applefactory.GetComputer();
    iphone->PrintInfo();
    mac->PrintInfo();

    return 0;
}