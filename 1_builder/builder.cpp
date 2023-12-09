#include <iostream>

class Computer {
public:
    class Builder {
        public:
            Builder(std::string name, std::string cpuName, int memorySize)
            : name_(name), cpu_(cpuName), memory_size_(memorySize), usb_supported_(false), hdmi_supported_(false)
            {};
            Builder& SupportUSB(bool enable){
                usb_supported_ = enable;
                return *this;
            };
            Builder& SupportHDMI(bool enable){
                hdmi_supported_ = enable;
                return *this;
            };
            Computer Build(){
                return Computer(name_, cpu_, memory_size_, usb_supported_, hdmi_supported_);
            };
        private:
            std::string name_;
            std::string cpu_;
            int memory_size_;
            bool usb_supported_;
            bool hdmi_supported_;
    };

    void ShowComputerConfig(){
        std::cout << "Computer Name: " << name_ << std::endl;
        std::cout << "CPU: " << cpu_ << std::endl;
        std::cout << "Memory Size: " << memory_size_ << std::endl;
        std::cout << "USB Supported: " << usb_supported_ << std::endl;
        std::cout << "HDMI Supported: " << hdmi_supported_ << std::endl;
        std::cout << std::endl;
    };
private:
    Computer(std::string name, std::string cpu, int memorySize, bool usb_supported_, bool hdmi_supported_)
    : name_(name), cpu_(cpu), memory_size_(memorySize), usb_supported_(usb_supported_), hdmi_supported_(hdmi_supported_)
        {};

private:
    std::string name_;
    std::string cpu_;
    int memory_size_;
    bool usb_supported_;
    bool hdmi_supported_;
};

int main(int argc, char** argv)
{
    std::cout << " Designe Patttern for builder demo" << std::endl;
    Computer mac_computer = Computer::Builder("Mac Computer", "M1 Pro", 16)
                            .SupportHDMI(true)
                            .Build();
    mac_computer.ShowComputerConfig();

    Computer mi_computer = Computer::Builder("Mi Computer", "I7 9700K", 32)
                            .SupportHDMI(true)
                            .SupportUSB(true)
                            .Build();
    mi_computer.ShowComputerConfig();

    return 0;
}