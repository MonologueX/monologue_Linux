#include <string>
typedef long long CountType;

struct CharInformation
{
    CharInformation(CountType count = 0)
        :m_count(count)
    {}
    char m_ch;
    CountType m_count;
    std::string m_code;
};

class Compress 
{
    public:
        int compress(const std::string& CompressName);
    private:
        CharInformation m_informations[256];
};
