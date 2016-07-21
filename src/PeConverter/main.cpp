#include <iostream>
#include <fstream>
#include <pe_bliss.h>

using namespace pe_bliss;

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        std::cout << "Usage: PeConverter PE_FILE" << std::endl;
        return 0;
    }

    //Открываем файл
    std::ifstream pe_file(argv[1], std::ios::in | std::ios::binary);
    if(!pe_file)
    {
        std::cout << "Cannot open " << argv[1] << std::endl;
        return 2;
    }

    try
    {
        //Создаем экземпляр PE или PE+ класса с помощью фабрики
        pe_base image(pe_factory::create_pe(pe_file));

        //Получим значение базового адреса загрузки образа (64-бита, универсально для PE и PE+)
        uint64_t base = 0x6E400000;

        //Произведем пересчет необходимых адресов
        rebase_image(image, get_relocations(image), base);

        //Создаем новый PE-файл
        std::string base_file_name(argv[1]);
        std::string::size_type slash_pos;
        if((slash_pos = base_file_name.find_last_of("/\\")) != std::string::npos)
            base_file_name = base_file_name.substr(slash_pos + 1);

        base_file_name = "new_" + base_file_name;
        std::ofstream new_pe_file(base_file_name.c_str(), std::ios::out | std::ios::binary | std::ios::trunc);
        if(!new_pe_file)
        {
            std::cout << "Cannot create " << base_file_name << std::endl;
            return 2;
        }

        //Пересобираем PE-файл
        rebuild_pe(image, new_pe_file);

        std::cout << "PE was rebuilt and saved to " << base_file_name << std::endl;
    }
    catch(const pe_exception& e)
    {
        //Если возникла ошибка
        std::cout << "Error: " << e.what() << std::endl;
        return 2;
    }

    return 0;
}
