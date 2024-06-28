#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Storage
{
public:
    virtual const string getContents() = 0;
    virtual ~Storage() = default;
};

class SecureStorage : public Storage
{
public:
    explicit SecureStorage(const string &data) : m_Contents(data) {}

    const string getContents()
    {
        return m_Contents;
    }

private:
    const string m_Contents;
};

class SecureStorageProxy : public Storage
{
    public: 
        explicit SecureStorageProxy(const string &data, const int password) : m_Password(password), m_SecureStorage(make_unique<SecureStorage>(data)) {
            cout << "SecureStorageProxy created." << endl;
        }
        const string getContents() override
        {
            if (authorized())
            {
                return m_SecureStorage->getContents();
            }
            else
            {
                return "Access denied!";
            }
        }
    private:
        unique_ptr<SecureStorage> m_SecureStorage;
        const int m_Password;
        bool authorized()
        {
            return m_Password == 42;
        }
};

int main()
{
    SecureStorageProxy secureStorage("Top Secret Information", 42);

    // Limit access to sensitive data
    cout << "Sensitive Data: " << secureStorage.getContents() << endl;

    return 0;
}
