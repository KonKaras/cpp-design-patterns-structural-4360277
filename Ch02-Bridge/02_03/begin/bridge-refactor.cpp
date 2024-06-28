#include <iostream>

class ITextHandler
{
    public:
    virtual std::string prepareMessage(const std::string &text) const = 0;
    virtual ~ITextHandler() = default;
};

class ITextSharer : 
{
    public:
    explicit ITextSharer(const ITextHandler &textHandler) : m_textHandler(textHandler) {}
    bool shareText(const std::string &text){
        const std::string preparedText = m_textHandler.prepareMessage(text);
        return sharePreparedText(preparedText);
    }
    virtual ~ITextSharer() = default;

    protected:
    virtual bool sharePreparedText(const std::string &text) = 0;

    private:
    const ITextHandler &m_textHandler;
};